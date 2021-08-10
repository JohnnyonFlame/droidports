#include <stdlib.h>
#include <zlib.h>
#include <zip.h>

#include "platform.h"
#include "zip_util.h"
#include "so_util.h"

void *AAssetManager_fromJava_impl(void *env, void *obj)
{
    return (void*)0xDEADBEEF;
}

typedef struct zipfail {
    zip_file_t *file;
    zip_int64_t index;
} zipfail;

zipfail *AAssetManager_open_impl(void *mgr, const char *filename, int mode)
{
    zip_t *apk = get_current_apk();
    zip_int64_t idx = zip_name_locate(apk, filename, ZIP_FL_NOCASE);

    if (idx < 0)
        return NULL;

    zipfail *zipf = calloc(1, sizeof(*zipf));
    zipf->file = zip_fopen_index(apk, idx, ZIP_FL_UNCHANGED);
    if (!zipf->file) {
        free(zipf);
        return NULL;
    }
    zipf->index = idx;

    return zipf;
}

off_t AAsset_getLength_impl(zipfail *f)
{
    zip_t *apk = get_current_apk();

    zip_stat_t stt = {};
    zip_stat_init(&stt);
    zip_stat_index(apk, f->index, ZIP_STAT_SIZE, &stt);

    return stt.size;
}

off_t AAsset_read_impl(zipfail *f, void *buf, size_t count)
{
    return zip_fread(f->file, buf, count);
}

void AAsset_close_impl(zipfail *f)
{
    if (!f->file)
        return;
        
    zip_fclose(f->file);
    f->file = NULL;

    free(f);
}

DynLibFunction symtable_zip[] = {
    {"inflate", (uintptr_t)&inflate},
    {"inflateInit_", (uintptr_t)&inflateInit_},
    {"inflateInit2_", (uintptr_t)&inflateInit2_},
    {"inflateEnd", (uintptr_t)&inflateEnd},
    {"inflateReset", (uintptr_t)&inflateReset},
    {"deflate", (uintptr_t)&deflate},
    {"compress", (uintptr_t)&compress},
    {"compress2", (uintptr_t)&compress2},
    {"deflateEnd", (uintptr_t)&deflateEnd},
    {"deflateInit_", (uintptr_t)&deflateInit_},
    {"deflateInit2_", (uintptr_t)&deflateInit2_},
    {"deflateReset", (uintptr_t)&deflateReset},
    {"crc32", (uintptr_t)&crc32},

    {"AAssetManager_fromJava", (uintptr_t)&AAssetManager_fromJava_impl},
    {"AAssetManager_open", (uintptr_t)&AAssetManager_open_impl},
    {"AAsset_getLength", (uintptr_t)&AAsset_getLength_impl},
    {"AAsset_read", (uintptr_t)&AAsset_read_impl},
    {"AAsset_close", (uintptr_t)&AAsset_close_impl},
    
    {NULL, (uintptr_t)NULL}
};