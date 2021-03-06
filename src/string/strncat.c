/*
FUNCTION
    <<strncat>>---concatenate strings

INDEX
    string_strncat

ANSI_SYNOPSIS
    #include <string.h>
    char *strncat(char *<[dst]>, const char *<[src]>, xsize_t <[length]>);

TRAD_SYNOPSIS
    #include <string.h>
    char *string_strncat(<[dst]>, <[src]>, <[length]>)
    char *<[dst]>;
    char *<[src]>;
    xsize_t <[length]>;

DESCRIPTION
    <<strncat>> appends not more than <[length]> characters from
    the string pointed to by <[src]> (including the    terminating
    null character) to the end of the string pointed to by
    <[dst]>.  The initial character of <[src]> overwrites the null
    character at the end of <[dst]>.  A terminating null character
    is always appended to the result

WARNINGS
    Note that a null is always appended, so that if the copy is
    limited by the <[length]> argument, the number of characters
    appended to <[dst]> is <<n + 1>>.

RETURNS
    This function returns the initial value of <[dst]>

PORTABILITY
<<strncat>> is ANSI C.

<<strncat>> requires no supporting OS subroutines.

QUICKREF
    strncat ansi pure
*/

#include "../../string.h"

char * string_strncat(char * s1, const char * s2, xsize_t n)
{
    char * s = s1;

    while (*s1)
    	++s1;

    while (n-- != 0 && (*s1++ = *s2++))
    {
    	if (n == 0)
    	    *s1 = '\0';
    }

    return s;
}
