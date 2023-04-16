#include <dirent.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 

#include "platform.h"
#include "stdio_bridge.h"
#include "so_util.h"

BIONIC_FILE __sF_fake[3] = {};

static FILE *_get_from(BRIDGE_FILE *fp)
{
    if (&__sF_fake[0] == (BIONIC_FILE*)fp)
        return stdin;
    else if (&__sF_fake[1] == (BIONIC_FILE*)fp)
        return stdout;
    else if (&__sF_fake[2] == (BIONIC_FILE*)fp)
        return stderr;
        
    return fp->real;
}

/*
static FILE *_get_to(FILE *fp)
{
    return fp;
}
*/

/*
    DETAILS::
    f: Flags if this hooked function should update the internal flags
    #define __SEOF 0x0020  // Found EOF.
    #define __SERR 0x0040  // Found error.
    Implementation::
    All bridges will return a bridge file pointer, that points towards a
    structure containing the guts of a Bionic file pointer plus a pointer
    for the real pointer.
*/

// Value Lists
#define V1 arg1
#define V2 arg1, arg2
#define V3 arg1, arg2, arg3
#define V4 arg1, arg2, arg3, arg4

#define STDIO_DECL(name, f, ret, ret_type, cast, vals, args)           \
    ABI_ATTR ret_type bridge_##name args                              \
    {                                                                  \
        cast                                                           \
        ret (name(vals));                                              \
        /* Set internal flags on the BIONIC FILE structure */          \
        if (f && fp) fp->_flags = (feof(fp)   << 5)                    \
                                | (ferror(fp) << 6);                   \
    }

STDIO_HOOKS
#undef STDIO_DECL

ABI_ATTR extern BRIDGE_FILE *bridge_fopen(const char *arg1, const char* arg2)
{
    FILE *f = fopen(arg1, arg2);
    if (!f)
        return NULL;

    BRIDGE_FILE *bridge = (BRIDGE_FILE*)calloc(1, sizeof(BRIDGE_FILE));
    bridge->real = f;
    return bridge;
}

ABI_ATTR extern BRIDGE_FILE *bridge_freopen(const char * arg1, const char * arg2, BRIDGE_FILE * _arg3)
{
    FILE *arg3 = _get_from(_arg3);
    _arg3->real = freopen(arg1, arg2, arg3);
    if (!_arg3->real) {
        free(_arg3);
        return NULL;
    }

    return _arg3;
}

ABI_ATTR extern int bridge_fclose(BRIDGE_FILE * _arg1)
{
    int ret;
    FILE *arg1 = _get_from(_arg1);
    ret = fclose(arg1);
    free(_arg1);

    return ret;
}

ABI_ATTR int bridge_fscanf(BRIDGE_FILE *fp, const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    int ret = vfscanf(_get_from(fp), fmt, va);
    va_end(va);

    return ret;
}

ABI_ATTR int bridge_fprintf(BRIDGE_FILE *fp, const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    int ret = vfprintf(_get_from(fp), fmt, va);
    va_end(va);

    return ret;
}

ABI_ATTR int bridge_printf(const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = vprintf(fmt, va);
    va_end(va);

    return ret;
}

ABI_ATTR int bridge_sprintf(char *s, const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = vsprintf(s, fmt, va);
    va_end(va);

    return ret;
}

ABI_ATTR int bridge_snprintf(char *s, int max, const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = vsnprintf(s, max, fmt, va);
    va_end(va);

    return ret;
}

ABI_ATTR int bridge_vsnprintf(char *s, int max, const char *fmt, va_list va)
{
    int ret;
    ret = vsnprintf(s, max, fmt, va);

    return ret;
}

ABI_ATTR int bridge_vsprintf(char *s, const char *fmt, va_list va)
{
    int ret;
    ret = vsprintf(s, fmt, va);
    return ret;
}

ABI_ATTR int bridge___vsprintf_chk(char * s, int flag, size_t slen, const char * format, va_list args)
{
    return __vsprintf_chk(s, flag, slen, format, args);
}

ABI_ATTR int bridge_vasprintf(char **s, const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = vasprintf(s, fmt, va);
    va_end(va);

    return ret;
}

ABI_ATTR int bridge_sscanf(const char *str, const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = vsscanf(str, fmt, va);
    va_end(va);

    return ret;
}

ABI_ATTR int bridge_vprintf(const char *fmt, va_list ap)
{
    return vprintf(fmt, ap);
}

// Taken from https://github.com/libhybris/libhybris/blob/master/hybris/common/hooks.c
ABI_ATTR int _hybris_hook_scandirat(int fd, const char *dir,
                      struct bionic_dirent ***namelist,
                      int (*filter) (const struct bionic_dirent *),
                      int (*compar) (const struct bionic_dirent **,
                                     const struct bionic_dirent **))
{
    struct dirent **namelist_r;
    struct bionic_dirent **result;
    struct bionic_dirent *filter_r;

    int i = 0;
    size_t nItems = 0;

    int res = scandirat(fd, dir, &namelist_r, NULL, NULL);

    if (res > 0 && namelist_r != NULL) {

        result = malloc(res * sizeof(struct bionic_dirent));
        if (!result)
            return -1;

        for (i = 0; i < res; i++) {
            filter_r = malloc(sizeof(struct bionic_dirent));
            if (!filter_r) {
                while (i-- > 0)
                    free(result[i]);
                free(result);
                return -1;
            }

            filter_r->d_ino = namelist_r[i]->d_ino;
            filter_r->d_off = namelist_r[i]->d_off;
            filter_r->d_reclen = namelist_r[i]->d_reclen;
            filter_r->d_type = namelist_r[i]->d_type;

            strcpy(filter_r->d_name, namelist_r[i]->d_name);
            filter_r->d_name[sizeof(namelist_r[i]->d_name) - 1] = '\0';

            if (filter != NULL && !(*filter)(filter_r)) {//apply filter
                free(filter_r);
                continue;
            }

            result[nItems++] = filter_r;
        }
        
        if (nItems && compar != NULL) // sort
            qsort(result, nItems, sizeof(struct bionic_dirent *), (__compar_fn_t)compar);

        *namelist = result;
    } else {
        return res;
    }

    return nItems;
}

ABI_ATTR int _hybris_hook_scandir(const char *dir,
                      struct bionic_dirent ***namelist,
                      int (*filter) (const struct bionic_dirent *),
                      int (*compar) (const struct bionic_dirent **,
                                     const struct bionic_dirent **))
{
    return _hybris_hook_scandirat(AT_FDCWD, dir, namelist, filter, compar);
}

extern void *__memcpy_chk;
extern void *__memmove_chk;
extern void *__memset_chk;
extern void *__strcat_chk;
extern void *__strcpy_chk;
extern void *__strlcat_chk;
extern void *__strlcpy_chk;
extern void *__strlen_chk;
extern void *__strrchr_chk;

ABI_ATTR char *__strncat_chk_impl(char *s1, const char *s2, size_t n, size_t s1len) {
	return strncat(s1, s2, n);
}

size_t
strlcat(char * restrict dst, const char * restrict src, size_t maxlen) {
    const size_t srclen = strlen(src);
    const size_t dstlen = strnlen(dst, maxlen);
    if (dstlen == maxlen) return maxlen+srclen;
    if (srclen < maxlen-dstlen) {
        memcpy(dst+dstlen, src, srclen+1);
    } else {
        memcpy(dst+dstlen, src, maxlen-1);
        dst[dstlen+maxlen-1] = '\0';
    }
    return dstlen + srclen;
}

size_t
strlcpy(char * restrict dst, const char * restrict src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen < maxlen) {
        memcpy(dst, src, srclen+1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen-1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}

char* __strchr_chk_impl(const char* p, int ch, size_t s_len) {
	return strchr(p, ch);
}

ABI_ATTR char *__strrchr_chk_impl(const char *p, int ch, size_t s_len) {
	return strrchr(p, ch);
}

ABI_ATTR char *__strcpy_chk_impl(char *dest, const char *src, size_t destlen) {
	return strcpy(dest, src);
}

ABI_ATTR size_t __strlcat_chk_impl(char *dest, char *src, size_t len, size_t dstlen) {
	return strlcat(dest, src, len);
}

ABI_ATTR size_t __strlen_chk_impl(const char *s, size_t s_len) {
	return strlen(s);
}

ABI_ATTR size_t __strlcpy_chk_impl(char *dest, char *src, size_t len, size_t dstlen) {
	return strlcpy(dest, src, len);
}

DynLibFunction symtable_stdio[] = {
    #define STDIO_DECL(name, f, ret, ret_type, cast, vals, args) {#name, (uintptr_t)&bridge_##name},
    STDIO_HOOKS
    #undef STDIO_DECL
    {"__sF", (uintptr_t)&__sF_fake},
    {"bsearch", (uintptr_t)&bsearch},
    {"fopen", (uintptr_t)&bridge_fopen},
    {"freopen", (uintptr_t)&bridge_freopen},
    {"fclose", (uintptr_t)&bridge_fclose},
    {"fscanf", (uintptr_t)&bridge_fscanf},
    {"fprintf", (uintptr_t)&bridge_fprintf},
    {"printf", (uintptr_t)&bridge_printf},
    {"sprintf", (uintptr_t)&bridge_sprintf},
    {"snprintf", (uintptr_t)&bridge_snprintf},
    {"vsnprintf", (uintptr_t)&bridge_vsnprintf},
    {"vsprintf", (uintptr_t)&bridge_vsprintf},
	{"__strchr_chk", (uintptr_t)&__strchr_chk_impl },
	{"__strcpy_chk", (uintptr_t)&__strcpy_chk_impl },
	{"__strlcat_chk", (uintptr_t)&__strlcat_chk_impl },
	{"__strlen_chk", (uintptr_t)&__strlen_chk_impl },
	{"__strrchr_chk", (uintptr_t)&__strrchr_chk_impl },
	{"__strncat_chk", (uintptr_t)&__strncat_chk_impl },
	{"__strlcpy_chk", (uintptr_t)&__strlcpy_chk_impl },
    {"__memcpy_chk", (uintptr_t)&__memcpy_chk },
	{"__memmove_chk", (uintptr_t)&__memmove_chk },
	{"__memset_chk", (uintptr_t)&__memset_chk },
	{"__strcat_chk", (uintptr_t)&__strcat_chk },
	{"__vsprintf_chk", (uintptr_t)&__vsprintf_chk },
	{"__vsnprintf_chk", (uintptr_t)&__vsnprintf_chk },
    {"vasprintf", (uintptr_t)&bridge_vasprintf},
    {"sscanf", (uintptr_t)&bridge_sscanf},
    {"vprintf", (uintptr_t)&bridge_vprintf},
    {"mkdir", (uintptr_t)&mkdir},
    {"stat", (uintptr_t)&stat},
    {"scandir", (uintptr_t)&_hybris_hook_scandir},
    {"scandirat", (uintptr_t)&_hybris_hook_scandirat},
    
    {NULL, (uintptr_t)NULL}
};