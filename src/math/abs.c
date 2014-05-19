#include "./fdlibm.h"
#include "../../math.h"

int math_abs(int i)
{
    return (i < 0) ? -i : i;
}
