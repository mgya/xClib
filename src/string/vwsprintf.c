#include <xC/xvarargs.h>
#include "../../string.h"
#include "./printf_.h"

int string_vwsprintf(xwchar_t *dest,const xwchar_t *format, xva_list_t arg_ptr)
{
  return vwsnprintf(dest,(xsize_t)-1,format,arg_ptr);
}
