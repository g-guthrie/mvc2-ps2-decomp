typedef signed short s16;
/* Four signed {x, y} halfword pairs. */
typedef struct { s16 x; s16 y; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
S16Pair data_u32_004C1BE0[4] = {
    { 4888, 0 }, { 0, 0 }, { -52, 87 }, { -25, 48 },
};
