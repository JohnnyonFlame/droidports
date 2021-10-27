#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <zip.h>
#include <string.h>
#include <lodepng.h>
#include <math.h>
#include <pthread.h>
#include <sys/types.h>

#include "pthread_bridge.h"
#include "platform.h"
#include "so_util.h"
#include "zip_util.h"
#include "io_util.h"
#include "fake_jni.h"
#include "gles2_bridge.h"
#include "RunnerJNILib.h"
#include "libyoyo_internals.h"
#include "libyoyo.h"
#include "media.h"

so_module *libyoyo = NULL;

uintptr_t *New_Room = NULL;
uintptr_t *Current_Room = NULL;
fct_add_t Function_Add = NULL;
create_ds_map_t CreateDsMap = NULL;
create_async_event_with_ds_map_t CreateAsynEventWithDSMap = NULL;
uint8_t *_IO_ButtonDown = NULL;
uint8_t *_IO_ButtonPressed = NULL;
uint8_t *_IO_ButtonReleased = NULL;
int32_t *g_MousePosX = NULL;
int32_t *g_MousePosY = NULL;
uint8_t *_IO_KeyDown = NULL;
uint8_t *_IO_LastKey = NULL;
uint8_t *_IO_CurrentKey = NULL;
uint8_t *_IO_KeyPressed = NULL;
uint8_t *_IO_KeyReleased = NULL;

ABI_ATTR void (*GamepadUpdate)() = NULL;
uint32_t *g_IOFrameCount = NULL;
long long *g_GML_DeltaTime = NULL;
char *g_fNoAudio = NULL;

// Built-in function tables 
static RFunction **the_functions = NULL;
static int *the_numb = NULL;

ABI_ATTR int32_t (*YYGetInt32)(RValue *val, int idx) = NULL;
ABI_ATTR int32_t (*Graphics_DisplayWidth)() = NULL;
ABI_ATTR int32_t (*Graphics_DisplayHeight)() = NULL;
ABI_ATTR float (*Audio_GetTrackPos)(int sound_id) = NULL;

ABI_ATTR routine_t F_YoYo_DrawTextureFlush = NULL;

uint8_t prev_kbd_state[N_KEYS] = {};
uint8_t cur_keys[N_KEYS] = {};

static char *fake_functs[] = {
    "object_set_collisions",
    "psn_show_error_dialog",
    "psn_check_free_space",
    "psn_get_leaderboard_score_range",
    "psn_default_user_name",
    "psn_name_for_pad",
    "psn_unlock_trophy",
    "psn_get_trophy_unlock_state",
    "psn_init_np_libs",
    "psn_exit_np_libs",
    "psn_get_leaderboard_score",
    "psn_post_leaderboard_score",
    "psn_post_leaderboard_score_comment",
    "psn_check_np_availability",
    "psn_tick_error_dialog",
    "psn_tick",
    "psn_np_status",
    "psn_get_friends_scores",
    "psn_name_for_user",
    "psn_default_user",
    "psn_user_for_pad",
    NULL
};

static char platform_savedir[PATH_MAX] = "";
void setup_platform_savedir(const char *gamename)
{
    //TODO:: Update psvita sdk and use the newlib mkdir.
#ifndef PLATFORM_VITA
    // For linux targets
	snprintf(platform_savedir, sizeof(platform_savedir), "%s/.config/%s/", getenv("HOME"), gamename);
	warning("Saving to folder %s.\n", platform_savedir);

    char mkdir_cmd[PATH_MAX];
    snprintf(mkdir_cmd, sizeof(mkdir_cmd), "mkdir -p %s", platform_savedir);

    if (system(mkdir_cmd) != 0) {
        fatal_error("Failed to create folder \"%s\".", platform_savedir);
        exit(-1);
    }
#else
    // For PS-vita target
    snprintf(platform_savedir, sizeof(platform_savedir), "ux0:data/%s/", gamename);
	warning("Saving to folder %s.\n", platform_savedir);
#endif
}

const char *get_platform_savedir()
{
    return platform_savedir;
}

ABI_ATTR int _dbg_csol_print(void *csol, const char *fmt, ...) {
    char csol_str[2048];
    va_list list;

    va_start(list, fmt);
    //int ret = vprintf(fmt, list);
    int ret = vsnprintf(csol_str, 2047, fmt, list);
    warning("%s", csol_str);
    va_end(list);
    return ret;
}

static routine_t FindFunctionRoutine(const char *f)
{
    ENSURE_SYMBOL(libyoyo, the_functions, "the_functions");
    ENSURE_SYMBOL(libyoyo, the_numb, "the_numb");
    
    for (int i = 0; i < *the_numb; i++) {
        if (strcmp((*the_functions)[i].f_name, f) == 0) {
            return (*the_functions)[i].f_routine;
        }
    }

    return NULL;
}

static void noop()
{

}

static void game_end_reimpl()
{
    ENSURE_SYMBOL(libyoyo, New_Room, "New_Room");

    *New_Room = 0xffffff9c;
}

static void YYError(const char *msg, ...)
{
    char err[1024];
    va_list va;
    va_start(va, msg);
    vsnprintf(err, sizeof(err), msg, va);
    va_end(va);

    fatal_error("%s\n", err);
    exit(-1);
}

double FORCE_PLATFORM = os_linux;
ABI_ATTR static double force_platform_type()
{
    return FORCE_PLATFORM;
}

ABI_ATTR int force_platform_type_gms2(void *self, int n, RValue *args)
{
    args[0].kind = VALUE_REAL;
    args[0].rvalue.val = FORCE_PLATFORM;
}

static int last_track_id = -1;
static double last_track_pos = 0.f;
static uint32_t last_track_pos_frame = 0;
ABI_ATTR void reimpl_F_AudioGetTrackPos(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ENSURE_SYMBOL(libyoyo, g_IOFrameCount, "g_IOFrameCount");
    ENSURE_SYMBOL(libyoyo, g_GML_DeltaTime, "g_GML_DeltaTime");
    ENSURE_SYMBOL(libyoyo, YYGetInt32, "_Z10YYGetInt32PK6RValuei");
    ENSURE_SYMBOL(libyoyo, Audio_GetTrackPos, "_Z17Audio_GetTrackPosi");
    ENSURE_SYMBOL(libyoyo, g_fNoAudio, "g_fNoAudio");
    int sound_id;
    if (*g_fNoAudio != '\0') {
        return;
    }

    ret->kind = VALUE_REAL;
    sound_id = YYGetInt32(args,0);

    // Discard data if not from last frame or not from the same id
    if ((last_track_id != sound_id) || (*g_IOFrameCount - last_track_pos_frame > 1)) {
        ret->rvalue.val = Audio_GetTrackPos(sound_id);
        last_track_pos = ret->rvalue.val;
    } else {
        // Reuse any data on this specific frame
        if (last_track_pos_frame == *g_IOFrameCount) {
            ret->rvalue.val = last_track_pos;
        } else {
            ret->rvalue.val = Audio_GetTrackPos(sound_id);

            // For timestamps that are within margin of error, enforce monotonic behavior, 
            // even if it means crafting ficticious timestamps.
            // This works around an issue with compressed audio streaming causing bogus
            // timestamp readings, leading to jittery or otherwise broken behavior on Deltarune Chapter 2
            if (ret->rvalue.val < last_track_pos && fabs(ret->rvalue.val - last_track_pos) < 0.1f) {
                ret->rvalue.val = last_track_pos + (double)*g_GML_DeltaTime / 1000000.0f;
            }

            // printf("frame %d, pos: %f, dt %f\n", *g_IOFrameCount, ret->rvalue.val, *g_GML_DeltaTime / 1000000.0f);
        }
    }
    
    last_track_pos_frame = *g_IOFrameCount;
    last_track_id = sound_id;
    last_track_pos = ret->rvalue.val;
}

// This hook disabled the majority of the input code, leaving this up to be implemented
// in a per-platform basis. Check sdl2_media.c as an example.
ABI_ATTR void IO_Start_Step_hook()
{
    // Symbol preamble
    ENSURE_SYMBOL(libyoyo, GamepadUpdate, "_Z14GamepadUpdateMv");
    ENSURE_SYMBOL(libyoyo, g_IOFrameCount, "g_IOFrameCount");
    ENSURE_SYMBOL(libyoyo, g_MousePosX, "g_MousePosX");
    ENSURE_SYMBOL(libyoyo, g_MousePosX, "g_MousePosY");
    ENSURE_SYMBOL(libyoyo, Graphics_DisplayWidth, "_Z21Graphics_DisplayWidthv");
    ENSURE_SYMBOL(libyoyo, Graphics_DisplayHeight, "_Z22Graphics_DisplayHeightv");

    if (*g_MousePosX < 0) *g_MousePosX = 0;
    if (*g_MousePosY < 0) *g_MousePosY = 0;
    if (*g_MousePosX > Graphics_DisplayWidth()) *g_MousePosX = Graphics_DisplayWidth();
    if (*g_MousePosY > Graphics_DisplayHeight()) *g_MousePosY = Graphics_DisplayHeight();

    *g_IOFrameCount = *g_IOFrameCount + 1;
    GamepadUpdate();
}

typedef struct CAudioGroup {
    int m_eLoadState;
    int m_groupId;
    int m_soundCount;
    int *m_soundsAdded;
    int m_soundsLoaded;
    int m_loadProgress;
    void * m_pData;
    char * m_pszName;
    struct CThread *m_pLoadThread;
    struct cAudio_Sound **m_ppSoundList;
} CAudioGroup;

typedef struct CAudioGroupMan {
    struct CAudioGroup **m_ppGroups;
    int m_groupCount;
} CAudioGroupMan;

typedef struct CThread {
    uint32_t m_hThread;
    int m_errorCode;
    char m_bTerminate;
    char m_bRunning;
    char m_bPaused;
    char padding;
    void * m_pFunctionArg;
    void * (* m_pThreadFunc)(void *);
    struct BIONIC_Mutex * m_pTermMutex;
} CThread;

typedef struct LLVMVars {
    char *pWad;
    int	nWadFileLength;
    int	nGlobalVariables;
    int	nInstanceVariables;
    int	nYYCode;
    struct YYVAR **ppVars;
    struct YYVAR **ppFuncs;
    struct YYGMLFuncs *pGMLFuncs;
    void *pYYStackTrace;
} LLVMVars;

static LLVMVars **g_pLLVMVars = NULL;
static void **g_nYYCode = NULL;
static void **g_ppYYStackTrace = NULL;
static void **g_pGameFileBuffer = NULL;
static char **g_pWorkingDirectory = NULL;
static char *g_fYYC = NULL;
static bionic_off_t *g_GameFileLength = NULL; //android had 32bit off_t???
static int g_fdGameFileBuffer = -1;
ABI_ATTR void (*InitLLVM)(LLVMVars *) = NULL;
static ABI_ATTR void (*SetWorkingDirectory_ptr)() = NULL;
static ABI_ATTR void (*Mutex__ctor)(void*, char*) = NULL;
static ABI_ATTR int (*Audio_WAVs)(uint8_t*, uint32_t, uint8_t*, int) = NULL;
static ABI_ATTR void (*CThread__start_PcNS)(CThread *, void *, void *, char *) = NULL;
static ABI_ATTR void (*CThread__start_NS)(CThread *, void *, void *) = NULL;
static ABI_ATTR void (*Audio_PrepareGroup)(void*) = NULL;

static ABI_ATTR int Audio_Load_cb(CAudioGroup *data)
{
    ENSURE_SYMBOL(libyoyo, Audio_PrepareGroup, "_Z18Audio_PrepareGroupi");

    Audio_PrepareGroup(data->m_soundsAdded[1]);
    return 0;
}

// Recalls data about Audio Groups
typedef struct AudioGroupInfo {
    int fd;
    void *memory_map;
    size_t memory_map_sz; 
} AudioGroupInfo;

static AudioGroupInfo *group_info = NULL;
ABI_ATTR int CAudioGroupMan__LoadGroup_reimpl(CAudioGroupMan *this, int groupId)
{
    ENSURE_SYMBOL(libyoyo, Audio_WAVs, "_Z10Audio_WAVsPhjS_i");
    ENSURE_SYMBOL(libyoyo, Mutex__ctor, "_ZN5MutexC1EPKc");

    // We might have either of those
    if (!CThread__start_PcNS && !CThread__start_NS) {
        CThread__start_PcNS = so_symbol(libyoyo, "_ZN7CThread5StartEPFPvS0_ES0_PcNS_9ePriorityE");
        CThread__start_NS = so_symbol(libyoyo, "_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE");
        if (!CThread__start_PcNS && !CThread__start_NS) {
            fatal_error("Symbol CThread::Start unavailable.\n");
            exit(-1);
        }
    }

    CAudioGroup *piVar4;
    char filename[PATH_MAX]; 
    void *mem = NULL;
    size_t mem_sz = 0;

    if (!group_info) {
        group_info = calloc(this->m_groupCount + 1, sizeof(group_info[0]));
    }

    if ((groupId < 1) || (this->m_groupCount <= groupId) || this->m_ppGroups[groupId] == NULL) {
        fatal_error("Unable to initialize Audio Group %d!\n", groupId);
        return 0;
    }

    snprintf(filename, sizeof(filename), "%saudiogroup%d.dat", get_platform_savedir(), groupId);
    int fd = -1;
    // Attempt to load from the working directory directly... (and if possibly,  mmaped)
    if (!io_buffer_from_file(filename, &fd, &mem, &mem_sz, IO_HINT_MMAP)) {
        // That failed, attempt to load from the apk
        snprintf(filename, sizeof(filename), "assets/audiogroup%d.dat", groupId);
        if (!zip_inflate_buf(zip_get_current_apk(), filename, &mem_sz, &mem)) {
            fatal_error("Unable to open Audio Group %d!\n", groupId);
            return 0;
        }
    }

    if (strncmp(mem + 8, "AUDO", 4) != 0) {
        fatal_error("Unable to stat '%s'\n", filename);
        goto audio_free_buf;
    }

    CAudioGroup *grp = this->m_ppGroups[groupId];
    grp->m_pData = mem;
    grp->m_eLoadState = 1;
    grp->m_loadProgress = 0;
    grp->m_soundsLoaded = 0;
    uint32_t sz = *(uint32_t*)(mem + 0xc);
    if (sz == 0) {
        fatal_error("Audiogroup '%s' is empty.\n", filename);
        goto audio_close_fd;
    }

    Audio_WAVs(mem + 0x10, sz, mem, groupId);
    CThread *thr = grp->m_pLoadThread;
    if (thr == NULL) {
        grp->m_pLoadThread = thr = malloc(sizeof(CThread));
        *thr = (CThread){
            .m_pTermMutex = malloc(sizeof(BIONIC_Mutex))
        };

        Mutex__ctor(thr->m_pTermMutex, "TermMutex");
    }

    // Chose one of the available symbols
    if (CThread__start_PcNS) 
        CThread__start_PcNS(thr, Audio_Load_cb, grp, "Audio group load thread");
    else if (CThread__start_NS) 
        CThread__start_NS(thr, Audio_Load_cb, grp);

    group_info[groupId].fd = fd;
    group_info[groupId].memory_map = mem;
    group_info[groupId].memory_map_sz = mem_sz;
    return 1;

audio_free_buf:
    if (fd < 0)
        free(mem);
    else {
        munmap(mem, mem_sz);
        close(fd);
    }
audio_close_fd:
    if (fd >= 0)
        close(fd);

    return 0;
}

extern void _ZdlPv(void *); //operator.delete
static ABI_ATTR (*Mutex__dtor)(void *) = NULL;
static ABI_ATTR (*MemoryManager__Free)(void *) = NULL;
ABI_ATTR CAudioGroup *CAudioGroup_dtor(CAudioGroup *this)
{
    // Since we have custom allocations, this dtor needs to be reimplemented...
    ENSURE_SYMBOL(libyoyo, Mutex__dtor, "_ZN5MutexD2Ev", "_ZN5MutexD1Ev");
    ENSURE_SYMBOL(libyoyo, MemoryManager__Free, "_ZN13MemoryManager4FreeEPv", "_ZN13MemoryManager4FreeEPKv");

    if (this->m_pLoadThread != NULL) {
        if (this->m_pLoadThread->m_pTermMutex) {
            Mutex__dtor(this->m_pLoadThread->m_pTermMutex);
            free(this->m_pLoadThread->m_pTermMutex);
        }
        free(this->m_pLoadThread);
    }

    this->m_pLoadThread = NULL;
    MemoryManager__Free(this->m_ppSoundList);
    this->m_ppSoundList = NULL;
    
    // Is this not memmapped?
    if (group_info[this->m_groupId].fd < 0) {
        free(this->m_pData);
    } else {
        munmap(group_info[this->m_groupId].memory_map, group_info[this->m_groupId].memory_map_sz);
        close(group_info[this->m_groupId].fd);
    }

    group_info[this->m_groupId] = (AudioGroupInfo){
        .fd = -1,
        .memory_map = NULL,
        .memory_map_sz = 0
    };

    return this;
}

ABI_ATTR void RunnerLoadGame_reimpl()
{
    //TODO:: Significantly improve this logic, e.g. with config files etc
    ENSURE_SYMBOL(libyoyo, g_pLLVMVars, "g_pLLVMVars");
    ENSURE_SYMBOL(libyoyo, g_nYYCode, "g_nYYCode");
    ENSURE_SYMBOL(libyoyo, g_pGameFileBuffer, "g_pGameFileBuffer");
    ENSURE_SYMBOL(libyoyo, g_GameFileLength, "g_GameFileLength");
    ENSURE_SYMBOL(libyoyo, g_pWorkingDirectory, "g_pWorkingDirectory");
    ENSURE_SYMBOL(libyoyo, g_fYYC, "g_fYYC");
    ENSURE_SYMBOL(libyoyo, InitLLVM, "_Z8InitLLVMP9SLLVMVars");
    
    size_t sz;
    g_ppYYStackTrace = so_symbol(libyoyo, "g_ppYYStackTrace");

    if (*g_fYYC) {
        *g_pLLVMVars = malloc(sizeof(**g_pLLVMVars));
        InitLLVM(*g_pLLVMVars);
        
        *g_nYYCode = (*g_pLLVMVars)->nYYCode;
        *g_ppYYStackTrace = (*g_pLLVMVars)->pYYStackTrace;
        *g_GameFileLength = (*g_pLLVMVars)->nWadFileLength;
        *g_pGameFileBuffer = (*g_pLLVMVars)->pWad;
    }

    if (!*g_fYYC || (*g_pLLVMVars)->pWad == NULL) {
        // Attempt to load game.droid from the working directory
        char WADNAME[PATH_MAX] = {};
        snprintf(WADNAME, sizeof(WADNAME), "%s%s", get_platform_savedir(), "game.droid");
        if (io_buffer_from_file(WADNAME, &g_fdGameFileBuffer, g_pGameFileBuffer, &sz, IO_HINT_MMAP)) {
            *g_pWorkingDirectory = strdup(get_platform_savedir());
            *g_GameFileLength = sz;
            return;
        }

        // Now attempt from the APK
        if (zip_inflate_buf(zip_get_current_apk(), "assets/game.droid", &sz, g_pGameFileBuffer)) {
            *g_pWorkingDirectory = strdup("assets/");
            *g_GameFileLength = sz;
            return;
        }

        // Failed completely...
        fatal_error("Unable to open game's WAD file.\n");
        exit(-1);
    }
}

char Extension_Call_DLL_Function_reimpl(int id, int argc, RValue *args, RValue *ret)
{
    // WARN_STUB;
    return 0;
}

void patch_specifics(so_module *mod)
{
    libyoyo = mod;

    // Apply function hooks
    DynLibHooks hooks[] = {
        {"_ZN13MemoryManager10DumpMemoryEP7__sFILE", (uintptr_t)&noop, 1},                                   // Skip memory dump
        {"_Z17alBufferDebugNamejPKc", (uintptr_t)&noop, 1},                                                  // Skip OpenAL debug code
        // {"_ZN8TConsole6OutputEPKcz", (uintptr_t)&_dbg_csol_print, 1},                                     // Hook debug output procedure
        {"_ZN12DummyConsole6OutputEPKcz", (uintptr_t)&_dbg_csol_print, 1},                                   // Hook debug output procedure
        {"_Z7YYErrorPKcz", (uintptr_t)&YYError, 1},                                                          // Hook error messages
        {"_Z23YoYo_GetPlatform_DoWorkv", (uintptr_t)&force_platform_type, 1},                                // Fake platform type
        {"_Z20GET_YoYo_GetPlatformP9CInstanceiP6RValue", (uintptr_t)&force_platform_type_gms2, 1},           // Fake platform type
        {"_Z14RunnerLoadGamev", (uintptr_t)&RunnerLoadGame_reimpl, 1},                                       // Custom game.droid loading mechanism
        {"_Z27Extension_Call_DLL_FunctioniiP6RValueS0_", (uintptr_t)&Extension_Call_DLL_Function_reimpl, 1}, // Custom extension logic
        {"_ZN14CAudioGroupMan9LoadGroupEi", (uintptr_t)&CAudioGroupMan__LoadGroup_reimpl, 1},                // Custom CAudioGroup loading (external and possibly mmapped)
        {"_ZN11CAudioGroupD2Ev", (uintptr_t)&CAudioGroup_dtor, 1},                                           // Custom CAudioGroup dtor
        {"_ZN11CAudioGroupD1Ev", (uintptr_t)&CAudioGroup_dtor, 1},                                           // Alt Custom CAudioGroup dtor
        {NULL}
    };

    hook_symbols(mod, hooks);

    // Attempt to find "Function_Add" function
    fct_add_t fct_add = NULL;
    ENSURE_SYMBOL(mod, fct_add, 
        "_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib", 
        "_Z12Function_AddPcPFvR6RValueP9CInstanceS3_iPS0_Eib"
    );

    // Add dummy functions (for missing built-in functions in specific runners)
    for (char **fct = &fake_functs[0]; *fct; fct++) {
        fct_add(*fct, noop, 1, 1);
    }

    // Add a "game_end" function (useless on 1.4.1788+)
    /* From 'https://store.yoyogames.com/downloads/gm-studio/release-notes-studio.html':
     * "Changed game_end() to be ignored on Android and iOS, following crash logs that indicated 
     * this was causing memory corruption and crashes in subsequent runs of your app"
     */
    fct_add("game_end", game_end_reimpl, 1, 1);

    // Reworked "audio_sound_get_track_position" function
    /* The provided built-in has non-monotonic, jittery behavior. This causes a plenthora of issues
     * on games that depend on semi-accurate timestamps.
     * This works around issues on Deltarune Chapter 2, such as missing beat blocks or jittery beat blocks. 
     */
    fct_add("audio_sound_get_track_position", reimpl_F_AudioGetTrackPos, 1, 1);

    // Rework the controller builtins
    register_gamepad_functs(fct_add);
    register_mouse_functs(fct_add);
    hook_symbol(mod, "_Z13IO_Start_Stepv", IO_Start_Step_hook, 1);

    // This function uses unaligned addresses on a ldmia instruction as an optimization
    // work around it with trampolines. If SIGBUSes happen on other address due to ldmia, might
    // be interesting to add them here or implement the hack globally.
    so_symbol_fix_ldmia(mod, "_Z11Shader_LoadPhjS_");
}

static void createSplashTexture(zip_t *apk, GLuint *tex, int *w_tex, int *h_tex, int *w, int *h)
{
    void *inflated_ptr = NULL;
    size_t inflated_bytes = 0;
    uint32_t *pixels = NULL;

    if (zip_inflate_buf(apk, "assets/splash.png", &inflated_bytes, &inflated_ptr)) {
        lodepng_decode32((unsigned char **)&pixels, w, h, inflated_ptr, inflated_bytes);
        free(inflated_ptr);
    } else {
        *w = 320;
        *h = 240;
        warning("Warning, no splash image available, creating xor pattern...\n");
        pixels = malloc(320 * 240 * sizeof(pixels[0]));

        for (int i = 0; i < 240; i++) {
            for (int j = 0; j < 320; j++) {
                pixels[i * 320 + j] = ((~i ^ j) << 16) | ((i ^ ~j) << 8) | (i ^ j);
            }
        }
    }

    // Get pot-2 sizes
    *w_tex = 1; while(*w_tex < *w) *w_tex *= 2;
    *h_tex = 1; while(*h_tex < *h) *h_tex *= 2;

    glGenTextures(1, tex);
    glBindTexture(GL_TEXTURE_2D, *tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *w_tex, *h_tex, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, *w, *h, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    glFlush();

    free(pixels);
}

static int prev_room = 0xFFFFFFFF;
void flushWhenFull()
{
    ENSURE_SYMBOL(libyoyo, g_IOFrameCount, "g_IOFrameCount");
    ENSURE_SYMBOL(libyoyo, Current_Room, "Current_Room");

    // Don't flush outside of room transitions
    if (*Current_Room == prev_room)
        return;

    prev_room = *Current_Room;
    if (!F_YoYo_DrawTextureFlush) {
        F_YoYo_DrawTextureFlush = FindFunctionRoutine("draw_texture_flush");
        if (!F_YoYo_DrawTextureFlush)
            return;
    }

    uint64_t mb_avphys = get_available_physram();
    if (mb_avphys < (MIN_FREE_MEM)) {
        RValue ret;
        F_YoYo_DrawTextureFlush(&ret, NULL, NULL, 0, NULL);
        glFlush();
    }
}

static void apply_hacks()
{
    //TODO:: Add these back in when config files are worked into the project
#if 0 
    routine_t surface_depth_disable = FindFunctionRoutine("surface_depth_disable");
    if (surface_depth_disable != NULL) {
        RValue ret;
        RValue args[1] = {
            {.kind = VALUE_BOOL, .rvalue.val = 1}
        };

        surface_depth_disable(&ret, NULL, NULL, 1, &args[0]);
        warning("HACK:: Disabled surface depth.\n");
    }
#endif
}

//TODO:: APK path, savepath, etc, shouldn't be hardcoded
void invoke_app(zip_t *apk, const char *apk_path)
{
    // Get current jni environment
    JNIEnv *env = jni_get_env();

    // Link and Resolve RunnerJNILib
    jni_register_class(&RunnerJNILib_class);
    Resolve_RunnerJNILib(libyoyo);

    // Setup gamename from file path - removes the folder path and non-alphanumeric chars
    //TODO:: Investigate on how to find this out from the APK - maybe somewhere on the 'assets/droid.unx' file?
    char *gamename = basename(apk_path);
    if (!gamename) {
        fatal_error("Unable to determine basename for '%s'.\n", apk_path);
        exit(-1);
    }

    char *gamename_ext = strrchr(gamename, '.');
    if (gamename_ext && gamename_ext != gamename)
        gamename = strndup(gamename, gamename_ext - gamename);
    else
        gamename = strdup(gamename);
    
    for (char *c = gamename; *c; c++) {
        if (!isalnum(*c))
            *c = '_';
    }

    // Setup folder path and structures
    setup_platform_savedir(gamename);

    int w, h;
    get_display_size(&w, &h);
    
    // Load splash screen background texture
    GLuint tex;
    int splash_w, splash_h, splash_tex_w, splash_tex_h;
    createSplashTexture(apk, &tex, &splash_tex_w, &splash_tex_h, &splash_w, &splash_h);
	_jstring splash_args[] = {
		MK_JSTRING(apk_path),
		MK_JSTRING("assets/splash.png")
    };

    // Display splash screen
    float aspect_png = (float)splash_w/(float)splash_h;
    float aspect_screen = (float)w/(float)h;
    float scale_x, scale_y;
    if (aspect_png > aspect_screen) {
        scale_x = 1.0f;
        scale_y = aspect_screen / aspect_png;
    } else {
        scale_x = aspect_png / aspect_screen;
        scale_y = 1.0f;
    }

    float nw = w*scale_x, nh = h*scale_y;
    glViewport((GLsizei)((w - nw) / 2.0f), (GLsizei)((h - nh) / 2), (GLsizei)nw, (GLsizei)nh);
    RunnerJNILib_RenderSplash(env, NULL, NULL, NULL, w, h, splash_tex_w, splash_tex_h, splash_w, splash_h);
    flip_display_surface();

    // Free splash screen background texture
    glDeleteTextures(1, &tex);

    // Initialize runner
	_jstring args[] = {
		MK_JSTRING(strdup(apk_path)),
		MK_JSTRING(strdup(get_platform_savedir(gamename))),
		MK_JSTRING(strdup("com.johnny.loader")),
	};

    zip_set_current_apk(apk);
    RunnerJNILib_Startup(env, NULL, &args[0], &args[1], &args[2], 4, 0);
    glViewport(0, 0, w, h);

	// RunnerJNILib_Resume(env, NULL, 1);
    apply_hacks();

    // Start main loop
    int ret = 1;
    do {
        ret = update_input();
        get_display_size(&w, &h);

        if (ret == 0)
            break;
        
        ret = RunnerJNILib_Process(env, 0x0, w, h, 0, 0, 0, 0, 0, 60);
		if (RunnerJNILib_canFlip(env, NULL))
        	flip_display_surface();
        
        flushWhenFull();
    } while (ret != 0 && ret != 2);

    warning("yoyo died.\n");
}