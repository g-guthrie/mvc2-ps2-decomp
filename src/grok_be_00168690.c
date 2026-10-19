typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern void func_0016B0C0(u8 *, u8 *, s32);
extern s32 func_0016B240(u8 *, s32);

s32 func_00168690(u8 *p, u8 *q)
{
    s32 a0;
    s32 s0;
    s16 v1;

    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    *(s16 *)(p + 0x20E) = 0;
    *(s16 *)(p + 0x4C0) = 0;
    a0 = (0x240 >> *(s32 *)(p + 0x4C8)) & 0xFFFF;
    if (p[0x454] == 0x4A) {
        p[0x4BF] = 0;
        s0 = a0 & 0x380;
    } else {
        p[0x4BF] = 1;
        s0 = a0 & 0x70;
    }
    v1 = *(s16 *)(p + 0x4C2);
    if (v1 & (s16)s0)
        return 0;
    *(s16 *)(p + 0x4C2) = v1 | (s16)s0;
    if (func_0016B240(p, 2) == 0)
        return 0;
    *(u16 *)(p + 0x4F0) |= (u16)s0;
    p[0x4BF] |= 0x80;
    p[0x4BE] = *(s8 *)(p + 0x4C8);
    return 0;
}
