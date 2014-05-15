#include "../../string.h"
#include "../../ctype.h"

int tr_wcsnicmp(const wchar * s1, const wchar * s2, size_t n)
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
