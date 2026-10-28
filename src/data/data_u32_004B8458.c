typedef signed short s16;
/* Entries 18..20 of the (x, y) halfword-pair table at D_004B8410 (0x004B8410 + 18 * 4).
 * func_003733B0 (src/xl14_c.c) indexes it by the u8 at actor +0x20 times 4 and loads the
 * x (+0) and y (+2) halfwords with lh, adding them to the actor position. */
typedef struct { s16 x; s16 y; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
S16Pair data_u32_004B8458[3] = {
    { 46, 250 },
    { 46, 250 },
    { 46, 250 },
};
