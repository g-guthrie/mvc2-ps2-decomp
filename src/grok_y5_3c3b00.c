typedef unsigned char u8;
typedef signed char s8;

typedef unsigned int u32;
/* jtbl_00475DD0 (src/data/jtbl_00475DD0.c): every non-padding entry
 * (func_003C3B80, func_003C3DE0, func_003C4140, func_003C41C0, func_003C41F0,
 * func_003C4260, func_003C42C0) is defined as void f(u8 *, u8 *).
 * Slots 4..10 are the state handlers selected by p[4]. */
extern void (*const jtbl_00475DD0[11])(u8 *, u8 *);

void func_003C3B00(u8 *p, u8 *q)
{
    jtbl_00475DD0[4 + p[4]](p, q);
    p[0x24] = ((s8 *)q)[0x24] + (s8)p[0x31];
    if ((s8)p[0x24] > 7)
        p[0x24] = 7;
    if ((s8)p[0x24] < 0)
        p[0x24] = 0;
}
