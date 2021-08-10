#ifndef __GLES2_BRIDGE_H__
#define __GLES2_BRIDGE_H__

#include "platform.h"
#include "gles2.h"

extern int init_gles2bridge();
uintptr_t resolve_gl_symbol(const char *symbol);

#endif /* __GLES2_BRIDGE_H__ */