#include "../../string.h"
#include "../../ctype.h"

int string_stricmp(const char * s1, const char * s2)
{
    while (*s1 != '\0' && tolower(*s1) == tolower(*s2))
    {
    	++s1;
    	++s2;
    }

    return tolower(*s1) - tolower(*s2);
}
