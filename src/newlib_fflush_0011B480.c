/*
 * Adapted from newlib 1.10.0 newlib/libc/stdio/fflush.c.
 * SPDX-License-Identifier: BSD-4-Clause
 * Upstream sourceware revision: newlib-1_10_0
 * (ffbf3c2fe5af89ba84aad3359964ead31121b7ad).
 *
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley. The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef struct __sbuf { unsigned char *_base; int _size; } SBuf;
typedef struct __sFILE FILE;
typedef struct _reent {
    int _errno;
    FILE *_stdin;
    FILE *_stdout;
    FILE *_stderr;
    int _inc;
    char _emergency[25];
    int _current_category;
    const char *_current_locale;
    int __sdidinit;
    void (*__cleanup)(struct _reent *);
} Reent;
struct __sFILE {
    unsigned char *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    SBuf _bf;
    int _lbfsize;
    void *_cookie;
    int (*_read)(void *, char *, int);
    int (*_write)(void *, const char *, int);
    s32 (*_seek)(void *, s32, int);
    int (*_close)(void *);
    SBuf _ub;
    unsigned char *_up;
    int _ur;
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    SBuf _lb;
    int _blksize;
    int _offset;
    Reent *_data;
};
extern Reent *D_0043B6F8;
extern void func_0011B7A8(Reent *);
extern int func_0011C838(Reent *, int (*)(FILE *));
#define __SWR 0x0008
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SERR 0x0040
#define EOF (-1)
#define CHECK_INIT(fp) do { \
    if ((fp)->_data == 0) (fp)->_data = D_0043B6F8; \
    if (!(fp)->_data->__sdidinit) func_0011B7A8((fp)->_data); \
} while (0)
int func_0011B480(register FILE *fp)
{
    register unsigned char *p;
    register int n, t;
    if (fp == 0)
        return func_0011C838(D_0043B6F8, func_0011B480);
    CHECK_INIT(fp);
    t = fp->_flags;
    if ((t & __SWR) == 0 || (p = fp->_bf._base) == 0)
        return 0;
    n = fp->_p - p;
    fp->_p = p;
    fp->_w = t & (__SLBF | __SNBF) ? 0 : fp->_bf._size;
    while (n > 0) {
        t = (*fp->_write)(fp->_cookie, (char *)p, n);
        if (t <= 0) {
            fp->_flags |= __SERR;
            return EOF;
        }
        p += t;
        n -= t;
    }
    return 0;
}
