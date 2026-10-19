/*
 * Adapted from newlib 1.10.0 newlib/libc/stdio/fvwrite.c::__sfvwrite.
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

typedef unsigned int size_t;
typedef struct __siov { const char *iov_base; size_t iov_len; } SdkIoVector;
typedef struct __suio { SdkIoVector *uio_iov; int uio_iovcnt; int uio_resid; } SdkIoRequest;

extern int func_00122560(FILE *);
extern int func_0011B480(FILE *);
extern void *func_0011D7F0(void *, const void *, size_t);
extern void *func_0011D5C8(const void *, int, size_t);
#define __SWR 0x0008
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SERR 0x0040
#define __SSTR 0x0200
#define EOF (-1)
#define BUFSIZ 1024
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define COPY(n) (void)func_0011D7F0((void *)fp->_p, (const void *)p, (size_t)(n))
#define GETIOV(extra_work) do { while (len == 0) { extra_work; p=iov->iov_base; len=iov->iov_len; iov++; } } while (0)
int func_0011C458(register FILE *fp, register SdkIoRequest *uio)
{
    register size_t len;
    register const char *p;
    register SdkIoVector *iov;
    register int w, s;
    char *nl;
    int nlknown, nldist;
    if ((len = uio->uio_resid) == 0) return 0;
    if (((fp->_flags & __SWR) == 0 || fp->_bf._base == 0) && func_00122560(fp)) return EOF;
    iov = uio->uio_iov;
    len = 0;
    if (fp->_flags & __SNBF) {
        do {
            GETIOV( ; );
            w = (*fp->_write)(fp->_cookie, (char *)p, MIN(len, BUFSIZ));
            if (w <= 0) goto err;
            p += w; len -= w;
        } while ((uio->uio_resid -= w) != 0);
    } else if ((fp->_flags & __SLBF) == 0) {
        do {
            GETIOV( ; );
            w = fp->_w;
            if (fp->_flags & __SSTR) {
                if (len < w) w = len;
                COPY(w); fp->_w -= w; fp->_p += w; w = len;
            } else if (fp->_p > fp->_bf._base && len > w) {
                COPY(w); fp->_p += w;
                if (func_0011B480(fp)) goto err;
            } else if (len >= (w = fp->_bf._size)) {
                w = (*fp->_write)(fp->_cookie, (char *)p, w);
                if (w <= 0) goto err;
            } else {
                w = len; COPY(w); fp->_w -= w; fp->_p += w;
            }
            p += w; len -= w;
        } while ((uio->uio_resid -= w) != 0);
    } else {
        nlknown = 0;
        do {
            GETIOV(nlknown = 0;);
            if (!nlknown) {
                nl = (char *)func_0011D5C8((const void *)p, '\n', len);
                nldist = nl ? nl + 1 - p : len + 1;
                nlknown = 1;
            }
            s = MIN(len, nldist); w = fp->_w + fp->_bf._size;
            if (fp->_p > fp->_bf._base && s > w) {
                COPY(w); fp->_p += w;
                if (func_0011B480(fp)) goto err;
            } else if (s >= (w = fp->_bf._size)) {
                w = (*fp->_write)(fp->_cookie, (char *)p, w);
                if (w <= 0) goto err;
            } else {
                w = s; COPY(w); fp->_w -= w; fp->_p += w;
            }
            if ((nldist -= w) == 0) {
                if (func_0011B480(fp)) goto err;
                nlknown = 0;
            }
            p += w; len -= w;
        } while ((uio->uio_resid -= w) != 0);
    }
    return 0;
err:
    fp->_flags |= __SERR;
    return EOF;
}
