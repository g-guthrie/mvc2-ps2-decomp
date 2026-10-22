typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* 16.16 fixed-point x,y pairs. */
typedef struct { s32 x; s32 y; } Fixed16Pair;
typedef char Fixed16Pair_size[(sizeof(Fixed16Pair)==8)?1:-1];
Fixed16Pair data_u32_0044F7D0[4] = {
    { 360448, 950272 },
    { -49152, 229376 },
    { 1081344, -32768 },
    { 0, 0 },
};
