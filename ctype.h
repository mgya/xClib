#ifndef _CTYPE_H_
#define _CTYPE_H_

#include <xC/xcharacter.h>
#include <xC/xboolean.h>

#define isalnum(c)      ctype_isalnum(c)
#define isalpha(c)      ctype_isalpha(c)
#define isblank(c)      ctype_isblank(c)
#define iscntrl(c)      ctype_iscntrl(c)
#define isdigit(c)      ctype_isdigit(c)
#define isgraph(c)      ctype_isgraph(c)
#define islower(c)      ctype_islower(c)
#define isprint(c)      ctype_isprint(c)
#define ispunct(c)      ctype_ispunct(c)
#define isspace(c)      ctype_isspace(c)
#define isupper(c)      ctype_isupper(c)
#define isxdigit(c)     ctype_isxdigit(c)
#define tolower(c)      ctype_tolower(c)
#define toupper(c)      ctype_toupper(c)

#define iswalnum(w)     ctype_iswalnum(w)
#define iswalpha(w)     ctype_iswalpha(w)
#define iswblank(w)     ctype_iswblank(w)
#define iswcntrl(w)     ctype_iswcntrl(w)
#define iswdigit(w)     ctype_iswdigit(w)
#define iswgraph(w)     ctype_iswgraph(w)
#define iswlower(w)     ctype_iswlower(w)
#define iswprint(w)     ctype_iswprint(w)
#define iswpunct(w)     ctype_iswpunct(w)
#define iswspace(w)     ctype_iswspace(w)
#define iswupper(w)     ctype_iswupper(w)
#define iswxdigit(w)    ctype_iswxdigit(w)
#define towlower(w)     ctype_towlower(w)
#define towupper(w)     ctype_towupper(w)

#ifdef __cplusplus
extern "C" {
#endif

xbool_t ctype_isalnum(char);
xbool_t ctype_isalpha(char);
xbool_t ctype_isblank(char);
xbool_t ctype_iscntrl(char);
xbool_t ctype_isdigit(char);
xbool_t ctype_isgraph(char);
xbool_t ctype_islower(char);
xbool_t ctype_isprint(char);
xbool_t ctype_ispunct(char);
xbool_t ctype_isspace(char);
xbool_t ctype_isupper(char);
xbool_t ctype_isxdigit(char);
char ctype_tolower(char);
char ctype_toupper(char);

xbool_t ctype_iswalnum(xwchar_t);
xbool_t ctype_iswalpha(xwchar_t);
xbool_t ctype_iswblank(xwchar_t);
xbool_t ctype_iswcntrl(xwchar_t);
xbool_t ctype_iswdigit(xwchar_t);
xbool_t ctype_iswgraph(xwchar_t);
xbool_t ctype_iswlower(xwchar_t);
xbool_t ctype_iswprint(xwchar_t);
xbool_t ctype_iswpunct(xwchar_t);
xbool_t ctype_iswspace(xwchar_t);
xbool_t ctype_iswupper(xwchar_t);
xbool_t ctype_iswxdigit(xwchar_t);
xwchar_t ctype_towlower(xwchar_t);
xwchar_t ctype_towupper(xwchar_t);

#ifdef __cplusplus
}
#endif

#endif /* _CTYPE_H_ */


