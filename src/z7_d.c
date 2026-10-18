typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C272A;
extern f32 D_004CD168[];
extern f32 D_004CD158[];

void func_001E4340(u32 a) {
    f32 z = 0.0f;
    f32 r = ((f32)(u32)D_004C272A - D_004CD168[0]) / (f32)a;
    if (r != z) r = r; else r = 1.0f;
    D_004CD158[0] = r;
}
