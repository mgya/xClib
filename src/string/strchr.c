/*
FUNCTION
    <<strchr>>---search for character in string

INDEX
    tr_strchr

ANSI_SYNOPSIS
    #include <string.h>
    char * tr_strchr(const char *<[string]>, int <[c]>);

TRAD_SYNOPSIS
    #include <string.h>
    char * tr_strchr(<[string]>, <[c]>);
    const char *<[string]>;
    int <[c]>;

DESCRIPTION
    This function finds the first occurence of <[c]> (converted to
    a char) in the string pointed to by <[string]> (including the
    terminating null character).

RETURNS
    Returns a pointer to the located character, or a null pointer
    if <[c]> does not occur in <[string]>.

PORTABILITY
<<strchr>> is ANSI C.

<<strchr>> requires no supporting OS subroutines.

QUICKREF
    strchr ansi pure
*/

#include "../../string.h"

const char * tr_strchr(const char * s1, char c)
{
    const char * p = s1;

    do
    {
    	if (*p == c)
    	{
    	    /* LINTED interface specification */
    	    return p;
    	}
    } while (*p++);

    return NULL;
}
