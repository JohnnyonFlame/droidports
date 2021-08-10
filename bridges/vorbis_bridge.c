#include <vorbis/vorbisfile.h>

#include "platform.h"
#include "so_util.h"
#include "vorbis_bridge.h"

#define VORBIS_FWD(sym, ret, args, vars) ABI_ATTR ret bridge_##sym args { ret r = sym vars; return r; }
#define VORBIS_FWD_NR(sym, ret, args, vars) ABI_ATTR ret bridge_##sym args { sym vars; }
VORBIS_HOOKS
#undef VORBIS_FWD_NR
#undef VORBIS_FWD

DynLibFunction symtable_vorbis[] = {
    #define VORBIS_FWD(sym, ret, args, vars) {#sym, (uintptr_t)&bridge_##sym},
    #define VORBIS_FWD_NR VORBIS_FWD
    VORBIS_HOOKS
    #undef VORBIS_FWD_NR
    #undef VORBIS_FWD
    
    {NULL, (uintptr_t)NULL}
};