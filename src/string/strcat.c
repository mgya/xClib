/*
FUNCTION
    <<strcat>>---concatenate strings

INDEX
    tr_strcat

ANSI_SYNOPSIS
    #include <string.h>
    char *tr_strcat(char *<[dst]>, const char *<[src]>);

TRAD_SYNOPSIS
    #include <string.h>
    char *tr_strcat(<[dst]>, <[src]>)
    char *<[dst]>;
    char *<[src]>;

DESCRIPTION
    <<strcat>> appends a copy of the string pointed to by <[src]>
    (including the terminating null character) to the end of the
    string pointed to by <[dst]>.  The initial character of
    <[src]> overwrites the null character at the end of <[dst]>.

RETURNS
    This function returns the initial value of <[dst]>

PORTABILITY
<<strcat>> is ANSI C.

<<strcat>> requires no supporting OS subroutines.

QUICKREF
    strcat ansi pure
*/

#include "../../string.h"

char * tr_strcat(char * s1, const char * s2)
{
    char * s = s1;

    while (*s1)
    	++s1;

    while (*s1++ = *s2++)
    	;

    return s;
}
