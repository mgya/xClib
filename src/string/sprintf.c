#include "../../string.h"
#include <xC/xvarargs.h>
#include "./printf_.h"

int string_sprintf(char *dest,const char *format,...)
{
  int n;
  xva_list_t arg_ptr;
  XVA_START(arg_ptr, format);
  n=vsprintf(dest,format,arg_ptr);
  XVA_END (arg_ptr);
  return n;
}
