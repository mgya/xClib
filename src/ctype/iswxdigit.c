/*
    isalnum.c
    version : 0.1
*/
/*
FUNCTION
    <<iswxdigit>>---hexadecimal digit wide character test

INDEX
    iswxdigit

ANSI_SYNOPSIS
    #include <wctype.h>
    int iswxdigit(wint_t <[c]>);

TRAD_SYNOPSIS
    #include <wctype.h>
    int iswxdigit(<[c]>)
    wint_t <[c]>;

DESCRIPTION
<<iswxdigit>> is a function which classifies wide character values that
are hexadecimal digits.

RETURNS
<<iswxdigit>> returns non-zero if <[c]> is a hexadecimal digit wide character.

PORTABILITY
<<iswxdigit>> is C99.

No supporting OS subroutines are required.
*/

#include "../../ctype.h"

bool tr_iswxdigit(wchar c)
{
    return c < 0x100 ? isxdigit((char)c) : false;
}
