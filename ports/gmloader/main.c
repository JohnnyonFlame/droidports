#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "io_util.h"
#include "platform.h"
#include "so_util.h"
#include "fake_jni.h"
#include "zip_util.h"
#include "media.h"
#include "gles2.h"

#include "symtables.h"

#include "libyoyo.h"

DynLibFunction *so_static_patches[] = {
    symtable_freetype,
    symtable_openal,
    NULL
};

DynLibFunction *so_dynamic_libraries[] = {
    symtable_ctype,
    symtable_freetype,
    symtable_math,
    symtable_misc,
    symtable_openal,
    symtable_pthread,
    symtable_stdio,
    symtable_zip,
    NULL
};

int main(int argc, char *argv[])
{
    uintptr_t addr_yoyo = 0x40000000;
    uintptr_t addr_stdcpp = addr_yoyo - (0x200000 + 0x10000);
    char *apk_path = argv[1];
    int extract = 0;

    // Initialize Display and OpenGL ES 2.0
    if (!init_display(-1, -1)) //TODO:: Detect current display size, etc
        return -1;
    
    if (!init_gles2())
        return -1;

    /* Open APK File */
    warning("Opening %s...\n", apk_path);

    int err;
    int fd = open(apk_path, O_RDONLY);
    if (fd < 0) {
        fatal_error("Unable to open apk file '%s': Error", apk_path);
        return -1;
    }

    warning("Creating zip handle...\n");
    zip_t *apk = zip_fdopen(fd, ZIP_RDONLY, &err);
    if (apk == NULL) {
        fatal_error("Unable to open apk file '%s': Error %d.", apk_path, err);
        return -1;
    }

    /* Load elf module */
    void *yoyo_inflated_ptr = NULL;
    void *stdcpp_inflated_ptr = NULL;
#if ARCH_ARMV6
    char *libyoyo = "lib/armeabi/libyoyo.so";
    char *libcpp = "lib/armeabi/libc++_shared.so";
#else
    char *libyoyo = "lib/armeabi-v7a/libyoyo.so";
    char *libcpp = "lib/armeabi-v7a/libc++_shared.so";
#endif
    warning("Inflating %s...\n", libcpp);
    size_t inflated_bytes = 0;
    if (zip_inflate_buf(apk, libcpp, &inflated_bytes, &stdcpp_inflated_ptr) == 0) {
        int fd;
        if (!io_buffer_from_file("libc++_shared.so", &fd, &stdcpp_inflated_ptr, &inflated_bytes, 0)) {
            fatal_error("Failed to acquire libc++_shared.so, exiting.\n");
            return -1;
        }
    }

    warning("Loading runner elf %s (%p, %d bytes)...\n", libcpp, stdcpp_inflated_ptr, inflated_bytes);
    so_module cpp = {};
    int ret = so_load(&cpp, libcpp, addr_stdcpp, stdcpp_inflated_ptr, inflated_bytes);
    if (ret != 0) {
        fatal_error("Unable to load library!\n");
        return -1;
    }

    warning("Inflating %s...\n", libyoyo);
    inflated_bytes = 0;
    if (zip_inflate_buf(apk, libyoyo, &inflated_bytes, &yoyo_inflated_ptr) == 0) {
        fatal_error("Failed to acquire shared library, exiting.\n");
        return -1;
    }

    warning("Loading runner elf %s (%p, %d bytes)...\n", libyoyo, yoyo_inflated_ptr, inflated_bytes);
    so_module runner = {};
    ret = so_load(&runner, libyoyo, addr_yoyo, yoyo_inflated_ptr, inflated_bytes);
    if (ret != 0) {
        fatal_error("Unable to load library!\n");
        return -1;
    }

    // Apply port specific patches and reflush
    warning("Applying port specific patches...\n", libyoyo);
    patch_specifics(&runner);
    so_flush_caches(&runner, 0);

    /* Jump into the application */
    invoke_app(apk, apk_path);
    deinit_gles2();

    return 0;
}
