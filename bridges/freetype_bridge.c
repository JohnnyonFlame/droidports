#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftadvanc.h>
#include <freetype/ftbbox.h>
#include <freetype/ftbdf.h>
#include <freetype/ftbitmap.h>
#include <freetype/ftbzip2.h>
#include <freetype/ftcache.h>
#include <freetype/ftchapters.h>
#include <freetype/ftcid.h>
#include <freetype/ftdriver.h>
#include <freetype/fterrors.h>
#include <freetype/ftfntfmt.h>
#include <freetype/ftgasp.h>
#include <freetype/ftglyph.h>
#include <freetype/ftgxval.h>
#include <freetype/ftgzip.h>
#include <freetype/ftimage.h>
#include <freetype/ftincrem.h>
#include <freetype/ftlcdfil.h>
#include <freetype/ftlist.h>
#include <freetype/ftlzw.h>
#include <freetype/ftmm.h>
#include <freetype/ftmodapi.h>
#include <freetype/ftmoderr.h>
#include <freetype/ftotval.h>
#include <freetype/ftoutln.h>
#include <freetype/ftparams.h>
#include <freetype/ftpfr.h>
#include <freetype/ftrender.h>
#include <freetype/ftsizes.h>
#include <freetype/ftsnames.h>
#include <freetype/ftstroke.h>
#include <freetype/ftsynth.h>
#include <freetype/ftsystem.h>
#include <freetype/fttrigon.h>
#include <freetype/fttypes.h>
#include <freetype/ftwinfnt.h>
#include <freetype/t1tables.h>
#include <freetype/ttnameid.h>
#include <freetype/tttables.h>
#include <freetype/tttags.h>

#include "platform.h"
#include "freetype_bridge.h"
#include "so_util.h"

#define FT_DECL_FWD(sym, ret, args, vars) ABI_ATTR static ret bridge_##sym args { return sym vars; }
#define FT_DECL_FWD_NR(sym, ret, args, vars) ABI_ATTR static ret bridge_##sym args { sym vars; }
FT_BRIDGE
#undef FT_DECL_FWD_NR
#undef FT_DECL_FWD

DynLibFunction symtable_freetype[] = {
    #define FT_DECL_FWD(sym, ret, args, vars) {#sym, (uintptr_t)&bridge_##sym},
    #define FT_DECL_FWD_NR FT_DECL_FWD
    FT_BRIDGE
    #undef FT_DECL_FWD_NR
    #undef FT_DECL_FWD
    
    {NULL, (uintptr_t)NULL}
};