/*
 * Excerpted from GCC's gcc/libgcc2.c for the EE signed division wrappers.
 * Copyright (C) 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,
 * 2000 Free Software Foundation, Inc.
 * SPDX-License-Identifier: GPL-2.0-or-later WITH GCC-exception-2.0
 *
 * The GCC Runtime Library Exception permits linking the compiled version of
 * libgcc2.c into combinations with other programs without restrictions from
 * this file. GPL restrictions still apply to modifications and source
 * distributions.
 *
 * Upstream source pin: gcc-mirror/gcc commit
 * db2e2f480c906879dad6930e4fe0784a52814426; gcc/version.c identifies it as
 * "2.96 20000808 (experimental)".
 */
#ifndef GCC_LIBGCC_SIGNED_DIVMOD_CORE_H
#define GCC_LIBGCC_SIGNED_DIVMOD_CORE_H

#include "gcc_libgcc_udivmod_core.h"

static inline DWtype __negdi2(DWtype u)
{
    DWunion w;
    DWunion uu;

    uu.ll = u;
    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((UWtype)w.s.low > 0);
    return w.ll;
}

#endif /* GCC_LIBGCC_SIGNED_DIVMOD_CORE_H */
