#include "../../../system/varargsex.h"
#include "../../string.h"
#include "./printf_.h"

int tr_wsnprintf(wchar *dest, size_t size, const wchar *format, ...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vwsnprintf(dest,size,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
