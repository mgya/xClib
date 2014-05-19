#include "../../string.h"
#include <xC/xvarargs.h>
#include "./printf_.h"

int string_snprintf(char *dest, xsize_t size, const char *format, ...)
{
  int n;
  xva_list_t arg_ptr;
  XVA_START(arg_ptr, format);
  n=vsnprintf(dest,size,format,arg_ptr);
  XVA_END (arg_ptr);
  return n;
}
