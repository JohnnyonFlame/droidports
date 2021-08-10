
#ifndef __CTYPE_FAKE_H__
#define __CTYPE_FAKE_H__

/* ctype related fakes */

#include "platform.h"

#include <stdio.h>

extern const char  *BIONIC_ctype_;
extern const short *BIONIC_tolower_tab_;
extern const short *BIONIC_toupper_tab_;

ABI_ATTR extern int bridge_isalnum(int c);
ABI_ATTR extern int bridge_isalpha(int c);
ABI_ATTR extern int bridge_iscntrl(int c);
ABI_ATTR extern int bridge_isdigit(int c);
ABI_ATTR extern int bridge_isgraph(int c);
ABI_ATTR extern int bridge_islower(int c);
ABI_ATTR extern int bridge_isprint(int c);
ABI_ATTR extern int bridge_ispunct(int c);
ABI_ATTR extern int bridge_isspace(int c);
ABI_ATTR extern int bridge_isupper(int c);
ABI_ATTR extern int bridge_isxdigit(int c);
ABI_ATTR extern int bridge_tolower(int c);
ABI_ATTR extern int bridge_toupper(int c);
ABI_ATTR extern int bridge_isblank(int c);
ABI_ATTR extern int bridge_isascii(int c);
ABI_ATTR extern int bridge_toascii(int c);
ABI_ATTR extern int bridge__tolower(int c);
ABI_ATTR extern int bridge__toupper(int c);

#endif /* __CTYPE_FAKE_H__ */