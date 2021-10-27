#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "platform.h"
#include "so_util.h"
#include "libyoyo_internals.h"
#include "libyoyo.h"

ABI_ATTR void achievement_available(RValue *ret, void *self, void *other, int argc, RValue *args)
{
    ret->kind = VALUE_BOOL;
    ret->rvalue.val = 0;
}

void register_achievements_functs(fct_add_t fct_add)
{
    fct_add("achievement_available", achievement_available, 0, 0);
}