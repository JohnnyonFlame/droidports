#include <SDL2/SDL.h>

#include "platform.h"
#include "so_util.h"
#include "media.h"
#include "libyoyo_internals.h"
#include "libyoyo.h"

#ifndef PLATFORM_VITA

static SDL_GameController *sdl_game_controllers[4] = {};
static SDL_Window *sdl_win;
static SDL_GLContext *sdl_ctx;

int init_display(int w, int h)
{
    uint32_t flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
    if (w == -1 || h == -1) {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;   
    }

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO);
    sdl_win = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);

    if (!sdl_win) {
		fatal_error("Failed to create window. %s\n", SDL_GetError());
		return 0;
	}
    
    // SDL2.0 specific code
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);

    sdl_ctx = SDL_GL_CreateContext(sdl_win);
	if (!sdl_ctx) {
		fatal_error("Failed to create context. %s\n", SDL_GetError());
		return 0;
	}

    SDL_GL_MakeCurrent(sdl_win, sdl_ctx);
    SDL_GL_SetSwapInterval(1); //Forced vsync, booo
    SDL_GL_SwapWindow(sdl_win); //Workaround for missing first frame
    return 1;
}

void get_display_size(int *w, int *h)
{
    return SDL_GetWindowSize(sdl_win, w, h);
}

void flip_display_surface()
{
    SDL_GL_SwapWindow(sdl_win);
}

static int update_button(int new_state, int old_state)
{
    if (new_state == GAMEPAD_BUTTON_STATE_HELD) {
        if (old_state < GAMEPAD_BUTTON_STATE_HELD)
            return GAMEPAD_BUTTON_STATE_DOWN;
        return GAMEPAD_BUTTON_STATE_HELD;
    } else {
        if (old_state > GAMEPAD_BUTTON_STATE_NEUTRAL)
            return GAMEPAD_BUTTON_STATE_UP;
        return GAMEPAD_BUTTON_STATE_NEUTRAL;
    }
}

#define N_BUTTONS 30
Uint8 *_IO_ButtonDown = NULL;
Uint8 *_IO_ButtonPressed = NULL;
Uint8 *_IO_ButtonReleased = NULL;
Uint32 *g_MousePosX = NULL;
Uint32 *g_MousePosY = NULL;

#define N_KEYS 256
Uint8 prev_kbd_state[N_KEYS] = {};
Uint8 cur_keys[N_KEYS] = {};
Uint8 *_IO_KeyDown = NULL;
Uint8 *_IO_LastKey = NULL;
Uint8 *_IO_CurrentKey = NULL;
Uint8 *_IO_KeyPressed = NULL;
Uint8 *_IO_KeyReleased = NULL;

static int mouse_button_map(int btn)
{
    switch(btn) {
        case SDL_BUTTON_LEFT: return 0;
        case SDL_BUTTON_MIDDLE: return 2;
        case SDL_BUTTON_RIGHT: return 1;
        default: return 2;
    }
}

static int keyboard_set_key(SDL_Keycode key, int state)
{
    ENSURE_SYMBOL(libyoyo, _IO_KeyDown, "_IO_KeyDown", "l_IO_KeyDown");
    ENSURE_SYMBOL(libyoyo, _IO_CurrentKey, "_IO_CurrentKey", "l_IO_CurrentKey");
    ENSURE_SYMBOL(libyoyo, _IO_KeyPressed, "_IO_KeyPressed", "l_IO_KeyPressed");
    ENSURE_SYMBOL(libyoyo, _IO_KeyReleased, "_IO_KeyReleased", "l_IO_KeyReleased");
    #define UPDATE_KEY(k) \
        { \
            if (state) \
                *_IO_CurrentKey = k; \
            else if (!state && *_IO_CurrentKey == k) \
                *_IO_CurrentKey = -1; \
            _IO_KeyDown[k] = state; \
            _IO_KeyPressed[k] = state; \
            _IO_KeyReleased[k] = !state; \
        }

    if (key == SDLK_LSHIFT || key == SDLK_RSHIFT)
        UPDATE_KEY(vk_shift);
    if (key == SDLK_LALT || key == SDLK_RALT)
        UPDATE_KEY(vk_alt);
    if (key == SDLK_LCTRL || key == SDLK_RCTRL)
        UPDATE_KEY(vk_control);

    if (key >= SDLK_a && key <= SDLK_z) {
        UPDATE_KEY(key + ('A' - 'a'));
    }
    if (key >= SDLK_0 && key <= SDLK_9) {
        UPDATE_KEY(key);
    }

    switch (key)
    {
    case SDLK_RETURN:      UPDATE_KEY(vk_enter);       break;
    case SDLK_ESCAPE:      UPDATE_KEY(vk_escape);      break;
    case SDLK_SPACE:       UPDATE_KEY(vk_space);       break;
    case SDLK_BACKSPACE:   UPDATE_KEY(vk_backspace);   break;
    case SDLK_TAB:         UPDATE_KEY(vk_tab);         break;
    case SDLK_PAUSE:       UPDATE_KEY(vk_pause);       break;
    case SDLK_PRINTSCREEN: UPDATE_KEY(vk_printscreen); break;
    case SDLK_LEFT:        UPDATE_KEY(vk_left);        break;
    case SDLK_RIGHT:       UPDATE_KEY(vk_right);       break;
    case SDLK_UP:          UPDATE_KEY(vk_up);          break;
    case SDLK_DOWN:        UPDATE_KEY(vk_down);        break;
    case SDLK_HOME:        UPDATE_KEY(vk_home);        break;
    case SDLK_END:         UPDATE_KEY(vk_end);         break;
    case SDLK_DELETE:      UPDATE_KEY(vk_delete);      break;
    case SDLK_INSERT:      UPDATE_KEY(vk_insert);      break;
    case SDLK_PAGEUP:      UPDATE_KEY(vk_pageup);      break;
    case SDLK_PAGEDOWN:    UPDATE_KEY(vk_pagedown);    break;
    case SDLK_F1:          UPDATE_KEY(vk_f1);          break;
    case SDLK_F2:          UPDATE_KEY(vk_f2);          break;
    case SDLK_F3:          UPDATE_KEY(vk_f3);          break;
    case SDLK_F4:          UPDATE_KEY(vk_f4);          break;
    case SDLK_F5:          UPDATE_KEY(vk_f5);          break;
    case SDLK_F6:          UPDATE_KEY(vk_f6);          break;
    case SDLK_F7:          UPDATE_KEY(vk_f7);          break;
    case SDLK_F8:          UPDATE_KEY(vk_f8);          break;
    case SDLK_F9:          UPDATE_KEY(vk_f9);          break;
    case SDLK_F10:         UPDATE_KEY(vk_f10);         break;
    case SDLK_F11:         UPDATE_KEY(vk_f11);         break;
    case SDLK_F12:         UPDATE_KEY(vk_f12);         break;
    case SDLK_KP_0:        UPDATE_KEY(vk_numpad0);     break;
    case SDLK_KP_1:        UPDATE_KEY(vk_numpad1);     break;
    case SDLK_KP_2:        UPDATE_KEY(vk_numpad2);     break;
    case SDLK_KP_3:        UPDATE_KEY(vk_numpad3);     break;
    case SDLK_KP_4:        UPDATE_KEY(vk_numpad4);     break;
    case SDLK_KP_5:        UPDATE_KEY(vk_numpad5);     break;
    case SDLK_KP_6:        UPDATE_KEY(vk_numpad6);     break;
    case SDLK_KP_7:        UPDATE_KEY(vk_numpad7);     break;
    case SDLK_KP_8:        UPDATE_KEY(vk_numpad8);     break;
    case SDLK_KP_9:        UPDATE_KEY(vk_numpad9);     break;
    case SDLK_KP_DIVIDE:   UPDATE_KEY(vk_divide);      break;
    case SDLK_KP_MULTIPLY: UPDATE_KEY(vk_multiply);    break;
    case SDLK_KP_MINUS:    UPDATE_KEY(vk_subtract);    break;
    case SDLK_KP_PLUS:     UPDATE_KEY(vk_add);         break;
    case SDLK_KP_DECIMAL:  UPDATE_KEY(vk_decimal);     break;
    case SDLK_LSHIFT:      UPDATE_KEY(vk_lshift);      break;
    case SDLK_LCTRL:       UPDATE_KEY(vk_lcontrol);    break;
    case SDLK_LALT:        UPDATE_KEY(vk_lalt);        break;
    case SDLK_RSHIFT:      UPDATE_KEY(vk_rshift);      break;
    case SDLK_RCTRL:       UPDATE_KEY(vk_rcontrol);    break;
    case SDLK_RALT:        UPDATE_KEY(vk_ralt);        break;
    default:
        break;
    }
}

static Uint32 prev_mouse_state = 0;
static int key_count = 0;
int update_input()
{
    ENSURE_SYMBOL(libyoyo, CreateDsMap, "_Z11CreateDsMapiz");
    ENSURE_SYMBOL(libyoyo, CreateAsynEventWithDSMap, "_Z24CreateAsynEventWithDSMapii");
    ENSURE_SYMBOL(libyoyo, _IO_CurrentKey, "_IO_CurrentKey", "l_IO_CurrentKey");
    ENSURE_SYMBOL(libyoyo, _IO_LastKey, "_IO_LastKey", "l_IO_LastKey");
    ENSURE_SYMBOL(libyoyo, _IO_KeyDown, "_IO_KeyDown", "l_IO_KeyDown");
    ENSURE_SYMBOL(libyoyo, _IO_KeyPressed, "_IO_KeyPressed", "l_IO_KeyPressed");
    ENSURE_SYMBOL(libyoyo, _IO_KeyReleased, "_IO_KeyReleased", "l_IO_KeyReleased");
    ENSURE_SYMBOL(libyoyo, _IO_ButtonDown, "_IO_ButtonDown");
    ENSURE_SYMBOL(libyoyo, _IO_ButtonPressed, "_IO_ButtonPressed");
    ENSURE_SYMBOL(libyoyo, _IO_ButtonReleased, "_IO_ButtonReleased");
    ENSURE_SYMBOL(libyoyo, g_MousePosX, "g_MousePosX");
    ENSURE_SYMBOL(libyoyo, g_MousePosY, "g_MousePosY");
    ENSURE_SYMBOL(libyoyo, g_MousePosY, "g_MousePosY");

    memset(_IO_KeyPressed, 0, N_KEYS);
    memset(_IO_KeyReleased, 0, N_KEYS);

    *_IO_LastKey = *_IO_CurrentKey;
    // Other events (keyboard, gamepad hotplug, etc)
    int prev_key_count = key_count;
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_CONTROLLERDEVICEADDED:
            if (ev.cdevice.which >= sizeof(sdl_game_controllers) / sizeof(sdl_game_controllers[0]))
                break;

            yoyo_gamepads[ev.cdevice.which].is_available = 1;

            if (SDL_IsGameController(ev.cdevice.which)) {
                SDL_GameController *controller = SDL_GameControllerOpen(ev.cdevice.which);
                sdl_game_controllers[ev.cdevice.which] = controller;

                // Async gamepad event
                int dsMap = CreateDsMap(2, "event_type", 0, 0, "gamepad discovered", "pad_index", (double)ev.cdevice.which, 0);
                CreateAsynEventWithDSMap(dsMap, 0x4b);
            }
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            if (ev.cdevice.which >= sizeof(sdl_game_controllers) / sizeof(sdl_game_controllers[0]))
                break;

            yoyo_gamepads[ev.cdevice.which].is_available = 0;

            printf("Disconnected controller %d!\n", ev.cdevice.which);
            SDL_GameControllerClose(sdl_game_controllers[ev.cdevice.which]);
            sdl_game_controllers[ev.cdevice.which] = NULL;

            // Async gamepad event
            int dsMap = CreateDsMap(2, "event_type", 0, 0, "gamepad lost", "pad_index", (double)ev.cdevice.which, 0);
            CreateAsynEventWithDSMap(dsMap, 0x4b);
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            if (ev.key.repeat == 1)
                break;

            key_count -= 1 - (ev.key.state * 2);
            keyboard_set_key(ev.key.keysym.sym, ev.key.state);
            break;
        case SDL_QUIT:
            return 0;
            break;
        }
    }

    _IO_KeyDown[vk_anykey] = key_count > 0;
    _IO_KeyPressed[vk_anykey] = (key_count > 0) && (prev_key_count == 0);
    _IO_KeyReleased[vk_anykey] = (key_count == 0) && (prev_key_count > 0);

    _IO_KeyDown[vk_nokey] = !_IO_KeyDown[vk_anykey];
    _IO_KeyPressed[vk_nokey] = !_IO_KeyPressed[vk_anykey];
    _IO_KeyReleased[vk_nokey] = !_IO_KeyReleased[vk_anykey];

    // Gamepad Input Code
    SDL_GameControllerUpdate();
    for (int i = 0; i < 4; i++) {
        if (sdl_game_controllers[i] == NULL)
            continue;

        uint8_t new_states[16] = {};
        int k = 0;
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_A);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_B);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_X);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_Y);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
        new_states[k++] = SDL_GameControllerGetAxis  (sdl_game_controllers[i], SDL_CONTROLLER_AXIS_TRIGGERLEFT) > 8000;
        new_states[k++] = SDL_GameControllerGetAxis  (sdl_game_controllers[i], SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 8000;
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_BACK);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_START);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_LEFTSTICK);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_RIGHTSTICK);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_DPAD_UP);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        new_states[k++] = SDL_GameControllerGetButton(sdl_game_controllers[i], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);

        for (int j = 0; j < 16; j++) {
            // down -> held or up -> cleared
            yoyo_gamepads[i].buttons[j] = (double)update_button(new_states[j], (int)yoyo_gamepads[i].buttons[j]);
        }

        k = 0;
        yoyo_gamepads[i].axis[k++] = ((double)SDL_GameControllerGetAxis(sdl_game_controllers[i], SDL_CONTROLLER_AXIS_LEFTX)) / 32767.f;
        yoyo_gamepads[i].axis[k++] = ((double)SDL_GameControllerGetAxis(sdl_game_controllers[i], SDL_CONTROLLER_AXIS_LEFTY)) / 32767.f;
        yoyo_gamepads[i].axis[k++] = ((double)SDL_GameControllerGetAxis(sdl_game_controllers[i], SDL_CONTROLLER_AXIS_RIGHTX)) / 32767.f;
        yoyo_gamepads[i].axis[k++] = ((double)SDL_GameControllerGetAxis(sdl_game_controllers[i], SDL_CONTROLLER_AXIS_RIGHTY)) / 32767.f;
    }

    // Mouse Code
    int x, y;
    Uint32 mouse_state = SDL_GetMouseState(&x, &y);

    memset(_IO_ButtonDown, 0, N_BUTTONS);
    memset(_IO_ButtonPressed, 0, N_BUTTONS);
    memset(_IO_ButtonReleased, 0, N_BUTTONS);

    *g_MousePosX = x;
    *g_MousePosY = y;
    #define IS_SET(state, mask) (((state) & (mask)) == (mask))
    for (int i = 0; i < 3; i++) {
        int id = mouse_button_map(i + SDL_BUTTON_LEFT);
        Uint32 mask = (1 << i);
        _IO_ButtonDown[id]     =  IS_SET(mouse_state, mask);
        _IO_ButtonPressed[id]  =  IS_SET(mouse_state, mask) && !IS_SET(prev_mouse_state, mask);
        _IO_ButtonReleased[id] = !IS_SET(mouse_state, mask) &&  IS_SET(prev_mouse_state, mask);
    }

    return 1;
}

#endif