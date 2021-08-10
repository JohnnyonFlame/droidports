#ifndef __OS_BUILD_H__
#define __OS_BUILD_H__

#include "platform.h"
#include "fake_jni.h"

#define OS_BUILD_FIELDS \
    STATIC_FIELD(jstring, MANUFACTURER, &MK_JSTRING("JohnnyonFlame"), "Ljava/lang/String;")

#define OS_BUILD_MANAGED_LIB_FUNCS                                                                                                                                                                     \
                    /*  |Class        |Identifier             |Return       |Arg Type Macros  |Arg Count Macro  |Signatures                                                                          */\
                    /*  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/\



#define OS_BUILD_NATIVE_LIB_FUNCS                                                                                                                                                                    \
            /*  |Class                     |Return       |Argument List Definition                                                                                                                 */\
            /*  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/\


#define DECL_NATIVE(cl, funct, ret, ...) ABI_ATTR extern ret (*OS_Build_##funct)(JNIEnv env, jobject obj, ##__VA_ARGS__);
OS_BUILD_MANAGED_LIB_FUNCS
#undef DECL_NATIVE

extern _jclass os_Build_class;

void Resolve_OS_BUILD(struct so_module *mod);

#endif /* __JNI_RUNNER_H__ */