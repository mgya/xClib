#include <xC/xvarargs.h>
#include "../../string.h"
#include "./printf_.h"

int string_wsnprintf(xwchar_t *dest, xsize_t size, const xwchar_t *format, ...)
{
  int n;
  xva_list_t arg_ptr;
  XVA_START(arg_ptr, format);
  n=vwsnprintf(dest,size,format,arg_ptr);
  XVA_END (arg_ptr);
  return n;
}
