/*
FUNCTION
    <<strcpy>>---copy string

INDEX
    strcpy

ANSI_SYNOPSIS
    #include <string.h>
    char *tr_strcpy(char *<[dst]>, const char *<[src]>);

TRAD_SYNOPSIS
    #include <string.h>
    char *tr_strcpy(<[dst]>, <[src]>)
    char *<[dst]>;
    char *<[src]>;

DESCRIPTION
    <<strcpy>> copies the string pointed to by <[src]>
    (including the terminating null character) to the array
    pointed to by <[dst]>.

RETURNS
    This function returns the initial value of <[dst]>.

PORTABILITY
<<strcpy>> is ANSI C.

<<strcpy>> requires no supporting OS subroutines.

QUICKREF
    strcpy ansi pure
*/

#include "../../string.h"

char * tr_strcpy(char * dst0, const char * src0)
{
    char * s = dst0;

    while (*dst0++ = *src0++)
    	;

    return s;
}
