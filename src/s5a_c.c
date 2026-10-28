/* EE GCC 2.96: ./tryee.sh src/s5a_c.c sn
 * func_003F89D8 (moved from w1812_i.c) is defined first: func_003F8AF8's
 * scheduling only matches with its callee already compiled in this file. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
s32 func_003F89D8(u8 *p, s32 x, s16 *o2, s8 *a3, s8 *t0, s8 *t1, s8 *t2, s32 *t3, s32 *t6, s32 *t5, s16 *a1) {
    *o2 = p[7] << 4;
    *t2 = (p[9] & 3) + 1;
    *t3 = *(u16 *)(p + 0x2A);
    switch (p[8]) {
    case 0:
        *t0 = 0x10;
        { s32 v = *t2; *t1 = v << 1; }
        *t5 = 1;
        *a1 = 0;
        *t6 = *(s32 *)(p + 0xC) / 2;
        break;
    case 1:
        *t0 = 8;
        { s32 v = *t2; *t1 = v; }
        *t5 = 1;
        *a1 = 1;
        *t6 = *(s32 *)(p + 0xC);
        break;
    case 2:
    case 3:
        *t0 = 4;
        { s32 v = *t2; *t1 = v; }
        *t5 = 2;
        *a1 = 2;
        *t6 = *(s32 *)(p + 0xC) << 1;
        break;
    }
    *t1 = 2;
    *t5 = 1;
    *t6 = *(s32 *)(p + 0xC) / 2;
    *t0 = 0x10;
    *a3 = -1;
    return 0;
}

s32 func_003F8AF8(u8 *p, s32 a, s32 b)
{
    s8 *pe, *pf;
    s32 *p10;
    s16 r;
    p10 = (s32 *)(p + 0x10);
    pf = (s8 *)(p + 0xF);
    pe = (s8 *)(p + 0xE);
    *(s16 *)(p + 0x2) = 1;
    if (func_003F89D8((u8 *)a, b, &r, (s8 *)(p + 0xC), (s8 *)(p + 0xD), pf, pe, (s32 *)(p + 0x14), (s32 *)(p + 0x18), p10, (s16 *)(p + 0x9A)) < 0)
        return 0;
    *(s32 *)(p + 0x34) = 0;
    *(s32 *)(p + 0x30) = 0;
    *(s32 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x28) = 0;
    *(s32 *)(p + 0x20) = 0;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x26) = 0;
    *(s16 *)(p + 0x24) = 0;
    {
    s32 x = *(s32 *)(p + 0x3C), y = *(s32 *)(p + 0x40), z = *(s32 *)(p + 0x44), w;
    *(s32 *)(p + 0x50) = *pe;
    *(s32 *)(p + 0x54) = *pf;
    w = *p10;
    *(s32 *)(p + 0x5C) = x;
    *(s32 *)(p + 0x60) = y;
    *(s32 *)(p + 0x58) = w;
    *(s32 *)(p + 0x64) = z;
    }
    *(s32 *)(p + 0x8C) = 0;
    *(s32 *)(p + 0x88) = 0;
    *(s16 *)(p + 0x98) = 2;
    return r;
}
