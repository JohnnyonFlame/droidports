/* so_util.c -- utils to load and hook .so modules
 *
 * Copyright (C) 2021 Andy Nguyen
 * 
 * This software may be modified and distributed under the terms
 * of the GPLv3 license. See the LICENSE.md file for details.
 */

/*
 * This file has been relicensed under GPLv3 with written permission
 * from the original authors.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

#include "crc32.h"
#include "platform.h"
#include "so_util.h"
#include "asm_encodings.h"
#include "zip_util.h"

#define PATCH_SZ 0x10000 //64 KB-ish arenas
static so_module *head = NULL, *tail = NULL;

static void trampoline_ldm(so_module *mod, uint32_t *dst)
{
  uint32_t trampoline[1];
  uint32_t funct[20] = {0xFAFAFAFA};
  uint32_t *ptr = funct;

  int cur = 0;
  int baseReg = ((*dst) >> 16) & 0xF;
  int bitMask =  (*dst)        & 0xFFFF;

  uint32_t stored = NULL;
  for (int i = 0; i < 16; i++) {
    if (bitMask & (1 << i)) {
      // If the register we're reading the offset from is the same as the one we're writing,
      // delay it to the very end so that the base pointer ins't clobbered
      if (baseReg == i)
        stored = LDR_OFFS(i, baseReg, cur).raw;
      else
        *ptr++ = LDR_OFFS(i, baseReg, cur).raw;
      cur += 4;
    }
  }

  // Perform the delayed load if needed
  if (stored) {
    *ptr++ = stored;
  }

  *ptr++ = LDR_OFFS(PC, PC, -0x4).raw;                  // LDR PC, [PC, -0x4]  ; jmp to [dst+0x4]
  *ptr++ = dst+1;                                       // .dword <...>        ; [dst+0x4]
  
  // Create sign extended relative address rel_addr
  trampoline[0] = B(dst, mod->patch_head).raw;

  unrestricted_memcpy(mod->patch_head, funct, ((uintptr_t)ptr) - ((uintptr_t)funct));
  unrestricted_memcpy(dst, trampoline, sizeof(trampoline));
  mod->patch_head += (ptr - funct) * sizeof(uint32_t);
}

void hook_thumb(uintptr_t addr, uintptr_t dst) {
  if (addr == 0)
    return;
  addr &= ~1;
  if (addr & 2) {
    uint16_t nop = 0x46c0; // NO-OP (MOV R8, R8)
    unrestricted_memcpy((void *)addr, &nop, sizeof(nop));
    addr += 2;
  }

#if ARCH_ARMV6
  uint32_t hook[3];
  hook[0] = 0x46c04778; // BX PC; NO-OP (MOV R8, R8)
  hook[1] = LDR_OFFS(PC, PC, -0x4).raw;
  hook[2] = dst;
#else
  uint32_t hook[2];
  hook[0] = 0xf000f8df; // LDR PC, [PC]
  hook[1] = dst;
#endif
  unrestricted_memcpy((void *)addr, hook, sizeof(hook));
}

void hook_arm(uintptr_t addr, uintptr_t dst) {
  if (addr == 0)
    return;
  uint32_t hook[2];
  hook[0] = LDR_OFFS(PC, PC, -0x4).raw; // LDR PC, [PC, #-0x4]
  hook[1] = dst;
  unrestricted_memcpy((void *)addr, hook, sizeof(hook));
}

void hook_address(uintptr_t addr, uintptr_t dst) {
  // Instead of guessing - check LSB for the "thumb" mode bit
  if ((long)addr & 1)
    hook_thumb(addr, dst);
  else
    hook_arm(addr, dst);
}

#ifdef NDEBUG
#pragma GCC push_options
#pragma GCC optimize ("O0")
void __gdb_breakpoint_add_symbol_file(so_module *mod, const char *fname)
{ 
  // This is used by the debug.gdb script
  // Optimizations are forced OFF so this isn't stripped away
}
#pragma GCC pop_options
#endif

int so_load(so_module *mod, const char *filename, uintptr_t load_addr, void *so_data, size_t sz) {
  int res = 0;
  uintptr_t data_addr = 0;

  // If compiled with debug, dump the loaded binaries, before changes are made
#ifdef NDEBUG
  uint32_t crc32_val = crc32(0xDEADBEEF, so_data, sz);

  // Extract filename from possible path
  char *last_bslash = strrchr(filename, '\\');
  char *file_basename = basename(last_bslash ? last_bslash+1: filename);

  char fname[2048] = "";
#ifndef PLATFORM_VITA
  snprintf(fname, sizeof(fname), "%08X-%s", crc32_val, file_basename);
#else
  snprintf(fname, sizeof(fname), "ux0:data/%08X-%s", crc32_val, filename);
#endif

  FILE *f = fopen(fname, "wb+");
  size_t written = 0;
  if (f) {
    written = fwrite(so_data, 1, sz, f);
    fclose(f);
  }

  if (written != sz) {
    warning("Failed to dump \"%s\"!, wrote %d out of %d bytes\n", fname, written, sz);
  }
#endif

  mod->ehdr = (Elf32_Ehdr *)so_data;
  mod->phdr = (Elf32_Phdr *)((uintptr_t)so_data + mod->ehdr->e_phoff);
  mod->shdr = (Elf32_Shdr *)((uintptr_t)so_data + mod->ehdr->e_shoff);

  mod->shstr = (char *)((uintptr_t)so_data + mod->shdr[mod->ehdr->e_shstrndx].sh_offset);

  for (int i = 0; i < mod->ehdr->e_phnum; i++) {
    if (mod->phdr[i].p_type == PT_LOAD) {
      void *prog_data;
      size_t prog_size;

      if ((mod->phdr[i].p_flags & PF_X) == PF_X) {
        // Allocate arena for code patches, trampolines, etc
        // Sits exactly under the desired allocation space
        mod->patch_size = ALIGN_MEM(PATCH_SZ, mod->phdr[i].p_align);
        mod->patch_blockid = block_alloc(1, load_addr - mod->patch_size, mod->patch_size);
        mod->patch_base = block_get_base_address(mod->patch_blockid);
        mod->patch_head = mod->patch_base;

        // Allocate space for the .text section
        prog_size = ALIGN_MEM(mod->phdr[i].p_memsz, mod->phdr[i].p_align);
        mod->text_blockid = block_alloc(1, load_addr, prog_size);

        if ((mod->text_blockid < 0) || (mod->patch_blockid < 0))
          goto err_free_so;

        prog_data = block_get_base_address(mod->text_blockid);

        mod->phdr[i].p_vaddr += (Elf32_Addr)prog_data;

        mod->text_base = mod->phdr[i].p_vaddr;
        mod->text_size = mod->phdr[i].p_memsz;

        data_addr = (uintptr_t)prog_data + prog_size;
      } else {
        if (data_addr == 0)
          goto err_free_so;

        prog_size = ALIGN_MEM(mod->phdr[i].p_memsz + mod->phdr[i].p_vaddr - (data_addr - mod->text_base), mod->phdr[i].p_align);
        mod->data_blockid = block_alloc(0, data_addr, prog_size);

        if (mod->data_blockid < 0)
          goto err_free_text;

        prog_data = block_get_base_address(mod->data_blockid);

        mod->phdr[i].p_vaddr += (Elf32_Addr)mod->text_base;

        mod->data_base = mod->phdr[i].p_vaddr;
        mod->data_size = mod->phdr[i].p_memsz;
      }

      char *zero = malloc(prog_size);
      memset(zero, 0, prog_size);
      unrestricted_memcpy(prog_data, zero, prog_size);
      free(zero);

      unrestricted_memcpy((void *)mod->phdr[i].p_vaddr, (void *)((uintptr_t)so_data + mod->phdr[i].p_offset), mod->phdr[i].p_filesz);
    }
  }

  for (int i = 0; i < mod->ehdr->e_shnum; i++) {
    char *sh_name = mod->shstr + mod->shdr[i].sh_name;
    uintptr_t sh_addr = mod->text_base + mod->shdr[i].sh_addr;
    size_t sh_size = mod->shdr[i].sh_size;
    if (strcmp(sh_name, ".dynamic") == 0) {
      mod->dynamic = (Elf32_Dyn *)sh_addr;
      mod->num_dynamic = sh_size / sizeof(Elf32_Dyn);
    } else if (strcmp(sh_name, ".dynstr") == 0) {
      mod->dynstr = (char *)sh_addr;
    } else if (strcmp(sh_name, ".dynsym") == 0) {
      mod->dynsym = (Elf32_Sym *)sh_addr;
      mod->num_dynsym = sh_size / sizeof(Elf32_Sym);
    } else if (strcmp(sh_name, ".rel.dyn") == 0) {
      mod->reldyn = (Elf32_Rel *)sh_addr;
      mod->num_reldyn = sh_size / sizeof(Elf32_Rel);
    } else if (strcmp(sh_name, ".rel.plt") == 0) {
      mod->relplt = (Elf32_Rel *)sh_addr;
      mod->num_relplt = sh_size / sizeof(Elf32_Rel);
    } else if (strcmp(sh_name, ".init_array") == 0) {
      mod->init_array = (void *)sh_addr;
      mod->num_init_array = sh_size / sizeof(void *);
    } else if (strcmp(sh_name, ".hash") == 0) {
      mod->hash = (void *)sh_addr;
    }
  }

  if (mod->dynamic == NULL ||
      mod->dynstr == NULL ||
      mod->dynsym == NULL ||
      mod->reldyn == NULL ||
      mod->relplt == NULL) {
    res = -2;
    goto err_free_data;
  }

  for (int i = 0; i < mod->num_dynamic; i++) {
    switch (mod->dynamic[i].d_tag) {
      case DT_SONAME:
        mod->soname = mod->dynstr + mod->dynamic[i].d_un.d_ptr;
        break;
      default:
        break;
    }
  }

  // If debugging is enabled, now trigger the gdb breakpoint.
#ifdef NDEBUG
  if (written == sz)
    __gdb_breakpoint_add_symbol_file(mod, fname);
#endif

  // All done
  free(so_data);

  if (!head && !tail) {
    head = mod;
    tail = mod;
  } else {
    tail->next = mod;
    tail = mod;
  }

  return 0;

  // Oops
err_free_data:
  block_free(mod->data_blockid, mod->data_size);
err_free_text:
  block_free(mod->text_blockid, mod->text_size);
err_free_so:
  free(so_data);

  return res;
}

int so_relocate(so_module *mod) {
  for (int i = 0; i < mod->num_reldyn + mod->num_relplt; i++) {
    Elf32_Rel *rel = i < mod->num_reldyn ? &mod->reldyn[i] : &mod->relplt[i - mod->num_reldyn];
    Elf32_Sym *sym = &mod->dynsym[ELF32_R_SYM(rel->r_info)];
    uintptr_t *ptr = (uintptr_t *)(mod->text_base + rel->r_offset);

    int type = ELF32_R_TYPE(rel->r_info);
    switch (type) {
      case R_ARM_ABS32:
        *ptr += mod->text_base + sym->st_value;
        break;

      case R_ARM_RELATIVE:
        *ptr += mod->text_base;
        break;

      case R_ARM_GLOB_DAT:
      case R_ARM_JUMP_SLOT:
      {
        if (sym->st_shndx != SHN_UNDEF)
          *ptr = mod->text_base + sym->st_value;
        break;
      }

      default:
        fatal_error("Error unknown relocation type %x\n", type);
        break;
    }
  }

  return 0;
}

uintptr_t so_resolve_link(so_module *mod, const char *symbol) {
  for (int i = 0; i < mod->num_dynamic; i++) {
    switch (mod->dynamic[i].d_tag) {
      case DT_NEEDED:
      {
        so_module *curr = head;
        while (curr) {
          if (curr != mod && strcmp(curr->soname, mod->dynstr + mod->dynamic[i].d_un.d_ptr) == 0) {
            uintptr_t link = so_symbol(curr, symbol);
            if (link)
              return link;
          }
          curr = curr->next;
        }

        break;
      }
      default:
        break;
    }
  }

  return 0;
}

void reloc_err(uintptr_t got0)
{
  // Find to which module this missing symbol belongs
  so_module *curr = head;
  while (curr) {
    if ((got0 >= curr->data_base) && (got0 <= curr->data_base + curr->data_size))
      break;
    
    curr = curr->next;
  }

  if (curr) {
    // Attempt to find symbol name and then display error
    for (int i = 0; i < curr->num_reldyn + curr->num_relplt; i++) {
      Elf32_Rel *rel = i < curr->num_reldyn ? &curr->reldyn[i] : &curr->relplt[i - curr->num_reldyn];
      Elf32_Sym *sym = &curr->dynsym[ELF32_R_SYM(rel->r_info)];
      uintptr_t *ptr = (uintptr_t *)(curr->text_base + rel->r_offset);

      int type = ELF32_R_TYPE(rel->r_info);
      switch (type) {
        case R_ARM_JUMP_SLOT:
        {
          if (got0 == (uintptr_t)ptr) {
            fatal_error("Unknown symbol \"%s\" (0x%p).\n", curr->dynstr + sym->st_name, (void*)got0);
            exit(-1);
          }
          break;
        }
      }
    }
  }

  // Ooops, this shouldn't have happened.
  fatal_error("Unknown symbol \"???\" (0x%p).\n", (void*)got0);
  exit(-1);
}

__attribute__((naked)) void plt0_stub()
{
    register uintptr_t got0 asm("r12");
    reloc_err(got0);
}

int so_resolve(so_module *mod) {
  for (int i = 0; i < mod->num_reldyn + mod->num_relplt; i++) {
    Elf32_Rel *rel = i < mod->num_reldyn ? &mod->reldyn[i] : &mod->relplt[i - mod->num_reldyn];
    Elf32_Sym *sym = &mod->dynsym[ELF32_R_SYM(rel->r_info)];
    uintptr_t *ptr = (uintptr_t *)(mod->text_base + rel->r_offset);

    int type = ELF32_R_TYPE(rel->r_info);
    switch (type) {
      case R_ARM_ABS32:
      case R_ARM_GLOB_DAT:
      case R_ARM_JUMP_SLOT:
      {
        if (sym->st_shndx == SHN_UNDEF) {
          int resolved = 0;
          uintptr_t link = so_resolve_link(mod, mod->dynstr + sym->st_name);
          if (link) {
            // debugPrintf("Resolved from dependencies: %s\n", mod->dynstr + sym->st_name);
            *ptr = link;
            resolved = 1;
          }

          for (int j = 0; so_dynamic_libraries[j] != NULL; j++) {
            DynLibFunction *funcs = so_dynamic_libraries[j];
            for (int k = 0; funcs[k].symbol != NULL; k++) {
              if (strcmp(mod->dynstr + sym->st_name, funcs[k].symbol) == 0) {
                if (resolved) {
                  // debugPrintf("Overriden: %s\n", mod->dynstr + sym->st_name);
                } else {
                  // debugPrintf("Resolved manually: %s\n", mod->dynstr + sym->st_name);
                }
                *ptr = funcs[k].func;
                resolved = 1;
                break;
              }
            }

            if (resolved)
              break;
          }

          // For unresolved PLT entries, set unresolved links to the error stub so it fails in runtime
          // For other entries, fail completely.
          if (!resolved) {
            if (type == R_ARM_JUMP_SLOT) {
              warning("Missing: %s\n", mod->dynstr + sym->st_name);
              *ptr = (uintptr_t)&plt0_stub;
            }
            else {
              fatal_error("Missing: %s\n", mod->dynstr + sym->st_name);
              exit(-1);
            }
              
          }
        }

        break;
      }

      default:
        break;
    }
  }

  return 0;
}

void so_initialize(so_module *mod) {
  for (int i = 0; i < mod->num_init_array; i++) {
    if (mod->init_array[i])
      mod->init_array[i]();
  }
}

uint32_t so_hash(const uint8_t *name) {
  uint64_t h = 0, g;
  while (*name) {
    h = (h << 4) + *name++;
    if ((g = (h & 0xf0000000)) != 0)
      h ^= g >> 24;
    h &= 0x0fffffff;
  }
  return h;
}

static int so_symbol_index(so_module *mod, const char *symbol)
{
  if (mod->hash) {
    uint32_t hash = so_hash((const uint8_t *)symbol);
    uint32_t nbucket = mod->hash[0];
    uint32_t *bucket = &mod->hash[2];
    uint32_t *chain = &bucket[nbucket];
    for (int i = bucket[hash % nbucket]; i; i = chain[i]) {
      if (mod->dynsym[i].st_shndx == SHN_UNDEF)
        continue;
      if (mod->dynsym[i].st_info != SHN_UNDEF && strcmp(mod->dynstr + mod->dynsym[i].st_name, symbol) == 0)
        return i;
    }
  }

  for (int i = 0; i < mod->num_dynsym; i++) {
    if (mod->dynsym[i].st_shndx == SHN_UNDEF)
      continue;
    if (mod->dynsym[i].st_info != SHN_UNDEF && strcmp(mod->dynstr + mod->dynsym[i].st_name, symbol) == 0)
      return i;
  }

  return -1;
}

uintptr_t so_symbol(so_module *mod, const char *symbol) {
  int index = so_symbol_index(mod, symbol);
  if (index == -1)
    return NULL;

  return mod->text_base + mod->dynsym[index].st_value;
}

void so_symbol_fix_ldmia(so_module *mod, const char *symbol)
{
  // This is meant to work around crashes due to unaligned accesses (SIGBUS :/) due to certain
  // kernels not having the fault trap enabled, e.g. certain RK3326 Odroid Go Advance clone distros.
  // TODO:: Maybe enable this only with a config flag? maybe with a list of known broken functions?
  // Known to trigger on GM:S's "_Z11Shader_LoadPhjS_" - if it starts happening on other places,
  // might be worth enabling it globally.
  
  int idx = so_symbol_index(mod, symbol);
  if (idx == -1)
    return;

  uintptr_t st_addr = mod->text_base + mod->dynsym[idx].st_value;
  for (uintptr_t addr = st_addr; addr < st_addr + mod->dynsym[idx].st_size; addr+=4) {
    uint32_t inst = *(uint32_t*)(addr);
    
    //Is this an LDMIA instruction with a R0-R12 base register?
    if (((inst & 0xFFF00000) == 0xE8900000) && (((inst >> 16) & 0xF) < SP) ) {
      warning("Found possibly misaligned ldmia on 0x%08X, trying to fix it... (instr: 0x%08X, to 0x%08X)\n", addr, *(uint32_t*)addr, mod->patch_head);
      trampoline_ldm(mod, addr);
    }
  }
}

void hook_symbol(so_module *mod, const char *symbol, uintptr_t dst, int is_optional)
{
  uintptr_t address;
  if (address = so_symbol(mod, symbol)) {
    hook_address(address, dst);
  } else if (!is_optional) {
    fatal_error("Failed to perform non-optional hook for symbol \"%s\"!\n", symbol);
    exit(-1);
  }
}

void hook_symbols(so_module *mod, DynLibHooks *hooks)
{
  for (int i = 0; hooks[i].symbol != NULL; i++) {
    hook_symbol(mod, hooks[i].symbol, hooks[i].hook, hooks[i].opt);
  }
}
