#include "../../string.h"
#include <xC/xmemory.h>

char * string_strdup(const char * str)
{
  char * puf = (char *)xmemory_alloc(strlen(str));

  if (XNULL == puf)
  {
      return puf;
  }

  strcpy(puf, str);

  return puf;
}
