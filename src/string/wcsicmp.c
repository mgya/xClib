#include "../../string.h"
#include "../../ctype.h"

int tr_wcsicmp(const wchar * s1, const wchar * s2)
{
    while (*s1 != '\0' && towlower(*s1) == towlower(*s2))
    {
    	++s1;
    	++s2;
    }

    return towlower(*s1) - towlower(*s2);
}
