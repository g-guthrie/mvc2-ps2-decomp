/*
 * Adapted from newlib/libc/stdio/vfprintf.c, static cvt() helper.
 * Upstream snapshot: native_client/nacl-newlib commit
 * ae3c49ca6ea1e77e9292a255ef55c477c512f8c9; embedded RCS revision:
 * vfprintf.c 1.28, 1999-07-05 18:51:05.
 * SPDX-License-Identifier: BSD-4-Clause
 */
/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include "newlib_stdio_types.h"

typedef unsigned int __uint32_t;
union double_union {
    double d;
    __uint32_t i[2];
};
#define word0(x) ((x).i[1])
#define Sign_bit ((__uint32_t)0x80000000)
#define ALT 0x001

extern char *func_0011A108(Reent *, double, int, int, int *, int *, char **);
extern int func_00119AB8(double, double);

static char *func_001220A0(data, value, ndigits, flags, sign, decpt, ch, length)
Reent *data;
double value;
int ndigits, flags, *decpt, ch, *length;
char *sign;
{
    int mode, dsgn;
    char *digits, *bp, *rve;
    union double_union tmp;

    if (ch == 'f') {
        mode = 3;
    } else {
        if (ch == 'e' || ch == 'E') ndigits++;
        mode = 2;
    }
    tmp.d = value;
    if (word0(tmp) & Sign_bit) {
        value = -value;
        *sign = '-';
    } else {
        *sign = '\0';
    }
    digits = func_0011A108(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || (flags & ALT)) {
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && value) *decpt = -ndigits + 1;
            bp += *decpt;
        }
        if (value == 0) rve = bp;
        while (rve < bp) *rve++ = '0';
    }
    *length = rve - digits;
    return digits;
}
