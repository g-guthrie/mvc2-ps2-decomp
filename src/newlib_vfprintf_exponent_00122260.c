/*
 * Adapted from newlib/libc/stdio/vfprintf.c, static exponent() helper.
 * Upstream snapshot: native_client/nacl-newlib commit
 * ae3c49ca6ea1e77e9292a255ef55c477c512f8c9; embedded RCS revision:
 * vfprintf.c 1.28, 1999-07-05 18:51:05.
 * MAXEXP is 308 in the accompanying newlib/libc/stdio/floatio.h. The Newlib
 * ChangeLog entry dated 2000-12-06 (mirror revision
 * 78dd8bdd127522b7d503b2acc9271079a2462926) records changing exponent's
 * expbuf from MAXEXP to a smaller bound after long-double support; this
 * target retains the earlier source form.
 * SPDX-License-Identifier: BSD-4-Clause
 *
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted provided
 * that the above copyright notice and this paragraph are duplicated in all
 * such forms and that any documentation, advertising materials, and other
 * materials related to such distribution and use acknowledge that the
 * software was developed by the University of California, Berkeley. The
 * name of the University may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* Original bound from newlib/libc/stdio/floatio.h. */
#define MAXEXP 308
#define to_char(n) ((n) + '0')

int func_00122260(char *p0, int exp, int fmtch)
{
    register char *p, *t;
    char expbuf[MAXEXP];

    p = p0;
    *p++ = fmtch;
    if (exp < 0) {
        exp = -exp;
        *p++ = '-';
    } else {
        *p++ = '+';
    }
    t = expbuf + MAXEXP;
    if (exp > 9) {
        do {
            *--t = to_char(exp % 10);
        } while ((exp /= 10) > 9);
        *--t = to_char(exp);
        for (; t < expbuf + MAXEXP; *p++ = *t++)
            ;
    } else {
        *p++ = '0';
        *p++ = to_char(exp);
    }
    return p - p0;
}
