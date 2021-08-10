#ifndef __ZIP_UTILS_H__
#define __ZIP_UTILS_H__

#include <zip.h>

zip_t *get_current_apk();
void set_current_apk(zip_t *apk);
int inflate_buf(zip_t *zip, const char *file, ssize_t *inflated_bytes, void **bytes);

#endif /* __ZIP_UTILS_H__ */