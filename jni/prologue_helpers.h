
#define ARG0
#define ARG1  arg1
#define ARG2  arg1, arg2
#define ARG3  arg1, arg2, arg3
#define ARG4  arg1, arg2, arg3, arg4
#define ARG5  arg1, arg2, arg3, arg4, arg5
#define ARG6  arg1, arg2, arg3, arg4, arg5, arg6
#define ARG7  arg1, arg2, arg3, arg4, arg5, arg6, arg7
#define ARG8  arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8
#define ARG9  arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9
#define ARG10 arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10

// A bunch of helper macros to generate all the bridges and function resolvers from the header tables
#define DECL_NATIVE(cl, funct, ret, ...) ABI_ATTR ret (*cl ## _ ## funct)(JNIEnv *env, jobject obj, ##__VA_ARGS__) = NULL;
NATIVE_LIB_FUNCS
#undef DECL_NATIVE

void RESOLVER(struct so_module *mod)
{
    #define hSTRINGIFY(a) #a
    #define STRINGIFY(a, b) hSTRINGIFY(a) "_" hSTRINGIFY(b)
    #define CONCAT(a, b) a ## b
    #define DECL_NATIVE(cl, funct, ...) *(uintptr_t *)&cl ## _ ##funct = so_symbol(mod, MANGLED_CLASSPATH #funct);
    NATIVE_LIB_FUNCS
    #undef DECL_NATIVE
}

// Prologue 2 - Defines the managed class methods and their bridges (e.g. the methods in this file)
// These are all the bridges that take variadic arguments through the "va_list va" argument
#include "prologue_helpers_v.h"
#define DECL_STATIC_MANAGED(CL, ID, RET, TYPES, ARGC, SIG)            \
    void CL ## _ ## ID ## _V(void *ignored, RET *ret, va_list va) {   \
        TYPES                                                         \
        *ret = CL ## _ ## ID(ARGC);                                   \
    }
#define DECL_STATIC_MANAGED_NR(CL, ID, RET, TYPES, ARGC, SIG)         \
    void CL ## _ ## ID ## _V(void *ignored, void *ign2, va_list va) { \
        TYPES                                                         \
        CL ## _ ## ID(ARGC);                                          \
    }
#define DECL_INSTANCE_MANAGED(CL, ID, RET, TYPES, ARGC, SIG)          \
    void CL ## _ ## ID ## _V(void *this, RET *ret, va_list va) {      \
        TYPES                                                         \
        *ret = CL ## _ ## ID(this, ARGC);                             \
    }
#define DECL_INSTANCE_MANAGED_NR(CL, ID, RET, TYPES, ARGC, SIG)       \
    void CL ## _ ## ID ## _V(void *this, void *ign2, va_list va) {    \
        TYPES                                                         \
        CL ## _ ## ID(this, ARGC);                                    \
    }
MANAGED_LIB_FUNCS
#undef DECL_INSTANCE_MANAGED_NR
#undef DECL_INSTANCE_MANAGED
#undef DECL_STATIC_MANAGED_NR
#undef DECL_STATIC_MANAGED

// These are all the bridges that take arguments through the array specifier
#include "prologue_helpers_a.h"
#define DECL_STATIC_MANAGED(CL, ID, RET, TYPES, ARGC, SIG)              \
    void CL ## _ ## ID ## _A(void *ignored, RET *ret, jvalue *args) {   \
        TYPES                                                           \
        *ret = CL ## _ ## ID(ARGC);                                     \
    }
#define DECL_STATIC_MANAGED_NR(CL, ID, RET, TYPES, ARGC, SIG)           \
    void CL ## _ ## ID ## _A(void *ignored, void *ign2, jvalue *args) { \
        TYPES                                                           \
        CL ## _ ## ID(ARGC);                                            \
    }
#define DECL_INSTANCE_MANAGED(CL, ID, RET, TYPES, ARGC, SIG)            \
    void CL ## _ ## ID ## _A(void *this, RET *ret, jvalue *args) {      \
        TYPES                                                           \
        *ret = CL ## _ ## ID(this, ARGC);                               \
    }
#define DECL_INSTANCE_MANAGED_NR(CL, ID, RET, TYPES, ARGC, SIG)         \
    void CL ## _ ## ID ## _A(void *this, void *ign2, jvalue *args) {    \
        TYPES                                                           \
        CL ## _ ## ID(this, ARGC);                                      \
    }
MANAGED_LIB_FUNCS
#undef DECL_INSTANCE_MANAGED_NR
#undef DECL_INSTANCE_MANAGED
#undef DECL_STATIC_MANAGED_NR
#undef DECL_STATIC_MANAGED

CLASS = {
    .classpath = CLASSPATH,
    .classname = CLASSNAME,
    .methods = (_jmethodID[]) {
        #define DECL_STATIC_MANAGED(CL, ID, RET, TYPES, ARGS, SIG) { .name = #ID, .signature = SIG, .addr_variadic = (vaarg_funct) CL ## _ ## ID ## _V, .addr_array = (array_funct) CL ## _ ## ID ## _A }, 
        #define DECL_STATIC_MANAGED_NR DECL_STATIC_MANAGED
        #define DECL_INSTANCE_MANAGED DECL_STATIC_MANAGED
        #define DECL_INSTANCE_MANAGED_NR DECL_STATIC_MANAGED
        MANAGED_LIB_FUNCS
        #undef DECL_INSTANCE_MANAGED_NR
        #undef DECL_INSTANCE_MANAGED
        #undef DECL_STATIC_MANAGED_NR
        #undef DECL_STATIC_MANAGED
        {NULL}
    },
    .fields = (_jfieldID[]){
        #define STATIC_FIELD(type, id, default, sig) { #id, sig, &id }, 
        #define DYNAMIC_FIELDS(type, id, default, sig) { #id, sig, &((STRUCT_NAME*)0x0)->#id },
        FIELDS
        #undef DYNAMIC_FIELDS
        #undef STATIC_FIELDS
        {NULL}
    },
    .instance_size = sizeof(STRUCT_NAME)
};