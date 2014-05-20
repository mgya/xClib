#include <xC/xvarargs.h>
#include "../../string.h"
#include "./printf_.h"

int string_vsprintf(char *dest,const char *format, xva_list_t arg_ptr)
{
  return vsnprintf(dest,(xsize_t)-1,format,arg_ptr);
}
