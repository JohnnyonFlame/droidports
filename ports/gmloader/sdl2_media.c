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

int update_input()
{
    ENSURE_SYMBOL(libyoyo, CreateDsMap, "_Z11CreateDsMapiz");
    ENSURE_SYMBOL(libyoyo, CreateAsynEventWithDSMap, "_Z24CreateAsynEventWithDSMapii");
    
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
        case SDL_QUIT:
            return 0;
            break;
        }
    }
    
    return 1;
}

#endif