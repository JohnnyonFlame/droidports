#ifndef __GLES2_LOADER_H__
#define __GLES2_LOADER_H__
// GL_APICALL ([\w\s]+) (\*?)GL_APIENTRY (\w+) \(([^)]+)\);
// GL_FWD($3, $1$2, (), ($4))

#include "platform.h"

#include "gles2_platform.h"
#include "gles2_macros.h"

#define glBindVertexArray glBindVertexArrayOES
#define glGenVertexArrays glGenVertexArraysOES
#define glDeleteVertexArrays glDeleteVertexArraysOES

extern int init_gles2();
extern void deinit_gles2();

#endif /* __GLES2_LOADER_H__ */