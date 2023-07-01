#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>       
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <elf.h>

#include "platform.h"
#include "so_util.h"

int unrestricted_memcpy(void *dst, const void *src, size_t len)
{
  memcpy(dst, src, len);
}

intptr_t block_alloc(int exec, uintptr_t base_addr, size_t sz)
{
  int flags = MAP_PRIVATE|MAP_ANONYMOUS|MAP_POPULATE;
  if ((void*)base_addr != NULL)
    flags |= MAP_FIXED;
  
  return (intptr_t)mmap((void*)base_addr, sz, PROT_READ|PROT_WRITE|(exec ? PROT_EXEC : 0), flags, 0, 0);
}

int block_valid(intptr_t block)
{
  return block != MAP_FAILED;
}

void block_free(uintptr_t block, size_t sz)
{
  munmap((void*)block, sz);
}

void* block_get_base_address(uintptr_t block)
{
  return (void*)block;
}

void so_flush_caches(so_module *mod, int write) {
	__builtin___clear_cache((void*)mod->text_base, (void*)(mod->text_base+mod->text_size));
	mprotect((void*)mod->text_base, mod->text_size, PROT_EXEC|(write ? PROT_WRITE|PROT_READ : PROT_READ));
}