#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <zip.h>

#include "platform.h"
#include "zip_util.h"

static zip_t *current_apk = NULL; 
zip_t *get_current_apk()
{
    return current_apk;
}

void set_current_apk(zip_t *apk)
{
    current_apk = apk;
}

int inflate_file(zip_t *zip, const char *file, const char *dst)
{
    zip_stat_t zip_st;
    if (zip_stat(zip, file, 0, &zip_st) == -1) {
        return 0;
    }

    zip_file_t *f = zip_fopen_index(zip, zip_st.index, ZIP_FL_UNCHANGED);
    if (f == NULL) {
        return 0;
    }

    int fd = open(dst, O_WRONLY | O_TRUNC | O_CREAT, 664);
    if (fd < 0) {
        goto inflate_file_zip;
    }

    zip_int64_t br, left = zip_st.size;
    uint8_t buf[1024] = {};
    while (left) {
        int blk = (left > sizeof(buf)) ? sizeof(buf) : left; 
        if ((br = zip_fread(f, buf, blk)) != blk) {
            goto inflate_file_fd;
        }

        if (write(fd, buf, blk) != blk) {
            goto inflate_file_fd;
        }
        left -= blk;
    }

    return 1;
inflate_file_fd:
    close(fd);
    remove(dst);
inflate_file_zip:
    zip_fclose(f);
    return 0;
}

int inflate_buf(zip_t *zip, const char *file, ssize_t *inflated_bytes, void **bytes)
{
    /* Attempt to locate the file */
    /* Get the uncompressed size */
    zip_stat_t so_stat;
    if (zip_stat(zip, file, 0, &so_stat) == -1) {
        fatal_error("Failed to stat file '%s'.\n", file);
        return 0;
    }

    zip_file_t *f = zip_fopen_index(zip, so_stat.index, ZIP_FL_UNCHANGED);
    if (f == NULL) {
        fatal_error("Unable to open '%s'!\n", file);
        return 0;
    }

    zip_int64_t br;
    void *buf = malloc(so_stat.size);
    if ((br = zip_fread(f, buf, so_stat.size)) != so_stat.size) {
        fatal_error("Reading file failed, read %lld out of %lld bytes.\n", br, so_stat.size);
        zip_fclose(f);
        free(buf);
        return 0;
    }

    *inflated_bytes = so_stat.size;
    *bytes = buf;

    zip_fclose(f);
    return 1;
}