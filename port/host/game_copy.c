/*
 * The game's own byte copies, which have no credited C (the port linked
 * empty generated stubs, so every copy through them did nothing).  The
 * retail code, byte for byte (no return value: neither sets $v0):
 *
 *   func_003F5630(dst, src, n)  forward copy of n bytes when n > 0
 *                               (unrolled by 8; overlap is not handled)
 *   func_003F5710(dst, src, n)  memmove: backwards when src < dst < src + n,
 *                               forwards otherwise
 *
 * Callers: src/nq242_a.c, src/nq235_a.c (func_003F5630); src/r11_11_e.c,
 * the texture pool's compaction (func_003F5710).
 */
#include "host.h"

void func_003F5630(int a0, int a1, int a2)
{
    s8 *d = (s8 *)(uintptr_t)a0;
    const s8 *s = (const s8 *)(uintptr_t)a1;
    int i;
    for (i = 0; i < a2; i++)
        d[i] = s[i];
}

void func_003F5710(int a0, int a1, int a2)
{
    s8 *d = (s8 *)(uintptr_t)a0;
    const s8 *s = (const s8 *)(uintptr_t)a1;
    int i;
    if ((uintptr_t)s < (uintptr_t)d && (uintptr_t)d < (uintptr_t)(s + a2)) {
        for (i = a2 - 1; i >= 0; i--)
            d[i] = s[i];
    } else {
        for (i = 0; i < a2; i++)
            d[i] = s[i];
    }
}
