#include "../../string.h"
#include "../../../system/varargsex.h"
#include "./printf_.h"

int tr_sprintf(char *dest,const char *format,...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vsprintf(dest,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
