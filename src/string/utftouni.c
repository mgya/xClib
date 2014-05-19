#include "../../string.h"

xsize_t string_utftouni(const char * src, xsize_t len, xwchar_t * dst, xsize_t n)
{
    xsize_t s = 0;
    xsize_t d = 0;

    if (0 == len)
    {
    	len = strlen(src);
    }
    
    while (s < len && d < n)
    {
    	if (d + 1 == n)
    	{
    	    break;
    	}
    	else if ((src[s] & 0x80) == 0) //bytes: 1; 0xxxxxxx
    	{
    	    dst[d++] = (xwchar_t)src[s++];
    	} 
    	else if ((src[s] & 0xE0) == 0xC0)  //bytes: 2; 110x-xxxx 10xx-xxxx
    	{
    	    dst[d] = (src[s + 0] & 0x1F) << 6;
    	    dst[d] |= (src[s + 1] & 0x3F);

    	    ++d;
    	    s += 2;
    	}
    	else //bytes: 3; 1110-xxxx 10xx-xxxx 10xx-xxxx
    	{
    	    dst[d]  = (src[s + 0] & 0x0F) << 12;
    	    dst[d] |= (src[s + 1] & 0x3F) << 6;
    	    dst[d] |= (src[s + 2] & 0x3F);

    	    ++d;
    	    s += 3;
    	} 
    }

    if (d < n)
    {
    	dst[d] = L'\0';
    }

    return d;
}
