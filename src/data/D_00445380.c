typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* func_0015DE10 (src/sa3_f.c) loads D_00445380[field 0x1C] (lwc1, stride 4)
 * once field 0x1C has reached 7, so the table covers at least 8 entries;
 * it is sized to the next referenced label D_004453B0 (the curve ends in
 * 0.0f there). */
f32 D_00445380[12] = {
    0.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.800000012f, 0.600000024f, 0.400000006f, 0.200000003f, 0.0f
};
