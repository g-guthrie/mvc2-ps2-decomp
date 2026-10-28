typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
extern s16 *D_00472CB0[];
void func_003A4340(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s32);
    u8 *o = *(u8 **)(p + 0x1C4);
    s16 *t;
    f32 x, y;
    f32 kx = 1.6666666269302368f;
    f32 ky = 2.142857074737549f;
    t = D_00472CB0[o[0x20D]]; t += p[0x20] * 4;
    x = kx * (f32)t[0];
    y = ky * (f32)t[1];
    t += 2;
    if (*(s16 *)(p + 0x140) != 0) x = -x;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + x;
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + y;
    p[0x24] = (*t++ != 0) ? 7 : 0;
    func_00175910(p, 0x17, 4, *t);
}
