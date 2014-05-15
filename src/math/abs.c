#include "./fdlibm.h"
#include "../../math.h"

int tr_abs(int i)
{
    return (i < 0) ? -i : i;
}
