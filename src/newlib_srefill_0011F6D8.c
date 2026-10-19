/*
 * Adapted from newlib 1.10.0 newlib/libc/stdio/refill.c::__srefill.
 * SPDX-License-Identifier: BSD-4-Clause
 * Upstream sourceware revision: newlib-1_10_0
 * (ffbf3c2fe5af89ba84aad3359964ead31121b7ad).
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
#include "newlib_stdio_types.h"
extern Reent *D_0043B6F8;
extern void func_0011B7A8(Reent *);
extern int func_0011B480(FILE *);
extern int func_0011F6A0(FILE *);
extern void func_0011CA18(FILE *);
extern int func_0011C838(Reent *, int (*)(FILE *));
extern void func_0011BAE0(void *, void *);
#define __SRD 0x0004
#define __SWR 0x0008
#define __SRW 0x0010
#define __SEOF 0x0020
#define __SERR 0x0040
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SMBF 0x0080
#define __SMOD 0x2000
#define EOF (-1)
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_0043B6F8; if (!(fp)->_data->__sdidinit) func_0011B7A8((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub._base != 0)
#define FREEUB(fp) { if ((fp)->_ub._base != (fp)->_ubuf) func_0011BAE0((fp)->_data, (char *)(fp)->_ub._base); (fp)->_ub._base = 0; }
int func_0011F6D8(register FILE *fp)
{
    CHECK_INIT(fp);
    fp->_r = 0;
    if (fp->_flags & __SEOF) return EOF;
    if ((fp->_flags & __SRD) == 0) {
        if ((fp->_flags & __SRW) == 0) return EOF;
        if (fp->_flags & __SWR) {
            if (func_0011B480(fp)) return EOF;
            fp->_flags &= ~__SWR;
            fp->_w = 0;
            fp->_lbfsize = 0;
        }
        fp->_flags |= __SRD;
    } else {
        if (HASUB(fp)) {
            FREEUB(fp);
            if ((fp->_r = fp->_ur) != 0) {
                fp->_p = fp->_up;
                return 0;
            }
        }
    }
    if (fp->_bf._base == 0) func_0011CA18(fp);
    if (fp->_flags & (__SLBF | __SNBF)) (void)func_0011C838(fp->_data, func_0011F6A0);
    fp->_p = fp->_bf._base;
    fp->_r = (*fp->_read)(fp->_cookie, (char *)fp->_p, fp->_bf._size);
    fp->_flags &= ~__SMOD;
    if (fp->_r <= 0) {
        if (fp->_r == 0) fp->_flags |= __SEOF;
        else { fp->_r = 0; fp->_flags |= __SERR; }
        return EOF;
    }
    return 0;
}
