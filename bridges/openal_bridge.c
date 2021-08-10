#define AL_ALEXT_PROTOTYPES

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/efx-creative.h>
#include <AL/efx-presets.h>
#include <AL/efx.h>

#include "platform.h"
#include "openal_bridge.h"
#include "so_util.h"

#define AL_DECL_FWD(sym, ret, args, vars) ABI_ATTR static ret bridge_##sym args { return sym vars; }
#define AL_DECL_FWD_NR(sym, ret, args, vars) ABI_ATTR static ret bridge_##sym args { sym vars; }
AL_BRIDGE
#undef AL_DECL_FWD_NR
#undef AL_DECL_FWD

DynLibFunction symtable_openal[] = {
    #define AL_DECL_FWD(sym, ret, args, vars) {#sym, (uintptr_t)&bridge_##sym},
    #define AL_DECL_FWD_NR AL_DECL_FWD
    AL_BRIDGE
    #undef AL_DECL_FWD_NR
    #undef AL_DECL_FWD
    
    {NULL, (uintptr_t)NULL}
};