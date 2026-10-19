#pragma padloop on
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004F20B0[];
extern s32 func_0016B250(u8 *, s32);
extern void func_0016B0C0(u8 *, u8 *, s32);

s32 func_00167F50(u8 *p, u8 *q)
{
    u8 *e;
    u8 *r;
    s32 i;
    s32 t0;
    s32 best;
    s32 v;

    if (func_0016B250(p, 3) == 0)
        return 0;
    func_0016B0C0(p, q, 0);
    e = D_004F20B0 + 0x5B8 + ((1 >> (p[2] & 1)) * 0x5B8);
    r = *(u8 **)(p + 0x220);
    best = 0x91;
    t0 = 0;
    for (i = 0; i < 3; i++, e += 0x5B8) {
        if (e[1] == r[1])
            continue;
        v = *(s16 *)(e + 0x434);
        if (v == 0)
            continue;
        v = (s16)v;
        if (best < v)
            continue;
        best = v;
        t0 += 1;
    }
    p[0x471] = 1;
    p[0x45C] = 0x7C;
    p[0x4BF] = 0;
    p[0x4BE] = t0;
    *(s16 *)(p + 0x4C0) = 0;
    return 0;
}
