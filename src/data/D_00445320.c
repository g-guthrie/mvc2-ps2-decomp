typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* func_0015DD60 (src/x6_b.c) loads D_00445320[field 0x1C] (lwc1, stride 4)
 * three times; it deletes the task first when the index exceeds 0x14, so
 * indices 0..20 are read. */
f32 D_00445320[21] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.100000001f, 0.300000012f, 0.5f,
    0.5f, 0.300000012f, 0.100000001f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
};
