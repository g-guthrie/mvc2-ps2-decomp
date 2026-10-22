typedef short s16;

/* Four (x, y) halfword pairs, read by func_0019C220. */
typedef struct {
    s16 x;
    s16 y;
} S16Pair;

typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];

S16Pair data_u32_0044A8E0[4] = {
    { 14, -6 }, { 13, -1 }, { -23, -7 }, { -24, -2 },
};
