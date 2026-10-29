/*
 * newlib's vfprintf core on the host (Port J).
 *
 * The game's printf family (printf func_0011EB60, sprintf func_0011F938,
 * vsprintf func_00122340/func_00122398, fprintf func_0011EB00, ...) all end
 * in _vfprintf_r = func_00120A30(reent, FILE *, fmt, va_list).  The credited
 * newlib C produced nothing on the host (empty strings), so the core is the
 * host's vsnprintf: string streams (__SSTR) get the bytes at fp->_p as
 * newlib would put them there, other streams (stdout) go to stderr.
 *
 * Formats are EE formats: `long` is 64-bit on the EE (hostify R1 makes it
 * long long), so `%l` becomes `%ll`.  va_list is a plain pointer on i386 and
 * wasm32 (hostify R15 makes the game's walkers host va_lists).
 */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "host.h"

typedef char va_check[sizeof(va_list) == 4 ? 1 : -1];

static void ee_format(char *out, size_t n, const char *f)
{
    size_t o = 0;
    while (*f && o + 3 < n) {
        if (*f != '%') {
            out[o++] = *f++;
            continue;
        }
        out[o++] = *f++;
        if (*f == '%') {
            out[o++] = *f++;
            continue;
        }
        while (*f && strchr("-+ #0123456789.*", *f) && o + 3 < n)
            out[o++] = *f++;
        if (*f == 'l' && f[1] != 'l') {
            out[o++] = 'l';
            out[o++] = 'l';
            f++;
        } else if (*f == 'q') { /* BSD quad */
            out[o++] = 'l';
            out[o++] = 'l';
            f++;
        }
    }
    out[o] = 0;
}

int func_00120A30(int reent, int fpi, int fmt, int ap)
{
    char fbuf[1024], tmp[4096];
    u8 *fp = (u8 *)(uintptr_t)fpi;
    va_list v;
    int n;
    (void)reent;
    if (!fmt)
        return 0;
    ee_format(fbuf, sizeof fbuf, (const char *)(uintptr_t)fmt);
    memcpy(&v, &ap, sizeof v);
    n = vsnprintf(tmp, sizeof tmp, fbuf, v);
    if (n < 0)
        return n;
    if (n >= (int)sizeof tmp)
        n = (int)sizeof tmp - 1;
    if (fp && (*(s16 *)(fp + 12) & 0x200)) { /* __SSTR: sprintf into fp->_p */
        u8 **p = (u8 **)fp;
        s32 *w = (s32 *)(fp + 8);
        int k = n < *w ? n : *w;
        memcpy(*p, tmp, (size_t)k);
        *p += k;
        *w -= k;
    } else {
        fputs("[ee] ", stderr);
        fwrite(tmp, 1, (size_t)n, stderr);
        if (n && tmp[n - 1] != '\n')
            fputc('\n', stderr);
    }
    return n;
}
