/*
 * Adapted from GCC 2.95.3 gcc/config/fp-bit.c::_fpdiv_parts and divide.
 * Copyright (C) 1994-1998 Free Software Foundation, Inc.
 * SPDX-License-Identifier: GPL-2.0-or-later WITH GCC-exception-2.0
 * Upstream source revision: releases/gcc-2.95.3
 * (7f236610e99c7a11fb18f056b6446b3c7c40979).
 * Retail truncates quotient guard bits before the mapped pack routine, so the
 * upstream final guard-bit rounding block is omitted here.
 * The zero-initialized fp_number_type NaN object is mapped at D_004AC6E8;
 * no data coverage is claimed for that symbol here.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef unsigned long long fractype;
typedef struct {
    u32 cls;
    u32 sign;
    s32 normal_exp;
    s32 pad;
    union { fractype ll; u32 l[2]; } fraction;
} fp_number_type;
extern fp_number_type D_004AC6E8;
extern void func_001191F0(u64 *src, fp_number_type *dst);
extern double func_00119118(fp_number_type *src);
#define CLASS_ZERO 2
#define CLASS_NUMBER 3
#define CLASS_INFINITY 4
#define IMPLICIT_1 ((fractype)1 << 60)
#define iszero(x) (((x)->cls ^ CLASS_ZERO) == 0)
#define isinf(x) (((x)->cls ^ CLASS_INFINITY) == 0)
#define isnan(x) ((x)->cls < 2)
static __inline__ fp_number_type *fpdiv_parts(fp_number_type *a, fp_number_type *b)
{
    fractype bit;
    fractype numerator;
    fractype denominator;
    fractype quotient;
    if (isnan(a)) return a;
    if (isnan(b)) return b;
    a->sign = a->sign ^ b->sign;
    if (isinf(a) || iszero(a)) {
        if (a->cls == b->cls) return &D_004AC6E8;
        return a;
    }
    if (isinf(b)) {
        a->fraction.ll = 0;
        a->normal_exp = 0;
        return a;
    }
    if (iszero(b)) {
        a->cls = CLASS_INFINITY;
        return a;
    }
    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;
    if (numerator < denominator) {
        numerator *= 2;
        a->normal_exp--;
    }
    bit = IMPLICIT_1;
    quotient = 0;
    while (bit) {
        if (numerator >= denominator) {
            quotient |= bit;
            numerator -= denominator;
        }
        bit >>= 1;
        numerator *= 2;
    }
    a->fraction.ll = quotient;
    return a;
}
double func_00119858(double arg_a, double arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type *res;
    func_001191F0((u64 *)&arg_a, &a);
    func_001191F0((u64 *)&arg_b, &b);
    res = fpdiv_parts(&a, &b);
    return func_00119118(res);
}
