#ifndef __FAKE_JNI_PRIV_H__
#define __FAKE_JNI_PRIV_H__

// Helpers to build function definitions and implementations for JNI libraries
#include "fake_jni.h"

#define JNI_PRIV_MACRO_TYPE_LIST      \
    JNI_PRIV_TYPE(Object, jobject)    \
    JNI_PRIV_TYPE(Boolean, jboolean)  \
    JNI_PRIV_TYPE(Byte, jbyte)        \
    JNI_PRIV_TYPE(Char, jchar)        \
    JNI_PRIV_TYPE(Short, jshort)      \
    JNI_PRIV_TYPE(Int, jint)          \
    JNI_PRIV_TYPE(Long, jlong)        \
    JNI_PRIV_TYPE(Float, jfloat)      \
    JNI_PRIV_TYPE(Double, jdouble)    \

#endif /* __FAKE_JNI_PRIV_H__ */