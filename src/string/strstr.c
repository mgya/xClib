/*
FUNCTION
    <<strstr>>---find string segment

INDEX
    strstr

ANSI_SYNOPSIS
    #include <string.h>
    char *tr_strstr(const char *<[s1]>, const char *<[s2]>);

TRAD_SYNOPSIS
    #include <string.h>
    char *strstr(<[s1]>, <[s2]>)
    char *<[s1]>;
    char *<[s2]>;

DESCRIPTION
    Locates the first occurence in the string pointed to by <[s1]> of
    the sequence of characters in the string pointed to by <[s2]>
    (excluding the terminating null  character).

RETURNS
    Returns a pointer to the located string segment, or a null
    pointer if the string <[s2]> is not found. If <[s2]> points to
    a string with zero length, the <[s1]> is returned.

PORTABILITY
<<strstr>> is ANSI C.

<<strstr>> requires no supporting OS subroutines.

QUICKREF
    strstr ansi pure
*/

#include "../../string.h"

const char * tr_strstr(const char * searchee, const char * lookfor)
{
    if (*searchee == '\0')
    {
    	if (*lookfor)
    	    return NULL;

    	return searchee;
    }

    while (*searchee)
    {
    	size_t i = 0;

    	while (1)
    	{
    	    if (lookfor[i] == '\0')
    	    {
    	    	return searchee;
    	    }

    	    if (lookfor[i] != searchee[i])
    	    {
    	    	break;
    	    }

    	    ++i;
    	}

    	++searchee;
    }

    return NULL;
}
