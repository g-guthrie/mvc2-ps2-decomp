/*
 * Adapted from newlib 1.10.0 newlib/libc/stdio/flags.c::__sflags.
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
#define __SRD 4
#define __SWR 8
#define __SAPP 0x100
#define __SRW 0x10
#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2
#define O_CREAT 0x200
#define O_TRUNC 0x400
#define O_APPEND 0x8
#define EINVAL 22
s32 func_0011B838(Reent *ptr, char *mode, s32 *optr)
{
    s32 ret, m, o;
    switch (mode[0]) {
    case 'r':
        ret = __SRD;
        m = O_RDONLY;
        o = 0;
        break;
    case 'w':
        ret = __SWR;
        m = O_WRONLY;
        o = O_CREAT | O_TRUNC;
        break;
    case 'a':
        ret = __SWR | __SAPP;
        m = O_WRONLY;
        o = O_CREAT | O_APPEND;
        break;
    default:
        ptr->_errno = EINVAL;
        return 0;
    }
    if (mode[1] && (mode[1] == '+' || mode[2] == '+')) {
        ret = __SRW;
        m = O_RDWR;
    }
    if (mode[1] && (mode[1] == 'b' || mode[2] == 'b')) {
#ifdef O_BINARY
        m |= O_BINARY;
#endif
    }
#ifdef __CYGWIN__
    else if (mode[1] && (mode[1] == 't' || mode[2] == 't'))
#else
    else
#endif
    {
#ifdef O_TEXT
        m |= O_TEXT;
#endif
    }
    *optr = m | o;
    return ret;
}
