/*
    isalnum.c
    version : 0.1
*/

/*
FUNCTION
<<isupper>>---uppercase character predicate

INDEX
isupper

ANSI_SYNOPSIS
#include <ctype.h>
int isupper(int <[c]>);

TRAD_SYNOPSIS
#include <ctype.h>
int isupper(<[c]>);

DESCRIPTION
<<isupper>> is a macro which classifies ASCII integer values by table
lookup.  It is a predicate returning non-zero for uppercase letters
(<<A>>--<<Z>>), and 0 for other characters.  It is defined only when
<<isascii>>(<[c]>) is true or <[c]> is EOF.

You can use a compiled subroutine instead of the macro definition by
undefining the macro using `<<#undef isupper>>'.

RETURNS
<<isupper>> returns non-zero if <[c]> is a uppercase letter (A-Z).

PORTABILITY
<<isupper>> is ANSI C.

No supporting OS subroutines are required.
*/

#include "../../ctype.h"
#include "./ctype_.h"

xbool_t ctype_isupper(char c)
{
    return ((_ctype_ + 1)[(xint8_t)c] & _U) != 0 ? XTRUE : XFALSE;
}
