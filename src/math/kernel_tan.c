#include "./fdlibm.h"
#include "../../math.h"

static const double 
one   =  1.00000000000000000000e+00, /* 0x3FF00000, 0x00000000 */
pio4  =  7.85398163397448278999e-01, /* 0x3FE921FB, 0x54442D18 */
pio4lo=  3.06161699786838301793e-17, /* 0x3C81A626, 0x33145C07 */
T[] =  {
    3.33333333333334091986e-01, /* 0x3FD55555, 0x55555563 */
    1.33333333333201242699e-01, /* 0x3FC11111, 0x1110FE7A */
    5.39682539762260521377e-02, /* 0x3FABA1BA, 0x1BB341FE */
    2.18694882948595424599e-02, /* 0x3F9664F4, 0x8406D637 */
    8.86323982359930005737e-03, /* 0x3F8226E3, 0xE96E8493 */
    3.59207910759131235356e-03, /* 0x3F6D6D22, 0xC9560328 */
    1.45620945432529025516e-03, /* 0x3F57DBC8, 0xFEE08315 */
    5.88041240820264096874e-04, /* 0x3F4344D8, 0xF2F26501 */
    2.46463134818469906812e-04, /* 0x3F3026F7, 0x1A8D1068 */
    7.81794442939557092300e-05, /* 0x3F147E88, 0xA03792A6 */
    7.14072491382608190305e-05, /* 0x3F12B80F, 0x32F0A7E9 */
    -1.85586374855275456654e-05, /* 0xBEF375CB, 0xDB605373 */
    2.59073051863633712884e-05, /* 0x3EFB2A70, 0x74BF7AD4 */
};

double kernel_tan(double x, double y, int iy)
{
    double z,r,v,w,s;
    int32_t ix,hx;
    GET_HIGH_WORD(hx,x);
    ix = hx&0x7fffffff;    /* high word of |x| */
    if(ix<0x3e300000)    	    /* x < 2**-28 */
    {if((int)x==0) {    	    /* generate inexact */
    	uint32_t low;
    	GET_LOW_WORD(low,x);
    	if(((ix|low)|(iy+1))==0) return one/fabs(x);
    	else return (iy==1)? x: -one/x;
    }
    }
    if(ix>=0x3FE59428) {     	    /* |x|>=0.6744 */
    	if(hx<0) {x = -x; y = -y;}
    	z = pio4-x;
    	w = pio4lo-y;
    	x = z+w; y = 0.0;
    }
    z    =  x*x;
    w     =  z*z;
    /* Break x^5*(T[1]+x^2*T[2]+...) into
    *      x^5(T[1]+x^4*T[3]+...+x^20*T[11]) +
    *      x^5(x^2*(T[2]+x^4*T[4]+...+x^22*[T12]))
    */
    r = T[1]+w*(T[3]+w*(T[5]+w*(T[7]+w*(T[9]+w*T[11]))));
    v = z*(T[2]+w*(T[4]+w*(T[6]+w*(T[8]+w*(T[10]+w*T[12])))));
    s = z*x;
    r = y + z*(s*(r+v)+y);
    r += T[0]*s;
    w = x+r;
    if(ix>=0x3FE59428) {
    	v = (double)iy;
    	return (double)(1-((hx>>30)&2))*(v-2.0*(x-(w*w/(w+v)-r)));
    }
    if(iy==1) return w;
    else {    	/* if allow error up to 2 ulp, 
    	    	simply return -1.0/(x+r) here */
    	/*  compute -1.0/(x+r) accurately */
    	double a,t;
    	z  = w;
    	SET_LOW_WORD(z,0);
    	v  = r-(z - x);     /* z+v = r+x */
    	t = a  = -1.0/w;    /* a = -1.0/w */
    	SET_LOW_WORD(t,0);
    	s  = 1.0+t*z;
    	return t+a*(s+t*v);
    }
}
