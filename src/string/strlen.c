/* 
FUNCTION
    <<strlen>>---character string length
    
INDEX
    strlen

ANSI_SYNOPSIS
    #include <string.h>
    xsize_t string_strlen(const char *<[str]>);

TRAD_SYNOPSIS
    #include <string.h>
    xsize_t string_strlen(<[str]>)
    char *<[src]>;

DESCRIPTION
    The <<strlen>> function works out the length of the string
    starting at <<*<[str]>>> by counting chararacters until it
    reaches a <<XNULL>> character.

RETURNS
    <<strlen>> returns the character count.

PORTABILITY
<<strlen>> is ANSI C.

<<strlen>> requires no supporting OS subroutines.

QUICKREF
    strlen ansi pure
*/

#include "../../string.h"

xsize_t string_strlen(const char * str)
{
  const char * start = str;

  while (*str)
    str++;

  return str - start;
}
