/*
    isalnum.c
    version : 0.1
*/

/*
FUNCTION
<<islower>>---lowercase character predicate

INDEX
islower

ANSI_SYNOPSIS
#include <ctype.h>
int islower(int <[c]>);

TRAD_SYNOPSIS
#include <ctype.h>
int islower(<[c]>);

DESCRIPTION
<<islower>> is a macro which classifies ASCII integer values by table
lookup.  It is a predicate returning non-zero for minuscules
(lowercase alphabetic characters), and 0 for other characters.
It is defined only when <<isascii>>(<[c]>) is true or <[c]> is EOF.

You can use a compiled subroutine instead of the macro definition by
undefining the macro using `<<#undef islower>>'.

RETURNS
<<islower>> returns non-zero if <[c]> is a lowercase letter (<<a>>--<<z>>).

PORTABILITY
<<islower>> is ANSI C.

No supporting OS subroutines are required.
*/

#include "../../ctype.h"
#include "./ctype_.h"

xbool_t ctype_islower(char c)
{
    return ((_ctype_ + 1)[(xint8_t)c] & _L) != 0 ? XTRUE : XFALSE;
}
