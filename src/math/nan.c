#include "./fdlibm.h"
#include "../../math.h"

double nan(const char * unused)
{
    double x;

    INSERT_WORDS(x,0x7ff80000,0);
    return x;
}
