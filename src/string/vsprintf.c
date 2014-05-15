#include "../../../system/varargsex.h"
#include "../../string.h"
#include "./printf_.h"

int tr_vsprintf(char *dest,const char *format, va_list arg_ptr)
{
  return vsnprintf(dest,(size_t)-1,format,arg_ptr);
}
