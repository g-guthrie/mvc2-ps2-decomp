/*
 * Adapted from newlib 1.10.0 newlib/libc/stdio/fclose.c.
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
extern int func_0011B480(FILE *);
extern void func_0011BAE0(void *, void *);
#define __SWR 0x0008
#define __SMBF 0x0080
#define EOF (-1)
#define CHECK_INIT(fp) do { \
    if ((fp)->_data == 0) (fp)->_data = D_0043B6F8; \
    if (!(fp)->_data->__sdidinit) func_0011B7A8((fp)->_data); \
} while (0)
#define HASUB(fp) ((fp)->_ub._base != 0)
#define FREEUB(fp) do { \
    if ((fp)->_ub._base != (fp)->_ubuf) \
        func_0011BAE0((fp)->_data, (char *)(fp)->_ub._base); \
    (fp)->_ub._base = 0; \
} while (0)
#define HASLB(fp) ((fp)->_lb._base != 0)
#define FREELB(fp) do { \
    func_0011BAE0((fp)->_data, (char *)(fp)->_lb._base); \
    (fp)->_lb._base = 0; \
} while (0)
int func_0011B380(register FILE *fp)
{
    int r;
    if (fp == 0) return 0;
    CHECK_INIT(fp);
    if (fp->_flags == 0) return 0;
    r = fp->_flags & __SWR ? func_0011B480(fp) : 0;
    if (fp->_close != 0 && (*fp->_close)(fp->_cookie) < 0)
        r = EOF;
    if (fp->_flags & __SMBF)
        func_0011BAE0(fp->_data, (char *)fp->_bf._base);
    if (HASUB(fp)) FREEUB(fp);
    if (HASLB(fp)) FREELB(fp);
    fp->_flags = 0;
    return r;
}
