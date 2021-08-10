
#include "fake_jni.h"

//thin wrapper
_jclass jstring_class = {
    .classpath = "java/lang/String",
    .classname = "String",
    .methods = (_jmethodID[]){
        {}
    },
    .fields = (_jfieldID[]){
        {}
    },
    .instance_size = sizeof(_jstring),
};