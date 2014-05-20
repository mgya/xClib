#include "./fdlibm.h"
#include "../../math.h"

double math_fabs(double x)
{
    xuint32_t high;
    GET_HIGH_WORD(high,x);
    SET_HIGH_WORD(x,high&0x7fffffff);
    return x;
}
