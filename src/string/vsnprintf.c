#include "../../../system/varargsex.h"
#include "../../string.h"
#include "../../../system/memory.h"
#include "./printf_.h"

struct str_data {
  char* str;
  size_t len;
  size_t size;
};

static size_t swrite(void*ptr, size_t nmemb, struct str_data* sd) {
  size_t tmp=sd->size-sd->len;
  if (tmp>0) {
    size_t len=nmemb;
    if (len>tmp) len=tmp;
    if (sd->str) {
      memcpy(sd->str+sd->len,ptr,len);
      sd->str[sd->len+len]=0;
    }
    sd->len+=len;
  }
  return nmemb;
}

int tr_vsnprintf(char* str, size_t size, const char *format, va_list arg_ptr) {
  int n;
//  struct str_data sd = { str, 0, size?size-1:0 };
//  struct arg_printf ap = { &sd, (int(*)(void*,size_t,void*)) swrite };
  struct str_data sd;
  struct arg_printf ap;
  sd.str = str;
  sd.len = 0;
  sd.size = size?size-1:0;
  ap.data = &sd;
  ap.put = (int(*)(void*,size_t,void*)) swrite;
  n=__v_sprintf(&ap,format,arg_ptr);
  if (str && size && n>=0) {
    if (size!=(size_t)-1 && ((size_t)n>=size)) str[size-1]=0;
    else str[n]=0;
  }
  return n;
}
