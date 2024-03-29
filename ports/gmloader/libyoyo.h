#ifndef __CNI_PATCH_H__
#define __CNI_PATCH_H__

#include <zip.h>
#include "platform.h"

extern int libyoyoIsForeground;
extern int setup_ended;
extern so_module *libyoyo;
extern const char *get_platform_savedir();
extern void patch_specifics(so_module *mod);
extern void invoke_app(zip_t *apk, const char *apk_path);

#endif