#include "../../string.h"
#include "../../ctype.h"

xuint64_t string_wcstoul(const xwchar_t * nptr, xwchar_t ** endptr, int base)
{
    register const xwchar_t * s = nptr;
    register xuint64_t acc;
    register xwchar_t c;
    register xuint64_t cutoff;
    register int neg = 0, any, cutlim;

    do {
    	c = *s++;
    } while (iswspace(c));
    if (c == L'-') {
    	neg = 1;
    	c = *s++;
    } else if (c == L'+')
    	c = *s++;
    if ((base == 0 || base == 16) &&
    	c == L'0' && (*s == L'x' || *s == L'X')) {
    	    c = s[1];
    	    s += 2;
    	    base = 16;
    }
    if (base == 0)
    	base = c == L'0' ? 8 : 10;

    cutoff = (xuint64_t)XUINT64_MAX / (xuint64_t)base;
    cutlim = (int)((xuint64_t)XUINT64_MAX % (xuint64_t)base);
    for (acc = 0, any = 0;; c = *s++) {
    	if (iswdigit(c))
    	    c -= L'0';
    	else if (iswalpha(c))
    	    c -= iswupper(c) ? L'A' - 10 : L'a' - 10;
    	else
    	    break;
    	if (c >= base)
    	    break;
    	if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
    	    any = -1;
    	else {
    	    any = 1;
    	    acc *= base;
    	    acc += c;
    	}
    }
    if (any < 0) {
    	acc = XUINT64_MAX;
    } else if (neg)
    	acc = (xuint64_t)(-(xint64_t)acc);
    if (endptr != 0)
    	*endptr = (xwchar_t *) (any ? s - 1 : nptr);
    return (acc);
}
