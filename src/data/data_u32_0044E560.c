typedef short s16;

/* Four (x, y) halfword pairs; the last pair is zero. */
typedef struct {
    s16 x;
    s16 y;
} S16Pair;

typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];

S16Pair data_u32_0044E560[4] = {
    { -23, 89 }, { -37, 98 }, { -50, 57 }, { 0, 0 },
};
