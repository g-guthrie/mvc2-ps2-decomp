typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* func_0014B660 copies this 32-byte table to the stack (two lq at
 * 0x0014B74C/50) and its second spawn loop reads one f32 pair per task
 * (lwc1 +0/+4, stride 8, four iterations at 0x0014B874..B8A8) into the
 * task scale fields 0x50/0x54. */
typedef struct { f32 x, y; } F32Pair;
F32Pair D_00443FF0[4] = {
    { 1.0f, 0.300000012f },
    { 1.0f, 0.300000012f },
    { 1.20000005f, 1.20000005f },
    { 1.0f, 1.0f }
};
