#include "../../string.h"
#include <xC/xmemory.h>

xwchar_t * string_wcsdup(const xwchar_t * str)
{
  xwchar_t * puf = (xwchar_t *)xmemory_alloc(wcslen(str));

  if (XNULL == puf)
  {
      return puf;
  }

  wcscpy(puf, str);

  return puf;
}
