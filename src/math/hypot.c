#include "./fdlibm.h"
#include "../../math.h"

double tr_hypot(double x, double y)
{
    return sqrt(x * x + y * y);
}
