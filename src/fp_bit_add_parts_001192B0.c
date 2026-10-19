/*
 * Adapted from GCC 2.95.3 gcc/config/fp-bit.c::_fpadd_parts.
 * Copyright (C) 1994-1999 Free Software Foundation, Inc.
 * SPDX-License-Identifier: GPL-2.0-or-later WITH GCC-exception-2.0
 * Upstream source revision: releases/gcc-2.95.3
 * (7f236610e99c7a11fb18f056b6446b3c7c40979).
 * The corresponding zero-initialized fp_number_type NaN object is mapped at
 * D_004AC6E8; no data coverage is claimed for that symbol here.
 */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long fractype;
typedef signed long long intfrac;
typedef struct {
    u32 cls;
    s32 sign;
    s32 normal_exp;
    s32 pad;
    fractype fraction;
} fp_number_type;
extern fp_number_type D_004AC6E8;
#define CLASS_ZERO 2
#define CLASS_NUMBER 3
#define CLASS_INFINITY 4
#define IMPLICIT_1 ((fractype)1 << 60)
#define IMPLICIT_2 ((fractype)1 << 61)
#define FRAC_NBITS 64
#define LSHIFT(x) ((x) = ((x) & 1) | ((x) >> 1))
#define isnan(x) ((x)->cls < 2)
#define isinf(x) (((x)->cls ^ CLASS_INFINITY) == 0)
#define iszero(x) (((x)->cls ^ CLASS_ZERO) == 0)
fp_number_type *func_001192B0(fp_number_type *a, fp_number_type *b,
                              fp_number_type *tmp)
{
    intfrac tfraction;
    int a_normal_exp;
    int b_normal_exp;
    fractype a_fraction;
    fractype b_fraction;
    if (isnan(a)) return a;
    if (isnan(b)) return b;
    if (isinf(a)) {
        if (isinf(b) && a->sign != b->sign) return &D_004AC6E8;
        return a;
    }
    if (isinf(b)) return b;
    if (iszero(b)) {
        if (iszero(a)) {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return tmp;
        }
        return a;
    }
    if (iszero(a)) return b;
    {
        int diff;
        a_normal_exp = a->normal_exp;
        b_normal_exp = b->normal_exp;
        a_fraction = a->fraction;
        b_fraction = b->fraction;
        diff = a_normal_exp - b_normal_exp;
        if (diff < 0) diff = -diff;
        if (diff < FRAC_NBITS) {
            while (a_normal_exp > b_normal_exp) {
                b_normal_exp++;
                LSHIFT(b_fraction);
            }
            while (b_normal_exp > a_normal_exp) {
                a_normal_exp++;
                LSHIFT(a_fraction);
            }
        } else {
            if (a_normal_exp > b_normal_exp) {
                b_normal_exp = a_normal_exp;
                b_fraction = 0;
            } else {
                a_normal_exp = b_normal_exp;
                a_fraction = 0;
            }
        }
    }
    if (a->sign != b->sign) {
        if (a->sign) tfraction = -a_fraction + b_fraction;
        else tfraction = a_fraction - b_fraction;
        if (tfraction >= 0) {
            tmp->sign = 0;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction = tfraction;
        } else {
            tmp->sign = 1;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction = -tfraction;
        }
        while (tmp->fraction < IMPLICIT_1 && tmp->fraction) {
            tmp->fraction <<= 1;
            tmp->normal_exp--;
        }
    } else {
        tmp->sign = a->sign;
        tmp->normal_exp = a_normal_exp;
        tmp->fraction = a_fraction + b_fraction;
    }
    tmp->cls = CLASS_NUMBER;
    if (tmp->fraction >= IMPLICIT_2) {
        LSHIFT(tmp->fraction);
        tmp->normal_exp++;
    }
    return tmp;
}
