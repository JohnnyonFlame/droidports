#define AL_ALEXT_PROTOTYPES

#include <errno.h>
#include <stdlib.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/efx-creative.h>
#include <AL/efx-presets.h>
#include <AL/efx.h>
#include <pthread.h>

#include "platform.h"
#include "pthread_bridge.h"
#include "openal_bridge.h"
#include "so_util.h"

//Directly bridged OpenAL functions
#define AL_DECL_FWD(sym, ret, args, vars) ABI_ATTR static ret bridge_##sym args { return sym vars; }
#define AL_DECL_FWD_NR(sym, ret, args, vars) ABI_ATTR static ret bridge_##sym args { sym vars; }
AL_BRIDGE
#undef AL_DECL_FWD_NR
#undef AL_DECL_FWD

ABI_ATTR static void bridge_alBufferMarkNeedsFreed(ALuint buffer)
{
    return;
}

DynLibFunction symtable_openal[] = {
    #define AL_DECL_FWD(sym, ret, args, vars) {#sym, (uintptr_t)&bridge_##sym},
    #define AL_DECL_FWD_NR AL_DECL_FWD
    AL_BRIDGE
    #undef AL_DECL_FWD_NR
    #undef AL_DECL_FWD

    {"alBufferMarkNeedsFreed", (uintptr_t)&bridge_alBufferMarkNeedsFreed},
    // {"alcSetThreadContext", (uintptr_t)&bridge_alcSetThreadContext},
    // {"alcGetThreadContext", (uintptr_t)&bridge_alcGetThreadContext},
    {NULL, (uintptr_t)NULL}
};