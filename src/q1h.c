typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 func_003DE700(f32,f32); extern double func_00119058(f32);
s32 func_00417700(f32 y, f32 x) {
    return (u8)((u32)(s32)(func_00119058(256.0f * func_003DE700(y,x)) / 6.283185307179586 + 0.5));
}
