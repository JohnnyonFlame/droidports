#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fake_jni.h"
#include "os_Build.h"
#include "so_util.h"

#define MANGLED_CLASSPATH "Java_android_os_Build_"
#define CLASSPATH "android/os/Build"
#define CLASSNAME "os_Build"
#define CLASS _jclass os_Build_class
#define STRUCT_NAME os_Build_obj
#define NATIVE_LIB_FUNCS OS_BUILD_NATIVE_LIB_FUNCS
#define MANAGED_LIB_FUNCS OS_BUILD_MANAGED_LIB_FUNCS
#define RESOLVER Resolve_OS_BUILD
#define FIELDS OS_BUILD_FIELDS

#include "prelude_helpers.h"
#include "prologue_helpers.h"