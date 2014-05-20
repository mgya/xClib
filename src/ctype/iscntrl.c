/*
    isalnum.c
    version : 0.1
*/

/*
FUNCTION
    <<iscntrl>>---control character predicate

INDEX
    iscntrl

ANSI_SYNOPSIS
    #include <ctype.h>
    int iscntrl(int <[c]>);

TRAD_SYNOPSIS
    #include <ctype.h>
    int iscntrl(<[c]>);

DESCRIPTION
<<iscntrl>> is a macro which classifies ASCII integer values by table
lookup.  It is a predicate returning non-zero for control characters, and 0
for other characters.  It is defined only when <<isascii>>(<[c]>) is
true or <[c]> is EOF.

You can use a compiled subroutine instead of the macro definition by
undefining the macro using `<<#undef iscntrl>>'.

RETURNS
<<iscntrl>> returns non-zero if <[c]> is a delete character or ordinary
control character (<<0x7F>> or <<0x00>>--<<0x1F>>).

PORTABILITY
<<iscntrl>> is ANSI C.

No supporting OS subroutines are required.
*/

#include "../../ctype.h"
#include "./ctype_.h"

xbool_t ctype_iscntrl(char c)
{
    return ((_ctype_ + 1)[(xint8_t)c] & _C) != 0 ? XTRUE : XFALSE;
}
