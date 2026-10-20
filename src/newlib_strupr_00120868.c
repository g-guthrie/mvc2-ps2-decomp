/* Newlib source ffbf3c2fe5af89ba84aad3359964ead31121b7ad, libc/string/strupr.c.
 * Original documentation follows. Character classifiers are original ctype.h definitions. */
extern const char _ctype_[];
#define islower(c) ((_ctype_+1)[(unsigned)(c)] & 02)
#define toupper(c) __extension__ ({ int __x=(c); islower(__x) ? (__x-'a'+'A') : __x; })
#define strupr func_00120868
/*
FUNCTION
        <<strupr>>---force string to uppercase

INDEX
        strupr

ANSI_SYNOPSIS

        char *strupr(char *<[a]>);

TRAD_SYNOPSIS

        char *strupr(<[a]>)
        char *<[a]>;

DESCRIPTION
        <<strupr>> converts each characters in the string at <[a]> to
        upper case.

RETURNS
        <<strupr>> returns its argument, <[a]>.

PORTABILITY
<<strupr>> is not widely portable.

<<strupr>> requires no supporting OS subroutines.

QUICKREF
        strupr */




char *
strupr (a)
     char *a;
{
  char *ret = a;

  while (*a != '\0')
    {
      if (islower (*a))
        *a = toupper (*a);
      ++a;
    }

  return ret;
}
