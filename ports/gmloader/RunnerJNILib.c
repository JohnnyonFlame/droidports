#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fake_jni.h"
#include "so_util.h"
#include "RunnerJNILib.h"
#include "so_util.h"

#define MANGLED_CLASSPATH "Java_com_yoyogames_runner_RunnerJNILib_"
#define CLASSPATH "com/yoyogames/runner/RunnerJNILib"
#define CLASSNAME "RunnerJNILib"
#define CLASS _jclass RunnerJNILib_class
#define STRUCT_NAME RunnerJNILib_obj
#define NATIVE_LIB_FUNCS JNIRUNNER_NATIVE_LIB_FUNCS
#define MANAGED_LIB_FUNCS JNIRUNNER_MANAGED_LIB_FUNCS
#define RESOLVER Resolve_RunnerJNILib
#define FIELDS JNIRUNNER_FIELDS

#include "prelude_helpers.h"

static void RunnerJNILib_OpenURL(jstring url)
{
    WARN_STUB
}

static jobject RunnerJNILib_CallExtensionFunction1(jstring class, jstring method, jint count, jdoubleArray dblarray, jobjectArray args)
{
    WARN_STUB
}

static jobject RunnerJNILib_CallExtensionFunction2(jstring class, jstring method, jint argcount, jobjectArray args)
{
    WARN_STUB
}

static jint RunnerJNILib_GamepadsCount()
{
    WARN_STUB
}

static void RunnerJNILib_ClearGamepads()
{
    WARN_STUB
}

static jboolean RunnerJNILib_GamepadConnected(jint deviceIndex)
{
    WARN_STUB
}

static jstring RunnerJNILib_GamepadDescription(jint deviceIndex)
{
    WARN_STUB
}

static jfloatArray RunnerJNILib_GamepadAxesValues(jint deviceIndex)
{
    WARN_STUB
}

static jfloatArray RunnerJNILib_GamepadButtonValues(jint deviceIndex)
{
    WARN_STUB
}

static jint RunnerJNILib_GamepadGMLMapping(jint deviceIndex, jint inputId)
{
    WARN_STUB
}

static void RunnerJNILib_PlayMP3(jstring file, jint loops)
{
    WARN_STUB
}

static void RunnerJNILib_StopMP3()
{
    WARN_STUB
}

static void RunnerJNILib_PauseMP3()
{
    WARN_STUB
}

static void RunnerJNILib_ResumeMP3()
{
    WARN_STUB
}

static void RunnerJNILib_SetMP3Volume(jfloat vol)
{
    WARN_STUB
}

static jboolean RunnerJNILib_PlayingMP3()
{
    WARN_STUB
}

static jint RunnerJNILib_GetDefaultFrameBuffer()
{
    WARN_STUB
}

static void RunnerJNILib_ShowMessage(jstring msg)
{
    WARN_STUB
}

static jint RunnerJNILib_UsingGL2()
{
    WARN_STUB
    return 1;
}

_jstring udid = MK_JSTRING("GetUDID");
static jstring RunnerJNILib_GetUDID()
{
    WARN_STUB
    return &udid;
}

static void RunnerJNILib_WaitForVsync()
{
    ;
}

static jint RunnerJNILib_HasVsyncHandler()
{
    return 1;
}

#include "prologue_helpers.h"