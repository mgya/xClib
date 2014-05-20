#include "./fdlibm.h"
#include "../../math.h"

xint64_t math_labs(xint64_t i)
{
    return (i < 0) ? -i : i;
}
