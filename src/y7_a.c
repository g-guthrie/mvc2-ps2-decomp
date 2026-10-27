typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }



void func_0013FFC0(u8 *p) {
    f32 a = 0.004999999888241291f;
    f32 b = -0.004999999888241291f;
    *(u32 *)(p + 0xD0) = *(u32 *)(p + 0xD0) | 0x20000;
    *(f32 *)(p + 0xE0) = a * (f32)*(s16 *)(p + 0x1E);
    *(f32 *)(p + 0xE4) = b * (f32)*(s16 *)(p + 0x1E);
}
