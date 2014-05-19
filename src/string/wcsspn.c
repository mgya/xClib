/*
FUNCTION
    <<wcsspn>>---get length of a wide substring 

ANSI_SYNOPSIS
    #include <xwchar_t.h>
    xsize_t wcsspn(const xwchar_t *<[s]>, const xwchar_t *<[set]>);

TRAD_SYNOPSIS
    xsize_t string_wcsspn(<[s]>, <[set]>
    const xwchar_t *<[s]>;
    const xwchar_t *<[set]>;

DESCRIPTION
    The <<wcsspn>> function computes the length of the maximum initial
    segment of the wide-character string pointed to by <[s]> which consists
    entirely of wide-character codes from the wide-character string
    pointed to by <[set]>.

RETURNS
    The wcsspn() function returns the length <[s1]>; no return value is
    reserved to indicate an error.

PORTABILITY
<<wcsspn>> is ISO/IEC 9899/AMD1:1995 (ISO C).

No supporting OS subroutines are required.
*/

/*    $NetBSD: wcsspn.c,v 1.1 2000/12/23 23:14:37 itojun Exp $    */

/*-
 * Copyright (c)1999 Citrus Project,
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *    citrus Id: wcsspn.c,v 1.1 1999/12/29 21:47:45 tshiozak Exp
 */

#include "../../string.h"

xsize_t string_wcsspn(const xwchar_t * s1, const xwchar_t * s2)
{
    const xwchar_t * s = s1;
    const xwchar_t * c;

    while (*s1)
    {
    	for (c = s2; *c; ++c)
    	{
    	    if (*s1 == *c)
    	    	break;
    	}

    	if (*c == '\0')
    	    break;

    	++s1;
    }

    return s1 - s;
}
