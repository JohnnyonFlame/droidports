#ifndef __GLES2_LOADER_H__
#define __GLES2_LOADER_H__
// GL_APICALL ([\w\s]+) (\*?)GL_APIENTRY (\w+) \(([^)]+)\);
// GL_FWD($3, $1$2, (), ($4))

#include "platform.h"

#ifdef USE_VITAGL
#include <psp2/gxm.h>
#include <vitashark.h>

typedef enum {
	VGL_MEM_VRAM, // CDRAM
	VGL_MEM_RAM, // USER_RW RAM
	VGL_MEM_SLOW, // PHYCONT_USER_RW RAM
	VGL_MEM_EXTERNAL, // newlib mem
	VGL_MEM_ALL
} vglMemType;

#else
// Dummy forwards declares for the missing gxm, shark and vitaGL types
typedef int SceGxmMultisampleMode;
typedef int shark_opt;
typedef int vglMemType;
typedef struct SceGxmTexture SceGxmTexture;
#endif

#include "gles2_platform.h"
#include "gles2_macros.h"

#define glBindVertexArray glBindVertexArrayOES
#define glGenVertexArrays glGenVertexArraysOES
#define glDeleteVertexArrays glDeleteVertexArraysOES

extern int init_gles2();
extern void deinit_gles2();

#endif /* __GLES2_LOADER_H__ */