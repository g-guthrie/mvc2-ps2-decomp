typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004D18EC;
extern s32 func_0016B240(u8 *, s32);
extern void func_0016B0C0(u8 *, u8 *, s32);
extern void func_00186CE0(u8 *, s32);
extern s32 func_00166710(u8 *, u8 *);

s32 func_00166630(u8 *p, u8 *q)
{
    if (func_0016B240(p, 0) == 0)
        return 0;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    if (D_004D18EC != 0)
        return 0;
    p[0x451] += 1;
    *(s32 *)(p + 0x460) = *(s32 *)(p + 0x4C8);
    *(s32 *)(p + 0x468) = 1;
    *(s32 *)(p + 0x46C) = ((p[0x1E6] * 3) << 10) ^ 0x800;
    *(s8 *)(p + 0x4B6) = -0x4C;
    *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x46C);
    *(s16 *)(p + 0x35E) = 0x800;
    func_00186CE0(p, 1);
    *(s16 *)(p + 0x35E) = 0;
    return func_00166710(p, q);
}
