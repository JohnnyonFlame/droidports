#ifndef __ZIP_UTILS_H__
#define __ZIP_UTILS_H__

#include <zip.h>

extern zip_t *zip_get_current_apk();
extern void zip_set_current_apk(zip_t *apk);
extern int zip_inflate_buf(zip_t *zip, const char *file, size_t *inflated_bytes, void **bytes);
extern int zip_inflate_buf_sz(zip_t *zip, const char *file, size_t *inflated_bytes, void **bytes, size_t max_bytes);
extern int zip_inflate_file(zip_t *zip, const char *file, const char *dst);

#endif /* __ZIP_UTILS_H__ */