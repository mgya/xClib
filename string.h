#ifndef _STRING_H_
#define _STRING_H_

#include "../system/character.h"
#include "../system/pointer.h"
#include "../system/integer.h"
#include "../system/varargsex.h"

#define ffs(d)                  tr_ffs(d)
#define utftouni(pc,s1,pw,s2)   tr_utftouni((pc),(s1),(pw),(s2))
#define unitoutf(pw,s1,pc,s2)   tr_unitoutf((pw),(s1),(pc),(s2))
#define strdup(pv)              tr_strdup(pv)
#define strcat(pv1,pv2)         tr_strcat((pv1),(pv2))
#define strchr(pv1,pv2)         tr_strchr((pv1),(pv2))
#define strcmp(pc1,pc2)         tr_strcmp((pc1),(pc2))
#define stricmp(pc1,pc2)        tr_stricmp((pc1),(pc2))
#define strcpy(pc1,pc2)         tr_strcpy((pc1),(pc2))
#define strcspn(pc1,pc2)        tr_strcspn((pc1),(pc2))
#define strlen(pc1)             tr_strlen(pc1)
#define strncat(pc1,pc2,s)      tr_strncat((pc1),(pc2),(s))
#define strncmp(pc1,pc2,s)      tr_strncmp((pc1),(pc2),(s))
#define strnicmp(pc1,pc2,s)     tr_strnicmp((pc1),(pc2),(s))
#define strncpy(pc1,pc2,s)      tr_strncpy((pc1),(pc2),(s))
#define strrchr(pc1,pc2)        tr_strrchr((pc1),(pc2))
#define strspn(pc1,pc2)         tr_strspn((pc1),(pc2))
#define strpbrk(pc1,pc2)        tr_strpbrk((pc1),(pc2))
#define strstr(pc1,pc2)         tr_strstr((pc1),(pc2))
#define wcsdup(pw)              tr_wcsdup(pw)
#define wcscat(pw1,pw2)         tr_wcscat((pw1),(pw2))
#define wcschr(pw1,pw2)         tr_wcschr((pw1),(pw2))
#define wcscmp(pw1,pw2)         tr_wcscmp((pw1),(pw2))
#define wcsicmp(pw1,pw2)        tr_wcsicmp((pw1),(pw2))
#define wcscpy(pw1,pw2)         tr_wcscpy((pw1),(pw2))
#define wcscspn(pw1,pw2)        tr_wcscspn((pw1),(pw2))
#define wcslen(pw)              tr_wcslen(pw)
#define wcsncat(pw1,pw2,s)      tr_wcsncat((pw1),(pw2),(s))
#define wcsncmp(pw1,pw2,s)      tr_wcsncmp((pw1),(pw2),(s))
#define wcsnicmp(pw1,pw2,s)     tr_wcsnicmp((pw1),(pw2),(s))
#define wcsncpy(pw1,pw2,s)      tr_wcsncpy((pw1),(pw2),(s))
#define wcsrchr(pw,w)           tr_wcsrchr((pw),(w))
#define wcsspn(pw1,pw2)         tr_wcsspn((pw1),(pw2))
#define wcspbrk(pw1,pw2)        tr_wcspbrk((pw1),(pw2))
#define wcsstr(pw1,pw2)         tr_wcsstr((pw1),(pw2))
#define strtoi(pc,ppc,i)        tr_strtoi((pc),(ppc),(i))
#define strtol(pc,ppc,i)        tr_strtol((pc),(ppc),(i))
#define strtoui(pc,ppc,i)       tr_strtoui((pc),(ppc),(i))
#define strtoul(pc,ppc,i)       tr_strtoul((pc),(ppc),(i))
#define strtod(pc,ppc)          tr_strtod((pc),(ppc))
#define strtold(pc,ppc)         tr_strtold((pc),(ppc))
#define wcstoi(pw,ppw,i)        tr_wcstoi((pw),(ppw),(i))
#define wcstol(pw,ppw,i)        tr_wcstol((pw),(ppw),(i))
#define wcstoui(pw,ppw,i)       tr_wcstoui((pw),(ppw),(i))
#define wcstoul(pw,ppw,i)       tr_wcstoul((pw),(ppw),(i))
#define wcstod(pw,ppw)          tr_wcstod((pw),(ppw))
#define wcstold(pw,ppw)         tr_wcstold((pw),(ppw))

#define sprintf         tr_sprintf
#define snprintf        tr_snprintf
#define vsprintf        tr_vsprintf
#define vsnprintf       tr_vsnprintf
#define wsprintf        tr_wsprintf
#define wsnprintf       tr_wsnprintf
#define vwsprintf       tr_vwsprintf
#define vwsnprintf      tr_vwsnprintf

#ifdef __cplusplus
extern "C" {
#endif

int tr_ffs(int);
size_t tr_utftouni(const char *, size_t, wchar *, size_t);
size_t tr_unitoutf(const wchar *, size_t, char *, size_t);
char * tr_strdup(const char *);
char * tr_strcat(char *, const char *);
const char * tr_strchr(const char *, char);
int tr_strcmp(const char *, const char *);
int tr_stricmp(const char *, const char *);
char * tr_strcpy(char *, const char *);
size_t tr_strcspn(const char *, const char *);
size_t tr_strlen(const char *);
char * tr_strncat(char *, const char *, size_t);
int tr_strncmp(const char *, const char *, size_t);
int tr_strnicmp(const char *, const char *, size_t);
char * tr_strncpy(char *, const char *, size_t);
const char * tr_strrchr(const char *, char);
size_t tr_strspn(const char *, const char *);
char * tr_strpbrk(const char *, const char *);
const char * tr_strstr(const char *, const char *);
wchar * tr_wcsdup(const wchar *);
wchar * tr_wcscat(wchar *, const wchar *);
const wchar * tr_wcschr(const wchar *, wchar);
int tr_wcscmp(const wchar *, const wchar *);
int tr_wcsicmp(const wchar *, const wchar *);
wchar * tr_wcscpy(wchar *, const wchar *);
size_t tr_wcscspn(const wchar *, const wchar *);
size_t tr_wcslen(const wchar *);
wchar * tr_wcsncat(wchar *, const wchar *, size_t);
int tr_wcsncmp(const wchar *, const wchar *, size_t);
int tr_wcsnicmp(const wchar *, const wchar *, size_t);
wchar * tr_wcsncpy(wchar *, const wchar *, size_t);
const wchar * tr_wcsrchr(const wchar *, wchar);
size_t tr_wcsspn(const wchar *, const wchar *);
wchar * tr_wcspbrk(const wchar *, const wchar *);
const wchar * tr_wcsstr(const wchar *, const wchar *);
int tr_strtoi(const char *, char **, int);
int64_t tr_strtol(const char *, char **, int);
unsigned int tr_strtoui(const char *, char **, int);
uint64_t tr_strtoul(const char *, char **, int);
double tr_strtod(const char *, char **);
long double tr_strtold(const char *, char **);
int tr_wcstoi(const wchar *, wchar **, int);
int64_t tr_wcstol(const wchar *, wchar **, int);
unsigned int tr_wcstoui(const wchar *, wchar **, int);
uint64_t tr_wcstoul(const wchar *, wchar **, int);
double tr_wcstod(const wchar *, wchar **);
long double tr_wcstold(const wchar *, wchar **);
int tr_sprintf(char *, const char *, ...);
int tr_snprintf(char *, size_t, const char *, ...);
int tr_vsprintf(char *, const char *, va_list);
int tr_vsnprintf(char *, size_t, const char *, va_list);
int tr_wsprintf(wchar *, const wchar *, ...);
int tr_wsnprintf(wchar *, size_t, const wchar *, ...);
int tr_vwsprintf(wchar *, const wchar *, va_list);
int tr_vwsnprintf(wchar *, size_t, const wchar *, va_list);

#ifdef __cplusplus
}
#endif

#endif /* _STRING_H_ */


