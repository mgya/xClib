#include "../../string.h"

wchar * tr_wcspbrk (const wchar * s, const wchar * accept)
{
    while (*s != L'\0')
    {
    	const wchar * a = accept;
    	while (*a != L'\0')
    	    if (*a++ == *s)
    	    	return (wchar *)s;
    	++s;
    }
    
    return NULL;
}

