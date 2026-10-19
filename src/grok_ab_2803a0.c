typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern void func_00186A60(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern u8 D_004D18A5;
extern s8 D_004D18DE;
extern u8 D_004D18A3;

s32 func_002803A0(u8 *p, s32 a1)
{
    u8 v;
    func_00186A60(p, a1);
    p[0x13C] = 1;
    p[7] = 0;
    p[6] = 0;
    p[5] = 0;
    *(s32 *)(p + 0x48) = 0;
    *(f32 *)(p + 0x50) = *(f32 *)(p + 0x298);
    *(f32 *)(p + 0x54) = *(f32 *)(p + 0x29C);
    *(f32 *)(p + 0x58) = *(f32 *)(p + 0x2A0);
    D_004D18A5 = 1;
    v = (u8)a1;
    if (v == 0) {
        *(s32 *)(p + 0x5C) = 0;
        goto rest;
    }
    if (v == 0x16) {
        if (D_004D18DE < 0)
            p[0x20] = 4;
        else {
            u8 a = 0;
            if (D_004D18DE != p[2])
                a = 1;
            if (D_004D18A3)
                a = (u8)(a + 2);
            p[0x20] = a;
        }
        p[0x20D] = 0;
        return 1;
    }
    if (v == 1) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x210] = 0;
        p[0x20D] = 0;
        return 1;
    }
    *(s32 *)(p + 0x5C) = 0;
rest:
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x1E7] = 0xFF;
    p[0x210] = 0;
    p[0x20D] = 0;
    p[0x168] = (p[0x216] & 0x80) ? 1 : 0;
    func_001757E0(p, 0, p[0x168]);
    return 1;
}
