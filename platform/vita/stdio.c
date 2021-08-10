#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>

//void vgl_file_log(const char *format, ...) {
//	__gnuc_va_list arg;
//	va_start(arg, format);
//	char msg[512];
//	vsprintf(msg, format, arg);
//	va_end(arg);
//	FILE *log = fopen("ux0:/data/gmloader.log", "a+");
//	if (log != NULL) {
//		fwrite(msg, 1, strlen(msg), log);
//		fclose(log);
//	}
//}

int mkdir(const char *pathname, mode_t mode) {
  // debugPrintf("mkdir: %s\n", pathname);
  if (sceIoMkdir(pathname, mode) < 0)
    return -1;
  return 0;
}

// Only used in ReadALConfig
char *getenv(const char *name) {
  return NULL;
}

int __set_errno(int n)
{
    errno = n;
}

char *basename(const char *s)
{
    extern char *__gnu_basename(const char *s);
    return __gnu_basename(s);
}

// From https://github.com/kraj/uClibc/blob/master/libc/misc/dirent/scandir.c
int scandir(const char *dir, struct dirent ***namelist,
	int (*selector) (const struct dirent *),
	int (*compar) (const struct dirent **, const struct dirent **))
{
    DIR *dp = opendir (dir);
    struct dirent *current;
    struct dirent **names = NULL;
    size_t names_size = 0, pos;
    int save;

    if (dp == NULL)
	return -1;

    save = errno;
    __set_errno (0);

    pos = 0;
    while ((current = readdir (dp)) != NULL) {
	int use_it = selector == NULL;

	if (! use_it)
	{
	    use_it = (*selector) (current);
	    /* The selector function might have changed errno.
	     * It was zero before and it need to be again to make
	     * the latter tests work.  */
	    if (! use_it)
		__set_errno (0);
	}
	if (use_it)
	{
	    struct dirent *vnew;
	    size_t dsize;

	    /* Ignore errors from selector or readdir */
	    __set_errno (0);

	    if (pos == names_size)
	    {
		struct dirent **new;
		if (names_size == 0)
		    names_size = 10;
		else
		    names_size *= 2;
		new = (struct dirent **) realloc (names,
					names_size * sizeof (struct dirent *));
		if (new == NULL)
		    break;
		names = new;
	    }

	    dsize = &current->d_name[256+1] - (char*)current;
	    vnew = (struct dirent *) malloc (dsize);
	    if (vnew == NULL)
		break;

	    names[pos++] = (struct dirent *) memcpy (vnew, current, dsize);
	}
    }

    if (errno != 0)
    {
	save = errno;
	closedir (dp);
	while (pos > 0)
	    free (names[--pos]);
	free (names);
	__set_errno (save);
	return -1;
    }

    closedir (dp);
    __set_errno (save);

    /* Sort the list if we have a comparison function to sort with.  */
    if (compar != NULL)
	qsort (names, pos, sizeof (struct dirent *), (__compar_fn_t) compar);
    *namelist = names;
    return pos;
}

int scandirat(int dirfd, const char *dir, struct dirent ***namelist,
              int (*sel)(const struct dirent *),
              int (*cmp)(const struct dirent **, const struct dirent **))
{
    return scandir(dir, namelist, sel, cmp);
}

ssize_t getdelim(char **d, size_t *sz, int n, FILE *f)
{
    return __getdelim(d, sz, n, f);
}

ssize_t getline(char **s, size_t *sz, FILE *f)
{
    return __getline(s, sz, f);
}