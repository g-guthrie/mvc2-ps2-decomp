typedef short s16;

/* Four (x, y) halfword pairs. */
typedef struct {
    s16 x;
    s16 y;
} S16Pair;

typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];

S16Pair data_u32_0044B380[4] = {
    { -19, 92 }, { 5, 78 }, { 0, 120 }, { 0, 106 },
};
