#include <xC/xvarargs.h>
#include "../../string.h"
#include "./printf_.h"

int string_wsprintf(xwchar_t *dest,const xwchar_t *format,...)
{
  int n;
  xva_list_t arg_ptr;
  XVA_START(arg_ptr, format);
  n=vwsprintf(dest,format,arg_ptr);
  XVA_END (arg_ptr);
  return n;
}
