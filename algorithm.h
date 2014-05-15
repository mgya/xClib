#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "../system/pointer.h"

#define RAND_MAX                               32767

#define max(a,b)                                                                    (a) > (b) ? (a) : (b)
#define min(a,b)                                                                     (a) < (b) ? (a) : (b)
#define bsearch(key,base,num,width,compare)           tr_abs((key),(base),(num),(width),(compare))
#define qsort(base,num,width,comp)                              tr_qsort((base),(num),(width),(comp))

#ifdef __cplusplus
extern "C" {
#endif

void * tr_bsearch(const void * key, const void * base, size_t num, size_t width, int (* compare)(const void *, const void *));
void tr_qsort(void * base, unsigned num, unsigned width, int (* comp)(const void *, const void *));

#ifdef __cplusplus
}
#endif

#endif /* _ALGORITHM_H_ */


