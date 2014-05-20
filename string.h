#ifndef _STRING_H_
#define _STRING_H_

#include <xC/xcharacter.h>
#include <xC/xpointer.h>
#include <xC/xinteger.h>
#include <xC/xvarargs.h>

#define ffs(d)                        string_ffs(d)
#define utftouni(pc,s1,pw,s2)         string_utftouni((pc),(s1),(pw),(s2))
#define unitoutf(pw,s1,pc,s2)         string_unitoutf((pw),(s1),(pc),(s2))
#define strdup(pv)                    string_strdup(pv)
#define strcat(pv1,pv2)               string_strcat((pv1),(pv2))
#define strchr(pv1,pv2)               string_strchr((pv1),(pv2))
#define strcmp(pc1,pc2)               string_strcmp((pc1),(pc2))
#define stricmp(pc1,pc2)              string_stricmp((pc1),(pc2))
#define strcpy(pc1,pc2)               string_strcpy((pc1),(pc2))
#define strcspn(pc1,pc2)              string_strcspn((pc1),(pc2))
#define strlen(pc1)                   string_strlen(pc1)
#define strncat(pc1,pc2,s)            string_strncat((pc1),(pc2),(s))
#define strncmp(pc1,pc2,s)            string_strncmp((pc1),(pc2),(s))
#define strnicmp(pc1,pc2,s)           string_strnicmp((pc1),(pc2),(s))
#define strncpy(pc1,pc2,s)            string_strncpy((pc1),(pc2),(s))
#define strrchr(pc1,pc2)              string_strrchr((pc1),(pc2))
#define strspn(pc1,pc2)               string_strspn((pc1),(pc2))
#define strpbrk(pc1,pc2)              string_strpbrk((pc1),(pc2))
#define strstr(pc1,pc2)               string_strstr((pc1),(pc2))
#define wcsdup(pw)                    string_wcsdup(pw)
#define wcscat(pw1,pw2)               string_wcscat((pw1),(pw2))
#define wcschr(pw1,pw2)               string_wcschr((pw1),(pw2))
#define wcscmp(pw1,pw2)               string_wcscmp((pw1),(pw2))
#define wcsicmp(pw1,pw2)              string_wcsicmp((pw1),(pw2))
#define wcscpy(pw1,pw2)               string_wcscpy((pw1),(pw2))
#define wcscspn(pw1,pw2)              string_wcscspn((pw1),(pw2))
#define wcslen(pw)                    string_wcslen(pw)
#define wcsncat(pw1,pw2,s)            string_wcsncat((pw1),(pw2),(s))
#define wcsncmp(pw1,pw2,s)            string_wcsncmp((pw1),(pw2),(s))
#define wcsnicmp(pw1,pw2,s)           string_wcsnicmp((pw1),(pw2),(s))
#define wcsncpy(pw1,pw2,s)            string_wcsncpy((pw1),(pw2),(s))
#define wcsrchr(pw,w)                 string_wcsrchr((pw),(w))
#define wcsspn(pw1,pw2)               string_wcsspn((pw1),(pw2))
#define wcspbrk(pw1,pw2)              string_wcspbrk((pw1),(pw2))
#define wcsstr(pw1,pw2)               string_wcsstr((pw1),(pw2))
#define strtoi(pc,ppc,i)              string_strtoi((pc),(ppc),(i))
#define strtol(pc,ppc,i)              string_strtol((pc),(ppc),(i))
#define strtoui(pc,ppc,i)             string_strtoui((pc),(ppc),(i))
#define strtoul(pc,ppc,i)             string_strtoul((pc),(ppc),(i))
#define strtod(pc,ppc)                string_strtod((pc),(ppc))
#define strtold(pc,ppc)               string_strtold((pc),(ppc))
#define wcstoi(pw,ppw,i)              string_wcstoi((pw),(ppw),(i))
#define wcstol(pw,ppw,i)              string_wcstol((pw),(ppw),(i))
#define wcstoui(pw,ppw,i)             string_wcstoui((pw),(ppw),(i))
#define wcstoul(pw,ppw,i)             string_wcstoul((pw),(ppw),(i))
#define wcstod(pw,ppw)                string_wcstod((pw),(ppw))
#define wcstold(pw,ppw)               string_wcstold((pw),(ppw))

#define sprintf(pc1,pc2,...)          string_sprintf((pc1),(pc2),__VA_ARGS__)
#define snprintf(pc1,s,pc2,...)       string_snprintf((pc1),(s),(pc2),__VA_ARGS__)
#define vsprintf(pc1,pc2,ls)          string_vsprintf((pc1),(pc2),(ls))
#define vsnprintf(pc1,s,pc2,ls)       string_vsnprintf((pc1),(s),(pc2),(ls))
#define wsprintf(pw1,pw2,...)         string_wsprintf((pw1),(pw2),__VA_ARGS__)
#define wsnprintf(pw1,s,pw2,...)      string_wsnprintf((pw1),(s),(pw2),__VA_ARGS__)
#define vwsprintf(pw1,pw2,ls)         string_vwsprintf((pw1),(pw2),(ls))
#define vwsnprintf(pw1,s,pw2,ls)      string_vwsnprintf((pw1),(s),(pw2),(ls))

#ifdef __cplusplus
extern "C" {
#endif

int string_ffs(int);
xsize_t string_utftouni(const char *, xsize_t, xwchar_t *, xsize_t);
xsize_t string_unitoutf(const xwchar_t *, xsize_t, char *, xsize_t);
char * string_strdup(const char *);
char * string_strcat(char *, const char *);
char * string_strchr(const char *, char);
int string_strcmp(const char *, const char *);
int string_stricmp(const char *, const char *);
char * string_strcpy(char *, const char *);
xsize_t string_strcspn(const char *, const char *);
xsize_t string_strlen(const char *);
char * string_strncat(char *, const char *, xsize_t);
int string_strncmp(const char *, const char *, xsize_t);
int string_strnicmp(const char *, const char *, xsize_t);
char * string_strncpy(char *, const char *, xsize_t);
char * string_strrchr(const char *, char);
xsize_t string_strspn(const char *, const char *);
char * string_strpbrk(const char *, const char *);
char * string_strstr(const char *, const char *);
xwchar_t * string_wcsdup(const xwchar_t *);
xwchar_t * string_wcscat(xwchar_t *, const xwchar_t *);
xwchar_t * string_wcschr(const xwchar_t *, xwchar_t);
int string_wcscmp(const xwchar_t *, const xwchar_t *);
int string_wcsicmp(const xwchar_t *, const xwchar_t *);
xwchar_t * string_wcscpy(xwchar_t *, const xwchar_t *);
xsize_t string_wcscspn(const xwchar_t *, const xwchar_t *);
xsize_t string_wcslen(const xwchar_t *);
xwchar_t * string_wcsncat(xwchar_t *, const xwchar_t *, xsize_t);
int string_wcsncmp(const xwchar_t *, const xwchar_t *, xsize_t);
int string_wcsnicmp(const xwchar_t *, const xwchar_t *, xsize_t);
xwchar_t * string_wcsncpy(xwchar_t *, const xwchar_t *, xsize_t);
xwchar_t * string_wcsrchr(const xwchar_t *, xwchar_t);
xsize_t string_wcsspn(const xwchar_t *, const xwchar_t *);
xwchar_t * string_wcspbrk(const xwchar_t *, const xwchar_t *);
xwchar_t * string_wcsstr(const xwchar_t *, const xwchar_t *);
int string_strtoi(const char *, char **, int);
xint64_t string_strtol(const char *, char **, int);
unsigned int string_strtoui(const char *, char **, int);
xuint64_t string_strtoul(const char *, char **, int);
double string_strtod(const char *, char **);
long double string_strtold(const char *, char **);
int string_wcstoi(const xwchar_t *, xwchar_t **, int);
xint64_t string_wcstol(const xwchar_t *, xwchar_t **, int);
unsigned int string_wcstoui(const xwchar_t *, xwchar_t **, int);
xuint64_t string_wcstoul(const xwchar_t *, xwchar_t **, int);
double string_wcstod(const xwchar_t *, xwchar_t **);
long double string_wcstold(const xwchar_t *, xwchar_t **);
int string_sprintf(char *, const char *, ...);
int string_snprintf(char *, xsize_t, const char *, ...);
int string_vsprintf(char *, const char *, xva_list_t);
int string_vsnprintf(char *, xsize_t, const char *, xva_list_t);
int string_wsprintf(xwchar_t *, const xwchar_t *, ...);
int string_wsnprintf(xwchar_t *, xsize_t, const xwchar_t *, ...);
int string_vwsprintf(xwchar_t *, const xwchar_t *, xva_list_t);
int string_vwsnprintf(xwchar_t *, xsize_t, const xwchar_t *, xva_list_t);

#ifdef __cplusplus
}
#endif

#endif /* _STRING_H_ */


