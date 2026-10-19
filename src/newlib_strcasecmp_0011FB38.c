/*
 * SPDX-License-Identifier: BSD-4-Clause
 * Adapted from newlib 1.10.0 newlib/libc/string/strcasecmp.c and
 * newlib/libc/include/ctype.h, sourceware tag newlib-1_10_0
 * (ffbf3c2fe5af89ba84aad3359964ead31121b7ad). The Newlib distribution
 * provides the Berkeley terms below in COPYING.NEWLIB, section 1.
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
#define _U 01
extern const char _ctype_[];
#define isupper(c) ((_ctype_ + 1)[(unsigned)(c)] & _U)
#define tolower(c) __extension__ ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x; })

int func_0011FB38(const char *s1, const char *s2)
{
  while (*s1 != '\0' && tolower(*s1) == tolower(*s2))
    {
      s1++;
      s2++;
    }

  return tolower(*(unsigned char *) s1) - tolower(*(unsigned char *) s2);
}
