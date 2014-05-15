#include "./fdlibm.h"
#include "../../math.h"

int finite(double x)
{
    int32_t hx;
    GET_HIGH_WORD(hx,x);
    return  (int)((uint32_t)((hx&0x7fffffff)-0x7ff00000)>>31);
}
