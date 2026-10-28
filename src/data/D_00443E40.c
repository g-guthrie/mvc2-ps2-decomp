typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;
/* func_0014A410(n) (src/w195_a.c) copies D_00443E40[n] (stride 12, three
 * lwc1 at 0x0014A4A4..AC) into the task position; its only caller
 * func_0014A3D0 passes n = 0..2. */
Vec3 D_00443E40[3] = {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 5.05000019f, 0.949999988f, -12.6999998f }
};
