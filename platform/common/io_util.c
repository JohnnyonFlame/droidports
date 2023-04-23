#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "io_util.h"

extern int io_buffer_from_file(const char *filename, int *_fd, void **buf, size_t *size, IO_HINTS hints)
{
    void *mem = NULL;
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return 0;
    }

    struct stat st;
    if (fstat(fd, &st) != 0) {
        goto io_bfff_fd;
    }

    size_t mem_sz = st.st_size;

    char *mmap_hint = getenv("GMLOADER_MMAP");
    if ((!mmap_hint || *mmap_hint == '1') && ((hints & IO_HINT_MMAP) == IO_HINT_MMAP)) {
        // IO_HINT_MMAP:: If possible, memory map this file instead.
        mem = mmap(NULL, mem_sz, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, NULL);
        if (mem == NULL) {
            goto io_bfff_fd;
        }
        
        *_fd = fd;
        *buf = mem;
        *size = mem_sz;
    } else {
        // No hint, just load the file instead.
        mem = malloc(mem_sz);
        if (mem == NULL) {
            goto io_bfff_fd;
        }

        if (read(fd, mem, mem_sz) != mem_sz) {
            goto io_bfff_free;
        }

        close(fd);
        *_fd = -1;
        *buf = mem;
        *size = mem_sz;
    }

    return 1;
io_bfff_free:
    free(mem);
io_bfff_fd:
    close(fd);
    return 0;
}

