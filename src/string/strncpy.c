/*
FUNCTION
    <<strncpy>>---counted copy string

INDEX
    strncpy

ANSI_SYNOPSIS
    #include <string.h>
    char *tr_strncpy(char *<[dst]>, const char *<[src]>, size_t <[length]>);

TRAD_SYNOPSIS
    #include <string.h>
    char *tr_strncpy(<[dst]>, <[src]>, <[length]>)
    char *<[dst]>;
    char *<[src]>;
    size_t <[length]>;

DESCRIPTION
    <<strncpy>> copies not more than <[length]> characters from the
    the string pointed to by <[src]> (including the terminating
    null character) to the array pointed to by <[dst]>.  If the
    string pointed to by <[src]> is shorter than <[length]>
    characters, null characters are appended to the destination
    array until a total of <[length]> characters have been
    written.

RETURNS
    This function returns the initial value of <[dst]>.

PORTABILITY
<<strncpy>> is ANSI C.

<<strncpy>> requires no supporting OS subroutines.

QUICKREF
    strncpy ansi pure
*/

#include "../../string.h"

char * tr_strncpy(char * dst0, const char * src0, size_t count)
{
    char * dscan = dst0;
    const char * sscan = src0;

    while (count > 0)
    {
    	--count;

    	if ((*dscan++ = *sscan++) == '\0')
    	    break;
    }

    while (count-- > 0)
    	*dscan++ = '\0';

    return dst0;
}
