typedef short s16;
typedef struct { s16 a; s16 b; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
/* Continues the {s16, s16} pair stream that func_0039EE60 walks (lh 0(p), lh 2(p), p += 4). */
S16Pair data_u32_00472864[15] = {
    { -28672, 0 }, { 0, 0 }, { 0, 0 }, { 4096, 32 }, { 0, 0 },
    { 2560, 7700 }, { 40, 0 }, { -128, -160 }, { -192, 0 }, { 0, -128 },
    { -176, -224 }, { -272, -320 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
};
