typedef signed short s16;
typedef float f32;
/* Entries 21..31 of the (x, y) halfword-pair table at D_004B8410 (0x004B8410 + 21 * 4),
 * read by func_003733B0 (src/xl14_c.c) with lh at index (actor +0x20) * 4, followed by the
 * first word of the float run that continues through data_u32_004B8494 and data_u32_004B84A8. */
typedef struct { s16 x; s16 y; } S16Pair;
typedef char S16Pair_size_check[(sizeof(S16Pair) == 4) ? 1 : -1];
typedef struct {
    S16Pair pairs[11];
    f32 scale;
} Data004B8464;
typedef char Data004B8464_size_check[(sizeof(Data004B8464) == 48) ? 1 : -1];
Data004B8464 data_u32_004B8464 = {
    {
        { 48, 248 }, { 48, 248 }, { 0, 0 },
        { -7680, 0 }, { -3072, 0 }, { -3072, 0 }, { 0, 0 },
        { 3072, 0 }, { 3072, 0 }, { 6144, 0 }, { 0, 0 },
    },
    1.8f,
};
