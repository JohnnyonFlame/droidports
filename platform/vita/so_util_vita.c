#include <psp2/io/dirent.h>
#include <psp2/io/fcntl.h>
#include <psp2/kernel/sysmem.h>
#include <kubridge.h>

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "elf.h"

#include "platform.h"
#include "so_util.h"

int unrestricted_memcpy(void *dst, const void *src, size_t len)
{
  kuKernelCpuUnrestrictedMemcpy(dst, src, len);
}

uintptr_t block_alloc(int exec, uintptr_t base_addr, size_t sz)
{
  SceKernelAllocMemBlockKernelOpt opt;
  memset(&opt, 0, sizeof(SceKernelAllocMemBlockKernelOpt));
  opt.size = sizeof(SceKernelAllocMemBlockKernelOpt);
  opt.attr = 0x1;
  opt.field_C = (SceUInt32)base_addr;

  return kuKernelAllocMemBlock(
    (exec) ? "rx_block": "rw_block", 
    (exec) ? SCE_KERNEL_MEMBLOCK_TYPE_USER_RX: SCE_KERNEL_MEMBLOCK_TYPE_USER_RW, 
    sz, &opt);
}

void block_free(uintptr_t block, size_t sz)
{
  sceKernelFreeMemBlock(block);
}

void *block_get_base_address(uintptr_t block)
{
  void *addr = NULL;
  sceKernelGetMemBlockBase(block, &addr);

  return addr;
}

void so_flush_caches(so_module *mod) {
  kuKernelFlushCaches((void *)mod->text_base, mod->text_size);
}