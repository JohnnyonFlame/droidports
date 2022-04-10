#include <math.h>
#include "platform.h"
#include "so_util.h"
#include "libyoyo_internals.h"
#include "libyoyo.h"

Gamepad yoyo_gamepads[4] = {
    [0 ... 3] = {
        .is_available = 0, 
        .was_available = 0,
        .buttons = {},
        .deadzone = 0.1f,
        .axis = {0.0f}
    }
};

#define IS_AXIS_BOUNDS ((axis >= 0) && (axis < ARRAY_SIZE(yoyo_gamepads[0].axis)))
#define IS_BTN_BOUNDS  ((btn  >= 0) && (btn  < ARRAY_SIZE(yoyo_gamepads[0].buttons)))
#define IS_CONTROLLER_BOUNDS ((id >= 0) && (id < ARRAY_SIZE(yoyo_gamepads)))

// (RValue *ret, void *self, void *other, int argc, RValue *args)
ABI_ATTR void gamepad_is_supported(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_BOOL;
    ret->rvalue.val = 1.0f;
}

ABI_ATTR void gamepad_get_device_count(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    // Documentation claims this can be "the number of available "slots" for game pads to be connected to."
    // and since this is the upper-end, we're using that.
    ret->kind = VALUE_REAL;
    ret->rvalue.val = (double)ARRAY_SIZE(yoyo_gamepads);
}

ABI_ATTR void gamepad_is_connected(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;

    int id = (int)args[0].rvalue.val;
    if (!IS_CONTROLLER_BOUNDS) {
        ret->rvalue.val = 0.0f;
        return;
    }

    ret->rvalue.val = (yoyo_gamepads[id].is_available) ? 1.0f : 0.0f;
}

ABI_ATTR void gamepad_get_description(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    Ref *ref = malloc(sizeof(*ref));

    *ref = (Ref){
        .m_refCount = 1,
        .m_size = strlen("Xbox 360 Controller (XInput STANDARD GAMEPAD)"),
        .m_thing = strdup("Xbox 360 Controller (XInput STANDARD GAMEPAD)")
    };

    ret->kind = VALUE_STRING;
    ret->rvalue.str = ref;
}

ABI_ATTR void gamepad_get_button_threshold(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    ret->rvalue.val = 0.5f;
}

ABI_ATTR void gamepad_set_button_threshold(RValue *ret, void *self, void *other, int argc, RValue *args)
{

}

ABI_ATTR void gamepad_axis_count(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    ret->rvalue.val = 4.f;
}

ABI_ATTR void gamepad_axis_value(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    int id = (int)args[0].rvalue.val;
    int axis = (int)(args[1].rvalue.val - gp_axislh);

    if (!IS_CONTROLLER_BOUNDS || !IS_AXIS_BOUNDS) {
        ret->rvalue.val = 0.0f;
        return;
    }

    ret->rvalue.val = yoyo_gamepads[id].axis[axis];
    if (fabs(ret->rvalue.val) < yoyo_gamepads[id].deadzone)
        ret->rvalue.val = 0.0f;
}

ABI_ATTR void gamepad_button_check(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    int id = (int)args[0].rvalue.val;
    int btn = (int)(args[1].rvalue.val - gp_face1);

    if (!IS_CONTROLLER_BOUNDS || !IS_BTN_BOUNDS) {
        ret->rvalue.val = 0.0f;
        return;
    }
    ret->rvalue.val = (yoyo_gamepads[id].buttons[btn] > 0) ? 1.0f : 0.0f;
}

ABI_ATTR void gamepad_button_check_pressed(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    int id = (int)args[0].rvalue.val;
    int btn = (int)(args[1].rvalue.val - gp_face1);

    if (!IS_CONTROLLER_BOUNDS || !IS_BTN_BOUNDS) {
        ret->rvalue.val = 0.0f;
        return;
    }

    ret->rvalue.val = (yoyo_gamepads[id].buttons[btn] == 2) ? 1.0f : 0.0f;
}

ABI_ATTR void gamepad_button_check_released(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    int id = (int)args[0].rvalue.val;
    int btn = (int)(args[1].rvalue.val - gp_face1);

    if (!IS_CONTROLLER_BOUNDS || !IS_BTN_BOUNDS) {
        ret->rvalue.val = 0.0f;
        return;
    }

    ret->rvalue.val = (yoyo_gamepads[id].buttons[btn] == -1) ? 1.0f : 0.0f;
}

ABI_ATTR void gamepad_button_count(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    ret->rvalue.val = 16.f;
}

ABI_ATTR void gamepad_button_value(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    int id = (int)args[0].rvalue.val;
    int btn = (int)(args[1].rvalue.val - gp_face1);
    if (!IS_CONTROLLER_BOUNDS || !IS_BTN_BOUNDS) {
        ret->rvalue.val = 0.0f;
        return;
    }

    ret->rvalue.val = (yoyo_gamepads[id].buttons[btn] > 0) ? 1.0f : 0.0f;
}

ABI_ATTR void gamepad_set_vibration(RValue *ret, void *self, void *other, int argc, RValue *args)
{
}

ABI_ATTR void gamepad_set_axis_deadzone(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    int id = (int)args[0].rvalue.val;
    double deadzone = args[1].rvalue.val;
    if (!IS_CONTROLLER_BOUNDS) {
        return;
    }

    yoyo_gamepads[id].deadzone = deadzone;
}

ABI_ATTR void gamepad_get_axis_deadzone(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_REAL;
    int id = (int)args[0].rvalue.val;
    if (!IS_CONTROLLER_BOUNDS) {
        ret->rvalue.val = 0.0f;
        return;
    }
 
    ret->rvalue.val = yoyo_gamepads[id].deadzone;
}

ABI_ATTR void gamepad_set_colour(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    
}

ABI_ATTR void GamePadRestart()
{
    ENSURE_SYMBOL(libyoyo, CreateDsMap, "_Z11CreateDsMapiz");
    ENSURE_SYMBOL(libyoyo, CreateAsynEventWithDSMap, "_Z24CreateAsynEventWithDSMapii");

    for (int i = 0; i < ARRAY_SIZE(yoyo_gamepads); i++) {
        if (yoyo_gamepads[i].is_available) {
            int dsMap = CreateDsMap(2, "event_type", 0, 0, "gamepad discovered", "pad_index", (double)i, 0);
            CreateAsynEventWithDSMap(dsMap, 0x4b);
        }
    }
}

void register_gamepad_functs(fct_add_t fct_add)
{
    fct_add("gamepad_is_supported", gamepad_is_supported, 0, 1);
    fct_add("gamepad_get_device_count", gamepad_get_device_count, 0, 1);
    fct_add("gamepad_is_connected", gamepad_is_connected, 1, 1);
    fct_add("gamepad_get_description", gamepad_get_description, 1, 1);
    fct_add("gamepad_get_button_threshold", gamepad_get_button_threshold, 1, 1);
    fct_add("gamepad_set_button_threshold", gamepad_set_button_threshold, 2, 1);
    fct_add("gamepad_get_axis_deadzone", gamepad_get_axis_deadzone, 1, 1);
    fct_add("gamepad_set_axis_deadzone", gamepad_set_axis_deadzone, 2, 1);
    fct_add("gamepad_button_count", gamepad_button_count, 1, 1);
    fct_add("gamepad_button_check", gamepad_button_check, 2, 1);
    fct_add("gamepad_button_check_pressed", gamepad_button_check_pressed, 2, 1);
    fct_add("gamepad_button_check_released", gamepad_button_check_released, 2, 1);
    fct_add("gamepad_button_value", gamepad_button_value, 2, 1);
    fct_add("gamepad_axis_count", gamepad_axis_count, 1, 1);
    fct_add("gamepad_axis_value", gamepad_axis_value, 2, 1);
    fct_add("gamepad_set_vibration", gamepad_set_vibration, 3, 1);
    fct_add("gamepad_set_color", gamepad_set_colour, 2, 1);
    fct_add("gamepad_set_colour", gamepad_set_colour, 2, 1);
    hook_symbol(libyoyo, "_Z14GamePadRestartv", GamePadRestart, 1);   
}
