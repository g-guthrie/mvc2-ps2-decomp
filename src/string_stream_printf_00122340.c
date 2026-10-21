/*
 * Recovered string-output helper at 00122340. Returns the formatted length
 * from vfprintf; the caller at 003D7350 consumes this result.
 * The temporary FILE uses the same Newlib string-stream layout as the exact
 * reentrant sibling func_00122398 in src/m6w9e.c.
 */
#include "newlib_stdio_types.h"

typedef char *va_list;

extern Reent *D_0043B6F8;
extern int func_001209B8(FILE *, const char *, va_list);

#define __SWR 0x0008
#define __SSTR 0x0200

int func_00122340(char *str, const char *fmt, va_list ap)
{
    FILE fake;
    int result;

    fake._flags = __SWR | __SSTR;
    fake._bf._base = fake._p = (unsigned char *)str;
    fake._bf._size = fake._w = 0x7FFFFFFF;
    fake._data = D_0043B6F8;
    result = func_001209B8(&fake, fmt, ap);
    *fake._p = 0;
    return result;
}
