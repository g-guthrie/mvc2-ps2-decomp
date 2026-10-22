/* Four (x, y) s16 pairs, 4-byte stride; the reader at 0x0019C67C loads each component with lh (offsets 0 and 2)
   from the D_0044A900 table, indexed by field 0x15B * 4, and converts to float. */
typedef signed short s16;
typedef struct { s16 x; s16 y; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
S16Pair data_u32_0044AB58[4] = {
    { -97, -38 }, { -97, -38 }, { -97, -38 }, { -97, -38 },
};
