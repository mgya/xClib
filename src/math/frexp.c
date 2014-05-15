#include "./fdlibm.h"
#include "../../math.h"

static const double
two54 =  1.80143985094819840000e+16; /* 0x43500000, 0x00000000 */

double tr_frexp(double x, int * eptr)
{
    int32_t hx, ix, lx;
    EXTRACT_WORDS(hx,lx,x);
    ix = 0x7fffffff&hx;
    *eptr = 0;
    if(ix>=0x7ff00000||((ix|lx)==0)) return x;    /* 0,inf,nan */
    if (ix<0x00100000) {    	/* subnormal */
    	x *= two54;
    	GET_HIGH_WORD(hx,x);
    	ix = hx&0x7fffffff;
    	*eptr = -54;
    }
    *eptr += (ix>>20)-1022;
    hx = (hx&0x800fffff)|0x3fe00000;
    SET_HIGH_WORD(x,hx);
    return x;
}
