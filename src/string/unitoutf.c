#include "../../string.h"

size_t tr_unitoutf(const wchar * src, size_t len, char * dst, size_t n)
{
    size_t s = 0;
    size_t d = 0;

    if (0 == len)
    {
    	len = wcslen(src);
    }
    	
    while (s < len && d < n)
    {
    	if (src[s] < 0x80) //bytes: 1; 0xxxxxxx
    	{
    	    if (n - d <= 1)
    	    {
    	    	break;
    	    }

    	    dst[d++] = (char)src[s++];
    	}
    	else if (src[s] < 0x800) //bytes: 2; 110x-xxxx 10xx-xxxx
    	{
    	    if (n - d <= 2)
    	    {
    	    	break;
    	    }

    	    dst[d + 0] = 0xc0 | (src[s] >> 6);
    	    dst[d + 1] = 0x80 | (src[s] & 0x3f);

    	    ++s;
    	    d += 2;
    	}
    	else //bytes: 3; 1110-xxxx 10xx-xxxx 10xx-xxxx
    	{
    	    if (n - d <= 3)
    	    {
    	    	break;
    	    }

    	    dst[d + 0] = 0xe0 | (src[s] >> 12);
    	    dst[d + 1] = 0x80 | ((src[s] >> 6) & 0x3f);
    	    dst[d + 2] = 0x80 | (src[s] & 0x3f);

    	    ++s;
    	    d += 3;
    	}
    }

    if (d < n)
    {
    	dst[d] = '\0';
    }

    return d;
}
