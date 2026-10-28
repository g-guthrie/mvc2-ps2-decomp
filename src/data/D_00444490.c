typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;
/* func_00150ED0 (src/z1_j.c) passes &D_00444490[p[3]] (stride 12) to
 * func_00150FD0(.., V3 *pos, ..) (src/q7_w.c). The three FF-terminated
 * lists at 0x00444400/20/50 use p[3] = 0..6. */
Vec3 D_00444490[7] = {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { -9.14000034f, 6.5f, -13.0100002f },
    { 0.0f, 6.5f, -13.0f },
    { 0.0f, 3.76999998f, -12.9899998f },
    { 0.0f, -6.0f, -13.0799999f },
    { 0.0f, 0.0f, -13.0f }
};
