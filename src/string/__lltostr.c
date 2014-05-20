#include "../../string.h"
#include <xC/xmemory.h>
#include "./printf_.h"


int __lltostr(char *s, int size, xuint64_t i, int base, char UpCase)
{
  char *tmp;
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
    if ((*tmp=(char)(i%base+'0'))>'9') *tmp+=(UpCase?'A':'a')-'9'-1;
    i=i/base;
    j++;
  }
  xmemory_move(s,tmp,j+1);

  return j;
}
