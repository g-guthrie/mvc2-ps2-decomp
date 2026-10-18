typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
s32 func_00164560(u8 *p, s32 b)
{
    extern s32 func_0016B240(u8 *, s32);
    extern void func_0016B0C0(u8 *, s32, s32);
    extern s32 func_001646A0(u8 *, s32);
    u8 *o;
    u32 a3;
    u32 u;
    f32 f, g;
    u32 t;
    if (func_0016B240(p, 6) == 0) return 0;
    func_0016B0C0(p, b, 0);
    o = *(u8 **)(p + 0x220);
    func_0016B0C0(p, b, 3);
    u = o[0x14E];
    f = (f32)u;
    g = *(f32 *)(p + 0x4C8);
    *(f32 *)(p + 0x460) = g + 1.6666666269302368f * f;
    func_0016B0C0(p, b, 1);
    *(s32 *)(p + 0x468) = *(s32 *)(p + 0x4C8);
    a3 = ((p[0x1E6] * 3) << 10) ^ 0x800;
    a3 = (u16)a3;
    if (*(s32 *)(p + 0x468) < 0) a3 = (u16)(a3 | 0x1000);
    if (*(s32 *)(p + 0x468) > 0) a3 = (u16)(a3 | 0x2000);
    t = p[0x451];
    p[0x451] = t + 1;
    *(s32 *)(p + 0x464) = p[0x1E4];
    *(s32 *)(p + 0x468) = (u16)a3;
    *(u16 *)(p + 0x4F0) = a3;
    *(s8 *)(p + 0x4B6) = -0x4C;
    return func_001646A0(p, b);
}
