/*
 * Adapted from GCC 2.95.3 gcc/config/fp-bit.c::pack_d.
 * Copyright (C) 1994-1998 Free Software Foundation, Inc.
 * SPDX-License-Identifier: GPL-2.0-or-later WITH GCC-exception-2.0
 * Upstream source revision: releases/gcc-2.95.3
 * (7f236610e99c7a11fb18f056b6446b3c7c40979).
 * Retail clamps denormals to zero and truncates guard bits; those target
 * behaviors are retained here.
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
typedef union {
    double value;
    fractype value_raw;
    struct { fractype fraction : 52 __attribute__((packed)); unsigned int exp : 11 __attribute__((packed)); unsigned int sign : 1 __attribute__((packed)); } bits;
} FLO_union_type;
#define CLASS_ZERO 2
#define CLASS_INFINITY 4
#define FRACBITS 52
#define EXPBITS 11
#define EXPBIAS 1023
#define EXPMAX 0x7FF
#define NGARDS 8
#define QUIET_NAN 0x0008000000000000ULL
#define FRAC_NBITS 64
#define iszero(x) (((x)->cls ^ CLASS_ZERO) == 0)
#define isinf(x) (((x)->cls ^ CLASS_INFINITY) == 0)
#define isnan(x) ((x)->cls < 2)
double func_00119118(fp_number_type *src)
{
    FLO_union_type dst;
    fractype fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;
    if (isnan(src)) {
        exp = EXPMAX;
        fraction |= QUIET_NAN;
    } else if (isinf(src)) {
        exp = EXPMAX;
        fraction = 0;
    } else if (iszero(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -1022) {
            exp = 0;
            fraction = 0;
        } else if (src->normal_exp > EXPBIAS) {
            exp = EXPMAX;
            fraction = 0;
        } else {
            exp = src->normal_exp + EXPBIAS;
            fraction >>= NGARDS;
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
