#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "platform.h"
#include "so_util.h"
#include "gles2.h"
#include "gles2_bridge.h"

#define GB_DECL_FWD(func, ret, args, vars)                                                         \
    ret (*func) vars = NULL;                                                                       \
    ABI_ATTR static ret bridge_##func vars { return func args; }
#define GB_DECL_FWD_NR(func, ret, args, vars)                                                      \
    ret (*func) vars = NULL;                                                                       \
    ABI_ATTR static ret bridge_##func vars { func args; }
#define GB_DECL_FWD_HOOK(func, ret, args, vars)                                                    \
    ret (*func) vars = NULL;                                                                       \
GLES2_FUNCS
GLES2_EXT_FUNCS
#undef GB_DECL_FWD_HOOK
#undef GB_DECL_FWD_NR
#undef GB_DECL_FWD

ABI_ATTR void bridge_glDiscardFramebufferEXT(GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
    // This is just a hint, maybe disable it
#if 0
    if (glDiscardFramebufferEXT)
        glDiscardFramebufferEXT(target, numAttachments, attachments);
#endif
}

uintptr_t resolve_gl_symbol(const char *symbol)
{
    //If this is a non-hooked bridged OpenGL call, return a bridged version only if the native one is present
    //If this is a hooked bridged OpenGL call, always return the bridge.
    #define GB_DECL_FWD(func, ret, args, vars)      else if (func && strcmp(symbol, #func) == 0) { return (uintptr_t)&bridge_##func; }
    #define GB_DECL_FWD_HOOK(func, ret, args, vars) else if (        strcmp(symbol, #func) == 0) { return (uintptr_t)&bridge_##func; }
    #define GB_DECL_FWD_NR(func, ret, args, vars) GB_DECL_FWD(func, ret, args, vars)

    if (0);
    GLES2_FUNCS
    GLES2_EXT_FUNCS
    #undef GB_DECL_FWD_NR
    #undef GB_DECL_FWD_HOOK
    #undef GB_DECL_FWD
    
    fatal_error("Unable to find OpenGL symbol \"%s\"!\n", symbol);

    return (uintptr_t)NULL;
}