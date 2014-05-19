#include "./fdlibm.h"
#include "../../math.h"

static const double one = 1.0, half=0.5, vchuge = 1.0e300;//qubing fix for error:'huge' is an obsolete keyword

double math_cosh(double x)
{    
    double t,w;
    xint32_t ix;
    xuint32_t lx;

    /* High word of |x|. */
    GET_HIGH_WORD(ix,x);
    ix &= 0x7fffffff;

    /* x is INF or NaN */
    if(ix>=0x7ff00000) return x*x;    

    /* |x| in [0,0.5*ln2], return 1+expm1(|x|)^2/(2*exp(|x|)) */
    if(ix<0x3fd62e43) {
        t = expm1(fabs(x));
        w = one+t;
        if (ix<0x3c800000) return w;    /* cosh(tiny) = 1 */
        return one+(t*t)/(w+w);
    }

    /* |x| in [0.5*ln2,22], return (exp(|x|)+1/exp(|x|)/2; */
    if (ix < 0x40360000) {
    	t = exp(fabs(x));
    	return half*t+half/t;
    }

    /* |x| in [22, log(maxdouble)] return half*exp(|x|) */
    if (ix < 0x40862E42)  return half*exp(fabs(x));

    /* |x| in [log(maxdouble), overflowthresold] */
    GET_LOW_WORD(lx,x);
    if (ix<0x408633CE || 
             (ix==0x408633ce && lx<=(xuint32_t)0x8fb9f87d)) {
        w = exp(half*fabs(x));
        t = half*w;
        return t*w;
    }

    /* |x| > overflowthresold, cosh(x) overflow */
    return vchuge*vchuge;//qubing fix for error:'huge' is an obsolete keyword
}
