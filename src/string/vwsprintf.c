#include "../../../system/varargsex.h"
#include "../../string.h"
#include "./printf_.h"

int tr_vwsprintf(wchar *dest,const wchar *format, va_list arg_ptr)
{
  return vwsnprintf(dest,(size_t)-1,format,arg_ptr);
}
