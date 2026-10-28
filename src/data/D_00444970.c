typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;
/* func_00153F70 (src/L3_b.c) and func_00154220 load all three lwc1
 * components of row b (stride 12, 0x001540A8..B0 / 0x00154350..58).
 * func_00154120 calls func_00153F70 with selector mode < 3, so rows 0..2. */
Vec3 D_00444970[3] = {
    { 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f },
    { 0.300000012f, 0.300000012f, 0.300000012f }
};
