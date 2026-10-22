typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef signed short s16;
typedef struct { u16 kind; u16 id; f32 value; } Tab004434B0Item;
typedef char Tab004434B0Item_size_check[(sizeof(Tab004434B0Item) == 8) ? 1 : -1];
typedef struct { s16 x; s16 y; } S16Pair;
typedef struct {
    f32 a;
    f32 b;
    u32 pad0[3];
    S16Pair pairs[10];
    u32 pad1[2];
    f32 c;
    f32 d;
    f32 e;
} Tab004434B0Tail;
typedef char Tab004434B0Tail_size_check[(sizeof(Tab004434B0Tail) == 80) ? 1 : -1];
typedef struct {
    Tab004434B0Item items[35];
    u32 pad;
    Tab004434B0Tail tail;
} Tab004434B0;
typedef char Tab004434B0_size_check[(sizeof(Tab004434B0) == 364) ? 1 : -1];
Tab004434B0 data_u32_004434B0 = {
    {
    { 0x0001u, 0x0064u, 0.0f },
    { 0x0001u, 0x0065u, 1.2f },
    { 0x0001u, 0x0066u, 1.2f },
    { 0x0001u, 0x0067u, 1.2f },
    { 0x0001u, 0x0068u, 1.2f },
    { 0x0001u, 0x0069u, 1.2f },
    { 0x0001u, 0x006Au, 1.2f },
    { 0x0001u, 0x006Bu, 1.2f },
    { 0x00FFu, 0x0000u, 0.0f },
    { 0x0000u, 0x0000u, 0.0f },
    { 0x0001u, 0x0064u, 0.0f },
    { 0x0001u, 0x0066u, 1.2f },
    { 0x0001u, 0x0068u, 1.2f },
    { 0x0001u, 0x006Au, 1.2f },
    { 0x00FFu, 0x0000u, 0.0f },
    { 0x0000u, 0x0000u, 0.0f },
    { 0x0001u, 0x0064u, 0.0f },
    { 0x0001u, 0x0065u, 1.2f },
    { 0x0001u, 0x0066u, 1.2f },
    { 0x0001u, 0x0067u, 1.2f },
    { 0x0001u, 0x0068u, 1.2f },
    { 0x0001u, 0x0069u, 1.2f },
    { 0x0001u, 0x006Au, 1.2f },
    { 0x0001u, 0x006Bu, 1.2f },
    { 0x00FFu, 0x0000u, 0.0f },
    { 0x0000u, 0x0000u, 0.0f },
    { 0x0001u, 0x0064u, 0.0f },
    { 0x0001u, 0x0065u, 1.2f },
    { 0x0001u, 0x0066u, 1.2f },
    { 0x0001u, 0x0067u, 1.2f },
    { 0x0001u, 0x0068u, 1.2f },
    { 0x0001u, 0x0069u, 1.2f },
    { 0x0001u, 0x006Au, 1.2f },
    { 0x0001u, 0x006Bu, 1.2f },
    { 0x00FFu, 0x0000u, 0.0f }
    },
    0x0u,
    {
        15.0f, 1.8e+02f,
        { 0x0u, 0x0u, 0x0u },
        {
            { 84, 144 },
            { 169, 230 },
            { 239, 244 },
            { 260, 263 },
            { 269, 135 },
            { 268, 180 },
            { 178, 8 },
            { 8, 273 },
            { 38, 66 },
            { 292, 7 }
        },
        { 0x0u, 0x0u },
        -9.14f, 6.5f, -13.0f
    }
};
