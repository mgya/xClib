#ifndef _MATH_H_
#define _MATH_H_

#include "../system/integer.h"
#include "../system/float.h"

#define abs(i)          tr_abs(i)
#define acos(d)         tr_acos(d)
#define asin(d)         tr_asin(d)
#define atan(d)         tr_atan(d)
#define atan2(d1,d2)    tr_atan2((d1),(d2))
#define ceil(d)         tr_ceil(d)
#define cos(d)          tr_cos(d)
#define cosh(d)         tr_cosh(d)
#define exp(d)          tr_exp(d)
#define fabs(d)         tr_fabs(d)
#define floor(d)        tr_floor(d)
#define fmod(d1,d2)     tr_fmod((d1),(d2))
#define frexp(d,pi)     tr_frexp((d),(pi))
#define labs(i)         tr_labs(i)
#define ldexp(d,i)      tr_ldexp((d),(i))
#define log(d)          tr_log(d)
#define log10(d)        tr_log10(d)
#define modf(d,pd)      tr_modf((d),(pd))
#define pow(d1,d2)      tr_pow((d1),(d2))
#define round(d)        tr_round(d)
#define lround(d)       tr_lround(d)
#define sin(d)          tr_sin(d)
#define sinh(d)         tr_sinh(d)
#define sqrt(d)         tr_sqrt(d)
#define tan(d)          tr_tan(d)
#define tanh(d)         tr_tanh(d)
#define hypot(d1,d2)    tr_hypot((d1),(d2))

#ifdef __cplusplus
extern "C" {
#endif

int tr_abs(int);
double tr_acos(double);
double tr_asin(double);
double tr_atan(double);
double tr_atan2(double, double);
double tr_ceil(double);
double tr_cos(double);
double tr_cosh(double);
double tr_exp(double);
double tr_fabs(double);
double tr_floor(double);
double tr_fmod(double, double);
double tr_frexp(double, int *);
int64_t tr_labs(int64_t);
double tr_ldexp(double, int);
double tr_log(double);
double tr_log10(double);
double tr_modf(double, double *);
double tr_pow(double, double);
int tr_round(double);
int64_t tr_lround(double);
double tr_sin(double);
double tr_sinh(double);
double tr_sqrt(double);
double tr_tan(double);
double tr_tanh(double);
double tr_hypot(double,double);

#ifdef __cplusplus
}
#endif

#endif /* _MATH_H_ */


