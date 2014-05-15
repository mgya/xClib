#include "./fdlibm.h"
#include "../../math.h"

int tr_round(double x)
{
    return (int)floor(x + 0.5);
}
