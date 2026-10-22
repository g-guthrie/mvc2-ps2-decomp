typedef signed short s16;
/* Fourteen signed halfword pairs; the last three are zero. */
typedef struct { s16 x; s16 y; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
S16Pair data_u32_0044AB68[14] = {
    { 6, -56 }, { 51, -99 }, { -87, -43 }, { -86, -44 },
    { 10, -56 }, { 7, -144 }, { -113, -21 }, { -113, -21 },
    { 71, -137 }, { 71, -137 }, { 7, -56 }, { 0, 0 },
    { 0, 0 }, { 0, 0 },
};
