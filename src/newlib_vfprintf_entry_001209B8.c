/*
 * Adapted from Newlib 1.10.0 newlib/libc/stdio/vfprintf.c::VFPRINTF.
 * The source file identifies this function as RCS revision 1.28
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

extern Reent *D_0043B6F8;
extern void func_0011B7A8(Reent *);
extern int func_00120A30(Reent *, FILE *, const char *, va_list);

#define CHECK_INIT(fp) do { \
    if ((fp)->_data == 0) (fp)->_data = D_0043B6F8; \
    if (!(fp)->_data->__sdidinit) func_0011B7A8((fp)->_data); \
} while (0)

int func_001209B8(FILE *fp, const char *fmt0, va_list ap)
{
    CHECK_INIT(fp);
    return func_00120A30(fp->_data, fp, fmt0, ap);
}
