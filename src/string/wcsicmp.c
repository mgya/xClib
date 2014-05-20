#include "../../string.h"
#include "../../ctype.h"

int string_wcsicmp(const xwchar_t * s1, const xwchar_t * s2)
{
    while (*s1 != '\0' && towlower(*s1) == towlower(*s2))
    {
    	++s1;
    	++s2;
    }

    return towlower(*s1) - towlower(*s2);
}
