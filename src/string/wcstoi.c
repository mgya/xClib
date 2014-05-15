#include "../../string.h"
#include "../../ctype.h"

int tr_wcstoi(const wchar * nptr, wchar ** endptr, int base)
{
    register const wchar * s = nptr;
    register unsigned int acc;
    register wchar c;
    register unsigned int cutoff;
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

    cutoff = neg ? -(int)INT32_MIN : INT32_MAX;
    cutlim = (int)(cutoff % (unsigned int)base);
    cutoff /= (unsigned long)base;
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
    	acc = neg ? INT32_MIN : INT32_MAX;
    } else if (neg)
    	acc = (unsigned int)(-(int)acc);
    if (endptr != 0)
    	*endptr = (wchar *) (any ? s - 1 : nptr);
    return (acc);
}
