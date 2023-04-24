#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <stdint.h>

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
    #define fatal_error(msg, ...) { fprintf(stderr, "%s:%d: " msg, __FILENAME__, __LINE__, ##__VA_ARGS__); }
    #define warning(msg, ...) { fprintf(stderr, msg, ##__VA_ARGS__); }
    #define WARN_STUB fprintf(stderr, "Warning, stubbed function \"%s\".\n", __FUNCTION__);
#else
    #define fatal_error(msg, ...) { fprintf(stderr, "%s:%d: " msg, __FILENAME__, __LINE__, ##__VA_ARGS__); }
    #define warning(msg, ...) { fprintf(stderr, msg, ##__VA_ARGS__); }
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

#define MIN_FREE_MEM (48 * 1024 * 1024)

typedef int bionic_off_t; // 32bit off_t type (BIONIC quirk - see https://cs.android.com/android/platform/superproject/+/master:bionic/docs/32-bit-abi.md)
extern uint64_t get_available_physram();

#endif /* __PLATFORM_H__ */