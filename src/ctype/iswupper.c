/*
    isalnum.c
    version : 0.1
*/
/*
FUNCTION
    <<iswupper>>---uppercase wide character test

INDEX
    iswupper

ANSI_SYNOPSIS
    #include <wctype.h>
    int iswupper(wint_t <[c]>);

TRAD_SYNOPSIS
    #include <wctype.h>
    int iswupper(<[c]>)
    wint_t <[c]>;

DESCRIPTION
<<iswupper>> is a function which classifies wide-character values that
have uppercase translations.

RETURNS
<<iswupper>> returns non-zero if <[c]> is a uppercase wide character.

PORTABILITY
<<iswupper>> is C99.

No supporting OS subroutines are required.
*/

#include "../../ctype.h"

bool tr_iswupper(wchar c)
{
    return towlower(c) != c;
}
