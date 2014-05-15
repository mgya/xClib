#include "./fdlibm.h"
#include "../../math.h"

int64_t tr_lround(double x)
{
    return (int64_t)floor(x + 0.5);
}
