#include "./fdlibm.h"
#include "../../math.h"

int64_t tr_labs(int64_t i)
{
    return (i < 0) ? -i : i;
}
