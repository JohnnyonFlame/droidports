#ifndef __ZIP_UTILS_H__
#define __ZIP_UTILS_H__

#include <zip.h>

extern zip_t *get_current_apk();
extern void set_current_apk(zip_t *apk);
extern int inflate_buf(zip_t *zip, const char *file, size_t *inflated_bytes, void **bytes);
extern int inflate_file(zip_t *zip, const char *file, const char *dst);

#endif /* __ZIP_UTILS_H__ */