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

// The following functions use a bridged ALCcontext structure, since the GM:S runner is accessing opaque structure 
// mutexes inside this struct.
typedef struct BRIDGE_ALCcontext {
    ALCcontext *or_ctx;
    char padding[0x54 - sizeof(ALCcontext*)];
    BIONIC_Mutex *mtx;
} BRIDGE_ALCcontext;

ABI_ATTR static void bridge_alcProcessContext(BRIDGE_ALCcontext *context)
{
    if (context)
        alcProcessContext(context->or_ctx);
}

ABI_ATTR static void bridge_alcSuspendContext(BRIDGE_ALCcontext *context)
{
    if (context)
        alcSuspendContext(context->or_ctx);
}

ABI_ATTR static void bridge_alcDestroyContext(BRIDGE_ALCcontext *context)
{
    if (!context)
        return;

    // Wait until mutex is actually destroyed
    while(pthread_mutex_destroy_bridge(&context->mtx->mutex) == EBUSY);

    alcDestroyContext(context->or_ctx);
    free(context->mtx);
    free(context);
}

ABI_ATTR static BRIDGE_ALCcontext *bridge_alcCreateContext(ALCdevice *device, const ALCint* attrlist)
{
    ALCcontext *ctx = alcCreateContext(device, attrlist);
    if (!ctx)
        return NULL;

    // Create fake mutex
    BRIDGE_ALCcontext *bctx = calloc(1, sizeof(*bctx));
    bctx->or_ctx = ctx;
    bctx->mtx = calloc(1, sizeof(*bctx->mtx));
    pthread_mutex_init_bridge(&bctx->mtx->mutex, NULL);
    return bctx;
}

volatile BRIDGE_ALCcontext *currentALCContext = NULL;
ABI_ATTR static ALCboolean bridge_alcMakeContextCurrent(BRIDGE_ALCcontext *context)
{
    ALCboolean ret;
    if (!context)
        return ALC_FALSE;

    if (ret = alcMakeContextCurrent(context->or_ctx))
        currentALCContext = context;

    return ret;
}

ABI_ATTR static BRIDGE_ALCcontext *bridge_alcGetCurrentContext()
{
    return currentALCContext;
}

ABI_ATTR static ALCdevice* bridge_alcGetContextsDevice(BRIDGE_ALCcontext *context)
{
    if (!context)
        return NULL;

    return alcGetContextsDevice(context->or_ctx);
}

#if 0
// thread level storage for the current thread context
__thread BRIDGE_ALCcontext *tlsCurrentALCContext = NULL;
ABI_ATTR static ALCboolean bridge_alcSetThreadContext(BRIDGE_ALCcontext *context)
{
    ALCboolean ret;
    if (ret = alcSetThreadContext(context->or_ctx))
        tlsCurrentALCContext = context;

    return ret;
}

ABI_ATTR static BRIDGE_ALCcontext *bridge_alcGetThreadContext()
{
    return tlsCurrentALCContext;
}
#endif

DynLibFunction symtable_openal[] = {
    #define AL_DECL_FWD(sym, ret, args, vars) {#sym, (uintptr_t)&bridge_##sym},
    #define AL_DECL_FWD_NR AL_DECL_FWD
    AL_BRIDGE
    #undef AL_DECL_FWD_NR
    #undef AL_DECL_FWD

    {"alcProcessContext", (uintptr_t)&bridge_alcProcessContext},
    {"alcSuspendContext", (uintptr_t)&bridge_alcSuspendContext},
    {"alcDestroyContext", (uintptr_t)&bridge_alcDestroyContext},
    {"alcCreateContext", (uintptr_t)&bridge_alcCreateContext},
    {"alcMakeContextCurrent", (uintptr_t)&bridge_alcMakeContextCurrent},
    {"alcGetCurrentContext", (uintptr_t)&bridge_alcGetCurrentContext},
    {"alcGetContextsDevice", (uintptr_t)&bridge_alcGetContextsDevice},
    // {"alcSetThreadContext", (uintptr_t)&bridge_alcSetThreadContext},
    // {"alcGetThreadContext", (uintptr_t)&bridge_alcGetThreadContext},
    {NULL, (uintptr_t)NULL}
};