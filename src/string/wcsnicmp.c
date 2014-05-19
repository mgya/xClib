#include "../../string.h"
#include "../../ctype.h"

int string_wcsnicmp(const xwchar_t * s1, const xwchar_t * s2, xsize_t n)
{
    if (n == 0)
    	return 0;

    while (n-- != 0 && towlower(*s1) == towlower(*s2))
    {
    	if (n == 0 || *s1 == L'\0')
    	    break;

    	++s1;
    	++s2;
    }

    return towlower(*s1) - towlower(*s2);
}
