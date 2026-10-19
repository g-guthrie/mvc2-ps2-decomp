/*
 * Adapted from Newlib 1.10.0 newlib/libc/stdio/vfprintf.c::__sbprintf.
 * The source file identifies this helper as RCS revision 1.28
 * (1999-07-05 18:51:05 cgf).
 * SPDX-License-Identifier: BSD-4-Clause
 * Upstream sourceware release commit:
 * ffbf3c2fe5af89ba84aad3359964ead31121b7ad.
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

typedef char *va_list;

#define __SNBF 0x0002
#define __SERR 0x0040
#define EOF (-1)
#define BUFSIZ 1024

extern int func_001209B8(FILE *, const char *, va_list);
extern int func_0011B480(FILE *);

int func_00120900(FILE *fp, const char *fmt, va_list ap)
{
    int ret;
    FILE fake;
    unsigned char buf[BUFSIZ];

    fake._data = fp->_data;
    fake._flags = fp->_flags & ~__SNBF;
    fake._file = fp->_file;
    fake._cookie = fp->_cookie;
    fake._write = fp->_write;

    fake._bf._base = fake._p = buf;
    fake._bf._size = fake._w = sizeof(buf);
    fake._lbfsize = 0;

    ret = func_001209B8(&fake, fmt, ap);
    if (ret >= 0 && func_0011B480(&fake))
        ret = EOF;
    if (fake._flags & __SERR)
        fp->_flags |= __SERR;
    return ret;
}
