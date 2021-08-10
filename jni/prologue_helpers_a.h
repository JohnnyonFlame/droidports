#undef F_v
#undef F_s
#undef F_ssiaa
#undef F_ssia
#undef F_i
#undef F_ii
#undef F_si
#undef F_f

#define F_v /* none */
#define F_s \
    jstring arg1 = args[0].p;
#define F_ssiaa \
    jstring arg1 = args[0].p; jstring arg2 = args[1].p; \
    jint    arg3 = args[2].i; jarray  arg4 = args[3].p; \
    jarray  arg5 = args[4].p;
#define F_ssia \
    jstring arg1 = args[0].p; jstring arg2 = args[1].p; \
    jint    arg3 = args[2].i; jarray  arg4 = args[3].p;
#define F_i \
    jint    arg1 = args[0].i;
#define F_ii \
    jint    arg1 = args[0].i; jint    arg2 = args[1].i;
#define F_si \
    jstring arg1 = args[0].p; jint    arg2 = args[1].i;
#define F_f \
    jfloat arg1  = args[0].f;
