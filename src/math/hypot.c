#include "./fdlibm.h"
#include "../../math.h"

double math_hypot(double x, double y)
{
    return sqrt(x * x + y * y);
}
