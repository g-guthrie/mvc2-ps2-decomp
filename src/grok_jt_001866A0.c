typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

void func_001866A0(u8 *p)
{
    f32 v;
    if ((*(s8 *)(p + 0x211) & (1 << *(s16 *)(p + 0x140))) == 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 26.66666603088379f * (f32)p[0x425];
        } else {
            *(f32 *)(p + 0x34) -= 26.66666603088379f * (f32)p[0x425];
        }
    }
    v = 640.0f;
    if (*(s16 *)(p + 0x140) != 0)
        v = -v;
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x5C) = -(v / 21.0f);
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x38) = 137.14285278320312f + *(f32 *)(p + 0x430);
    *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    *(f32 *)(p + 0x60) = (*(f32 *)(p + 0x430) - *(f32 *)(p + 0x38)) / 20.0f - (20.0f * *(f32 *)(p + 0x6C)) / 2.0f;
}
