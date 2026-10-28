typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* func_00156A40 (src/n5.c) loads D_00444C00[field 0x1C] (lwc1, stride 4)
 * after bounding the index to < 6, and writes it to scale fields 0x78..0x80. */
f32 D_00444C00[6] = { 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f };
