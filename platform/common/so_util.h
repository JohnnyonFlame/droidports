#ifndef __SO_UTIL_H__
#define __SO_UTIL_H__


#include <sys/types.h>
#include <stdint.h>
#include <stddef.h>
#include "elf.h"

#include "platform.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ALIGN_MEM(x, align) (((x) + ((align) - 1)) & ~((align) - 1))
#define ENSURE_SYMBOL(mod, symbol, ...) \
  { \
    if (symbol == NULL) { \
      const char *aliases[] = {__VA_ARGS__}; \
      for (int __i = 0; __i < ARRAY_SIZE(aliases); __i++) { \
        if (*(uintptr_t*)&symbol = (uintptr_t)so_symbol(mod, aliases[__i])) \
          break; \
      } \
      if (symbol == NULL) { \
        fatal_error("Symbol \"%s\" not found.\n", #symbol); \
        exit(-1); \
      } \
    } \
  }

ABI_ATTR typedef int (* init_array_t)();
typedef struct so_module {
  struct so_module *next;

  // The cave and patch arenas are both usable for code generation (e.g. for code instrumentation).
  // patch arena is allocated prior to the .text segment, while the cave is the padding region used
  // to align segments, and thus left free to use as a code cave (see "p_align" member of the
  // program header table entries).
  uintptr_t patch_blockid, text_blockid, data_blockid;
  uintptr_t patch_base, patch_head, cave_base, cave_head, text_base, data_base;
  size_t patch_size, cave_size, text_size, data_size;

  Elf32_Ehdr *ehdr;
  Elf32_Phdr *phdr;
  Elf32_Shdr *shdr;

  Elf32_Dyn *dynamic;
  Elf32_Sym *dynsym;
  Elf32_Rel *reldyn;
  Elf32_Rel *relplt;

  init_array_t *init_array;
  uint32_t *hash;

  int num_dynamic;
  int num_dynsym;
  int num_reldyn;
  int num_relplt;
  int num_init_array;

  char *soname;
  char *shstr;
  char *dynstr;
} so_module;

typedef struct {
  char *symbol;
  uintptr_t func;
} DynLibFunction;

typedef struct {
  char *symbol;
  uintptr_t hook;
  int opt;
} DynLibHooks;

void hook_address(uintptr_t addr, uintptr_t dst);
void hook_symbol(so_module *mod, const char *symbol, uintptr_t dst, int is_optional);
void hook_symbols(so_module *mod, DynLibHooks *hooks);

void so_flush_caches(so_module *mod);
int so_load(so_module *mod, const char *filename, uintptr_t load_addr, void *so_data, size_t sz);
int so_relocate(so_module *mod);
int so_resolve(so_module *mod);
void so_initialize(so_module *mod);
uintptr_t so_symbol(so_module *mod, const char *symbol);

//Platform Specific Implementations
void so_symbol_fix_ldmia(so_module *mod, const char *symbol);
int unrestricted_memcpy(void *dst, const void *src, size_t len);
uintptr_t block_alloc(int exec, uintptr_t base_addr, size_t sz);
void block_free(uintptr_t block, size_t sz);
void *block_get_base_address(uintptr_t block);
void so_flush_caches(so_module *mod);

// Defined on a per-port basis on their specific main.c files
extern DynLibFunction *so_static_patches[];    // Functions to be replaced in the binary
extern DynLibFunction *so_dynamic_libraries[]; // Functions to be resolved

#ifdef __cplusplus
};
#endif

#endif