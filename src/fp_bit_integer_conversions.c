/* GCCfp-bit.c, source7f236610e99c7a11fb18f056b6446b3c7c40979; native double-to32-bit integer conversions. */
/* This is a software floating point library which can be used instead of
   the floating point routines in libgcc1.c for targets without hardware
   floating point.
 Copyright (C) 1994, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file with other programs, and to distribute
those programs without any restriction coming from the use of this
file.  (The General Public License restrictions do apply in other
respects; for example, they cover modification of the file, and
distribution when not linked into another program.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* As a special exception, if you link this library with other files,
   some of which are compiled with GCC, to produce an executable,
   this library does not by itself cause the resulting executable
   to be covered by the GNU General Public License.
   This exception does not however invalidate any other reasons why
   the executable file might be covered by the GNU General Public License.  */

typedef unsigned long long fractype;
typedef unsigned int halffractype;
typedef signed int SItype;
typedef unsigned int USItype;
typedef double FLO_type;
typedef enum { CLASS_SNAN,CLASS_QNAN,CLASS_ZERO,CLASS_NUMBER,CLASS_INFINITY } fp_class_type;
typedef struct { fp_class_type class; unsigned int sign; int normal_exp; union { fractype ll; halffractype l[2]; } fraction; } fp_number_type;
typedef union { double value; fractype value_raw; halffractype words[2]; } FLO_union_type;
extern void func_001191F0(FLO_union_type *,fp_number_type *);
#define unpack_d func_001191F0
#define isnan(x) ((x)->class < CLASS_ZERO)
#define isinf(x) (((x)->class ^ CLASS_INFINITY) == 0)
#define iszero(x) (((x)->class ^ CLASS_ZERO) == 0)
#define MAX_SI_INT 0x7fffffff
#define MAX_USI_INT 0xffffffffU
#define FRACBITS 52
#define NGARDS 8
SItype
func_00119BC0 (FLO_type arg_a)
{
  fp_number_type a;
  SItype tmp;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  /* get reasonable MAX_SI_INT... */
  if (isinf (&a))
    return a.sign ? (-MAX_SI_INT)-1 : MAX_SI_INT;
  /* it is a number, but a small one */
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > 30)
    return a.sign ? (-MAX_SI_INT)-1 : MAX_SI_INT;
  tmp = a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
  return a.sign ? (-tmp) : (tmp);
}

USItype
func_00119CE8 (FLO_type arg_a)
{
  fp_number_type a;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  /* it is a negative number */
  if (a.sign)
    return 0;
  /* get reasonable MAX_USI_INT... */
  if (isinf (&a))
    return MAX_USI_INT;
  /* it is a number, but a small one */
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > 31)
    return MAX_USI_INT;
  else if (a.normal_exp > (FRACBITS + NGARDS))
    return a.fraction.ll << (a.normal_exp - (FRACBITS + NGARDS));
  else
    return a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
}
