/*
 * Adapted from newlib 1.10.0 newlib/libc/stdlib/mprec.c.
 * SPDX-License-Identifier: HPND
 * Upstream sourceware revision: newlib-1_10_0 (ffbf3c2fe5af89ba84aad3359964ead31121b7ad).
 * David M. Gay, Copyright (c) 1991 by AT&T. The full upstream notice follows.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy or
 * modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY. IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 */
#include "newlib_stdio_types.h"

typedef signed int __Long;
typedef unsigned int __ULong;
#define Pack_32 1
#define Sign_Extend(a, b) ((void)0)
typedef unsigned short u16;
typedef unsigned int __uint32_t;
union double_union {
    double d;
    __uint32_t i[2];
};
#define word0(x) ((x).i[1])
#define word1(x) ((x).i[0])
#define Exp_shift 20
#define Exp_msk1 ((__uint32_t)0x00100000)
#define Exp_mask ((__uint32_t)0x7ff00000)
#define P 53
#define Bias 1023
#define Exp_1 ((__uint32_t)0x3ff00000)
#define Ebits 11
#define Frac_mask ((__uint32_t)0x000fffff)
#define Balloc func_0011DA88
#define Bfree func_0011DB30
#define multadd func_0011DB60
#define s2b func_0011DC68
#define hi0bits func_0011DD98
#define lo0bits func_0011DE18
#define mult func_0011DF10
#define lshift func_0011E220
#define cmp func_0011E378
#define diff func_0011E3E0
#define ulp func_0011E570
#define b2d func_0011E640
#define d2b func_0011E7D8
#define Storeinc(a, b, c) \
    (((unsigned short *)a)[1] = (unsigned short)(b), \
     ((unsigned short *)a)[0] = (unsigned short)(c), (a)++)
extern _Bigint *func_0011DA88(Reent *, int);
extern _Bigint *func_0011DB60(struct _reent *, _Bigint *, int, int);
extern _Bigint *func_0011DC68(struct _reent *, const char *, int, int, __ULong);
extern int func_0011DD98(__ULong);
extern _Bigint *func_0011DF10(struct _reent *, _Bigint *, _Bigint *);
extern _Bigint *func_0011E220(struct _reent *, _Bigint *, int);
extern int func_0011E378(_Bigint *, _Bigint *);
extern _Bigint *func_0011E3E0(struct _reent *, _Bigint *, _Bigint *);
extern double func_0011E570(double);
extern double func_0011E640(_Bigint *, int *);
extern _Bigint *func_0011E7D8(struct _reent *, double, int *, int *);
extern void func_0011DB30(Reent *, _Bigint *);
extern __ULong func_0011DE18(__ULong *);



_Bigint *
func_0011DC68(Reent *ptr, const char *s, int nd0, int nd, __ULong y9)
{
  _Bigint *b;
  int i, k;
  __Long x, y;

  x = (nd + 8) / 9;
  for (k = 0, y = 1; x > y; y <<= 1, k++);
#ifdef Pack_32
  b = Balloc (ptr, k);
  b->_x[0] = y9;
  b->_wds = 1;
#else
  b = Balloc (ptr, k + 1);
  b->_x[0] = y9 & 0xffff;
  b->_wds = (b->_x[1] = y9 >> 16) ? 2 : 1;
#endif

  i = 9;
  if (9 < nd0)
    {
      s += 9;
      do
	b = multadd (ptr, b, 10, *s++ - '0');
      while (++i < nd0);
      s++;
    }
  else
    s += 10;
  for (; i < nd; i++)
    b = multadd (ptr, b, 10, *s++ - '0');
  return b;
}

int
func_0011DD98(__ULong x)
{
  register int k = 0;

  if (!(x & 0xffff0000))
    {
      k = 16;
      x <<= 16;
    }
  if (!(x & 0xff000000))
    {
      k += 8;
      x <<= 8;
    }
  if (!(x & 0xf0000000))
    {
      k += 4;
      x <<= 4;
    }
  if (!(x & 0xc0000000))
    {
      k += 2;
      x <<= 2;
    }
  if (!(x & 0x80000000))
    {
      k++;
      if (!(x & 0x40000000))
	return 32;
    }
  return k;
}

_Bigint *
func_0011DF10(Reent *ptr, _Bigint *a, _Bigint *b)
{
  _Bigint *c;
  int k, wa, wb, wc;
  __ULong carry, y, z;
  __ULong *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
#ifdef Pack_32
  __ULong z2;
#endif

  if (a->_wds < b->_wds)
    {
      c = a;
      a = b;
      b = c;
    }
  k = a->_k;
  wa = a->_wds;
  wb = b->_wds;
  wc = wa + wb;
  if (wc > a->_maxwds)
    k++;
  c = Balloc (ptr, k);
  for (x = c->_x, xa = x + wc; x < xa; x++)
    *x = 0;
  xa = a->_x;
  xae = xa + wa;
  xb = b->_x;
  xbe = xb + wb;
  xc0 = c->_x;
#ifdef Pack_32
  for (; xb < xbe; xb++, xc0++)
    {
      if ((y = *xb & 0xffff) != 0)
	{
	  x = xa;
	  xc = xc0;
	  carry = 0;
	  do
	    {
	      z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
	      carry = z >> 16;
	      z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
	      carry = z2 >> 16;
	      Storeinc (xc, z2, z);
	    }
	  while (x < xae);
	  *xc = carry;
	}
      if ((y = *xb >> 16) != 0)
	{
	  x = xa;
	  xc = xc0;
	  carry = 0;
	  z2 = *xc;
	  do
	    {
	      z = (*x & 0xffff) * y + (*xc >> 16) + carry;
	      carry = z >> 16;
	      Storeinc (xc, z, z2);
	      z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
	      carry = z2 >> 16;
	    }
	  while (x < xae);
	  *xc = z2;
	}
    }
#else
  for (; xb < xbe; xc0++)
    {
      if (y = *xb++)
	{
	  x = xa;
	  xc = xc0;
	  carry = 0;
	  do
	    {
	      z = *x++ * y + *xc + carry;
	      carry = z >> 16;
	      *xc++ = z & 0xffff;
	    }
	  while (x < xae);
	  *xc = carry;
	}
    }
#endif
  for (xc0 = c->_x, xc = xc0 + wc; wc > 0 && !*--xc; --wc);
  c->_wds = wc;
  return c;
}



_Bigint *
func_0011E220(Reent *ptr, _Bigint *b, int k)
{
  int i, k1, n, n1;
  _Bigint *b1;
  __ULong *x, *x1, *xe, z;

#ifdef Pack_32
  n = k >> 5;
#else
  n = k >> 4;
#endif
  k1 = b->_k;
  n1 = n + b->_wds + 1;
  for (i = b->_maxwds; n1 > i; i <<= 1)
    k1++;
  b1 = Balloc (ptr, k1);
  x1 = b1->_x;
  for (i = 0; i < n; i++)
    *x1++ = 0;
  x = b->_x;
  xe = x + b->_wds;
#ifdef Pack_32
  if (k &= 0x1f)
    {
      k1 = 32 - k;
      z = 0;
      do
	{
	  *x1++ = *x << k | z;
	  z = *x++ >> k1;
	}
      while (x < xe);
      if ((*x1 = z) != 0)
	++n1;
    }
#else
  if (k &= 0xf)
    {
      k1 = 16 - k;
      z = 0;
      do
	{
	  *x1++ = *x << k & 0xffff | z;
	  z = *x++ >> k1;
	}
      while (x < xe);
      if (*x1 = z)
	++n1;
    }
#endif
  else
    do
      *x1++ = *x++;
    while (x < xe);
  b1->_wds = n1 - 1;
  Bfree (ptr, b);
  return b1;
}

int
func_0011E378(_Bigint *a, _Bigint *b)
{
  __ULong *xa, *xa0, *xb, *xb0;
  int i, j;

  i = a->_wds;
  j = b->_wds;
#ifdef DEBUG
  if (i > 1 && !a->_x[i - 1])
    Bug ("cmp called with a->_x[a->_wds-1] == 0");
  if (j > 1 && !b->_x[j - 1])
    Bug ("cmp called with b->_x[b->_wds-1] == 0");
#endif
  if (i -= j)
    return i;
  xa0 = a->_x;
  xa = xa0 + j;
  xb0 = b->_x;
  xb = xb0 + j;
  for (;;)
    {
      if (*--xa != *--xb)
	return *xa < *xb ? -1 : 1;
      if (xa <= xa0)
	break;
    }
  return 0;
}

_Bigint *
func_0011E3E0(Reent *ptr, _Bigint *a, _Bigint *b)
{
  _Bigint *c;
  int i, wa, wb;
  __Long borrow, y;		/* We need signed shifts here. */
  __ULong *xa, *xae, *xb, *xbe, *xc;
#ifdef Pack_32
  __Long z;
#endif

  i = cmp (a, b);
  if (!i)
    {
      c = Balloc (ptr, 0);
      c->_wds = 1;
      c->_x[0] = 0;
      return c;
    }
  if (i < 0)
    {
      c = a;
      a = b;
      b = c;
      i = 1;
    }
  else
    i = 0;
  c = Balloc (ptr, a->_k);
  c->_sign = i;
  wa = a->_wds;
  xa = a->_x;
  xae = xa + wa;
  wb = b->_wds;
  xb = b->_x;
  xbe = xb + wb;
  xc = c->_x;
  borrow = 0;
#ifdef Pack_32
  do
    {
      y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
      borrow = y >> 16;
      Sign_Extend (borrow, y);
      z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
      borrow = z >> 16;
      Sign_Extend (borrow, z);
      Storeinc (xc, z, y);
    }
  while (xb < xbe);
  while (xa < xae)
    {
      y = (*xa & 0xffff) + borrow;
      borrow = y >> 16;
      Sign_Extend (borrow, y);
      z = (*xa++ >> 16) + borrow;
      borrow = z >> 16;
      Sign_Extend (borrow, z);
      Storeinc (xc, z, y);
    }
#else
  do
    {
      y = *xa++ - *xb++ + borrow;
      borrow = y >> 16;
      Sign_Extend (borrow, y);
      *xc++ = y & 0xffff;
    }
  while (xb < xbe);
  while (xa < xae)
    {
      y = *xa++ + borrow;
      borrow = y >> 16;
      Sign_Extend (borrow, y);
      *xc++ = y & 0xffff;
    }
#endif
  while (!*--xc)
    wa--;
  c->_wds = wa;
  return c;
}

double
func_0011E570(double _x)
{
  union double_union x, a;
  register __Long L;

  x.d = _x;

  L = (word0 (x) & Exp_mask) - (P - 1) * Exp_msk1;
#ifndef Sudden_Underflow
  if (L > 0)
    {
#endif
#ifdef IBM
      L |= Exp_msk1 >> 4;
#endif
      word0 (a) = L;
#ifndef _DOUBLE_IS_32BITS
      word1 (a) = 0;
#endif

#ifndef Sudden_Underflow
    }
  else
    {
      L = -L >> Exp_shift;
      if (L < Exp_shift)
	{
	  word0 (a) = 0x80000 >> L;
#ifndef _DOUBLE_IS_32BITS
	  word1 (a) = 0;
#endif
	}
      else
	{
	  word0 (a) = 0;
	  L -= Exp_shift;
#ifndef _DOUBLE_IS_32BITS
         word1 (a) = L >= 31 ? 1 : 1 << (31 - L);
#endif
	}
    }
#endif
  return a.d;
}

double
func_0011E640(_Bigint *a, int *e)
{
  __ULong *xa, *xa0, w, y, z;
  int k;
  union double_union d;
#ifdef VAX
  __ULong d0, d1;
#else
#define d0 word0(d)
#define d1 word1(d)
#endif

  xa0 = a->_x;
  xa = xa0 + a->_wds;
  y = *--xa;
#ifdef DEBUG
  if (!y)
    Bug ("zero y in b2d");
#endif
  k = hi0bits (y);
  *e = 32 - k;
#ifdef Pack_32
  if (k < Ebits)
    {
      d0 = Exp_1 | y >> (Ebits - k);
      w = xa > xa0 ? *--xa : 0;
#ifndef _DOUBLE_IS_32BITS
      d1 = y << ((32 - Ebits) + k) | w >> (Ebits - k);
#endif
      goto ret_d;
    }
  z = xa > xa0 ? *--xa : 0;
  if (k -= Ebits)
    {
      d0 = Exp_1 | y << k | z >> (32 - k);
      y = xa > xa0 ? *--xa : 0;
#ifndef _DOUBLE_IS_32BITS
      d1 = z << k | y >> (32 - k);
#endif
    }
  else
    {
      d0 = Exp_1 | y;
#ifndef _DOUBLE_IS_32BITS
      d1 = z;
#endif
    }
#else
  if (k < Ebits + 16)
    {
      z = xa > xa0 ? *--xa : 0;
      d0 = Exp_1 | y << k - Ebits | z >> Ebits + 16 - k;
      w = xa > xa0 ? *--xa : 0;
      y = xa > xa0 ? *--xa : 0;
      d1 = z << k + 16 - Ebits | w << k - Ebits | y >> 16 + Ebits - k;
      goto ret_d;
    }
  z = xa > xa0 ? *--xa : 0;
  w = xa > xa0 ? *--xa : 0;
  k -= Ebits + 16;
  d0 = Exp_1 | y << k + 16 | z << k | w >> 16 - k;
  y = xa > xa0 ? *--xa : 0;
  d1 = w << k + 16 | y << k;
#endif
ret_d:
#ifdef VAX
  word0 (d) = d0 >> 16 | d0 << 16;
  word1 (d) = d1 >> 16 | d1 << 16;
#else
#undef d0
#undef d1
#endif
  return d.d;
}

_Bigint *
func_0011E7D8(Reent *ptr, double _d, int *e, int *bits)
{
  union double_union d;
  _Bigint *b;
  int de, i, k;
  __ULong *x, y, z;
#ifdef VAX
  __ULong d0, d1;
#endif
  d.d = _d;
#ifdef VAX
  d0 = word0 (d) >> 16 | word0 (d) << 16;
  d1 = word1 (d) >> 16 | word1 (d) << 16;
#else
#define d0 word0(d)
#define d1 word1(d)
  d.d = _d;
#endif

#ifdef Pack_32
  b = Balloc (ptr, 1);
#else
  b = Balloc (ptr, 2);
#endif
  x = b->_x;

  z = d0 & Frac_mask;
  d0 &= 0x7fffffff;		/* clear sign bit, which we ignore */
#ifdef Sudden_Underflow
  de = (int) (d0 >> Exp_shift);
#ifndef IBM
  z |= Exp_msk11;
#endif
#else
  if ((de = (int) (d0 >> Exp_shift)) != 0)
    z |= Exp_msk1;
#endif
#ifdef Pack_32
#ifndef _DOUBLE_IS_32BITS
  if (d1)
    {
      y = d1;
      k = lo0bits (&y);
      if (k)
	{
         x[0] = y | z << (32 - k);
	  z >>= k;
	}
      else
	x[0] = y;
      i = b->_wds = (x[1] = z) ? 2 : 1;
    }
  else
#endif
    {
#ifdef DEBUG
      if (!z)
	Bug ("Zero passed to d2b");
#endif
      k = lo0bits (&z);
      x[0] = z;
      i = b->_wds = 1;
#ifndef _DOUBLE_IS_32BITS
      k += 32;
#endif
    }
#else
  if (d1)
    {
      y = d1;
      k = lo0bits (&y);
      if (k)
	if (k >= 16)
	  {
	    x[0] = y | z << 32 - k & 0xffff;
	    x[1] = z >> k - 16 & 0xffff;
	    x[2] = z >> k;
	    i = 2;
	  }
	else
	  {
	    x[0] = y & 0xffff;
	    x[1] = y >> 16 | z << 16 - k & 0xffff;
	    x[2] = z >> k & 0xffff;
	    x[3] = z >> k + 16;
	    i = 3;
	  }
      else
	{
	  x[0] = y & 0xffff;
	  x[1] = y >> 16;
	  x[2] = z & 0xffff;
	  x[3] = z >> 16;
	  i = 3;
	}
    }
  else
    {
#ifdef DEBUG
      if (!z)
	Bug ("Zero passed to d2b");
#endif
      k = lo0bits (&z);
      if (k >= 16)
	{
	  x[0] = z;
	  i = 0;
	}
      else
	{
	  x[0] = z & 0xffff;
	  x[1] = z >> 16;
	  i = 1;
	}
      k += 32;
    }
  while (!x[i])
    --i;
  b->_wds = i + 1;
#endif
#ifndef Sudden_Underflow
  if (de)
    {
#endif
#ifdef IBM
      *e = (de - Bias - (P - 1) << 2) + k;
      *bits = 4 * P + 8 - k - hi0bits (word0 (d) & Frac_mask);
#else
      *e = de - Bias - (P - 1) + k;
      *bits = P - k;
#endif
#ifndef Sudden_Underflow
    }
  else
    {
      *e = de - Bias - (P - 1) + 1 + k;
#ifdef Pack_32
      *bits = 32 * i - hi0bits (x[i - 1]);
#else
      *bits = (i + 2) * 16 - hi0bits (x[i]);
#endif
    }
#endif
  return b;
}
