/* Incomplete, and not 100% accurate C implementation of JNI */ 
/* See included classes to understand how to interface with this */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>

#include "platform.h"
#include "fake_jni.h"
#include "fake_jni_priv.h"
#include "os_Build.h"

#include <SDL2/SDL.h>

static struct JNINativeInterface jni_iface;
static struct JNIInvokeInterface jni_fake_vm;
static jclass registeredClasses[2048] = {
	&os_Build_class,
	NULL
};

JNIEnv *jni_get_env()
{
	return &jni_iface;
}

void jni_register_class(jclass clazz)
{
	int idx;
	for (idx = 0; registeredClasses[idx]; idx++);

	registeredClasses[idx] = clazz;
	registeredClasses[idx+1] = NULL;
}

//jobject differs a tiny bit from the rest, some of the macro functions are not used at all, and NewObjectArray differs from the macro
//Set them unused and reimplement NewObjectArray
__attribute__((unused)) static ABI_ATTR jobjectArray  iface_NewObjectArray(JNIEnv*, jsize ); 
__attribute__((unused)) static ABI_ATTR jobject      *iface_GetObjectArrayElements(JNIEnv*, jobjectArray, jboolean *); 
__attribute__((unused)) static ABI_ATTR void          iface_ReleaseObjectArrayElements(JNIEnv*, jobjectArray, jobject *, jint); 
__attribute__((unused)) static ABI_ATTR void          iface_GetObjectArrayRegion(JNIEnv*, jobjectArray, jsize, jsize, jobject *); 
__attribute__((unused)) static ABI_ATTR void          iface_SetObjectArrayRegion(JNIEnv*, jobjectArray, jsize, jsize, const jobject *); 
__attribute__((unused)) static ABI_ATTR jobjectArray  iface_NewObjectArray(JNIEnv*, jsize ); 

// Defines all the necessary member accessor dispatchers
#define FROM_VARIADIC {  }
#define JNI_PRIV_TYPE(pretty, type) \
    static ABI_ATTR type ## Array iface_New ## pretty ## Array(JNIEnv *env, jsize size) { \
		type ## Array ref = calloc(1, sizeof(*ref)); \
		ref->elements = calloc(size, sizeof(type)); \
		ref->count = size; \
		return ref; \
	} \
    static ABI_ATTR type *iface_Get ## pretty ## ArrayElements(JNIEnv *env, type ## Array ref, jboolean *isCopy) { \
		if (isCopy) *isCopy = JNI_TRUE; \
		type *array = malloc(sizeof(type) * ref->count); \
		memcpy(array, ref->elements, sizeof(type) * ref->count); \
		return array; \
	} \
    static ABI_ATTR void iface_Release ## pretty ## ArrayElements(JNIEnv *env, type ## Array ref, type *arr, jint mode) { \
		if (mode == 0 || mode == JNI_COMMIT) memcpy(arr, ref->elements, sizeof(type) * ref->count); \
		if (mode == 0 || mode == JNI_ABORT) free(arr); \
	} \
    static ABI_ATTR void iface_Get ## pretty ## ArrayRegion(JNIEnv *env, type ## Array ref, jsize start, jsize length, type *arr) { \
		memcpy(arr, ref->elements + sizeof(type) * start, sizeof(type) * length); \
	} \
    static ABI_ATTR void iface_Set ## pretty ## ArrayRegion(JNIEnv *env, type ## Array ref, jsize start, jsize length, const type *arr) { \
		memcpy(ref->elements + sizeof(type) * start, arr, sizeof(type) * length); \
	} \
    static ABI_ATTR type iface_Get ## pretty ## Field (JNIEnv *env, jobject obj, jfieldID field) { \
		return *(type*)((long)obj + (long)field->offset); \
	} \
    static ABI_ATTR void iface_Set ## pretty ## Field(JNIEnv *env, jobject obj, jfieldID field, type value) { \
		*(type*)((long)obj + (long)field->offset) = value; \
	} \
    static ABI_ATTR type iface_GetStatic ## pretty ## Field(JNIEnv *env, jclass jclazz, jfieldID field) { \
		if (jclazz && field) return *(type*)field->offset; \
	} \
    static ABI_ATTR void iface_SetStatic ## pretty ## Field(JNIEnv *env, jclass jclazz, jfieldID field, type value) { \
		if (jclazz && field) *(type*)field->offset = *(type*)&value; \
	}
JNI_PRIV_MACRO_TYPE_LIST
#undef JNI_PRIV_TYPE

// Defines all the necessary method call dispatchers
#define VA_RESOLVE(body)   \
	va_list va;            \
	va_start(va, method) ; \
	body                   \
	va_end(va);


#define CHECK_FUNCT_VA \
	if (method && method->addr_variadic)

#define CHECK_FUNCT_AR \
	if (method && method->addr_array)

#define JNI_PRIV_TYPE(pretty, type)                                                                                                              \
    static ABI_ATTR type  iface_CallNonvirtual ## pretty ## Method (JNIEnv *env, jobject obj, jclass jclazz, jmethodID method, ...)           { type ret = 0; VA_RESOLVE(CHECK_FUNCT_VA method->addr_variadic(obj, &ret, va);)  return ret; } \
    static ABI_ATTR type  iface_CallNonvirtual ## pretty ## MethodV(JNIEnv *env, jobject obj, jclass jclazz, jmethodID method, va_list va)    { type ret = 0;            CHECK_FUNCT_VA method->addr_variadic(obj, &ret, va);   return ret; } \
    static ABI_ATTR type  iface_CallNonvirtual ## pretty ## MethodA(JNIEnv *env, jobject obj, jclass jclazz, jmethodID method, jvalue *value) { type ret = 0;            CHECK_FUNCT_AR method->addr_array(obj, &ret, value);   return ret; } \
    static ABI_ATTR type  iface_Call           ## pretty ## Method (JNIEnv *env, jobject obj, jmethodID method, ...)                          { type ret = 0; VA_RESOLVE(CHECK_FUNCT_VA method->addr_variadic(obj, &ret, va);)  return ret; } \
    static ABI_ATTR type  iface_Call           ## pretty ## MethodV(JNIEnv *env, jobject obj, jmethodID method, va_list va)                   { type ret = 0;            CHECK_FUNCT_VA method->addr_variadic(obj, &ret, va);   return ret; } \
    static ABI_ATTR type  iface_Call           ## pretty ## MethodA(JNIEnv *env, jobject obj, jmethodID method, jvalue *value)                { type ret = 0;            CHECK_FUNCT_AR method->addr_array(obj, &ret, value);   return ret; } \
    static ABI_ATTR type  iface_CallStatic     ## pretty ## Method (JNIEnv *env, jclass jclazz, jmethodID method, ...)                        { type ret = 0; VA_RESOLVE(CHECK_FUNCT_VA method->addr_variadic(NULL, &ret, va);) return ret; } \
    static ABI_ATTR type  iface_CallStatic     ## pretty ## MethodV(JNIEnv *env, jclass jclazz, jmethodID method, va_list va)                 { type ret = 0;            CHECK_FUNCT_VA method->addr_variadic(NULL, &ret, va);  return ret; } \
    static ABI_ATTR type  iface_CallStatic     ## pretty ## MethodA(JNIEnv *env, jclass jclazz, jmethodID method, jvalue *value)              { type ret = 0;            CHECK_FUNCT_AR method->addr_array(NULL, &ret, value);  return ret; }
JNI_PRIV_MACRO_TYPE_LIST
#undef JNI_PRIV_TYPE

static ABI_ATTR void iface_CallNonvirtualVoidMethod (JNIEnv *env, jobject obj, jclass jclazz, jmethodID method, ...)           { VA_RESOLVE(CHECK_FUNCT_VA method->addr_variadic(obj, NULL, va);)  }
static ABI_ATTR void iface_CallNonvirtualVoidMethodV(JNIEnv *env, jobject obj, jclass jclazz, jmethodID method, va_list va)    {            CHECK_FUNCT_VA method->addr_variadic(obj, NULL, va);   }
static ABI_ATTR void iface_CallNonvirtualVoidMethodA(JNIEnv *env, jobject obj, jclass jclazz, jmethodID method, jvalue *value) {            CHECK_FUNCT_AR method->addr_array(obj, NULL, value);   }
static ABI_ATTR void iface_CallVoidMethod (JNIEnv *env, jobject obj, jmethodID method, ...)                                    { VA_RESOLVE(CHECK_FUNCT_VA method->addr_variadic(obj, NULL, va);)  }
static ABI_ATTR void iface_CallVoidMethodV(JNIEnv *env, jobject obj, jmethodID method, va_list va)                             {            CHECK_FUNCT_VA method->addr_variadic(obj, NULL, va);   }
static ABI_ATTR void iface_CallVoidMethodA(JNIEnv *env, jobject obj, jmethodID method, jvalue *value)                          {            CHECK_FUNCT_AR method->addr_array(obj, NULL, value);   }
static ABI_ATTR void iface_CallStaticVoidMethod (JNIEnv *env, jclass jclazz, jmethodID method, ...)                            { VA_RESOLVE(CHECK_FUNCT_VA method->addr_variadic(NULL, NULL, va);) }
static ABI_ATTR void iface_CallStaticVoidMethodV(JNIEnv *env, jclass jclazz, jmethodID method, va_list va)                     {            CHECK_FUNCT_VA method->addr_variadic(NULL, NULL, va);  }
static ABI_ATTR void iface_CallStaticVoidMethodA(JNIEnv *env, jclass jclazz, jmethodID method, jvalue *value)                  {            CHECK_FUNCT_AR method->addr_array(NULL, NULL, value);  }

ABI_ATTR static jobjectArray iface_NewObjectArray_NONTRIVIAL(JNIEnv *env, jsize len, jclass clazz, jobject init)
{
	WARN_STUB;
	return NULL;
}

static jint iface_GetVersion(JNIEnv *env)
{
	return 10;
}

static jclass iface_DefineClass(JNIEnv *env, const char *name, jobject loader,
    const jbyte* buf, jsize bufLen)
{
	WARN_STUB;
	return NULL;
}

static jclass iface_FindClass(JNIEnv *env, const char* name)
{
	for (int i = 0; registeredClasses[i]; i++) {
		jclass c = registeredClasses[i];
		if (strcmp(c->classpath, name) == 0) {
			return c;
		}
	}

	return NULL;
}

static jclass iface_GetSuperclass(JNIEnv *env, jclass jclazz)
{
	/* No inheritance here */
	return jclazz;
}

static jboolean iface_IsAssignableFrom(JNIEnv *env, jclass jclazz1, jclass jclazz2)
{
	WARN_STUB;
}

static jmethodID iface_FromReflectedMethod(JNIEnv *env, jobject jmethod)
{
	WARN_STUB;
}

static jfieldID iface_FromReflectedField(JNIEnv *env, jobject jfield)
{
	WARN_STUB;
}

static jobject iface_ToReflectedMethod(JNIEnv *env, jclass jcls, jmethodID methodID, jboolean isStatic)
{
	WARN_STUB;
}

static jobject iface_ToReflectedField(JNIEnv *env, jclass jcls, jfieldID fieldID, jboolean isStatic)
{
	WARN_STUB;
}

static jint iface_Throw(JNIEnv *env, jthrowable jobj)
{
	WARN_STUB;
}

static jint iface_ThrowNew(JNIEnv *env, jclass jclazz, const char* message)
{
	WARN_STUB;
}

static jthrowable iface_ExceptionOccurred(JNIEnv *env)
{
	WARN_STUB;
}

static void iface_ExceptionDescribe(JNIEnv *env)
{
	WARN_STUB;
}

static void iface_ExceptionClear(JNIEnv *env)
{
	WARN_STUB;
}

static void iface_FatalError(JNIEnv *env, const char* msg)
{
	WARN_STUB;
}

static jint iface_PushLocalFrame(JNIEnv *env, jint capacity)
{
	WARN_STUB;
}

static jobject iface_PopLocalFrame(JNIEnv *env, jobject jresult)
{
	WARN_STUB;
}

static jobject iface_NewGlobalRef(JNIEnv *env, jobject jobj)
{
	return jobj;
}

static void iface_DeleteGlobalRef(JNIEnv *env, jobject jglobalRef)
{
	;
}

static jobject iface_NewLocalRef(JNIEnv *env, jobject jobj)
{
	return jobj;
}

static void iface_DeleteLocalRef(JNIEnv *env, jobject jlocalRef)
{
	;
}

static jint iface_EnsureLocalCapacity(JNIEnv *env, jint capacity)
{
	WARN_STUB;
}

static jboolean iface_IsSameObject(JNIEnv *env, jobject jref1, jobject jref2)
{
	WARN_STUB;
}

static jobject iface_AllocObject(JNIEnv *env, jclass jclazz)
{
	WARN_STUB;
}

static jobject iface_NewObject(JNIEnv *env, jclass jclazz, jmethodID methodID, ...)
{
	WARN_STUB;
}

static jobject iface_NewObjectV(JNIEnv *env, jclass jclazz, jmethodID methodID, va_list args)
{
	WARN_STUB;
}

static jobject iface_NewObjectA(JNIEnv *env, jclass jclazz, jmethodID methodID, jvalue* args)
{
	WARN_STUB;
}

static jclass iface_GetObjectClass(JNIEnv *env, jobject jobj)
{
	return jobj->clazz;
}

static jboolean iface_IsInstanceOf(JNIEnv *env, jobject jobj, jclass jclazz)
{
	WARN_STUB;
}

static jmethodID iface_GetMethodID(JNIEnv *env, jclass clazz, const char* name, const char* sig)
{
	if (clazz) {
		for (int i = 0; clazz->methods[i].name; i++) {
			if ((strcmp(name, clazz->methods[i].name)      == 0) && 
				(strcmp(sig,  clazz->methods[i].signature) == 0)) {
				return &clazz->methods[i];
			}
		}
		warning("Class %s does not have method %s.\n", clazz->classname, name);
	} else {
		warning("Could not look up method %s, NULL class.\n", name);
	}

	return NULL;
}

static jfieldID iface_GetFieldID(JNIEnv *env, jclass clazz, const char* name, const char* sig)
{
	if (clazz) {
		for (int i = 0; clazz->fields[i].name; i++) {
			if (strcmp(name, clazz->fields[i].name) == 0 && 
				strcmp(sig,  clazz->fields[i].signature) == 0) {
				return &clazz->fields[i];
			}
		}

		warning("Class %s does not have field %s.\n", clazz->classname, name);
	} else {
		warning("Could not look up field %s, NULL class.\n", name);
	}
	
	return NULL;
	//WARN_STUB;
}

static jmethodID iface_GetStaticMethodID(JNIEnv *env, jclass clazz, const char* name, const char* sig)
{
	return iface_GetMethodID(env, clazz, name, sig);
	//WARN_STUB;
}

static jfieldID iface_GetStaticFieldID(JNIEnv *env, jclass clazz, const char* name, const char* sig)
{
	return iface_GetFieldID(env, clazz, name, sig);
	//WARN_STUB;
}

static jstring iface_NewString(JNIEnv *env, const jchar* unicodeChars, jsize len)
{
	return strndup(unicodeChars, len);
}

static jsize iface_GetStringLength(JNIEnv *env, jstring jstr)
{
	return strlen(jstr->str);
}

static const jchar* iface_GetStringChars(JNIEnv *env, jstring jstr, jboolean* isCopy)
{
	if (isCopy) *isCopy = JNI_TRUE;
	return strdup(jstr->str);
}

static void iface_ReleaseStringChars(JNIEnv *env, jstring jstr, const jchar* chars)
{
	free(chars);
}

static jstring iface_NewStringUTF(JNIEnv *env, const char* bytes)
{
	jstring *str = calloc(1, sizeof(*str));
	*str = &MK_JSTRING(strdup(bytes));

	return str;
}

static jsize iface_GetStringUTFLength(JNIEnv *env, jstring jstr)
{
	return strlen(jstr->str);
}

static const char* iface_GetStringUTFChars(JNIEnv *env, jstring jstr, jboolean* isCopy)
{
	if (isCopy) 
		*isCopy = JNI_TRUE;
	return strdup(jstr ? jstr->str : "(nil)");
}

static void iface_ReleaseStringUTFChars(JNIEnv *env, jstring jstr, const char* utf)
{
	free(utf);
}

static jsize iface_GetArrayLength(JNIEnv *env, jarray jarr)
{
	return jarr->count;
}

static jobject iface_GetObjectArrayElement(JNIEnv *env, jobjectArray jarr, jsize index)
{
	return ((jobject*)jarr->elements)[index];
}

static void iface_SetObjectArrayElement(JNIEnv *env, jobjectArray jarr, jsize index, jobject jobj)
{
	if (jarr)
		((jobject*)jarr->elements)[index] = jobj;
}

static jint iface_RegisterNatives(JNIEnv *env, jclass jclazz,
    const JNINativeMethod* methods, jint nMethods)
{
	WARN_STUB;
}

static jint iface_UnregisterNatives(JNIEnv *env, jclass jclazz)
{
	WARN_STUB;
}

static jint iface_MonitorEnter(JNIEnv *env, jobject jobj)
{
	WARN_STUB;
}

static jint iface_MonitorExit(JNIEnv *env, jobject jobj)
{
	WARN_STUB;
}

static jint iface_GetJavaVM(JNIEnv *env, JavaVM** vm)
{
	*vm = (JavaVM*)&jni_fake_vm;
    jni_fake_vm.reserved0 = (uintptr_t)&jni_fake_vm;
    return 0;
}

static void iface_GetStringRegion(JNIEnv *env, jstring jstr, jsize start, jsize len, jchar* buf)
{
	WARN_STUB;
}

static void iface_GetStringUTFRegion(JNIEnv *env, jstring jstr, jsize start, jsize len, char* buf)
{
	WARN_STUB;
}

static void* iface_GetPrimitiveArrayCritical(JNIEnv *env, jarray jarr, jboolean* isCopy)
{
	//WARN_STUB;
	return NULL;
}

static void iface_ReleasePrimitiveArrayCritical(JNIEnv *env, jarray jarr, void* carray, jint mode)
{
	WARN_STUB;
}

static const jchar* iface_GetStringCritical(JNIEnv *env, jstring jstr, jboolean* isCopy)
{
	WARN_STUB;
}

static void iface_ReleaseStringCritical(JNIEnv *env, jstring jstr, const jchar* carray)
{
	WARN_STUB;
}

static jweak iface_NewWeakGlobalRef(JNIEnv *env, jobject jobj)
{
	WARN_STUB;
}

static void iface_DeleteWeakGlobalRef(JNIEnv *env, jweak wref)
{
	WARN_STUB;
}

static jboolean iface_ExceptionCheck(JNIEnv *env)
{
	WARN_STUB;
}

static jobjectRefType iface_GetObjectRefType(JNIEnv *env, jobject jobj)
{
	WARN_STUB;
}

static jobject iface_NewDirectByteBuffer(JNIEnv *env, void* address, jlong capacity)
{
	WARN_STUB;
}

static void* iface_GetDirectBufferAddress(JNIEnv *env, jobject jbuf)
{
	WARN_STUB;
}

static jlong iface_GetDirectBufferCapacity(JNIEnv *env, jobject jbuf)
{
	WARN_STUB;
}

typedef void (*funcptr_t)();

static struct JNINativeInterface jni_iface = {
	.reserved0 = &jni_iface,
	.GetVersion = &iface_GetVersion, 
	.DefineClass = &iface_DefineClass, 
	.FindClass = &iface_FindClass, 
	.FromReflectedMethod = &iface_FromReflectedMethod, 
	.FromReflectedField = &iface_FromReflectedField, 

    /* spec doesn't show jboolean parameter */
	.ToReflectedMethod = &iface_ToReflectedMethod, 
	.GetSuperclass = &iface_GetSuperclass, 
	.IsAssignableFrom = &iface_IsAssignableFrom, 

    /* spec doesn't show jboolean parameter */
	.ToReflectedField = &iface_ToReflectedField, 
	.Throw = &iface_Throw, 
	.ThrowNew = &iface_ThrowNew, 
	.ExceptionOccurred = &iface_ExceptionOccurred, 
	.ExceptionDescribe = &iface_ExceptionDescribe, 
	.ExceptionClear = &iface_ExceptionClear, 
	.FatalError = &iface_FatalError, 
	.PushLocalFrame = &iface_PushLocalFrame, 
	.PopLocalFrame = &iface_PopLocalFrame, 
	.NewGlobalRef = &iface_NewGlobalRef, 
	.DeleteGlobalRef = &iface_DeleteGlobalRef, 
	.DeleteLocalRef = &iface_DeleteLocalRef, 
	.IsSameObject = &iface_IsSameObject, 
	.NewLocalRef = &iface_NewLocalRef, 
	.EnsureLocalCapacity = &iface_EnsureLocalCapacity, 
	.AllocObject = &iface_AllocObject, 
	.NewObject = &iface_NewObject, 
	.NewObjectV = &iface_NewObjectV, 
	.NewObjectA = &iface_NewObjectA, 
	.GetObjectClass = &iface_GetObjectClass, 
	.IsInstanceOf = &iface_IsInstanceOf, 
	.GetMethodID = &iface_GetMethodID, 
	.CallObjectMethod = &iface_CallObjectMethod, 
	.CallObjectMethodV = &iface_CallObjectMethodV, 
	.CallObjectMethodA = &iface_CallObjectMethodA, 
	.CallBooleanMethod = &iface_CallBooleanMethod, 
	.CallBooleanMethodV = &iface_CallBooleanMethodV, 
	.CallBooleanMethodA = &iface_CallBooleanMethodA, 
	.CallByteMethod = &iface_CallByteMethod, 
	.CallByteMethodV = &iface_CallByteMethodV, 
	.CallByteMethodA = &iface_CallByteMethodA, 
	.CallCharMethod = &iface_CallCharMethod, 
	.CallCharMethodV = &iface_CallCharMethodV, 
	.CallCharMethodA = &iface_CallCharMethodA, 
	.CallShortMethod = &iface_CallShortMethod, 
	.CallShortMethodV = &iface_CallShortMethodV, 
	.CallShortMethodA = &iface_CallShortMethodA, 
	.CallIntMethod = &iface_CallIntMethod, 
	.CallIntMethodV = &iface_CallIntMethodV, 
	.CallIntMethodA = &iface_CallIntMethodA, 
	.CallLongMethod = &iface_CallLongMethod, 
	.CallLongMethodV = &iface_CallLongMethodV, 
	.CallLongMethodA = &iface_CallLongMethodA, 
	.CallFloatMethod = &iface_CallFloatMethod, 
	.CallFloatMethodV = &iface_CallFloatMethodV, 
	.CallFloatMethodA = &iface_CallFloatMethodA, 
	.CallDoubleMethod = &iface_CallDoubleMethod, 
	.CallDoubleMethodV = &iface_CallDoubleMethodV, 
	.CallDoubleMethodA = &iface_CallDoubleMethodA, 
	.CallVoidMethod = &iface_CallVoidMethod, 
	.CallVoidMethodV = &iface_CallVoidMethodV, 
	.CallVoidMethodA = &iface_CallVoidMethodA, 
	.CallNonvirtualObjectMethod = &iface_CallNonvirtualObjectMethod, 
	.CallNonvirtualObjectMethodV = &iface_CallNonvirtualObjectMethodV, 
	.CallNonvirtualObjectMethodA = &iface_CallNonvirtualObjectMethodA, 
	.CallNonvirtualBooleanMethod = &iface_CallNonvirtualBooleanMethod, 
	.CallNonvirtualBooleanMethodV = &iface_CallNonvirtualBooleanMethodV, 
	.CallNonvirtualBooleanMethodA = &iface_CallNonvirtualBooleanMethodA, 
	.CallNonvirtualByteMethod = &iface_CallNonvirtualByteMethod, 
	.CallNonvirtualByteMethodV = &iface_CallNonvirtualByteMethodV, 
	.CallNonvirtualByteMethodA = &iface_CallNonvirtualByteMethodA, 
	.CallNonvirtualCharMethod = &iface_CallNonvirtualCharMethod, 
	.CallNonvirtualCharMethodV = &iface_CallNonvirtualCharMethodV, 
	.CallNonvirtualCharMethodA = &iface_CallNonvirtualCharMethodA, 
	.CallNonvirtualShortMethod = &iface_CallNonvirtualShortMethod, 
	.CallNonvirtualShortMethodV = &iface_CallNonvirtualShortMethodV, 
	.CallNonvirtualShortMethodA = &iface_CallNonvirtualShortMethodA, 
	.CallNonvirtualIntMethod = &iface_CallNonvirtualIntMethod, 
	.CallNonvirtualIntMethodV = &iface_CallNonvirtualIntMethodV, 
	.CallNonvirtualIntMethodA = &iface_CallNonvirtualIntMethodA, 
	.CallNonvirtualLongMethod = &iface_CallNonvirtualLongMethod, 
	.CallNonvirtualLongMethodV = &iface_CallNonvirtualLongMethodV, 
	.CallNonvirtualLongMethodA = &iface_CallNonvirtualLongMethodA, 
	.CallNonvirtualFloatMethod = &iface_CallNonvirtualFloatMethod, 
	.CallNonvirtualFloatMethodV = &iface_CallNonvirtualFloatMethodV, 
	.CallNonvirtualFloatMethodA = &iface_CallNonvirtualFloatMethodA, 
	.CallNonvirtualDoubleMethod = &iface_CallNonvirtualDoubleMethod, 
	.CallNonvirtualDoubleMethodV = &iface_CallNonvirtualDoubleMethodV, 
	.CallNonvirtualDoubleMethodA = &iface_CallNonvirtualDoubleMethodA, 
	.CallNonvirtualVoidMethod = &iface_CallNonvirtualVoidMethod, 
	.CallNonvirtualVoidMethodV = &iface_CallNonvirtualVoidMethodV, 
	.CallNonvirtualVoidMethodA = &iface_CallNonvirtualVoidMethodA, 
	.GetFieldID = &iface_GetFieldID, 
	.GetObjectField = &iface_GetObjectField, 
	.GetBooleanField = &iface_GetBooleanField, 
	.GetByteField = &iface_GetByteField, 
	.GetCharField = &iface_GetCharField, 
	.GetShortField = &iface_GetShortField, 
	.GetIntField = &iface_GetIntField, 
	.GetLongField = &iface_GetLongField, 
	.GetFloatField = &iface_GetFloatField, 
	.GetDoubleField = &iface_GetDoubleField, 
	.SetObjectField = &iface_SetObjectField, 
	.SetBooleanField = &iface_SetBooleanField, 
	.SetByteField = &iface_SetByteField, 
	.SetCharField = &iface_SetCharField, 
	.SetShortField = &iface_SetShortField, 
	.SetIntField = &iface_SetIntField, 
	.SetLongField = &iface_SetLongField, 
	.SetFloatField = &iface_SetFloatField, 
	.SetDoubleField = &iface_SetDoubleField, 
	.GetStaticMethodID = &iface_GetStaticMethodID, 
	.CallStaticObjectMethod = &iface_CallStaticObjectMethod, 
	.CallStaticObjectMethodV = &iface_CallStaticObjectMethodV, 
	.CallStaticObjectMethodA = &iface_CallStaticObjectMethodA, 
	.CallStaticBooleanMethod = &iface_CallStaticBooleanMethod, 
	.CallStaticBooleanMethodV = &iface_CallStaticBooleanMethodV, 
	.CallStaticBooleanMethodA = &iface_CallStaticBooleanMethodA, 
	.CallStaticByteMethod = &iface_CallStaticByteMethod, 
	.CallStaticByteMethodV = &iface_CallStaticByteMethodV, 
	.CallStaticByteMethodA = &iface_CallStaticByteMethodA, 
	.CallStaticCharMethod = &iface_CallStaticCharMethod, 
	.CallStaticCharMethodV = &iface_CallStaticCharMethodV, 
	.CallStaticCharMethodA = &iface_CallStaticCharMethodA, 
	.CallStaticShortMethod = &iface_CallStaticShortMethod, 
	.CallStaticShortMethodV = &iface_CallStaticShortMethodV, 
	.CallStaticShortMethodA = &iface_CallStaticShortMethodA, 
	.CallStaticIntMethod = &iface_CallStaticIntMethod, 
	.CallStaticIntMethodV = &iface_CallStaticIntMethodV, 
	.CallStaticIntMethodA = &iface_CallStaticIntMethodA, 
	.CallStaticLongMethod = &iface_CallStaticLongMethod, 
	.CallStaticLongMethodV = &iface_CallStaticLongMethodV, 
	.CallStaticLongMethodA = &iface_CallStaticLongMethodA, 
	.CallStaticFloatMethod = &iface_CallStaticFloatMethod, 
	.CallStaticFloatMethodV = &iface_CallStaticFloatMethodV, 
	.CallStaticFloatMethodA = &iface_CallStaticFloatMethodA, 
	.CallStaticDoubleMethod = &iface_CallStaticDoubleMethod, 
	.CallStaticDoubleMethodV = &iface_CallStaticDoubleMethodV, 
	.CallStaticDoubleMethodA = &iface_CallStaticDoubleMethodA, 
	.CallStaticVoidMethod = &iface_CallStaticVoidMethod, 
	.CallStaticVoidMethodV = &iface_CallStaticVoidMethodV, 
	.CallStaticVoidMethodA = &iface_CallStaticVoidMethodA, 
	.GetStaticFieldID = &iface_GetStaticFieldID, 
	.GetStaticObjectField = &iface_GetStaticObjectField, 
	.GetStaticBooleanField = &iface_GetStaticBooleanField, 
	.GetStaticByteField = &iface_GetStaticByteField, 
	.GetStaticCharField = &iface_GetStaticCharField, 
	.GetStaticShortField = &iface_GetStaticShortField, 
	.GetStaticIntField = &iface_GetStaticIntField, 
	.GetStaticLongField = &iface_GetStaticLongField, 
	.GetStaticFloatField = &iface_GetStaticFloatField, 
	.GetStaticDoubleField = &iface_GetStaticDoubleField, 
	.SetStaticObjectField = &iface_SetStaticObjectField, 
	.SetStaticBooleanField = &iface_SetStaticBooleanField, 
	.SetStaticByteField = &iface_SetStaticByteField, 
	.SetStaticCharField = &iface_SetStaticCharField, 
	.SetStaticShortField = &iface_SetStaticShortField, 
	.SetStaticIntField = &iface_SetStaticIntField, 
	.SetStaticLongField = &iface_SetStaticLongField, 
	.SetStaticFloatField = &iface_SetStaticFloatField, 
	.SetStaticDoubleField = &iface_SetStaticDoubleField, 
	.NewString = &iface_NewString, 
	.GetStringLength = &iface_GetStringLength, 
	.GetStringChars = &iface_GetStringChars, 
	.ReleaseStringChars = &iface_ReleaseStringChars, 
	.NewStringUTF = &iface_NewStringUTF, 
	.GetStringUTFLength = &iface_GetStringUTFLength,

    /* JNI spec says this returns const jbyte*, but that's inconsistent */
	.GetStringUTFChars = &iface_GetStringUTFChars, 
	.ReleaseStringUTFChars = &iface_ReleaseStringUTFChars, 
	.GetArrayLength = &iface_GetArrayLength, 
	.NewObjectArray = &iface_NewObjectArray_NONTRIVIAL, 
	.GetObjectArrayElement = &iface_GetObjectArrayElement,
	.SetObjectArrayElement = &iface_SetObjectArrayElement,
	.NewBooleanArray = &iface_NewBooleanArray,
	.NewByteArray = &iface_NewByteArray,
	.NewCharArray = &iface_NewCharArray,
	.NewShortArray = &iface_NewShortArray,
	.NewIntArray = &iface_NewIntArray,
	.NewLongArray = &iface_NewLongArray,
	.NewFloatArray = &iface_NewFloatArray,
	.NewDoubleArray = &iface_NewDoubleArray,
	.GetBooleanArrayElements = &iface_GetBooleanArrayElements,
	.GetByteArrayElements = &iface_GetByteArrayElements,
	.GetCharArrayElements = &iface_GetCharArrayElements,
	.GetShortArrayElements = &iface_GetShortArrayElements,
	.GetIntArrayElements = &iface_GetIntArrayElements,
	.GetLongArrayElements = &iface_GetLongArrayElements,
	.GetFloatArrayElements = &iface_GetFloatArrayElements,
	.GetDoubleArrayElements = &iface_GetDoubleArrayElements,
	.ReleaseBooleanArrayElements = &iface_ReleaseBooleanArrayElements, 
	.ReleaseByteArrayElements = &iface_ReleaseByteArrayElements, 
	.ReleaseCharArrayElements = &iface_ReleaseCharArrayElements, 
	.ReleaseShortArrayElements = &iface_ReleaseShortArrayElements, 
	.ReleaseIntArrayElements = &iface_ReleaseIntArrayElements, 
	.ReleaseLongArrayElements = &iface_ReleaseLongArrayElements, 
	.ReleaseFloatArrayElements = &iface_ReleaseFloatArrayElements, 
	.ReleaseDoubleArrayElements = &iface_ReleaseDoubleArrayElements, 
	.GetBooleanArrayRegion = &iface_GetBooleanArrayRegion, 
	.GetByteArrayRegion = &iface_GetByteArrayRegion, 
	.GetCharArrayRegion = &iface_GetCharArrayRegion, 
	.GetShortArrayRegion = &iface_GetShortArrayRegion, 
	.GetIntArrayRegion = &iface_GetIntArrayRegion, 
	.GetLongArrayRegion = &iface_GetLongArrayRegion, 
	.GetFloatArrayRegion = &iface_GetFloatArrayRegion, 
	.GetDoubleArrayRegion = &iface_GetDoubleArrayRegion, 

	.SetBooleanArrayRegion = &iface_SetBooleanArrayRegion, 
	.SetByteArrayRegion = &iface_SetByteArrayRegion, 
	.SetCharArrayRegion = &iface_SetCharArrayRegion, 
	.SetShortArrayRegion = &iface_SetShortArrayRegion, 
	.SetIntArrayRegion = &iface_SetIntArrayRegion, 
	.SetLongArrayRegion = &iface_SetLongArrayRegion, 
	.SetFloatArrayRegion = &iface_SetFloatArrayRegion, 
	.SetDoubleArrayRegion = &iface_SetDoubleArrayRegion, 
	.RegisterNatives = &iface_RegisterNatives, 
	.UnregisterNatives = &iface_UnregisterNatives, 
	.MonitorEnter = &iface_MonitorEnter, 
	.MonitorExit = &iface_MonitorExit, 
	.GetJavaVM = &iface_GetJavaVM, 
	.GetStringRegion = &iface_GetStringRegion, 
	.GetStringUTFRegion = &iface_GetStringUTFRegion, 
	.GetPrimitiveArrayCritical = &iface_GetPrimitiveArrayCritical, 
	.ReleasePrimitiveArrayCritical = &iface_ReleasePrimitiveArrayCritical, 
	.GetStringCritical = &iface_GetStringCritical, 
	.ReleaseStringCritical = &iface_ReleaseStringCritical, 
	.NewWeakGlobalRef = &iface_NewWeakGlobalRef, 
	.DeleteWeakGlobalRef = &iface_DeleteWeakGlobalRef, 
	.ExceptionCheck = &iface_ExceptionCheck, 
	.NewDirectByteBuffer = &iface_NewDirectByteBuffer, 
	.GetDirectBufferAddress = &iface_GetDirectBufferAddress, 
	.GetDirectBufferCapacity = &iface_GetDirectBufferCapacity, 

    /* added in JNI 1.6 */
	.GetObjectRefType = &iface_GetObjectRefType,
};

static jobject iface_ret0()
{
    return 0;
}

static jint iface_AttachCurrentThread(JavaVM *vm, void **p_env, void *thr_args)
{
    if (p_env)
        *p_env = (void*)&jni_iface;

    return 1;
}

static struct JNIInvokeInterface jni_fake_vm = {
    .DestroyJavaVM = &iface_ret0,
    .AttachCurrentThread = &iface_AttachCurrentThread,
    .DetachCurrentThread = &iface_ret0,
    .GetEnv = &iface_ret0,
    .AttachCurrentThreadAsDaemon = &iface_ret0
};