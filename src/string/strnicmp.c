#include "../../string.h"
#include "../../ctype.h"

int tr_strnicmp(const char * s1, const char * s2, size_t n)
{
    if (n == 0)
    	return 0;

    while (n-- != 0 && tolower(*s1) == tolower(*s2))
    {
    	if (n == 0 || *s1 == '\0')
    	    break;

    	++s1;
    	++s2;
    }

    return tolower(*s1) - tolower(*s2);
}
