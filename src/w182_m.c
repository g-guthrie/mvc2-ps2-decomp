typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00447110[];

void func_00186900(u8 *p)
{
    s32 m;
    f32 a, b, c, d;
    m = 1 << *(s16 *)(p + 0x140);
    if ((*(s8 *)(p + 0x211) & m) == 0) {
        a = 1.6666666269302368f;
        b = (f32)*(s16 *)((*(s8 *)(p + 0x4DD) << 1) + ((u32)D_00447110 + ((p[1] * 3) << 1)));
        b = a * b;
        if (*(s16 *)(p + 0x140) != 0) {
            b = -b;
        }
        *(f32 *)(p + 0x34) += b;
    }
    a = 640.0f;
    if (*(s16 *)(p + 0x140) != 0) {
        a = -a;
    }
    c = *(f32 *)(p + 0x34);
    b = a / 21.0f;
    c = c + a;
    *(f32 *)(p + 0x34) = c;
    *(f32 *)(p + 0x5C) = -b;
    *(s32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x38) = 137.14285278320312f + *(f32 *)(p + 0x430);
    *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    *(f32 *)(p + 0x60) = (*(f32 *)(p + 0x430) - *(f32 *)(p + 0x38)) / 20.0f - (20.0f * *(f32 *)(p + 0x6C)) / 2.0f;
}
