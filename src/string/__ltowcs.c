#include "../../string.h"
#include "../../../system/memory.h"
#include "./printf_.h"

int __ltowcs(wchar *s, unsigned int size, unsigned long i, unsigned int base, int UpCase)
{
  wchar *tmp;
  unsigned int j=0;

  s[--size]=0;

  tmp=s+size;

  if ((base==0)||(base>36)) base=10;

  j=0;
  if (!i)
  {
    *(--tmp)='0';
    j=1;
  }

  while((tmp>s)&&(i))
  {
    tmp--;
    if ((*tmp=(wchar)(i%base+'0'))>'9') *tmp+=(UpCase?'A':'a')-'9'-1;
    i=i/base;
    j++;
  }
 // wcsncpy(s,tmp,j+1);
  memmove(s,tmp,(j+1)*sizeof(wchar));

  return j;
}
