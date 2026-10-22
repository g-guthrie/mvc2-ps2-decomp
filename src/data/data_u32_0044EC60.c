typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
/* x/y s16 offset pairs read by func_001DCDE0 (8 at +0, 9 at +0x20) */
typedef struct Mv_0044EC60 {
    s16 x;
    s16 y;
} Mv_0044EC60;
typedef char Mv_0044EC60_size_check[(sizeof(Mv_0044EC60) == 4) ? 1 : -1];
Mv_0044EC60 data_u32_0044EC60[20] = {
    { 0, -16 },
    { 16, -8 },
    { 16, 8 },
    { 0, 16 },
    { -16, -8 },
    { -16, 8 },
    { 0, 0 },
    { 0, 0 },
    { -21, -21 },
    { -21, 0 },
    { -21, 21 },
    { 0, -21 },
    { 0, 0 },
    { 0, 21 },
    { 21, -21 },
    { 21, 0 },
    { 21, 21 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};
