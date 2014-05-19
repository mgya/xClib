#include <xC/xvarargs.h>
#include "../../string.h"
#include <xC/xmemory.h>
#include "./printf_.h"

struct str_data {
  xwchar_t* str;
  xsize_t len;
  xsize_t size;
};

static xsize_t swrite(void*ptr, xsize_t nmemb, struct str_data* sd) {
  xsize_t tmp=sd->size-sd->len;
  if (tmp>0) {
    xsize_t len=nmemb;
    if (len>tmp) len=tmp;
    if (sd->str) {
      wcsncpy(sd->str+sd->len,(xwchar_t *)ptr,len);
     // xmemory_copy(sd->str+sd->len,ptr,len);
      sd->str[sd->len+len]=L'\0';
    }
    sd->len+=len;
  }
  return nmemb;
}

int string_vwsnprintf(xwchar_t* str, xsize_t size, const xwchar_t *format, xva_list_t arg_ptr) {
  int n;
//  struct str_data sd = { str, 0, size?size-1:0 };
//  struct arg_printf ap = { &sd, (int(*)(void*,xsize_t,void*)) swrite };
  struct str_data sd;
  struct arg_printf ap;
  sd.str = str;
  sd.len = 0;
  sd.size = size?size-1:0;
  ap.data = &sd;
  ap.put = (int(*)(void*,xsize_t,void*)) swrite;
  n=__v_wsprintf(&ap,format,arg_ptr);
  if (str && size && n>=0) {
    if (size!=(xsize_t)-1 && ((xsize_t)n>=size)) str[size-1]=0;
    else str[n]=0;
  }
  return n;
}
