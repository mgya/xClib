#ifndef _CTYPE_H_
#define _CTYPE_H_

#include "../system/character.h"
#include "../system/boolean.h"

#define isalnum(c)      tr_isalnum(c)
#define isalpha(c)      tr_isalpha(c)
#define isblank(c)      tr_isblank(c)
#define iscntrl(c)      tr_iscntrl(c)
#define isdigit(c)      tr_isdigit(c)
#define isgraph(c)      tr_isgraph(c)
#define islower(c)      tr_islower(c)
#define isprint(c)      tr_isprint(c)
#define ispunct(c)      tr_ispunct(c)
#define isspace(c)      tr_isspace(c)
#define isupper(c)      tr_isupper(c)
#define isxdigit(c)     tr_isxdigit(c)
#define tolower(c)      tr_tolower(c)
#define toupper(c)      tr_toupper(c)

#define iswalnum(w)     tr_iswalnum(w)
#define iswalpha(w)     tr_iswalpha(w)
#define iswblank(w)     tr_iswblank(w)
#define iswcntrl(w)     tr_iswcntrl(w)
#define iswdigit(w)     tr_iswdigit(w)
#define iswgraph(w)     tr_iswgraph(w)
#define iswlower(w)     tr_iswlower(w)
#define iswprint(w)     tr_iswprint(w)
#define iswpunct(w)     tr_iswpunct(w)
#define iswspace(w)     tr_iswspace(w)
#define iswupper(w)     tr_iswupper(w)
#define iswxdigit(w)    tr_iswxdigit(w)
#define towlower(w)     tr_towlower(w)
#define towupper(w)     tr_towupper(w)

#ifdef __cplusplus
extern "C" {
#endif

bool tr_isalnum(char);
bool tr_isalpha(char);
bool tr_isblank(char);
bool tr_iscntrl(char);
bool tr_isdigit(char);
bool tr_isgraph(char);
bool tr_islower(char);
bool tr_isprint(char);
bool tr_ispunct(char);
bool tr_isspace(char);
bool tr_isupper(char);
bool tr_isxdigit(char);
char tr_tolower(char);
char tr_toupper(char);

bool tr_iswalnum(wchar);
bool tr_iswalpha(wchar);
bool tr_iswblank(wchar);
bool tr_iswcntrl(wchar);
bool tr_iswdigit(wchar);
bool tr_iswgraph(wchar);
bool tr_iswlower(wchar);
bool tr_iswprint(wchar);
bool tr_iswpunct(wchar);
bool tr_iswspace(wchar);
bool tr_iswupper(wchar);
bool tr_iswxdigit(wchar);
wchar tr_towlower(wchar);
wchar tr_towupper(wchar);

#ifdef __cplusplus
}
#endif

#endif /* _CTYPE_H_ */


