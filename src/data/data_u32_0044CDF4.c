typedef unsigned short u16;
/* Eleven small unsigned halfword pairs. */
typedef struct { u16 a; u16 b; } U16Pair;
typedef char U16Pair_size_check[(sizeof(U16Pair) == 4) ? 1 : -1];
U16Pair data_u32_0044CDF4[11] = {
    { 0, 0 }, { 0, 0 }, { 0, 0 }, { 3, 5 },
    { 2, 4 }, { 1, 3 }, { 0, 2 }, { 0, 4 },
    { 0, 4 }, { 1, 5 }, { 2, 5 },
};
