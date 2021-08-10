#define F_v /* none */
#define F_s \
    jstring arg1 = va_arg(va, jstring);
#define F_ssiaa \
    jstring arg1 = va_arg(va, jstring); jstring arg2 = va_arg(va, jstring); \
    jint    arg3 = va_arg(va, jint);    jarray  arg4 = va_arg(va, jarray);  \
    jarray  arg5 = va_arg(va, jarray);
#define F_ssia \
    jstring arg1 = va_arg(va, jstring); jstring arg2 = va_arg(va, jstring); \
    jint    arg3 = va_arg(va, jint);    jarray  arg4 = va_arg(va, jarray);
#define F_i \
    jint arg1 = va_arg(va, jint);
#define F_ii \
    jint arg1 = va_arg(va, jint); jint arg2 = va_arg(va, jint);
#define F_si \
    jstring arg1 = va_arg(va, jstring); jint arg2 = va_arg(va, jint);
#define F_f \
    jfloat arg1 = va_arg(va, jdouble);
