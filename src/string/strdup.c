#include "../../string.h"
#include "../../../system/memory.h"

char * tr_strdup(const char * str)
{
  char * puf = (char *)malloc(strlen(str));

  if (NULL == puf)
  {
      return puf;
  }

  strcpy(puf, str);

  return puf;
}
