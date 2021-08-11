#include <SDL2/SDL.h>

#include "platform.h"
#include "gles2.h"
#include "gles2_bridge.h"

int init_gles2()
{
    // Attempt first to find hooked versions - if it fails, load normal ones.
#ifndef PLATFORM_VITA
    #define GB_DECL_FWD(func, ret, args, vars) func = SDL_GL_GetProcAddress(#func);
#else
    #define GB_DECL_FWD(func, ret, args, vars) func = vglGetProcAddress(#func);
#endif
    #define GB_DECL_FWD_NR GB_DECL_FWD
    #define GB_DECL_FWD_HOOK GB_DECL_FWD
    GLES2_FUNCS
    GLES2_EXT_FUNCS
    #undef GB_DECL_FWD_HOOK
    #undef GB_DECL_FWD_NR
    #undef GB_DECL_FWD

    return 1;
}

void deinit_gles2()
{
    /* */
}