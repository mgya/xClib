/*
    isalnum.c
    version : 0.1
*/

/*
FUNCTION
    <<isalnum>>---alphanumeric character predicate

INDEX
    isalnum

ANSI_SYNOPSIS
    #include <ctype.h>
    int isalnum(int <[c]>);

TRAD_SYNOPSIS
    #include <ctype.h>
    int isalnum(<[c]>);


DESCRIPTION
<<isalnum>> is a macro which classifies ASCII integer values by table
lookup.  It is a predicate returning non-zero for alphabetic or
numeric ASCII characters, and <<0>> for other arguments.  It is defined
for all integer values.

You can use a compiled subroutine instead of the macro definition by
undefining the macro using `<<#undef isalnum>>'.

RETURNS
<<isalnum>> returns non-zero if <[c]> is a letter (<<a>>--<<z>> or
<<A>>--<<Z>>) or a digit (<<0>>--<<9>>).

PORTABILITY
<<isalnum>> is ANSI C.

No OS subroutines are required.
*/

#include "../../ctype.h"
#include "./ctype_.h"

xbool_t ctype_isalnum(char c)
{
    return ((_ctype_ + 1)[(xint8_t)c] & (_U | _L | _N)) != 0 ? XTRUE : XFALSE;
}
