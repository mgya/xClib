/*
    printf_.h
    version : 0.1
*/

#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <xC/xvarargs.h>
#include <xC/xcharacter.h>
#include <xC/xpointer.h>

struct arg_printf {
  void *data;
  int (*put)(void*,xsize_t,void*);
};

#ifdef __cplusplus
extern "C" {
#endif

int isinf(double d);
int isnan(double d);

int __v_sprintf(struct arg_printf *, const char *, xva_list_t);
int __dtostr(double d,char *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int g);
int __ltostr(char *, unsigned int, unsigned long, unsigned int, int);
int __lltostr(char *, int, xuint64_t, int, char);

int __v_wsprintf(struct arg_printf *, const xwchar_t *, xva_list_t);
int __dtowcs(double d,xwchar_t *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int g);
int __ltowcs(xwchar_t *, unsigned int, unsigned long, unsigned int, int);
int __lltowcs(xwchar_t *, int, xuint64_t, int, xwchar_t);


#ifdef __cplusplus
}
#endif

#endif /*    _PRINTF_H_    */
