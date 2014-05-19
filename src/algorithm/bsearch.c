#include "../../algorithm.h"

void * algorithm_bsearch(const void *key, const void *base, xsize_t num, xsize_t width, int (*compare)(const void *, const void *))
{
  char *lo = (char *) base;
  char *hi = (char *) base + (num - 1) * width;
  char *mid;
  unsigned int half;
  int result;
  while (lo <= hi)
  {
    if ((half = num / 2) != 0)
    {
      mid = lo + (num & 1 ? half : (half - 1)) * width;
      if (!(result = (*compare)(key,mid)))
        return mid;
      else if (result < 0)
      {
        hi = mid - width;
        num = num & 1 ? half : half-1;
      }
      else
      {
        lo = mid + width;
        num = half;
      }
    }
    else if (num)
      return ((*compare)(key,lo) ? XNULL : lo);
    else
      break;
  }
  return XNULL;
}

