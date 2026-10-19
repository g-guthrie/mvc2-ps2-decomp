#pragma padloop on
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004F20B0[];
extern void func_0016B0C0(u8 *, u8 *, s32);
extern s32 func_00166C80(u8 *, u8 *, s32);

s32 func_001685A0(u8 *p, u8 *q)
{
    u8 *e;
    s32 i;
    s32 sum;
    s32 a;
    s32 b;

    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 2);
    e = D_004F20B0 + ((p[2] ^ 1) * 0x5B8);
    sum = 0;
    for (i = 0; i < 3; i++, e += 0xB70)
        sum += *(s16 *)(e + 0x434);
    a = (sum * 144) / 100;
    b = (*(s32 *)(p + 0x4C8) * 144) / 100;
    return func_00166C80(p, q, !(b < a));
}
