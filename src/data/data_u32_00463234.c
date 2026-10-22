typedef unsigned int u32;
typedef signed short s16;
typedef struct { s16 x; s16 y; } S16Pair;
typedef struct { s16 x; s16 y; s16 z; } S16Triple;
/* Zero lead-in, then (from 0x00463240) 16 s16 triples indexed by a 4-bit random value times 6 (func_0035CCA0 reads lh at +0/+2/+4), then x/y s16 pairs from 0x004632A0 at stride 4 (func_0035D080). */
typedef struct {
    u32 lead[3];
    S16Triple scatter[16];
    S16Pair offsets[4];
} Data00463234;
typedef char Data00463234_size_check[(sizeof(Data00463234) == 124) ? 1 : -1];
Data00463234 data_u32_00463234 = {
    { 0, 0, 0 },
    {
        { -128, 640, -32 }, { 0, 256, -24 }, { 0, 256, -24 }, { 512, 768, -40 },
        { 768, 512, -32 }, { -384, 640, -32 }, { -1024, 512, -16 }, { 1024, 768, -48 },
        { 160, 640, -64 }, { -448, 608, -56 }, { 128, 448, -40 }, { 640, 864, -56 },
        { -896, 544, -48 }, { -448, 704, -56 }, { 1024, 576, -32 }, { 0, 256, -16 },
    },
    { { -127, 24 }, { -67, 54 }, { -61, 2 }, { 11, 27 } },
};
