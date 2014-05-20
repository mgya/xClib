#include "../../string.h"
#include "../../ctype.h"

unsigned int string_strtoui(const char * nptr, char ** endptr, int base)
{
    register const char * s = nptr;
    register unsigned int acc;
    register char c;
    register unsigned int cutoff;
    register int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while (isspace(c));
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
            c = s[1];
            s += 2;
            base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;

    cutoff = (unsigned int)XUINT32_MAX / (unsigned int)base;
    cutlim = (int)((unsigned int)XUINT32_MAX % (unsigned int)base);
    for (acc = 0, any = 0;; c = *s++) {
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c))
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
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
        acc = XUINT32_MAX;
    } else if (neg)
        acc = (unsigned int)(-(xint64_t)acc);
    if (endptr != 0)
        *endptr = (char *) (any ? s - 1 : nptr);
    return (acc);
}
