#include <math.h>
#include <stdlib.h>

#include "platform.h"
#include "math_bridge.h"
#include "so_util.h"

#ifdef PLATFORM_VITA
//    FB_DECL_FWD(__signbit,   double,        (x),    (double      x))
//    FB_DECL_FWD(__finite,    double,        (x),    (double      x))
//    FB_DECL_FWD(__finitef,   float,         (x),    (float       x))
double __signbit(double x)
{
    return __signbitd(x);
}

double __finite(double x)
{
    return finite(x);
}

float __finitef(float x)
{
    return finitef(x);
}
#endif

#define FB_DECL_FWD(func, ret, args, vars) ABI_ATTR ret bridge_##func vars { return func args; }
MATH_BRIDGE_DEFS
#undef FB_DECL_FWD

extern void *__aeabi_idivmod;
extern void *__aeabi_uidivmod;
extern void *__aeabi_idiv;
extern void *__aeabi_uidiv;
extern void *__aeabi_d2ulz;
extern void *__aeabi_ul2d;
extern void *__aeabi_d2lz;
extern void *__aeabi_l2d;
extern void *__aeabi_l2f;
extern void *__aeabi_ldivmod;
extern void *__aeabi_i2d;
extern void *__aeabi_uldivmod;
extern void *__aeabi_ddiv;
extern void *__aeabi_dadd;
extern void *__aeabi_dcmplt;
extern void *__aeabi_dmul;
extern void *__aeabi_dsub;
extern void *__aeabi_dcmpge;
extern void *__aeabi_dcmpgt;
extern void *__aeabi_f2d;
extern void *__aeabi_d2uiz;
extern void *__aeabi_ui2d;

DynLibFunction symtable_math[] = {
    #define FB_DECL_FWD(func, ret, args, vars) {#func, (uintptr_t)&bridge_##func},
    MATH_BRIDGE_DEFS
    #undef FB_DECL_FWD
    {"__aeabi_idivmod", (uintptr_t)&__aeabi_idivmod},
    {"__aeabi_uidivmod", (uintptr_t)&__aeabi_uidivmod},
    {"__aeabi_idiv", (uintptr_t)&__aeabi_idiv},
    {"__aeabi_uidiv", (uintptr_t)&__aeabi_uidiv},
    {"__aeabi_d2ulz", (uintptr_t)&__aeabi_d2ulz},
    {"__aeabi_ul2d", (uintptr_t)&__aeabi_ul2d},
    {"__aeabi_d2lz", (uintptr_t)&__aeabi_d2lz},
    {"__aeabi_l2d", (uintptr_t)&__aeabi_l2d},
    {"__aeabi_l2f", (uintptr_t)&__aeabi_l2f},
    {"__aeabi_ldivmod", (uintptr_t)&__aeabi_ldivmod},
    {"__aeabi_i2d", (uintptr_t)&__aeabi_i2d},
    {"__aeabi_uldivmod", (uintptr_t)&__aeabi_uldivmod},
    {"__aeabi_ddiv", (uintptr_t)&__aeabi_ddiv},
    {"__aeabi_dadd", (uintptr_t)&__aeabi_dadd},
    {"__aeabi_dcmplt", (uintptr_t)&__aeabi_dcmplt},
    {"__aeabi_dmul", (uintptr_t)&__aeabi_dmul},
    {"__aeabi_dsub", (uintptr_t)&__aeabi_dsub},
    {"__aeabi_dcmpge", (uintptr_t)&__aeabi_dcmpge},
    {"__aeabi_dcmpgt", (uintptr_t)&__aeabi_dcmpgt},
    {"__aeabi_f2d", (uintptr_t)&__aeabi_f2d},
    {"__aeabi_d2uiz", (uintptr_t)&__aeabi_d2uiz},
    {"__aeabi_ui2d", (uintptr_t)&__aeabi_ui2d},
    
    {NULL, (uintptr_t)NULL}
};