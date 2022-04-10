#include <math.h>
#include <stdlib.h>

#include "platform.h"
#include "math_bridge.h"
#include "so_util.h"

#define FB_DECL_FWD(func, ret, args, vars) ABI_ATTR ret bridge_##func vars { return func args; }
MATH_BRIDGE_DEFS
#undef FB_DECL_FWD

extern void *__aeabi_d2f;
extern void *__aeabi_d2iz;
extern void *__aeabi_d2lz;
extern void *__aeabi_d2uiz;
extern void *__aeabi_d2ulz;
extern void *__aeabi_dadd;
extern void *__aeabi_dcmpeq;
extern void *__aeabi_dcmpge;
extern void *__aeabi_dcmpgt;
extern void *__aeabi_dcmple;
extern void *__aeabi_dcmplt;
extern void *__aeabi_ddiv;
extern void *__aeabi_dmul;
extern void *__aeabi_dsub;
extern void *__aeabi_f2d;
extern void *__aeabi_f2iz;
extern void *__aeabi_f2uiz;
extern void *__aeabi_fadd;
extern void *__aeabi_fcmpeq;
extern void *__aeabi_fcmpge;
extern void *__aeabi_fcmpgt;
extern void *__aeabi_fcmple;
extern void *__aeabi_fcmplt;
extern void *__aeabi_fdiv;
extern void *__aeabi_fmul;
extern void *__aeabi_fsub;
extern void *__aeabi_i2d;
extern void *__aeabi_i2f;
extern void *__aeabi_idiv;
extern void *__aeabi_idivmod;
extern void *__aeabi_l2d;
extern void *__aeabi_l2f;
extern void *__aeabi_ldivmod;
extern void *__aeabi_ui2d;
extern void *__aeabi_ui2f;
extern void *__aeabi_uidiv;
extern void *__aeabi_uidivmod;
extern void *__aeabi_ul2d;
extern void *__aeabi_uldivmod;

DynLibFunction symtable_math[] = {
    #define FB_DECL_FWD(func, ret, args, vars) {#func, (uintptr_t)&bridge_##func},
    MATH_BRIDGE_DEFS
    #undef FB_DECL_FWD
    {"__aeabi_d2f", (uintptr_t)&__aeabi_d2f},
    {"__aeabi_d2iz", (uintptr_t)&__aeabi_d2iz},
    {"__aeabi_d2lz", (uintptr_t)&__aeabi_d2lz},
    {"__aeabi_d2uiz", (uintptr_t)&__aeabi_d2uiz},
    {"__aeabi_d2ulz", (uintptr_t)&__aeabi_d2ulz},
    {"__aeabi_dadd", (uintptr_t)&__aeabi_dadd},
    {"__aeabi_dcmpeq", (uintptr_t)&__aeabi_dcmpeq},
    {"__aeabi_dcmpge", (uintptr_t)&__aeabi_dcmpge},
    {"__aeabi_dcmpgt", (uintptr_t)&__aeabi_dcmpgt},
    {"__aeabi_dcmple", (uintptr_t)&__aeabi_dcmple},
    {"__aeabi_dcmplt", (uintptr_t)&__aeabi_dcmplt},
    {"__aeabi_ddiv", (uintptr_t)&__aeabi_ddiv},
    {"__aeabi_dmul", (uintptr_t)&__aeabi_dmul},
    {"__aeabi_dsub", (uintptr_t)&__aeabi_dsub},
    {"__aeabi_f2d", (uintptr_t)&__aeabi_f2d},
    {"__aeabi_f2iz", (uintptr_t)&__aeabi_f2iz},
    {"__aeabi_f2uiz", (uintptr_t)&__aeabi_f2uiz},
    {"__aeabi_fadd", (uintptr_t)&__aeabi_fadd},
    {"__aeabi_fcmpeq", (uintptr_t)&__aeabi_fcmpeq},
    {"__aeabi_fcmpge", (uintptr_t)&__aeabi_fcmpge},
    {"__aeabi_fcmpgt", (uintptr_t)&__aeabi_fcmpgt},
    {"__aeabi_fcmple", (uintptr_t)&__aeabi_fcmple},
    {"__aeabi_fcmplt", (uintptr_t)&__aeabi_fcmplt},
    {"__aeabi_fdiv", (uintptr_t)&__aeabi_fdiv},
    {"__aeabi_fmul", (uintptr_t)&__aeabi_fmul},
    {"__aeabi_fsub", (uintptr_t)&__aeabi_fsub},
    {"__aeabi_i2d", (uintptr_t)&__aeabi_i2d},
    {"__aeabi_i2f", (uintptr_t)&__aeabi_i2f},
    {"__aeabi_idiv", (uintptr_t)&__aeabi_idiv},
    {"__aeabi_idivmod", (uintptr_t)&__aeabi_idivmod},
    {"__aeabi_l2d", (uintptr_t)&__aeabi_l2d},
    {"__aeabi_l2f", (uintptr_t)&__aeabi_l2f},
    {"__aeabi_ldivmod", (uintptr_t)&__aeabi_ldivmod},
    {"__aeabi_ui2d", (uintptr_t)&__aeabi_ui2d},
    {"__aeabi_ui2f", (uintptr_t)&__aeabi_ui2f},
    {"__aeabi_uidiv", (uintptr_t)&__aeabi_uidiv},
    {"__aeabi_uidivmod", (uintptr_t)&__aeabi_uidivmod},
    {"__aeabi_ul2d", (uintptr_t)&__aeabi_ul2d},
    {"__aeabi_uldivmod", (uintptr_t)&__aeabi_uldivmod},
    {NULL, (uintptr_t)NULL}
};
