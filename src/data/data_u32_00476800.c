typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef struct { u16 a; u16 b; u32 c[3]; } Rec16;
/* Five f32 (x, y, z) vectors (z is constant), one zero pad word, then four 16-byte records. */
typedef struct { f32 v[5][3]; u32 pad; Rec16 recs[4]; } Block128;
typedef char Block128_size_check[(sizeof(Block128) == 128) ? 1 : -1];
Block128 data_u32_00476800 = {
    {
        { 0.219999999f, 3.83999991f, -12.9899998f },
        { 0.180000007f, 1.07599998f, -12.9899998f },
        { 0.0960000008f, -1.63999999f, -12.9899998f },
        { -1.77999997f, -4.45200014f, -12.9899998f },
        { -5.9000001f, -7.61199999f, -12.9899998f },
    },
    0u,
    {
        { 0x0001u, 0x0047u, 0u, 0u, 0u },
        { 0x0001u, 0x004Cu, 0u, 0u, 0u },
        { 0x0001u, 0x004Du, 0u, 0u, 0u },
        { 0x00FFu, 0x004Fu, 0u, 0u, 0u },
    },
};
