#include "./fdlibm.h"
#include "../../math.h"

static const double one = 1.0, shuge = 1.0e307;

double math_sinh(double x)
{    
    double t,w,h;
    xint32_t ix,jx;
    xuint32_t lx;

    /* High word of |x|. */
    GET_HIGH_WORD(jx,x);
    ix = jx&0x7fffffff;

    /* x is INF or NaN */
    if(ix>=0x7ff00000) return x+x;    

    h = 0.5;
    if (jx<0) h = -h;
    /* |x| in [0,22], return sign(x)*0.5*(E+E/(E+1))) */
    if (ix < 0x40360000) {    	/* |x|<22 */
    	if (ix<0x3e300000)     	/* |x|<2**-28 */
    	    if(shuge+x>one) return x;/* sinh(tiny) = tiny with inexact */
    	t = expm1(fabs(x));
    	if(ix<0x3ff00000) return h*(2.0*t-t*t/(t+one));
    	return h*(t+t/(t+one));
    }

    /* |x| in [22, log(maxdouble)] return 0.5*exp(|x|) */
    if (ix < 0x40862E42)  return h*exp(fabs(x));

    /* |x| in [log(maxdouble), overflowthresold] */
    GET_LOW_WORD(lx,x);
    if (ix<0x408633CE || (ix==0x408633ce && lx<=(xuint32_t)0x8fb9f87d)) {
    	w = exp(0.5*fabs(x));
    	t = h*w;
    	return t*w;
    }

    /* |x| > overflowthresold, sinh(x) overflow */
    return x*shuge;
}
