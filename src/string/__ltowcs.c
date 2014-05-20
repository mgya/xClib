#include "../../string.h"
#include <xC/xmemory.h>
#include "./printf_.h"

int __ltowcs(xwchar_t *s, unsigned int size, unsigned long i, unsigned int base, int UpCase)
{
  xwchar_t *tmp;
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
    if ((*tmp=(xwchar_t)(i%base+'0'))>'9') *tmp+=(UpCase?'A':'a')-'9'-1;
    i=i/base;
    j++;
  }
 // wcsncpy(s,tmp,j+1);
  xmemory_move(s,tmp,(j+1)*sizeof(xwchar_t));

  return j;
}
