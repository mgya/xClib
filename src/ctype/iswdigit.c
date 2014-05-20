/*
    isalnum.c
    version : 0.1
*/

/*
FUNCTION
    <<iswdigit>>---decimal digit wide character test

INDEX
    iswdigit

ANSI_SYNOPSIS
    #include <wctype.h>
    int iswdigit(wint_t <[c]>);

TRAD_SYNOPSIS
    #include <wctype.h>
    int iswdigit(<[c]>)
    wint_t <[c]>;

DESCRIPTION
<<iswdigit>> is a function which classifies wide-character values that
are decimal digits.

RETURNS
<<iswdigit>> returns non-zero if <[c]> is a decimal digit wide character.

PORTABILITY
<<iswdigit>> is C99.

No supporting OS subroutines are required.
*/

#include "../../ctype.h"

xbool_t ctype_iswdigit(xwchar_t c)
{
    return c < 0x100 ? isdigit((char)c) : XFALSE;
}
