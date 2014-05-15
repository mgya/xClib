#-------------------------------------------------
#
# Project created by QtCreator 2014-05-15T15:55:49
#
#-------------------------------------------------

QT       -= core gui

TARGET = xClib
TEMPLATE = lib
CONFIG += staticlib
INCLUDEPATH = ../../../

SOURCES += \
    ../algorithm/bsearch.c \
    ../algorithm/qsort.c \
    ../ctype/isalnum.c \
    ../ctype/isalpha.c \
    ../ctype/isblank.c \
    ../ctype/iscntrl.c \
    ../ctype/isdigit.c \
    ../ctype/isgraph.c \
    ../ctype/islower.c \
    ../ctype/isprint.c \
    ../ctype/ispunct.c \
    ../ctype/isspace.c \
    ../ctype/isupper.c \
    ../ctype/iswalnum.c \
    ../ctype/iswalpha.c \
    ../ctype/iswblank.c \
    ../ctype/iswcntrl.c \
    ../ctype/iswdigit.c \
    ../ctype/iswgraph.c \
    ../ctype/iswlower.c \
    ../ctype/iswprint.c \
    ../ctype/iswpunct.c \
    ../ctype/iswspace.c \
    ../ctype/iswupper.c \
    ../ctype/iswxdigit.c \
    ../ctype/isxdigit.c \
    ../ctype/tolower.c \
    ../ctype/toupper.c \
    ../ctype/towlower.c \
    ../ctype/towupper.c \
    ../string/__dtostr.c \
    ../string/__dtowcs.c \
    ../string/__isinf.c \
    ../string/__isnan.c \
    ../string/__lltostr.c \
    ../string/__lltowcs.c \
    ../string/__ltostr.c \
    ../string/__ltowcs.c \
    ../string/__v_sprintf.c \
    ../string/__v_wsprintf.c \
    ../string/ffs.c \
    ../string/snprintf.c \
    ../string/sprintf.c \
    ../string/strcat.c \
    ../string/strchr.c \
    ../string/strcmp.c \
    ../string/strcpy.c \
    ../string/strcspn.c \
    ../string/strdup.c \
    ../string/stricmp.c \
    ../string/strlen.c \
    ../string/strncat.c \
    ../string/strncmp.c \
    ../string/strncpy.c \
    ../string/strnicmp.c \
    ../string/strpbrk.c \
    ../string/strrchr.c \
    ../string/strspn.c \
    ../string/strstr.c \
    ../string/strtod.c \
    ../string/strtoi.c \
    ../string/strtol.c \
    ../string/strtold.c \
    ../string/strtoui.c \
    ../string/strtoul.c \
    ../string/unitoutf.c \
    ../string/utftouni.c \
    ../string/vsnprintf.c \
    ../string/vsprintf.c \
    ../string/vwsnprintf.c \
    ../string/vwsprintf.c \
    ../string/wcscat.c \
    ../string/wcschr.c \
    ../string/wcscmp.c \
    ../string/wcscpy.c \
    ../string/wcscspn.c \
    ../string/wcsdup.c \
    ../string/wcsicmp.c \
    ../string/wcslen.c \
    ../string/wcsncat.c \
    ../string/wcsncmp.c \
    ../string/wcsncpy.c \
    ../string/wcsnicmp.c \
    ../string/wcspbrk.c \
    ../string/wcsrchr.c \
    ../string/wcsspn.c \
    ../string/wcsstr.c \
    ../string/wcstod.c \
    ../string/wcstoi.c \
    ../string/wcstol.c \
    ../string/wcstold.c \
    ../string/wcstoui.c \
    ../string/wcstoul.c \
    ../string/wsnprintf.c \
    ../string/wsprintf.c \
    ../math/abs.c \
    ../math/acos.c \
    ../math/asin.c \
    ../math/atan.c \
    ../math/atan2.c \
    ../math/ceil.c \
    ../math/copysign.c \
    ../math/cos.c \
    ../math/cosh.c \
    ../math/exp.c \
    ../math/expm1.c \
    ../math/fabs.c \
    ../math/finite.c \
    ../math/floor.c \
    ../math/fmod.c \
    ../math/frexp.c \
    ../math/hypot.c \
    ../math/kernel_cos.c \
    ../math/kernel_rem_pio2.c \
    ../math/kernel_sin.c \
    ../math/kernel_tan.c \
    ../math/labs.c \
    ../math/ldexp.c \
    ../math/log.c \
    ../math/log10.c \
    ../math/lround.c \
    ../math/modf.c \
    ../math/nan.c \
    ../math/pow.c \
    ../math/rem_pio2.c \
    ../math/round.c \
    ../math/scalbn.c \
    ../math/sin.c \
    ../math/sinh.c \
    ../math/sqrt.c \
    ../math/tan.c \
    ../math/tanh.c

HEADERS += \
    ../../algorithm.h \
    ../../ctype.h \
    ../../math.h \
    ../../string.h \
    ../ctype/ctype_.h \
    ../string/printf_.h \
    ../math/fdlibm.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
