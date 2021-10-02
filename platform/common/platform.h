#ifndef __PLATFORM_H__
#define __PLATFORM_H__

// Definitions for ABI attributes
// Flags bridges and native library functions as the correct ABI, e.g. for
// compiling with HardFP toolchains and drivers, since armv7a android libraries are
// compiled to the SoftFP ABI.
#if __ARM_PCS_VFP==1
#define ABI_ATTR __attribute__((pcs("aapcs")))
#else
#define ABI_ATTR
#endif

#define ARCH_ARMV6 (defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__))

#ifdef DEBUG
    #ifndef PLATFORM_VITA
        #define fatal_error(msg, ...) { fprintf(stderr, "%s:%d: " msg, __FILE__, __LINE__, ##__VA_ARGS__); }
        #define warning(msg, ...) { fprintf(stderr, msg, ##__VA_ARGS__); }
        #define WARN_STUB fprintf(stderr, "Warning, stubbed function \"%s\".\n", __FUNCTION__);
    #else
        void vgl_file_log(const char *format, ...);
        #define fatal_error(msg, ...) { vgl_file_log("%s:%d: " msg, __FILE__, __LINE__, ##__VA_ARGS__); }
        #define warning(msg, ...) { vgl_file_log(msg, ##__VA_ARGS__); }
        #define WARN_STUB vgl_file_log("Warning, stubbed function \"%s\".\n", __FUNCTION__);
    #endif
#else
    #ifndef PLATFORM_VITA
        #define fatal_error(msg, ...) { fprintf(stderr, "%s:%d: " msg, __FILE__, __LINE__, ##__VA_ARGS__); }
    #else
        void vgl_file_log(const char *format, ...);
        #define fatal_error(msg, ...) { vgl_file_log("%s:%d: " msg, __FILE__, __LINE__, ##__VA_ARGS__); }
    #endif
    #define warning(msg, ...)
    #define WARN_STUB
#endif

#ifdef __builtin_types_compatible_p
#define __must_be_array(a) \
 BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))
#else
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define MIN_FREE_MEM 48 * 1024 * 1024

#endif /* __PLATFORM_H__ */