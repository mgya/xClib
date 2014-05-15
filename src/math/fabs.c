#include "./fdlibm.h"
#include "../../math.h"

double tr_fabs(double x)
{
    uint32_t high;
    GET_HIGH_WORD(high,x);
    SET_HIGH_WORD(x,high&0x7fffffff);
    return x;
}
