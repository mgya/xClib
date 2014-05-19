/*
FUNCTION
    <<wcsncpy>>---copy part of a wide-character string 

ANSI_SYNOPSIS
    #include <xwchar_t.h>
    xwchar_t *string_wcsncpy(xwchar_t *<[s1]>, const xwchar_t *<[s2]>, xsize_t <[n]>);

TRAD_SYNOPSIS
    xwchar_t *string_wcsncpy(<[s1]>, <[s2]>, <[n]>
    xwchar_t *<[s1]>;
    const xwchar_t *<[s2]>;
    xsize_t <[n]>;

DESCRIPTION
    The <<wcsncpy>> function copies not more than n wide-character codes
    (wide-character codes that follow a null wide-character code are not
    copied) from the array pointed to by <[s2]> to the array pointed to
    by <[s1]>. If copying takes place between objects that overlap, the
    behaviour is undefined.

    If the array pointed to by <[s2]> is a wide-character string that is
    shorter than <[n]> wide-character codes, null wide-character codes are
    appended to the copy in the array pointed to by <[s1]>, until <[n]>
    wide-character codes in all are written. 

RETURNS
    The <<wcsncpy>> function returns <[s1]>; no return value is reserved to
    indicate an error. 

PORTABILITY
<<wcsncpy>> is ISO/IEC 9899/AMD1:1995 (ISO C).

No supporting OS subroutines are required.
*/

/*    $NetBSD: wcsncpy.c,v 1.1 2000/12/23 23:14:36 itojun Exp $    */

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
 *    citrus Id: wcsncpy.c,v 1.1 1999/12/29 21:47:45 tshiozak Exp
 */

#include "../../string.h"

xwchar_t * string_wcsncpy(xwchar_t * dst0, const xwchar_t * src0, xsize_t count)
{
    xwchar_t * dscan = dst0;
    const xwchar_t * sscan = src0;

    while (count > 0)
    {
    	--count;

    	if ((*dscan++ = *sscan++) == '\0')
    	    break;
    }

    while (count-- > 0)
    	*dscan++ = '\0';

    return dst0;
}
