typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

/* Fragment of the {s16 x, s16 y} offset table at D_0044A900: func at 0x0019C650 reads lh at D_0044A900 + idx*4 (x) and D_0044A902 + idx*4 (y), idx = lbu 0x15B(parent obj). */
typedef struct S16Pair {
    s16 x;
    s16 y;
} S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];

S16Pair data_u32_0044A9B0[20] = {
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
    { -26, -54 },
};
