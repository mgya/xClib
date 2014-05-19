#include "../../string.h"
#include "../../ctype.h"

xuint64_t string_strtoul(const char * nptr, char ** endptr, int base)
{
    register const char * s = nptr;
    register xuint64_t acc;
    register char c;
    register xuint64_t cutoff;
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

    cutoff = (xuint64_t)XUINT64_MAX / (xuint64_t)base;
    cutlim = (int)((xuint64_t)XUINT64_MAX % (xuint64_t)base);
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
        acc = XUINT64_MAX;
    } else if (neg)
        acc = (xuint64_t)(-(xint64_t)acc);
    if (endptr != 0)
        *endptr = (char *) (any ? s - 1 : nptr);
    return (acc);
}
