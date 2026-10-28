typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

s32 func_00174240(u8 *p)
{
    extern void func_001741D0();
    extern s32 fptosi(f32);
    f32 out[2];
    f32 a, b, sel, sum;
    s32 lo;

    func_001741D0(p + 0x34, out);
    a = 1.6666666269302368f * (f32)p[0x14E] * *(f32 *)(p + 0x50);
    b = 1.6666666269302368f * (f32)p[0x14F] * *(f32 *)(p + 0x50);
    sel = (*(s16 *)(p + 0x140) != 0) ? a : b;
    sum = 213.3333282470703f + (a + b);
    out[0] += 106.66666412353516f;
    lo = (u16)fptosi(out[0] + sel);
    if ((u16)fptosi(640.0f + sum) < lo)
        return 0;
    sum = *(f32 *)(p + 0x54);
    b = (f32)p[0x14C];
    a = 2.142857074737549f * b * sum;
    b = 2.142857074737549f * (f32)p[0x14D] * sum;
    sum = 68.57142639160156f + (a + b);
    lo = (u16)fptosi(out[1] + (34.28571319580078f + b));
    return !((u16)fptosi(480.0f + sum) < lo);
}
