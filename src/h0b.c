typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0032FEB0(f32 t, f32 *a, f32 *b, f32 *c) {
    f32 u = 1.0f - t;
    *a = 0.5f * u * u;
    *b = 0.5f + u * t;
    *c = 0.5f * t * t;
}
