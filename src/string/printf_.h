/*
    printf_.h
    version : 0.1
*/

#ifndef _PRINTF_H_
#define _PRINTF_H_

#include "../../../system/varargsex.h"
#include "../../../system/character.h"
#include "../../../system/pointer.h"

struct arg_printf {
  void *data;
  int (*put)(void*,size_t,void*);
};

#ifdef __cplusplus
extern "C" {
#endif

int isinf(double d);
int isnan(double d);
    
int vsprintf(char *, const char *, va_list);
int vsnprintf(char *, size_t, const char *, va_list);
int __v_sprintf(struct arg_printf *, const char *, va_list);
int __dtostr(double d,char *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int g);
int __ltostr(char *, unsigned int, unsigned long, unsigned int, int);
int __lltostr(char *, int, uint64_t, int, char);

int vwsprintf(wchar *, const wchar *, va_list);
int vwsnprintf(wchar *, size_t, const wchar *, va_list);
int __v_wsprintf(struct arg_printf *, const wchar *, va_list);
int __dtowcs(double d,wchar *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int g);
int __ltowcs(wchar *, unsigned int, unsigned long, unsigned int, int);
int __lltowcs(wchar *, int, uint64_t, int, wchar);


#ifdef __cplusplus
}
#endif

#endif /*    _PRINTF_H_    */
