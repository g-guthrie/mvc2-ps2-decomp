typedef signed short s16;
/* Eleven {x, z} signed halfword pairs. */
typedef struct { s16 x; s16 z; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
S16Pair data_u32_00447AF4[11] = {
    { -1152, 1152 }, { -1280, 1280 }, { -1408, 1408 }, { -1536, 1024 },
    { -1280, 1280 }, { -1056, 768 }, { -1024, 1024 }, { -1280, 1280 },
    { -1536, 896 }, { -1280, 1280 }, { -1056, 1056 },
};
