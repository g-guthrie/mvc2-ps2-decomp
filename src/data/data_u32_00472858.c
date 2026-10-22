typedef short s16;
typedef struct { s16 a; s16 b; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
/* Stream of {s16, s16} pairs; func_0039EE60 reads lh 0(p) and lh 2(p) then advances p by 4. */
S16Pair data_u32_00472858[3] = { { -28672, 8 }, { -28672, 8 }, { -28672, 8 } };
