typedef float f32;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { f32 curve[8]; s16 a0; s16 a1; u32 z0; u32 z1; u32 z2; s16 b0; s16 b1; u32 z3; u32 flag; u32 z4; s16 c0; s16 c1; u32 z5; u32 z6; u32 z7; } CurveBlock;
typedef char CurveBlock_size_check[(sizeof(CurveBlock) == 80) ? 1 : -1];
CurveBlock data_u32_004766B0 = {
    { -3.33333325f, -2.5f, -1.66666663f, -0.833333313f, 0.833333313f, 1.66666663f, 2.5f, 3.33333325f },
    1, 50, 0x00000000u, 0x00000000u, 0x00000000u, 1, 3, 0x00000000u, 0x80000000u, 0x00000000u, 255, 15, 0x00000000u, 0x00000000u, 0x00000000u
};
