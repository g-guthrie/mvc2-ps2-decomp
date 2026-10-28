/*
 * Adapted from newlib 1.10.0 newlib/libc/stdlib/mprec.c (Balloc, Bfree,
 * multadd). SPDX-License-Identifier: HPND
 * David M. Gay, Copyright (c) 1991 by AT&T. See src/newlib_mprec_helpers.c
 * for the full upstream notice.
 *
 * EE GCC 2.96: -O2 -G0 -msoft-float. multadd must follow Balloc in this
 * unit: GCC 2.96 marks a function it has compiled (without -fexceptions) as
 * non-throwing, and reorg only looks past calls that cannot throw, so the
 * plain bnez retail uses after the Balloc call needs Balloc defined here.
 */
#include "newlib_stdio_types.h"

typedef unsigned int __ULong;
/* The shared Reent prefix stops at _p5s; _freelist follows it. */
typedef struct {
    Reent prefix;
    _Bigint **_freelist;
} MprecReent;

extern void *func_00119DC8(Reent *, unsigned int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
#define _calloc_r func_00119DC8
#define Balloc func_0011DA88
#define Bfree func_0011DB30
#define multadd func_0011DB60
#define Bcopy(x, y) memcpy((char *)&x->_sign, (char *)&y->_sign, y->_wds * sizeof(int) + 2 * sizeof(int))

_Bigint *
Balloc(Reent *ptr, int k)
{
  int x;
  _Bigint *rv;
  MprecReent *r = (MprecReent *) ptr;

  if (r->_freelist == 0)
    {
      r->_freelist = (_Bigint **) _calloc_r (ptr, sizeof (_Bigint *), 15 + 1);
      if (r->_freelist == 0)
        return 0;
    }

  if ((rv = r->_freelist[k]) != 0)
    {
      r->_freelist[k] = rv->_next;
    }
  else
    {
      x = 1 << k;
      rv = (_Bigint *) _calloc_r (ptr, 1, sizeof (_Bigint) + (x - 1) * sizeof (rv->_x));
      if (rv == 0)
        return 0;
      rv->_k = k;
      rv->_maxwds = x;
    }
  rv->_sign = rv->_wds = 0;
  return rv;
}

void
Bfree(Reent *ptr, _Bigint *v)
{
  MprecReent *r = (MprecReent *) ptr;

  if (v)
    {
      v->_next = r->_freelist[v->_k];
      r->_freelist[v->_k] = v;
    }
}

_Bigint *
multadd(Reent *ptr, _Bigint *b, int m, int a)
{
  int i, wds;
  __ULong *x, y;
  __ULong xi, z;
  _Bigint *b1;

  wds = b->_wds;
  x = b->_x;
  i = 0;
  do
    {
      xi = *x;
      y = (xi & 0xffff) * m + a;
      z = (xi >> 16) * m + (y >> 16);
      a = (int) (z >> 16);
      *x++ = (z << 16) + (y & 0xffff);
    }
  while (++i < wds);
  if (a)
    {
      if (wds >= b->_maxwds)
	{
	  b1 = Balloc (ptr, b->_k + 1);
	  Bcopy (b1, b);
	  Bfree (ptr, b);
	  b = b1;
	}
      b->_x[wds++] = a;
      b->_wds = wds;
    }
  return b;
}
