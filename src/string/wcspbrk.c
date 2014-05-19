#include "../../string.h"

xwchar_t * string_wcspbrk (const xwchar_t * s, const xwchar_t * accept)
{
    while (*s != L'\0')
    {
    	const xwchar_t * a = accept;
    	while (*a != L'\0')
    	    if (*a++ == *s)
    	    	return (xwchar_t *)s;
    	++s;
    }
    
    return XNULL;
}

