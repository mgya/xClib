#include <xC/xvarargs.h>
#include "../../string.h"
#include "./printf_.h"

#define MAX_WIDTH 10*1024

static unsigned long skip_to(const xwchar_t *format) {
  unsigned long nr;
  for (nr=0; format[nr] && (format[nr]!=L'%'); ++nr);
  return nr;
}

#define A_WRITE(fn,buf,sz)    ((fn)->put((void*)(buf),(sz),(fn)->data))
#define B_WRITE(fn,buf,sz)    { if ((unsigned long)(sz) > (((unsigned long)(int)(-1))>>1) || len+(int)(sz)<len) return -1; A_WRITE(fn,buf,sz); } while (0)

static const xwchar_t pad_line[2][16]= { {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'}, };
static int write_pad(unsigned int* dlen,struct arg_printf* fn, unsigned int len, int padwith) {
  int nr=0;
  if ((int)len<0 || *dlen+len<len) return -1;
  for (;len>15;len-=16,nr+=16) {
    A_WRITE(fn,pad_line[(padwith==L'0')?1:0],16);
  }
  if (len>0) {
    A_WRITE(fn,pad_line[(padwith==L'0')?1:0],(unsigned int)len); nr+=len;
  }
  *dlen += nr;
  return 0;
}

int __v_wsprintf(struct arg_printf* fn, const xwchar_t *format, xva_list_t arg_ptr)
{
  unsigned int len=0;

  while (*format) {
    unsigned long sz = skip_to(format);
    if (sz) {
      B_WRITE(fn,format,sz); len+=sz;
      format+=sz;
    }
    if (*format==L'%') {
      xwchar_t buf[128];
      union { xwchar_t*s; } u_str;
#define s u_str.s

      int retval;
      xwchar_t ch, padwith=L' ', precpadwith=L' ';

      xwchar_t flag_in_sign=0;
      xwchar_t flag_upcase=0;
      xwchar_t flag_hash=0;
      xwchar_t flag_left=0;
      xwchar_t flag_space=0;
      xwchar_t flag_sign=0;
      xwchar_t flag_dot=0;
      xwchar_t flag_long=0;

      unsigned int base;
      unsigned int width=0, preci=0;

      long number=0;
      xint64_t llnumber=0;

      ++format;
inn_printf:
      switch(ch=*format++) {
      case 0:
    return -1;
    break;

      /* FLAGS */
      case L'#':
    flag_hash=-1;
      case L'z':
    goto inn_printf;

      case L'h':
    --flag_long;
    goto inn_printf;
      case L'j':
      case L'q':    	/* BSD ... */
      case L'L':
    ++flag_long; /* fall through */
      case L'l':
    ++flag_long;
    goto inn_printf;

      case L'-':
    flag_left=1;
    goto inn_printf;

      case L' ':
    flag_space=1;
    goto inn_printf;

      case L'+':
    flag_sign=1;
    goto inn_printf;

      case L'0':
      case L'1':
      case L'2':
      case L'3':
      case L'4':
      case L'5':
      case L'6':
      case L'7':
      case L'8':
      case L'9':
    if(flag_dot) return -1;
    width=wcstoui(format-1,(xwchar_t**)&s,10);
    if (width>MAX_WIDTH) return -1;
    if (ch==L'0' && !flag_left) padwith=L'0';
    format=s;
    goto inn_printf;

      case L'*':
    width=XVA_ARG(arg_ptr,int);
    if (width>MAX_WIDTH) return -1; /* width is unsiged, so this catches <0, too */
    goto inn_printf;

      case L'.':
    flag_dot=1;
    if (*format==L'*') {
      int tmp=XVA_ARG(arg_ptr,int);
      preci=tmp<0?0:tmp;
      ++format;
    } else {
      long int tmp=wcstoi(format,(xwchar_t**)&s,10);
      preci=tmp<0?0:tmp;
      format=s;
    }
    if (preci>MAX_WIDTH) return -1;
    goto inn_printf;

      /* print a xwchar_t or % */
      case L'c':
    ch=(xwchar_t)XVA_ARG(arg_ptr,int);
      case L'%':
    B_WRITE(fn,&ch,1); ++len;
    break;
      /* print a string */
      case L's':
    s=XVA_ARG(arg_ptr,xwchar_t *);
    sz = (unsigned long)wcslen(s);
    if (flag_dot && sz>preci) sz=preci;
    preci=0;
    flag_dot^=flag_dot;
    padwith=precpadwith=L' ';

print_out:
      {
    xwchar_t *sign=s;
    int todo=0;
    
    if (! (width||preci) ) {
      B_WRITE(fn,s,sz); len+=sz;
      break;
    }
    
    if (flag_in_sign) todo=1;
    if (flag_hash>0)  todo=flag_hash;
    if (todo) {
      s+=todo;
      sz-=todo;
      width-=todo;
    }

    /* These are the cases for 1234 or "1234" respectively:
          %.6u -> "001234"
          %6u  -> "  1234"
          %06u -> "001234"
          %-6u -> "1234  "
          %.6s -> "1234"
          %6s  -> "  1234"
          %06s -> "  1234"
          %-6s -> "1234  "
          %6.5u -> " 01234"
          %6.5s -> "  1234"
           In this code, for %6.5s, 6 is width, 5 is preci.
       flag_dot means there was a '.' and preci is set.
       flag_left means there was a '-'.
       sz is 4 (strlen("1234")).
       padwith will be '0' for %06u, ' ' otherwise.
       precpadwith is '0' for %u, ' ' for %s.
     */

    if (flag_dot && width==0) width=preci;
    if (!flag_dot) preci=sz;
    if (!flag_left) { /* do left-side padding */
      if (write_pad(&len,fn,width-preci,padwith))
        return -1;
    }
    if (todo) {
      B_WRITE(fn,sign,todo);
      len+=todo;
    }
    /* do preci padding */
    if (write_pad(&len,fn,preci-sz,precpadwith))
      return -1;
    /* write actual string */
    B_WRITE(fn,s,sz); len+=sz;
    if (flag_left) {
      if (write_pad(&len,fn,width-preci,padwith))
        return -1;
    }
    
    break;
      }

      /* print an integer value */
      case L'b':
    base=2;
    sz=0;
    goto num_printf;
      case L'p':
    flag_hash=2;
    flag_long=1;
    ch=L'x';
      case L'X':
    flag_upcase=(ch==L'X');
      case L'x':
    base=16;
    sz=0;
    if (flag_hash) {
      buf[1]=L'0';
      buf[2]=ch;
      flag_hash=2;
      sz=2;
    }
    if (preci>width) width=preci;
    goto num_printf;
      case L'd':
      case L'i':
    flag_in_sign=1;
      case L'u':
    base=10;
    sz=0;
    goto num_printf;
      case L'o':
    base=8;
    sz=0;
    if (flag_hash) {
      buf[1]=L'0';
      flag_hash=1;
      ++sz;
    }

num_printf:
    s=buf+1;

    if (flag_long>0) {
      if (flag_long>1)
        llnumber=XVA_ARG(arg_ptr,xint64_t);
      else
        number=XVA_ARG(arg_ptr,long);
    }
    else {
      number=XVA_ARG(arg_ptr,int);
      if (sizeof(int) != sizeof(long) && !flag_in_sign)
        number&=((unsigned int)-1);
    }

    if (flag_in_sign) {
      if ((flag_long>1)&&(llnumber<0)) {
        llnumber=-llnumber;
        flag_in_sign=2;
      } 
      else if (number<0) {
          number=-number;
          flag_in_sign=2;
        }
    }
    if (flag_long<0) number&=0xffff;
    if (flag_long<-1) number&=0xff;
    if (flag_long>1)
      retval = __lltowcs(s+sz,sizeof(buf)/sizeof(xwchar_t)-5,(xuint64_t) llnumber,base,flag_upcase);
    else
      retval = __ltowcs(s+sz,sizeof(buf)/sizeof(xwchar_t)-5,(unsigned long) number,base,flag_upcase);

    /* When 0 is printed with an explicit precision 0, the output is empty. */
    if (flag_dot && retval == 1 && s[sz] == L'0') {
      if (preci == 0||flag_hash > 0) {
        sz = 0;
      }
      flag_hash = 0;
    } else sz += retval;

    if (flag_in_sign==2) {
      *(--s)=L'-';
      ++sz;
    } else if ((flag_in_sign)&&(flag_sign || flag_space)) {
      *(--s)=(flag_sign)?L'+':L' ';
      ++sz;
    } else flag_in_sign=0;

    precpadwith=L'0';

    goto print_out;

      /* print a floating point value */
      case L'f':
      case L'g':
	{
	  int g=(ch==L'g');
	  double d=XVA_ARG(arg_ptr,double);
	  s=buf+1;
	  if (width==0) width=1;
	  if (!flag_dot) preci=6;
	  if (flag_sign || d < +0.0) flag_in_sign=1;

	  sz=__dtowcs(d,s,sizeof(buf)/sizeof(xwchar_t)-1,width,preci,g);

	  if (flag_dot) {
	    xwchar_t *tmp;
	    if ((tmp=wcschr(s,L'.'))) {
	      if (preci || flag_hash) ++tmp;
	      while (preci>0 && *++tmp) --preci;
	      *tmp=0;
	    } else if (flag_hash) {
	      s[sz]=L'.';
	      s[++sz]=L'\0';
	    }
	  }

	  if (g) {
	    xwchar_t *tmp,*tmp1;	/* boy, is _this_ ugly! */
	    if ((tmp=wcschr(s,L'.'))) {
	      tmp1=wcschr(tmp,L'e');
	      while (*tmp) ++tmp;
	      if (tmp1) tmp=tmp1;
	      while (*--tmp==L'0') ;
	      if (*tmp!=L'.') ++tmp;
	      *tmp=0;
	      if (tmp1) wcscpy(tmp,tmp1);
	    }
	  }
	  
	  if ((flag_sign || flag_space) && d>=0) {
	    *(--s)=(flag_sign)?L'+':L' ';
	    ++sz;
	  }
	  
	  sz=wcslen(s);
	  if (width<sz) width=sz;
	  padwith='0';
	  flag_dot=0;
	  flag_hash=0;
	  goto print_out;
	}
      default:
    break;
      }
    }
  }
  return len;
}
