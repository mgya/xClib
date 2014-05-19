#include "./fdlibm.h"
#include "../../math.h"

xint64_t math_lround(double x)
{
    return (xint64_t)floor(x + 0.5);
}
