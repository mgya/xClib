#include "../../string.h"
#include "../../../system/memory.h"

wchar * tr_wcsdup(const wchar * str)
{
  wchar * puf = (wchar *)malloc(wcslen(str));

  if (NULL == puf)
  {
      return puf;
  }

  wcscpy(puf, str);

  return puf;
}
