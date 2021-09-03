#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "platform.h"
#include "so_util.h"
#include "libyoyo_internals.h"
#include "libyoyo.h"

ABI_ATTR void mouse_set(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ENSURE_SYMBOL(libyoyo, g_MousePosX, "g_MousePosX");
    ENSURE_SYMBOL(libyoyo, g_MousePosY, "g_MousePosY");
    ENSURE_SYMBOL(libyoyo, YYGetInt32, "_Z10YYGetInt32PK6RValuei");

    *g_MousePosX = YYGetInt32(args, 0);
    *g_MousePosY = YYGetInt32(args, 1);
}

ABI_ATTR void mouse_get_x(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ENSURE_SYMBOL(libyoyo, g_MousePosX, "g_MousePosX");

    ret->kind = VALUE_REAL;
    ret->rvalue.val = *g_MousePosX;
}

ABI_ATTR void mouse_get_y(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ENSURE_SYMBOL(libyoyo, g_MousePosY, "g_MousePosY");

    ret->kind = VALUE_REAL;
    ret->rvalue.val = *g_MousePosY;
}

void register_mouse_functs(fct_add_t fct_add)
{
    fct_add("display_mouse_set", mouse_set, 2, 0);
    fct_add("window_mouse_set", mouse_set, 2, 0);
    fct_add("display_mouse_get_x", mouse_get_x, 1, 0);
    fct_add("display_mouse_get_y", mouse_get_y, 1, 0);
    fct_add("window_mouse_get_x", mouse_get_x, 1, 0);
    fct_add("window_mouse_get_y", mouse_get_y, 1, 0);
}