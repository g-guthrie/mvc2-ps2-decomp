typedef signed short s16;
/* Twelve signed {x, y} halfword pairs; the entry at 0x0044DFE0 + 0x2C is zero. */
typedef struct { s16 x; s16 y; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
S16Pair data_u32_0044DFE0[12] = {
    { -12, 132 }, { 46, 112 }, { 66, 87 }, { 58, 57 },
    { -11, 20 }, { -53, 57 }, { -56, 88 }, { -45, 114 },
    { -21, 84 }, { -12, 93 }, { -22, 76 }, { 0, 0 },
};
