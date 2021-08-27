#ifndef __STDIO_HOOKS_H__
#define __STDIO_HOOKS_H__

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <wchar.h>

/* "struct dirent" from bionic/libc/include/dirent.h */
struct bionic_dirent {
    uint64_t         d_ino;
    int64_t          d_off;
    unsigned short   d_reclen;
    unsigned char    d_type;
    char             d_name[256];
};

/* https://android.googlesource.com/platform/bionic/+/68dc20d41193831a94df04b994ff2f601dd38d10/libc/include/stdio.h */
/* stdio buffers */
#if defined(__LP64__)
struct BIONIC__sbuf {
  unsigned char* _base;
  size_t _size;
};
#else
struct BIONIC__sbuf {
	unsigned char *_base;
	int	_size;
};
#endif

typedef	struct BIONIC__sFILE {
	unsigned char *_p;	/* current position in (some) buffer */
	int	_r;		/* read space left for getc() */
	int	_w;		/* write space left for putc() */
#if defined(__LP64__)
	int	_flags;		/* flags, below; this FILE is free if 0 */
	int	_file;		/* fileno, if Unix descriptor, else -1 */
#else
	short	_flags;		/* flags, below; this FILE is free if 0 */
	short	_file;		/* fileno, if Unix descriptor, else -1 */
#endif
	struct	BIONIC__sbuf _bf;	/* the buffer (at least 1 byte, if !NULL) */
	int	_lbfsize;	/* 0 or -_bf._size, for inline putc */
	/* operations */
	void	*_cookie;	/* cookie passed to io functions */
	int	(*_close)(void *);
	int	(*_read)(void *, char *, int);
	fpos_t	(*_seek)(void *, fpos_t, int);
	int	(*_write)(void *, const char *, int);
	/* extension data, to avoid further ABI breakage */
	struct	BIONIC__sbuf _ext;
	/* data for long sequences of ungetc() */
	unsigned char *_up;	/* saved _p when _p is doing ungetc data */
	int	_ur;		/* saved _r when _r is counting ungetc data */
	/* tricks to meet minimum requirements even when malloc() fails */
	unsigned char _ubuf[3];	/* guarantee an ungetc() buffer */
	unsigned char _nbuf[1];	/* guarantee a getc() buffer */
	/* separate buffer for fgetln() when line crosses buffer boundary */
	struct	BIONIC__sbuf _lb;	/* buffer for fgetln() */
	/* Unix stdio files get aligned to block boundaries on fseek() */
	int	_blksize;	/* stat.st_blksize (may be != _bf._size) */
	fpos_t	_offset;	/* current lseek offset */
} BIONIC_FILE;

typedef struct BRIDGE_FILE {
    BIONIC_FILE fake;
    FILE *real;
} BRIDGE_FILE;

extern BIONIC_FILE __sF_fake[3];

#define RET_FILES return _get_from
#define RET_OTHER return
#define RET_VOID
#define RET_ZERO 0, 

/* 
    STDIO_DECL(name, sync, ret, ret_type, cast, vals, args):
    name: Bridged funciton's original name
    sync: Whether this function should update the BRIDGE_FILE _flags structure 
    ret: Return Macro
    ret_type: Function's return type
    cast: Macro that acquires the real file pointer from the bridged file
    vals: 
    args:
*/
#define STDIO_HOOKS                                                                                                                               \
    STDIO_DECL(clearerr,        0, RET_VOID,  void,     C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(feof,            0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(ferror,          0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(fflush,          0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(fgetc,           0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(fgetpos,         0, RET_OTHER, int,      C_FX,    V2, (BRIDGE_FILE * _arg1, fpos_t *restrict arg2))                                \
    STDIO_DECL(fgets,           0, RET_OTHER, char*,    C_XXF,   V3, (char * arg1, int arg2, BRIDGE_FILE * _arg3))                                \
    STDIO_DECL(fputc,           0, RET_OTHER, int,      C_XF,    V2, (int arg1, BRIDGE_FILE * _arg2))                                             \
    STDIO_DECL(fputs,           0, RET_OTHER, int,      C_XF,    V2, (const char * arg1, BRIDGE_FILE * _arg2))                                    \
    STDIO_DECL(fread,           1, RET_OTHER, size_t,   C_XXXF,  V4, (void * arg1, size_t arg2, size_t arg3, BRIDGE_FILE * _arg4))                \
    STDIO_DECL(fseek,           0, RET_OTHER, int,      C_FXX,   V3, (BRIDGE_FILE * _arg1, long arg2, int arg3))                                  \
    STDIO_DECL(fseeko,          0, RET_OTHER, int,      C_FXX,   V3, (BRIDGE_FILE * _arg1, off_t arg2, int arg3))                                 \
    STDIO_DECL(fsetpos,         0, RET_OTHER, int,      C_FX,    V2, (BRIDGE_FILE * _arg1, const fpos_t * arg2))                                  \
    STDIO_DECL(ftell,           0, RET_OTHER, long,     C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(ftello,          0, RET_OTHER, off_t,    C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(fwrite,          0, RET_OTHER, size_t,   C_XXXF,  V4, (const void * arg1, size_t arg2, size_t arg3, BRIDGE_FILE * _arg4))          \
    STDIO_DECL(getc,            0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(getdelim,        0, RET_OTHER, ssize_t,  C_XXXF,  V4, (char ** arg1, size_t * arg2, int arg3, BRIDGE_FILE * _arg4))                \
    STDIO_DECL(getline,         0, RET_OTHER, ssize_t,  C_XXF,   V3, (char ** arg1, size_t * arg2, BRIDGE_FILE * _arg3))                          \
    STDIO_DECL(putc,            0, RET_OTHER, int,      C_XF,    V2, (int arg1, BRIDGE_FILE * _arg2))                                             \
    STDIO_DECL(rewind,          0, RET_VOID,  void,     C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(setbuf,          0, RET_VOID,  void,     C_FX,    V2, (BRIDGE_FILE * _arg1, char * arg2))                                          \
    STDIO_DECL(setvbuf,         0, RET_OTHER, int,      C_FXXX,  V4, (BRIDGE_FILE * _arg1, char * arg2, int arg3, size_t arg4))                   \
    STDIO_DECL(ungetc,          0, RET_OTHER, int,      C_XF,    V2, (int arg1, BRIDGE_FILE * _arg2))                                             \
    STDIO_DECL(vfprintf,        0, RET_OTHER, int,      C_FXX,   V3, (BRIDGE_FILE * _arg1, const char * arg2, va_list arg3))                      \
    STDIO_DECL(vfscanf,         0, RET_OTHER, int,      C_FXX,   V3, (BRIDGE_FILE * _arg1, const char * arg2, va_list arg3))                      \
    STDIO_DECL(fileno,          0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    /* STDIO_DECL(pclose,          0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                  */\
    /* STDIO_DECL(flockfile,       0, RET_VOID,  void,     C_F,     V1, (BRIDGE_FILE * _arg1))                                                  */\
    /* STDIO_DECL(ftrylockfile,    0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                  */\
    /* STDIO_DECL(funlockfile,     0, RET_VOID,  void,     C_F,     V1, (BRIDGE_FILE * _arg1))                                                  */\
    STDIO_DECL(getc_unlocked,   0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(putc_unlocked,   0, RET_OTHER, int,      C_XF,    V2, (int arg1, BRIDGE_FILE * _arg2))                                             \
    STDIO_DECL(getw,            0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(putw,            0, RET_OTHER, int,      C_XF,    V2, (int arg1, BRIDGE_FILE * _arg2))                                             \
    STDIO_DECL(setbuffer,       0, RET_VOID,  void,     C_FXX,   V3, (BRIDGE_FILE * _arg1, char * arg2, int arg3))                                \
    STDIO_DECL(setlinebuf,      0, RET_ZERO,  int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    /* STDIO_DECL(endmntent,       0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                  */\
    STDIO_DECL(fputws,          0, RET_OTHER, int,      C_XF,    V2, (const wchar_t * arg1, BRIDGE_FILE * _arg2))                                 \
    STDIO_DECL(vfwprintf,       0, RET_OTHER, int,      C_FXX,   V3, (BRIDGE_FILE * _arg1, const wchar_t * arg2, va_list arg3))                   \
    STDIO_DECL(fputwc,          0, RET_OTHER, wint_t,   C_XF,    V2, (wchar_t arg1, BRIDGE_FILE * _arg2))                                         \
    STDIO_DECL(putwc,           0, RET_OTHER, wint_t,   C_XF,    V2, (wchar_t arg1, BRIDGE_FILE * _arg2))                                         \
    STDIO_DECL(fgetwc,          0, RET_OTHER, wint_t,   C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(getwc,           0, RET_OTHER, wint_t,   C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__fbufsize,      0, RET_OTHER, size_t,   C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__fpending,      0, RET_OTHER, size_t,   C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__flbf,          0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__freadable,     0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__fwritable,     0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__freading,      0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__fwriting,      0, RET_OTHER, int,      C_F,     V1, (BRIDGE_FILE * _arg1))                                                       \
    STDIO_DECL(__fsetlocking,   0, RET_OTHER, int,      C_FX,    V2, (BRIDGE_FILE * _arg1, int arg2))                                             \
    STDIO_DECL(__fpurge,        0, RET_VOID,  void,     C_F,     V1, (BRIDGE_FILE * _arg1))                                                       

    /* STDIO_DECL(setmntent,       RET_FILES, FILE *,          C_XX,    V2,   (const char * arg1, const char * arg2))                         */   \
    /* STDIO_DECL(getmntent,       RET_OTHER, struct mntent *, C_F,     V1,    (FILE * _arg1))                                                 */  \
    /* STDIO_DECL(getmntent_r,     RET_OTHER, struct mntent *, C_FXXX,  V4, (FILE * _arg1, struct mntent * arg2, char * arg3, int arg4))    */     \
    /* STDIO_DECL(fgetln,          RET_OTHER, char*,           C_FX,    V2,   (FILE * _arg1, size_t * arg2))                                   */  \
    /* STDIO_DECL(fpurge,          RET_OTHER, int,             C_F,     V1,    (FILE * _arg1))                                                  */ \

// Casts
#define C_F    FILE *fp, *arg1 = fp = _get_from(_arg1);
#define C_XX   FILE *fp = NULL;
#define C_XF   FILE *fp, *arg2 = fp = _get_from(_arg2);
#define C_FX   FILE *fp, *arg1 = fp = _get_from(_arg1);
#define C_XXF  FILE *fp, *arg3 = fp = _get_from(_arg3);
#define C_FXX  FILE *fp, *arg1 = fp = _get_from(_arg1);
#define C_XXXF FILE *fp, *arg4 = fp = _get_from(_arg4);
#define C_FXXX FILE *fp, *arg1 = fp = _get_from(_arg1);

#define STDIO_DECL(name, f, ret, ret_type, cast, vals, args) \
    ABI_ATTR extern ret_type bridge_##name args;
STDIO_HOOKS
#undef STDIO_DECL

ABI_ATTR extern BRIDGE_FILE *bridge_fopen(const char *arg1, const char* arg2);
ABI_ATTR extern BRIDGE_FILE *bridge_freopen(const char * arg1, const char * arg2, BRIDGE_FILE * _arg3);
ABI_ATTR extern int bridge_fclose(BRIDGE_FILE * _arg1);
ABI_ATTR extern int bridge_fscanf(BRIDGE_FILE *fp, const char *fmt, ...);
ABI_ATTR extern int bridge_fprintf(BRIDGE_FILE *fp, const char *fmt, ...);
ABI_ATTR extern int bridge_printf(const char *fmt, ...);
ABI_ATTR extern int bridge_sprintf(char *s, const char *fmt, ...);
ABI_ATTR extern int bridge_snprintf(char *s, int max, const char *fmt, ...);
ABI_ATTR extern int bridge_vsnprintf(char *s, int max, const char *fmt, va_list va);
ABI_ATTR extern int bridge_vsprintf(char *s, const char *fmt, va_list va);
ABI_ATTR extern int bridge_vasprintf(char **s, const char *fmt, ...);
ABI_ATTR extern int bridge_sscanf(const char *str, const char *fmt, ...);
ABI_ATTR extern int bridge_vprintf(const char *fmt, va_list ap);
ABI_ATTR extern int _hybris_hook_scandirat(int fd, const char *dir,
                      struct bionic_dirent ***namelist,
                      int (*filter) (const struct bionic_dirent *),
                      int (*compar) (const struct bionic_dirent **,
                                     const struct bionic_dirent **));
ABI_ATTR extern int _hybris_hook_scandir(const char *dir,
                      struct bionic_dirent ***namelist,
                      int (*filter) (const struct bionic_dirent *),
                      int (*compar) (const struct bionic_dirent **,
                                     const struct bionic_dirent **));

#endif /* __STDIO_HOOKS_H__ */