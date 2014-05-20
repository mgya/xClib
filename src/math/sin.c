#include "./fdlibm.h"
#include "../../math.h"

double math_sin(double x)
{
    double y[2],z=0.0;
    xint32_t n,ix;

    /* High word of x. */
    GET_HIGH_WORD(ix,x);

    /* |x| ~< pi/4 */
    ix &= 0x7fffffff;
    if(ix <= 0x3fe921fb) return kernel_sin(x,z,0);

    /* sin(Inf or NaN) is NaN */
    else if (ix>=0x7ff00000) return x-x;

    /* argument reduction needed */
    else {
    	n = rem_pio2(x,y);
    	switch(n&3) {
    	case 0: return  kernel_sin(y[0],y[1],1);
    	case 1: return  kernel_cos(y[0],y[1]);
    	case 2: return -kernel_sin(y[0],y[1],1);
    	default:
    	    return -kernel_cos(y[0],y[1]);
    	}
    }
}
