#ifndef __JNI_RUNNER_H__
#define __JNI_RUNNER_H__

#include "platform.h"
#include "fake_jni.h"

#define JNIRUNNER_FIELDS \


#define JNIRUNNER_MANAGED_LIB_FUNCS \
                      /*  |Class         |Identifier             |Return      |Arg Type Macros  |Arg Count Macro  |Signatures                                                                          */\
                      /*  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/\
    DECL_STATIC_MANAGED_NR( RunnerJNILib, OpenURL,                void,        F_s,              ARG1,             "(Ljava/lang/jstring;)V")                                                           \
    DECL_STATIC_MANAGED   ( RunnerJNILib, OsGetInfo,              jobject,     F_v,              ARG0,             "()I")                                                                              \
    DECL_STATIC_MANAGED   ( RunnerJNILib, CallExtensionFunction1, jobject,     F_ssiaa,          ARG5,             "(Ljava/lang/jstring;Ljava/lang/jstring;I[D[Ljava/lang/Object;)Ljava/lang/Object;") \
    DECL_STATIC_MANAGED   ( RunnerJNILib, CallExtensionFunction2, jobject,     F_ssia,           ARG4,             "(Ljava/lang/jstring;Ljava/lang/jstring;I[Ljava/lang/Object;)Ljava/lang/Object;")   \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, ClearGamepads,          void,        F_v,              ARG0,             "()V")                                                                              \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GamepadsCount,          jint,        F_v,              ARG0,             "()I")                                                                              \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GamepadConnected,       jboolean,    F_i,              ARG1,             "(I)Z")                                                                             \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GamepadDescription,     jstring,     F_i,              ARG1,             "(I)Ljava/lang/String;")                                                            \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GamepadAxesValues,      jfloatArray, F_i,              ARG1,             "(I)[F")                                                                            \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GamepadButtonValues,    jfloatArray, F_i,              ARG1,             "(I)[F")                                                                            \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GamepadGMLMapping,      jint,        F_ii,             ARG2,             "(II)I")                                                                            \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, PlayMP3,                void,        F_si,             ARG2,             "(Ljava/lang/jstring;I)V")                                                          \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, StopMP3,                void,        F_v,              ARG0,             "()V")                                                                              \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, PauseMP3,               void,        F_v,              ARG0,             "()V")                                                                              \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, ResumeMP3,              void,        F_v,              ARG0,             "()V")                                                                              \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, SetMP3Volume,           void,        F_f,              ARG1,             "(F)V")                                                                             \
    DECL_STATIC_MANAGED   ( RunnerJNILib, PlayingMP3,             jboolean,    F_v,              ARG0,             "()Z")                                                                              \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GetDefaultFrameBuffer,  jint,        F_v,              ARG0,             "()I")                                                                              \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, ShowMessage,            void,        F_s,              ARG1,             "(Ljava/lang/jstring;)V")                                                           \
    DECL_STATIC_MANAGED   ( RunnerJNILib, UsingGL2,               jint,        F_v,              ARG0,             "()I")                                                                              \
    DECL_STATIC_MANAGED   ( RunnerJNILib, GetUDID,                jstring,     F_v,              ARG0,             "()Ljava/lang/jstring;")                                                            \
    DECL_STATIC_MANAGED_NR( RunnerJNILib, WaitForVsync,           void,        F_v,              ARG0,             "()V")                                                                              \
    DECL_STATIC_MANAGED   ( RunnerJNILib, HasVsyncHandler,        jint,        F_v,              ARG0,             "()I")                                                                              \

#define JNIRUNNER_NATIVE_LIB_FUNCS \
            /*  |Class                                   |Return       |Argument List Definition                                                                                                                 */\
            /*  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/              \
    DECL_NATIVE( RunnerJNILib, Startup,                  void,         jstring _apkPath, jstring _saveFilesDir, jstring _packageName, int _sleepMargin, int useAssetManager)                                       \
    DECL_NATIVE( RunnerJNILib, CreateVersionDSMap,       int,          int sdkint, jstring RELEASE, jstring MODEL, jstring DEVICE, jstring MANUFACTURER, jstring CPU_ABI, jstring CPU_ABI2, jstring BOOTLOADER,    \
                                                                       jstring BOARD, jstring version, jstring region, jstring versionName, jboolean physicalKeyboardAvailable)                                    \
    DECL_NATIVE( RunnerJNILib, Process,                  int,          int _width, int _height, float _accelX, float _accelY, float _accelZ, int _keypadStatus, int _orientation, float _refreshrate )             \
    DECL_NATIVE( RunnerJNILib, TouchEvent,               void,         int _type, int _index, float _x, float _y)                                                                                                  \
    DECL_NATIVE( RunnerJNILib, RenderSplash,             void,         jstring _apkPath, jstring _splashName, int  _screenWidth, int _screenHeight, int _texWidth, int _texHeight, int _pngWidth, int _pngHeight ) \
    DECL_NATIVE( RunnerJNILib, Resume,                   void,         int _param )                                                                                                                                \
    DECL_NATIVE( RunnerJNILib, Pause,                    void,         int _param )                                                                                                                                \
    DECL_NATIVE( RunnerJNILib, KeyEvent,                 void,         int _type, int _keycode, int _keychar, int _eventSource)                                                                                    \
    DECL_NATIVE( RunnerJNILib, SetKeyValue,              void,         int _type, int _val, jstring _valjstring )                                                                                                  \
    DECL_NATIVE( RunnerJNILib, GetAppID,                 jstring,      int _param )                                                                                                                                \
    DECL_NATIVE( RunnerJNILib, GetSaveFileName,          jstring,      jstring _fileName )                                                                                                                         \
    DECL_NATIVE( RunnerJNILib, ExpandCompressedFile,     jobjectArray, jstring _destLocalPath, jstring _compressedFileName )                                                                                       \
    DECL_NATIVE( RunnerJNILib, iCadeEventDispatch,       void,         int _button, char _down)                                                                                                                    \
    DECL_NATIVE( RunnerJNILib, registerGamepadConnected, void,         int _deviceIndex, int _buttonCount, int _axisCount)                                                                                         \
    DECL_NATIVE( RunnerJNILib, initGLFuncs,              int,          int _usingGL2)                                                                                                                              \
    DECL_NATIVE( RunnerJNILib, canFlip,                  char          /* none */)                                                                                                                                 \
    DECL_NATIVE( RunnerJNILib, GCMPushResult,            void,         jstring _dataString, int _type, char _bSuccess)

#define DECL_NATIVE(cl, funct, ret, ...) ABI_ATTR extern ret (*RunnerJNILib_##funct)(JNIEnv *env, jobject obj, ##__VA_ARGS__);
JNIRUNNER_NATIVE_LIB_FUNCS
#undef DECL_NATIVE

extern _jclass RunnerJNILib_class;

void Resolve_RunnerJNILib(struct so_module *mod);

#endif /* __JNI_RUNNER_H__ */
