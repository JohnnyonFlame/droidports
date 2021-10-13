#ifndef __IO_UTIL_H__
#define __IO_UTIL_H__

typedef enum {
    IO_HINT_MMAP = 1, // Attempt to mmap instead of loading
} IO_HINTS;

extern int io_buffer_from_file(const char *filename, int *_fd, void **buf, size_t *size, IO_HINTS hints);

#endif /* __IO_UTILS_H__ */