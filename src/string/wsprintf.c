#include "../../../system/varargsex.h"
#include "../../string.h"
#include "./printf_.h"

int tr_wsprintf(wchar *dest,const wchar *format,...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vwsprintf(dest,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
