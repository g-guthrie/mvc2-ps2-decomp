typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern const u32 jtbl_004C20F8[16] __attribute__((section(".sdata")));

void func_003C32F0(u8 *p, u8 *q)
{
    u32 t;
    s32 v;
    if (q[5] != 0) {
        t = p[4];
        p[4] = t + 1;
        return;
    }
    if (q[0x169] != 0x16) {
        t = p[4];
        p[4] = t + 1;
        return;
    }
    ((void (*)(u8 *, u8 *))jtbl_004C20F8[10 + p[5]])(p, q);
    v = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    p[0x24] = (u8)v;
    if (*(s8 *)(p + 0x24) > 7)
        p[0x24] = 7;
    if (*(s8 *)(p + 0x24) < 0)
        p[0x24] = 0;
}
