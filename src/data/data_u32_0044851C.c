typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

/* Fragment of the {s16 x, s16 y} offset table at D_004484B4: func_001821D0 reads lh at D_004484B4 + char*12 + (i8 at obj+0x1E7)*4 + bit*2, converts to float and adds/subtracts the scaled value to obj+0x5C. */
typedef struct S16Pair {
    s16 x;
    s16 y;
} S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];

S16Pair data_u32_0044851C[3] = {
    { -64, 8 },
    { -64, 8 },
    { -64, 8 },
};
