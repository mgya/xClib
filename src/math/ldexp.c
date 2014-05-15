#include "./fdlibm.h"
#include "../../math.h"

double tr_ldexp(double value, int exp)
{
    if(!finite(value)||value==0.0) return value;
    return scalbn(value,exp);
}
