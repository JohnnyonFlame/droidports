#ifndef JNI_H_
#define JNI_H_

/* A facsimile of the jni headers - with some changes to make it easier to implement */ 

#include "platform.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

struct so_module;

typedef uint8_t  jboolean;
typedef int8_t   jbyte;
typedef uint16_t jchar;
typedef int16_t  jshort;
typedef int32_t  jint;
typedef int64_t  jlong;
typedef float    jfloat;
typedef double   jdouble;

typedef union jvalue {
    void            *p;
    jboolean         z;
    jbyte            b;
    jchar            c;
    jshort           s;
    jint             i;
    jlong            l;
    jfloat           f;
    jdouble          d;
} jvalue;

typedef void (*vaarg_funct)(void *obj, void *ret, va_list va); // For <...> and <va_list> 
typedef void (*array_funct)(void *obj, void *ret, jvalue *values); // For arrays
typedef struct _jmethodID {
    const char *name;
    const char *signature;
    vaarg_funct addr_variadic; // For <...> and <va_list> 
    array_funct addr_array; // For arrays
} _jmethodID;

typedef struct _jfieldID {
    const char *name;
    const char *signature;
    void *offset; // Direct address for static fields, offsets for instance fields
} _jfieldID;

typedef _jfieldID *jfieldID;     /* field IDs */
typedef _jmethodID *jmethodID;

typedef struct _jclass {
    const char *classpath;
    const char *classname;
    jmethodID methods;
    jfieldID fields;
    size_t instance_size;
} _jclass;

typedef struct _jobject {
    _jclass *clazz;
    /* ... */
} _jobject;

typedef struct _jarray {
    _jclass clazz;
    int count;
    void *elements;
} _jarray;

typedef struct _jthrowable {} _jthrowable;

enum JNI_METHOD_SPECIFIER {
    JNI_METHOD_STATIC,
    JNI_METHOD_VIRTUAL,
    JNI_METHOD_NONVIRTUAL
};

typedef struct _jstring {
    _jclass *clazz;
    char *str;
} _jstring;

typedef jint      jsize;
typedef _jobject *jobject;
typedef _jclass  *jclass;
typedef _jstring *jstring;
typedef _jarray  *jarray;
typedef jarray    jobjectArray;
typedef jarray    jstringArray;
typedef jarray    jbooleanArray;
typedef jarray    jbyteArray;
typedef jarray    jcharArray;
typedef jarray    jshortArray;
typedef jarray    jintArray;
typedef jarray    jlongArray;
typedef jarray    jfloatArray;
typedef jarray    jdoubleArray;
typedef jobject   jthrowable;
typedef jobject   jweak;

struct JNIInvokeInterface;

typedef enum jobjectRefType {
    JNIInvalidRefType = 0,
    JNILocalRefType = 1,
    JNIGlobalRefType = 2,
    JNIWeakGlobalRefType = 3
} jobjectRefType;

typedef struct {
    const char* name;
    const char* signature;
    void*       fnPtr;
} JNINativeMethod;

struct _JNIEnv;
struct _JavaVM;
typedef const struct JNINativeInterface* JNIEnv;
typedef const struct JNIInvokeInterface* JavaVM;

struct JNINativeInterface {
    void*       reserved0;
    void*       reserved1;
    void*       reserved2;
    void*       reserved3;

    ABI_ATTR jint        (*GetVersion)(JNIEnv);

    ABI_ATTR jclass      (*DefineClass)(JNIEnv, const char*, jobject, const jbyte*, jsize);
    ABI_ATTR jclass      (*FindClass)(JNIEnv, const char*);

    ABI_ATTR jmethodID   (*FromReflectedMethod)(JNIEnv, jobject);
    ABI_ATTR jfieldID    (*FromReflectedField)(JNIEnv, jobject);

    ABI_ATTR jobject     (*ToReflectedMethod)(JNIEnv, jclass, jmethodID, jboolean);

    ABI_ATTR jclass      (*GetSuperclass)(JNIEnv, jclass);
    ABI_ATTR jboolean    (*IsAssignableFrom)(JNIEnv, jclass, jclass);

    ABI_ATTR jobject     (*ToReflectedField)(JNIEnv, jclass, jfieldID, jboolean);

    ABI_ATTR jint        (*Throw)(JNIEnv, jthrowable);
    ABI_ATTR jint        (*ThrowNew)(JNIEnv, jclass, const char *);
    ABI_ATTR jthrowable  (*ExceptionOccurred)(JNIEnv);
    ABI_ATTR void        (*ExceptionDescribe)(JNIEnv);
    ABI_ATTR void        (*ExceptionClear)(JNIEnv);
    ABI_ATTR void        (*FatalError)(JNIEnv, const char*);

    ABI_ATTR jint        (*PushLocalFrame)(JNIEnv, jint);
    ABI_ATTR jobject     (*PopLocalFrame)(JNIEnv, jobject);

    ABI_ATTR jobject     (*NewGlobalRef)(JNIEnv, jobject);
    ABI_ATTR void        (*DeleteGlobalRef)(JNIEnv, jobject);
    ABI_ATTR void        (*DeleteLocalRef)(JNIEnv, jobject);
    ABI_ATTR jboolean    (*IsSameObject)(JNIEnv, jobject, jobject);

    ABI_ATTR jobject     (*NewLocalRef)(JNIEnv, jobject);
    ABI_ATTR jint        (*EnsureLocalCapacity)(JNIEnv, jint);

    ABI_ATTR jobject     (*AllocObject)(JNIEnv, jclass);
    ABI_ATTR jobject     (*NewObject)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jobject     (*NewObjectV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jobject     (*NewObjectA)(JNIEnv, jclass, jmethodID, jvalue*);

    ABI_ATTR jclass      (*GetObjectClass)(JNIEnv, jobject);
    ABI_ATTR jboolean    (*IsInstanceOf)(JNIEnv, jobject, jclass);
    ABI_ATTR jmethodID   (*GetMethodID)(JNIEnv, jclass, const char*, const char*);

    ABI_ATTR jobject     (*CallObjectMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jobject     (*CallObjectMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jobject     (*CallObjectMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jboolean    (*CallBooleanMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jboolean    (*CallBooleanMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jboolean    (*CallBooleanMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jbyte       (*CallByteMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jbyte       (*CallByteMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jbyte       (*CallByteMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jchar       (*CallCharMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jchar       (*CallCharMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jchar       (*CallCharMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jshort      (*CallShortMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jshort      (*CallShortMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jshort      (*CallShortMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jint        (*CallIntMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jint        (*CallIntMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jint        (*CallIntMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jlong       (*CallLongMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jlong       (*CallLongMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jlong       (*CallLongMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jfloat      (*CallFloatMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jfloat      (*CallFloatMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jfloat      (*CallFloatMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR jdouble     (*CallDoubleMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR jdouble     (*CallDoubleMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR jdouble     (*CallDoubleMethodA)(JNIEnv, jobject, jmethodID, jvalue*);
    ABI_ATTR void        (*CallVoidMethod)(JNIEnv, jobject, jmethodID, ...);
    ABI_ATTR void        (*CallVoidMethodV)(JNIEnv, jobject, jmethodID, va_list);
    ABI_ATTR void        (*CallVoidMethodA)(JNIEnv, jobject, jmethodID, jvalue*);

    ABI_ATTR jobject     (*CallNonvirtualObjectMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jobject     (*CallNonvirtualObjectMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jobject     (*CallNonvirtualObjectMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jboolean    (*CallNonvirtualBooleanMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jboolean    (*CallNonvirtualBooleanMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jboolean    (*CallNonvirtualBooleanMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jbyte       (*CallNonvirtualByteMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jbyte       (*CallNonvirtualByteMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jbyte       (*CallNonvirtualByteMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jchar       (*CallNonvirtualCharMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jchar       (*CallNonvirtualCharMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jchar       (*CallNonvirtualCharMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jshort      (*CallNonvirtualShortMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jshort      (*CallNonvirtualShortMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jshort      (*CallNonvirtualShortMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jint        (*CallNonvirtualIntMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jint        (*CallNonvirtualIntMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jint        (*CallNonvirtualIntMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jlong       (*CallNonvirtualLongMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jlong       (*CallNonvirtualLongMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jlong       (*CallNonvirtualLongMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jfloat      (*CallNonvirtualFloatMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jfloat      (*CallNonvirtualFloatMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jfloat      (*CallNonvirtualFloatMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR jdouble     (*CallNonvirtualDoubleMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR jdouble     (*CallNonvirtualDoubleMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR jdouble     (*CallNonvirtualDoubleMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);
    ABI_ATTR void        (*CallNonvirtualVoidMethod)(JNIEnv, jobject, jclass, jmethodID, ...);
    ABI_ATTR void        (*CallNonvirtualVoidMethodV)(JNIEnv, jobject, jclass, jmethodID, va_list);
    ABI_ATTR void        (*CallNonvirtualVoidMethodA)(JNIEnv, jobject, jclass, jmethodID, jvalue*);

    ABI_ATTR jfieldID    (*GetFieldID)(JNIEnv, jclass, const char*, const char*);

    ABI_ATTR jobject     (*GetObjectField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jboolean    (*GetBooleanField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jbyte       (*GetByteField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jchar       (*GetCharField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jshort      (*GetShortField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jint        (*GetIntField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jlong       (*GetLongField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jfloat      (*GetFloatField)(JNIEnv, jobject, jfieldID);
    ABI_ATTR jdouble     (*GetDoubleField)(JNIEnv, jobject, jfieldID);

    ABI_ATTR void        (*SetObjectField)(JNIEnv, jobject, jfieldID, jobject);
    ABI_ATTR void        (*SetBooleanField)(JNIEnv, jobject, jfieldID, jboolean);
    ABI_ATTR void        (*SetByteField)(JNIEnv, jobject, jfieldID, jbyte);
    ABI_ATTR void        (*SetCharField)(JNIEnv, jobject, jfieldID, jchar);
    ABI_ATTR void        (*SetShortField)(JNIEnv, jobject, jfieldID, jshort);
    ABI_ATTR void        (*SetIntField)(JNIEnv, jobject, jfieldID, jint);
    ABI_ATTR void        (*SetLongField)(JNIEnv, jobject, jfieldID, jlong);
    ABI_ATTR void        (*SetFloatField)(JNIEnv, jobject, jfieldID, jfloat);
    ABI_ATTR void        (*SetDoubleField)(JNIEnv, jobject, jfieldID, jdouble);

    ABI_ATTR jmethodID   (*GetStaticMethodID)(JNIEnv, jclass, const char*, const char*);

    ABI_ATTR jobject     (*CallStaticObjectMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jobject     (*CallStaticObjectMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jobject     (*CallStaticObjectMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jboolean    (*CallStaticBooleanMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jboolean    (*CallStaticBooleanMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jboolean    (*CallStaticBooleanMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jbyte       (*CallStaticByteMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jbyte       (*CallStaticByteMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jbyte       (*CallStaticByteMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jchar       (*CallStaticCharMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jchar       (*CallStaticCharMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jchar       (*CallStaticCharMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jshort      (*CallStaticShortMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jshort      (*CallStaticShortMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jshort      (*CallStaticShortMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jint        (*CallStaticIntMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jint        (*CallStaticIntMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jint        (*CallStaticIntMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jlong       (*CallStaticLongMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jlong       (*CallStaticLongMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jlong       (*CallStaticLongMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jfloat      (*CallStaticFloatMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jfloat      (*CallStaticFloatMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jfloat      (*CallStaticFloatMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR jdouble     (*CallStaticDoubleMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR jdouble     (*CallStaticDoubleMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR jdouble     (*CallStaticDoubleMethodA)(JNIEnv, jclass, jmethodID, jvalue*);
    ABI_ATTR void        (*CallStaticVoidMethod)(JNIEnv, jclass, jmethodID, ...);
    ABI_ATTR void        (*CallStaticVoidMethodV)(JNIEnv, jclass, jmethodID, va_list);
    ABI_ATTR void        (*CallStaticVoidMethodA)(JNIEnv, jclass, jmethodID, jvalue*);

    ABI_ATTR jfieldID    (*GetStaticFieldID)(JNIEnv, jclass, const char*, const char*);

    ABI_ATTR jobject     (*GetStaticObjectField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jboolean    (*GetStaticBooleanField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jbyte       (*GetStaticByteField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jchar       (*GetStaticCharField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jshort      (*GetStaticShortField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jint        (*GetStaticIntField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jlong       (*GetStaticLongField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jfloat      (*GetStaticFloatField)(JNIEnv, jclass, jfieldID);
    ABI_ATTR jdouble     (*GetStaticDoubleField)(JNIEnv, jclass, jfieldID);

    ABI_ATTR void        (*SetStaticObjectField)(JNIEnv, jclass, jfieldID, jobject);
    ABI_ATTR void        (*SetStaticBooleanField)(JNIEnv, jclass, jfieldID, jboolean);
    ABI_ATTR void        (*SetStaticByteField)(JNIEnv, jclass, jfieldID, jbyte);
    ABI_ATTR void        (*SetStaticCharField)(JNIEnv, jclass, jfieldID, jchar);
    ABI_ATTR void        (*SetStaticShortField)(JNIEnv, jclass, jfieldID, jshort);
    ABI_ATTR void        (*SetStaticIntField)(JNIEnv, jclass, jfieldID, jint);
    ABI_ATTR void        (*SetStaticLongField)(JNIEnv, jclass, jfieldID, jlong);
    ABI_ATTR void        (*SetStaticFloatField)(JNIEnv, jclass, jfieldID, jfloat);
    ABI_ATTR void        (*SetStaticDoubleField)(JNIEnv, jclass, jfieldID, jdouble);

    ABI_ATTR jstring     (*NewString)(JNIEnv, const jchar*, jsize);
    ABI_ATTR jsize       (*GetStringLength)(JNIEnv, jstring);
    ABI_ATTR const jchar* (*GetStringChars)(JNIEnv, jstring, jboolean*);
    ABI_ATTR void        (*ReleaseStringChars)(JNIEnv, jstring, const jchar*);
    ABI_ATTR jstring     (*NewStringUTF)(JNIEnv, const char*);
    ABI_ATTR jsize       (*GetStringUTFLength)(JNIEnv, jstring);

    ABI_ATTR const char* (*GetStringUTFChars)(JNIEnv, jstring, jboolean*);
    ABI_ATTR void        (*ReleaseStringUTFChars)(JNIEnv, jstring, const char*);
    ABI_ATTR jsize       (*GetArrayLength)(JNIEnv, jarray);
    ABI_ATTR jobjectArray (*NewObjectArray)(JNIEnv, jsize, jclass, jobject);
    ABI_ATTR jobject     (*GetObjectArrayElement)(JNIEnv, jobjectArray, jsize);
    ABI_ATTR void        (*SetObjectArrayElement)(JNIEnv, jobjectArray, jsize, jobject);

    ABI_ATTR jbooleanArray (*NewBooleanArray)(JNIEnv, jsize);
    ABI_ATTR jbyteArray    (*NewByteArray)(JNIEnv, jsize);
    ABI_ATTR jcharArray    (*NewCharArray)(JNIEnv, jsize);
    ABI_ATTR jshortArray   (*NewShortArray)(JNIEnv, jsize);
    ABI_ATTR jintArray     (*NewIntArray)(JNIEnv, jsize);
    ABI_ATTR jlongArray    (*NewLongArray)(JNIEnv, jsize);
    ABI_ATTR jfloatArray   (*NewFloatArray)(JNIEnv, jsize);
    ABI_ATTR jdoubleArray  (*NewDoubleArray)(JNIEnv, jsize);

    ABI_ATTR jboolean*   (*GetBooleanArrayElements)(JNIEnv, jbooleanArray, jboolean*);
    ABI_ATTR jbyte*      (*GetByteArrayElements)(JNIEnv, jbyteArray, jboolean*);
    ABI_ATTR jchar*      (*GetCharArrayElements)(JNIEnv, jcharArray, jboolean*);
    ABI_ATTR jshort*     (*GetShortArrayElements)(JNIEnv, jshortArray, jboolean*);
    ABI_ATTR jint*       (*GetIntArrayElements)(JNIEnv, jintArray, jboolean*);
    ABI_ATTR jlong*      (*GetLongArrayElements)(JNIEnv, jlongArray, jboolean*);
    ABI_ATTR jfloat*     (*GetFloatArrayElements)(JNIEnv, jfloatArray, jboolean*);
    ABI_ATTR jdouble*    (*GetDoubleArrayElements)(JNIEnv, jdoubleArray, jboolean*);

    ABI_ATTR void        (*ReleaseBooleanArrayElements)(JNIEnv, jbooleanArray, jboolean*, jint);
    ABI_ATTR void        (*ReleaseByteArrayElements)(JNIEnv, jbyteArray, jbyte*, jint);
    ABI_ATTR void        (*ReleaseCharArrayElements)(JNIEnv, jcharArray, jchar*, jint);
    ABI_ATTR void        (*ReleaseShortArrayElements)(JNIEnv, jshortArray, jshort*, jint);
    ABI_ATTR void        (*ReleaseIntArrayElements)(JNIEnv, jintArray, jint*, jint);
    ABI_ATTR void        (*ReleaseLongArrayElements)(JNIEnv, jlongArray, jlong*, jint);
    ABI_ATTR void        (*ReleaseFloatArrayElements)(JNIEnv, jfloatArray, jfloat*, jint);
    ABI_ATTR void        (*ReleaseDoubleArrayElements)(JNIEnv, jdoubleArray, jdouble*, jint);

    ABI_ATTR void        (*GetBooleanArrayRegion)(JNIEnv, jbooleanArray, jsize, jsize, jboolean*);
    ABI_ATTR void        (*GetByteArrayRegion)(JNIEnv, jbyteArray, jsize, jsize, jbyte*);
    ABI_ATTR void        (*GetCharArrayRegion)(JNIEnv, jcharArray, jsize, jsize, jchar*);
    ABI_ATTR void        (*GetShortArrayRegion)(JNIEnv, jshortArray, jsize, jsize, jshort*);
    ABI_ATTR void        (*GetIntArrayRegion)(JNIEnv, jintArray, jsize, jsize, jint*);
    ABI_ATTR void        (*GetLongArrayRegion)(JNIEnv, jlongArray, jsize, jsize, jlong*);
    ABI_ATTR void        (*GetFloatArrayRegion)(JNIEnv, jfloatArray, jsize, jsize, jfloat*);
    ABI_ATTR void        (*GetDoubleArrayRegion)(JNIEnv, jdoubleArray, jsize, jsize, jdouble*);

    ABI_ATTR void        (*SetBooleanArrayRegion)(JNIEnv, jbooleanArray, jsize, jsize, const jboolean*);
    ABI_ATTR void        (*SetByteArrayRegion)(JNIEnv, jbyteArray, jsize, jsize, const jbyte*);
    ABI_ATTR void        (*SetCharArrayRegion)(JNIEnv, jcharArray, jsize, jsize, const jchar*);
    ABI_ATTR void        (*SetShortArrayRegion)(JNIEnv, jshortArray, jsize, jsize, const jshort*);
    ABI_ATTR void        (*SetIntArrayRegion)(JNIEnv, jintArray, jsize, jsize, const jint*);
    ABI_ATTR void        (*SetLongArrayRegion)(JNIEnv, jlongArray, jsize, jsize, const jlong*);
    ABI_ATTR void        (*SetFloatArrayRegion)(JNIEnv, jfloatArray, jsize, jsize, const jfloat*);
    ABI_ATTR void        (*SetDoubleArrayRegion)(JNIEnv, jdoubleArray, jsize, jsize, const jdouble*);

    ABI_ATTR jint        (*RegisterNatives)(JNIEnv, jclass, const JNINativeMethod*, jint);
    ABI_ATTR jint        (*UnregisterNatives)(JNIEnv, jclass);
    ABI_ATTR jint        (*MonitorEnter)(JNIEnv, jobject);
    ABI_ATTR jint        (*MonitorExit)(JNIEnv, jobject);
    ABI_ATTR jint        (*GetJavaVM)(JNIEnv, JavaVM**);

    ABI_ATTR void        (*GetStringRegion)(JNIEnv, jstring, jsize, jsize, jchar*);
    ABI_ATTR void        (*GetStringUTFRegion)(JNIEnv, jstring, jsize, jsize, char*);

    ABI_ATTR void*       (*GetPrimitiveArrayCritical)(JNIEnv, jarray, jboolean*);
    ABI_ATTR void        (*ReleasePrimitiveArrayCritical)(JNIEnv, jarray, void*, jint);

    ABI_ATTR const jchar* (*GetStringCritical)(JNIEnv, jstring, jboolean*);
    ABI_ATTR void        (*ReleaseStringCritical)(JNIEnv, jstring, const jchar*);

    ABI_ATTR jweak       (*NewWeakGlobalRef)(JNIEnv, jobject);
    ABI_ATTR void        (*DeleteWeakGlobalRef)(JNIEnv, jweak);

    ABI_ATTR jboolean    (*ExceptionCheck)(JNIEnv);

    ABI_ATTR jobject     (*NewDirectByteBuffer)(JNIEnv, void*, jlong);
    ABI_ATTR void*       (*GetDirectBufferAddress)(JNIEnv, jobject);
    ABI_ATTR jlong       (*GetDirectBufferCapacity)(JNIEnv, jobject);

    ABI_ATTR jobjectRefType (*GetObjectRefType)(JNIEnv, jobject);
};


struct JNIInvokeInterface {
    void* reserved0;
    void* reserved1;
    void* reserved2;

    jint  (*DestroyJavaVM)(JavaVM*);
    jint  (*AttachCurrentThread)(JavaVM*, JNIEnv*, void*);
    jint  (*DetachCurrentThread)(JavaVM*);
    jint  (*GetEnv)(JavaVM*, void**, jint);
    jint  (*AttachCurrentThreadAsDaemon)(JavaVM*, JNIEnv*, void*);
};

typedef struct JavaVMAttachArgs {
    jint        version;
    const char* name;
    jobject     group;
} JavaVMAttachArgs;

typedef struct JavaVMOption {
    const char* optionString;
    void*       extraInfo;
} JavaVMOption;

typedef struct JavaVMInitArgs {
    jint          version;
    jint          nOptions;
    JavaVMOption* options;
    jboolean      ignoreUnrecognized;
} JavaVMInitArgs;

jint JNI_OnLoad(JavaVM* vm, void* reserved);
void JNI_OnUnload(JavaVM* vm, void* reserved);

#define JNI_FALSE   0
#define JNI_TRUE    1

#define JNI_VERSION_1_1 0x00010001
#define JNI_VERSION_1_2 0x00010002
#define JNI_VERSION_1_4 0x00010004
#define JNI_VERSION_1_6 0x00010006

#define JNI_OK          (0)
#define JNI_ERR         (-1)
#define JNI_EDETACHED   (-2)
#define JNI_EVERSION    (-3)

#define JNI_COMMIT      1
#define JNI_ABORT       2

#define MK_JSTRING(data) (_jstring){.clazz = &jstring_class, .str = data}

extern _jclass jstring_class;

extern JNIEnv jni_get_env();
extern void jni_register_class(jclass clazz);

#endif  /* JNI_H_ */
