/* Adapted excerpts from gcc/libgcc2.c and gcc/longlong.h.
 * Source pin: gcc-mirror/gcc db2e2f480c906879dad6930e4fe0784a52814426
 * (GCC 2.96 20000808). Longlong.h excerpts additionally carry
 * Copyright (C) 1991, 1992, 1994-2000 Free Software Foundation, Inc.
 * SPDX-License-Identifier: GPL-2.0-or-later WITH GCC-exception-2.0
 * The original libgcc2.c notice and linking exception follow verbatim.
 */
/* More subroutines needed by GCC output code on some machines.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1989, 92, 93, 94, 95, 96, 97, 98, 1999, 2000
   Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#ifndef GCC_LIBGCC_UDIVMOD_CORE_H
#define GCC_LIBGCC_UDIVMOD_CORE_H

/* The target is EE EABI with 32-bit words and 64-bit DImode values. */
#define BITS_PER_UNIT 8
#define LIBGCC2_WORDS_BIG_ENDIAN 0
#define MIN_UNITS_PER_WORD 4
#define W_TYPE_SIZE (4 * BITS_PER_UNIT)
typedef int QItype __attribute__((mode(QI)));
typedef unsigned int UQItype __attribute__((mode(QI)));
typedef int HItype __attribute__((mode(HI)));
typedef unsigned int UHItype __attribute__((mode(HI)));
typedef int SItype __attribute__((mode(SI)));
typedef unsigned int USItype __attribute__((mode(SI)));
typedef int DItype __attribute__((mode(DI)));
typedef unsigned int UDItype __attribute__((mode(DI)));
typedef int word_type __attribute__((mode(__word__)));
#define Wtype SItype
#define UWtype USItype
#define HWtype SItype
#define UHWtype USItype
#define DWtype DItype
#define UDWtype UDItype

struct DWstruct { Wtype low, high; };
typedef union { struct DWstruct s; DWtype ll; } DWunion;

#ifndef GCC_LIBGCC_CLZ_TABLE
#error Define GCC_LIBGCC_CLZ_TABLE to an existing 256-byte table symbol.
#endif
extern const UQItype GCC_LIBGCC_CLZ_TABLE[];
#define __clz_tab GCC_LIBGCC_CLZ_TABLE
#define __BITS4 (W_TYPE_SIZE / 4)
#define __ll_B ((UWtype) 1 << (W_TYPE_SIZE / 2))
#define __ll_lowpart(t) ((UWtype) (t) & (__ll_B - 1))
#define __ll_highpart(t) ((UWtype) (t) >> (W_TYPE_SIZE / 2))

/* GCC 2.96 longlong.h: generic subtraction and the MIPS multiply primitive. */
#define sub_ddmmss(sh, sl, ah, al, bh, bl) \
  do { UWtype __x; __x = (al) - (bl); \
       (sh) = (ah) - (bh) - (__x > (al)); (sl) = __x; } while (0)
#define umul_ppmm(w1, w0, u, v) \
  __asm__ ("multu %2,%3" \
           : "=l" ((USItype) (w0)), "=h" ((USItype) (w1)) \
           : "d" ((USItype) (u)), "d" ((USItype) (v)))
#define __udiv_qrnnd_c(q, r, n1, n0, d) \
  do { \
    UWtype __d1, __d0, __q1, __q0; \
    UWtype __r1, __r0, __m; \
    __d1 = __ll_highpart (d); __d0 = __ll_lowpart (d); \
    __r1 = (n1) % __d1; __q1 = (n1) / __d1; \
    __m = (UWtype) __q1 * __d0; \
    __r1 = __r1 * __ll_B | __ll_highpart (n0); \
    if (__r1 < __m) { \
      __q1--, __r1 += (d); \
      if (__r1 >= (d)) if (__r1 < __m) __q1--, __r1 += (d); \
    } \
    __r1 -= __m; \
    __r0 = __r1 % __d1; __q0 = __r1 / __d1; \
    __m = (UWtype) __q0 * __d0; \
    __r0 = __r0 * __ll_B | __ll_lowpart (n0); \
    if (__r0 < __m) { \
      __q0--, __r0 += (d); \
      if (__r0 >= (d)) if (__r0 < __m) __q0--, __r0 += (d); \
    } \
    __r0 -= __m; \
    (q) = (UWtype) __q1 * __ll_B | __q0; (r) = __r0; \
  } while (0)
#define UDIV_NEEDS_NORMALIZATION 1
#define udiv_qrnnd __udiv_qrnnd_c
#define count_leading_zeros(count, x) \
  do { \
    UWtype __xr = (x); UWtype __a; \
    if (W_TYPE_SIZE <= 32) \
      __a = __xr < ((UWtype)1<<2*__BITS4) \
        ? (__xr < ((UWtype)1<<__BITS4) ? 0 : __BITS4) \
        : (__xr < ((UWtype)1<<3*__BITS4) ? 2*__BITS4 : 3*__BITS4); \
    else \
      for (__a = W_TYPE_SIZE - 8; __a > 0; __a -= 8) \
        if (((__xr >> __a) & 0xff) != 0) break; \
    (count) = W_TYPE_SIZE - (__clz_tab[__xr >> __a] + __a); \
  } while (0)

static inline
UDWtype
__udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;

#if !UDIV_NEEDS_NORMALIZATION
  if (d1 == 0)
    {
      if (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      else
	{
	  /* qq = NN / 0d */

	  if (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      if (rp != 0)
	{
	  rr.s.low = n0;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }

#else /* UDIV_NEEDS_NORMALIZATION */

  if (d1 == 0)
    {
      if (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  count_leading_zeros (bm, d0);

	  if (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      else
	{
	  /* qq = NN / 0d */

	  if (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  count_leading_zeros (bm, d0);

	  if (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  else
	    {
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q1, n1, n2, n1, d0);
	    }

	  /* n1 != d0...  */

	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0 >> bm.  */
	}

      if (rp != 0)
	{
	  rr.s.low = n0 >> bm;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  else
    {
      if (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  if (rp != 0)
	    {
	      rr.s.low = n0;
	      rr.s.high = n1;
	      *rp = rr.ll;
	    }
	}
      else
	{
	  /* 0q = NN / dd */

	  count_leading_zeros (bm, d1);
	  if (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      if (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      else
		q0 = 0;

	      q1 = 0;

	      if (rp != 0)
		{
		  rr.s.low = n0;
		  rr.s.high = n1;
		  *rp = rr.ll;
		}
	    }
	  else
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      if (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      if (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.low = (n1 << b) | (n0 >> bm);
		  rr.s.high = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.low = q0;
  ww.s.high = q1;
  return ww.ll;
}

#endif /* GCC_LIBGCC_UDIVMOD_CORE_H */
