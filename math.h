#ifndef _MATH_H_
#define _MATH_H_

#include <xC/xinteger.h>
#include <xC/xfloat.h>

#define abs(i)          math_abs(i)
#define acos(d)         math_acos(d)
#define asin(d)         math_asin(d)
#define atan(d)         math_atan(d)
#define atan2(d1,d2)    math_atan2((d1),(d2))
#define ceil(d)         math_ceil(d)
#define cos(d)          math_cos(d)
#define cosh(d)         math_cosh(d)
#define exp(d)          math_exp(d)
#define fabs(d)         math_fabs(d)
#define floor(d)        math_floor(d)
#define fmod(d1,d2)     math_fmod((d1),(d2))
#define frexp(d,pi)     math_frexp((d),(pi))
#define labs(i)         math_labs(i)
#define ldexp(d,i)      math_ldexp((d),(i))
#define log(d)          math_log(d)
#define log10(d)        math_log10(d)
#define modf(d,pd)      math_modf((d),(pd))
#define pow(d1,d2)      math_pow((d1),(d2))
#define round(d)        math_round(d)
#define lround(d)       math_lround(d)
#define sin(d)          math_sin(d)
#define sinh(d)         math_sinh(d)
#define sqrt(d)         math_sqrt(d)
#define tan(d)          math_tan(d)
#define tanh(d)         math_tanh(d)
#define hypot(d1,d2)    math_hypot((d1),(d2))

#ifdef __cplusplus
extern "C" {
#endif

int math_abs(int);
double math_acos(double);
double math_asin(double);
double math_atan(double);
double math_atan2(double, double);
double math_ceil(double);
double math_cos(double);
double math_cosh(double);
double math_exp(double);
double math_fabs(double);
double math_floor(double);
double math_fmod(double, double);
double math_frexp(double, int *);
xint64_t math_labs(xint64_t);
double math_ldexp(double, int);
double math_log(double);
double math_log10(double);
double math_modf(double, double *);
double math_pow(double, double);
int math_round(double);
xint64_t math_lround(double);
double math_sin(double);
double math_sinh(double);
double math_sqrt(double);
double math_tan(double);
double math_tanh(double);
double math_hypot(double,double);

#ifdef __cplusplus
}
#endif

#endif /* _MATH_H_ */


