#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

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
    uintptr_t address = 0x40000000;
    char *apk_path = argv[1];
    int extract = 0;

    // Initialize Display and OpenGL ES 2.0
    if (!init_display(-1, -1)) //TODO:: Detect current display size, etc
        return -1;
    
    if (!init_gles2())
        return -1;

    /* Open APK File */
    int err;
    int fd = open(apk_path, O_RDONLY);
    if (fd < 0) {
        fatal_error("Unable to open apk file '%s': Error", apk_path);
        return -1;
    }

    zip_t *apk = zip_fdopen(fd, ZIP_RDONLY, &err);
    if (apk == NULL) {
        fatal_error("Unable to open apk file '%s': Error %d.", apk_path, err);
        return -1;
    }

    /* Load elf module */
    void *inflated_ptr = NULL;
    char *lib = "lib/armeabi-v7a/libyoyo.so";
    ssize_t inflated_bytes = 0;
    if (inflate_buf(apk, lib, &inflated_bytes, &inflated_ptr) == 0) {
        fatal_error("Failed to acquire shared library, exiting.\n");
        return -1;
    }

    so_module runner = {};
    int ret = so_load(&runner, lib, address, inflated_ptr, inflated_bytes);
    if (ret != 0) {
        fatal_error("Unable to load library!\n");
        return -1;
    }

    // Perform module initialization
    so_relocate(&runner);
    so_resolve(&runner);
    so_initialize(&runner);

    // Apply port specific patches
    patch_specifics(&runner);

    // Point of no return - set rx and flush caches
    so_flush_caches(&runner);

    /* Jump into the application */
    invoke_app(apk, apk_path);
    deinit_gles2();

    return 0;
}