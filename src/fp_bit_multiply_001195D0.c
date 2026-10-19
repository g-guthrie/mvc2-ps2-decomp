/*
 * Adapted from GCC 2.95.3 gcc/config/fp-bit.c::_fpmul_parts and multiply.
 * Copyright (C) 1994-1998 Free Software Foundation, Inc.
 * SPDX-License-Identifier: GPL-2.0-or-later WITH GCC-exception-2.0
 * Upstream source revision: releases/gcc-2.95.3
 * (7f236610e99c7a11fb18f056b6446b3c7c40979).
 * The upstream final guard-bit rounding block is omitted because this retail
 * runtime truncates those guard bits before calling the mapped pack routine.
 * The zero-initialized fp_number_type NaN object is mapped at D_004AC6E8;
 * no data coverage is claimed for that symbol here.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long long UDItype;
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
#define FRAC_NBITS 64
#define FRACHIGH 0x8000000000000000ULL
#define FRACHIGH2 0xC000000000000000ULL
#define IMPLICIT_1 ((fractype)1 << 60)
#define IMPLICIT_2 ((fractype)1 << 61)
#define LSHIFT(a) ((a) = ((a) & 1) | ((a) >> 1))
#define isnan(x) ((x)->cls < 2)
#define isinf(x) (((x)->cls ^ CLASS_INFINITY) == 0)
#define iszero(x) (((x)->cls ^ CLASS_ZERO) == 0)
static __inline__ fp_number_type *fpmul_parts(fp_number_type *a, fp_number_type *b, fp_number_type *tmp)
{
    fractype low = 0;
    fractype high = 0;
    if (isnan(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isnan(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }
    if (isinf(a)) {
        if (iszero(b)) return &D_004AC6E8;
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isinf(b)) {
        if (iszero(a)) return &D_004AC6E8;
        b->sign = a->sign != b->sign;
        return b;
    }
    if (iszero(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (iszero(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }
    {
        UDItype nl = a->fraction.ll & 0xFFFFFFFF;
        UDItype nh = a->fraction.ll >> 32;
        UDItype ml = b->fraction.ll & 0xFFFFFFFF;
        UDItype mh = b->fraction.ll >> 32;
        UDItype pp_ll = ml * nl;
        UDItype pp_hl = mh * nl;
        UDItype pp_lh = ml * nh;
        UDItype pp_hh = mh * nh;
        UDItype res2 = 0;
        UDItype res0 = 0;
        UDItype ps_hh__ = pp_hl + pp_lh;
        if (ps_hh__ < pp_hl) res2 += 0x100000000LL;
        pp_hl = (ps_hh__ << 32) & 0xFFFFFFFF00000000LL;
        res0 = pp_ll + pp_hl;
        if (res0 < pp_ll) res2++;
        res2 += ((ps_hh__ >> 32) & 0xFFFFFFFFL) + pp_hh;
        high = res2;
        low = res0;
    }
    tmp->normal_exp = a->normal_exp + b->normal_exp;
    tmp->sign = a->sign != b->sign;
    tmp->normal_exp += 4;
    while (high >= IMPLICIT_2) {
        tmp->normal_exp++;
        if (high & 1) {
            low >>= 1;
            low |= FRACHIGH;
        }
        high >>= 1;
    }
    while (high < IMPLICIT_1) {
        tmp->normal_exp--;
        high <<= 1;
        if (low & FRACHIGH) high |= 1;
        low <<= 1;
    }
    tmp->fraction.ll = high;
    tmp->cls = CLASS_NUMBER;
    return tmp;
}
double func_001195D0(double arg_a, double arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type *res;
    func_001191F0((u64 *)&arg_a, &a);
    func_001191F0((u64 *)&arg_b, &b);
    res = fpmul_parts(&a, &b, &tmp);
    return func_00119118(res);
}
