/*
    ctype_.h
    version : 0.1
*/

#ifndef _CTYPE_IMP_H_
#define _CTYPE_IMP_H_

#define    _U    01
#define    _L    02
#define    _N    04
#define    _S    010
#define _P    020
#define _C    040
#define _X    0100
#define    _B    0200

#define _CTYPE_DATA_0_127 \
    _C,    _C,    _C,    _C,    _C,    _C,    _C,    _C, \
    _C,    _C|_S,    _C|_S,    _C|_S,    _C|_S,    _C|_S,    _C,    _C, \
    _C,    _C,    _C,    _C,    _C,    _C,    _C,    _C, \
    _C,    _C,    _C,    _C,    _C,    _C,    _C,    _C, \
    _S|_B,    _P,    _P,    _P,    _P,    _P,    _P,    _P, \
    _P,    _P,    _P,    _P,    _P,    _P,    _P,    _P, \
    _N,    _N,    _N,    _N,    _N,    _N,    _N,    _N, \
    _N,    _N,    _P,    _P,    _P,    _P,    _P,    _P, \
    _P,    _U|_X,    _U|_X,    _U|_X,    _U|_X,    _U|_X,    _U|_X,    _U, \
    _U,    _U,    _U,    _U,    _U,    _U,    _U,    _U, \
    _U,    _U,    _U,    _U,    _U,    _U,    _U,    _U, \
    _U,    _U,    _U,    _P,    _P,    _P,    _P,    _P, \
    _P,    _L|_X,    _L|_X,    _L|_X,    _L|_X,    _L|_X,    _L|_X,    _L, \
    _L,    _L,    _L,    _L,    _L,    _L,    _L,    _L, \
    _L,    _L,    _L,    _L,    _L,    _L,    _L,    _L, \
    _L,    _L,    _L,    _P,    _P,    _P,    _P,    _C

#define _CTYPE_DATA_128_256 \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0

static const char _ctype_[1 + 256] = {
    0,
    _CTYPE_DATA_0_127,
    _CTYPE_DATA_128_256
};

#endif    /* _CTYPE_IMP_H_ */
