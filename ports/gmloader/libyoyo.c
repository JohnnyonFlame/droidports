#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <zip.h>
#include <string.h>
#include <lodepng.h>

#include "platform.h"
#include "so_util.h"
#include "zip_util.h"
#include "fake_jni.h"
#include "gles2_bridge.h"
#include "RunnerJNILib.h"
#include "libyoyo_internals.h"
#include "libyoyo.h"
#include "media.h"

so_module *libyoyo = NULL;

uintptr_t *New_Room = NULL;
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

void (*GamepadUpdate)() = NULL;
uint32_t *g_IOFrameCount = NULL;

ABI_ATTR int32_t (*YYGetInt32)(RValue *val, int idx) = NULL;
ABI_ATTR int32_t (*Graphics_DisplayWidth)() = NULL;
ABI_ATTR int32_t (*Graphics_DisplayHeight)() = NULL;

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

static void noop()
{

}

static void game_end_reimpl()
{
    ENSURE_SYMBOL(libyoyo, New_Room, "New_Room");

    *New_Room = 0xffffff9c;
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

    g_IOFrameCount++;
    GamepadUpdate();
}

void patch_specifics(so_module *mod)
{
    libyoyo = mod;

    // Apply function hooks
    DynLibHooks hooks[] = {
        {"_ZN13MemoryManager10DumpMemoryEP7__sFILE", (uintptr_t)&noop, 1},                         // Skip memory dump
        {"_Z17alBufferDebugNamejPKc", (uintptr_t)&noop, 1},                                        // Skip OpenAL debug code
        // {"_ZN8TConsole6OutputEPKcz", (uintptr_t)&_dbg_csol_print, 1},                           // Hook debug output procedure
        {"_ZN12DummyConsole6OutputEPKcz", (uintptr_t)&_dbg_csol_print, 1},                         // Hook debug output procedure
        {"_Z23YoYo_GetPlatform_DoWorkv", (uintptr_t)&force_platform_type, 1},                      // Fake platform type
        {"_Z20GET_YoYo_GetPlatformP9CInstanceiP6RValue", (uintptr_t)&force_platform_type_gms2, 1}, // Fake platform type
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

    // Rework the controller builtins
    register_gamepad_functs(fct_add);
    register_mouse_functs(fct_add);
    hook_symbol(libyoyo, "_Z13IO_Start_Stepv", IO_Start_Step_hook, 1);

    // This function uses unaligned addresses on a ldmia instruction as an optimization
    // work around it with trampolines.
    uintptr_t shd_load = so_symbol(mod, "_Z11Shader_LoadPhjS_");
    if (shd_load) {
        for (int i = 0; i < 2048; i++) {
            uint32_t inst = *(uint32_t*)(shd_load + (i*sizeof(uint32_t)));
            //Is this an LDMIA instruction, and not on pc?
            if (((inst & 0xFFF00000) == 0xE8900000) && (((inst >> 16) & 0xF) != 0xC) ) {
                warning("Found possibly misaligned ldmia on 0x%08X, trying to fix it...\n", shd_load + (i*sizeof(uint32_t)));
                trampoline_ldm(shd_load + (i*sizeof(uint32_t)));
                break;
            }
        }
    }
}

// Must be free'd after use.
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

static void createSplashTexture(zip_t *apk, GLuint *tex, int *w_tex, int *h_tex, int *w, int *h)
{
    void *inflated_ptr = NULL;
    ssize_t inflated_bytes = 0;
    uint32_t *pixels = NULL;

    if (inflate_buf(apk, "assets/splash.png", &inflated_bytes, &inflated_ptr)) {
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

    set_current_apk(apk);
    RunnerJNILib_Startup(env, NULL, &args[0], &args[1], &args[2], 4, 0);
    glViewport(0, 0, w, h);

	// RunnerJNILib_Resume(env, NULL, 1);

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
    } while (ret != 0 && ret != 2);

    warning("yoyo died.\n");
}