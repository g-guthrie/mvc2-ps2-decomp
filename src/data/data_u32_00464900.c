typedef float f32;
typedef signed short s16;
typedef unsigned short u16;
typedef struct { f32 x; f32 y; } F32Pair;
/* Two tables back to back. The 8-byte f32 pairs are indexed by the byte at +0x20D (func_00386940 lwc1 at +0 and +4). The 6-byte records from 0x00464930 are indexed by the byte at +0x20 and their middle s16 is added to the float at +0x38 (func_003879F0). */
typedef struct { s16 a; s16 dy; u16 b; } Rec6;
typedef struct {
    F32Pair pairs[6];
    Rec6 recs[8];
} Data00464900;
typedef char Data00464900_size_check[(sizeof(Data00464900) == 96) ? 1 : -1];
Data00464900 data_u32_00464900 = {
    {
        { -11.666666f, 8.5714283f },
        { -14.166666f, 6.42857122f },
        { -13.333333f, 0.0f },
        { -11.666666f, -8.5714283f },
        { -11.666666f, 8.5714283f },
        { 0.0f, 0.0f }
    },
    {
        { 0, 0, 1047 },
        { 0, 0, 2071 },
        { 0, 8, 1559 },
        { 255, 72, 1559 },
        { 254, 136, 1559 },
        { 253, 200, 1559 },
        { 252, 264, 1559 },
        { 0, 0, 0 },
    },
};
