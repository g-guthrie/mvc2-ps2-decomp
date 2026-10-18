typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004BF5B0[4];
void func_00197660(u8 *p, u8 *q) {
    extern s32 func_00417A40();
    s16 t;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x68) = 0;
    t = (func_00417A40() & 0x3F00) - 0x2000;
    *(f32 *)(p + 0x5C) = (1.6666666269302368f * (f32)t) / 256.0f;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) - 68.57142639160156f;
    if (func_00417A40() & 1) {
        *(s8 *)(p + 0x31) = 2;
    } else {
        *(s8 *)(p + 0x31) = -2;
    }
    *(f32 *)(p + 0x60) = (2.142857074737549f * (f32)D_004BF5B0[func_00417A40() & 3]) / 256.0f;
}

