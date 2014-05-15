#include "../../string.h"
#include "../../../system/varargsex.h"
#include "./printf_.h"

int tr_snprintf(char *dest, size_t size, const char *format, ...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vsnprintf(dest,size,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
