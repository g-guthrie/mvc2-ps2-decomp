typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x; f32 y; } F32Pair;
typedef struct { u8 a; u8 b; } U8Pair;
/* Ten f32 (x, y) pairs with a constant y step, then ten u8 pairs that sum to 0x40 each, then zero padding. */
typedef struct { F32Pair pts[10]; U8Pair side[10]; u8 tail[12]; } Block112;
typedef char Block112_size_check[(sizeof(Block112) == 112) ? 1 : -1];
Block112 data_u32_00472570 = {
    {
        { -86.6666641f, 102.85714f },
        { -93.3333282f, 111.428566f },
        { -100.0f, 120.0f },
        { -113.333328f, 128.571426f },
        { -120.0f, 137.142853f },
        { -106.666664f, 145.714279f },
        { -113.333328f, 154.285706f },
        { -126.666664f, 162.857132f },
        { -96.6666641f, 171.428558f },
        { -100.0f, 180.0f },
    },
    {
        { 0x28u, 0x18u },
        { 0x2Au, 0x16u },
        { 0x2Cu, 0x14u },
        { 0x2Eu, 0x12u },
        { 0x30u, 0x10u },
        { 0x32u, 0x0Eu },
        { 0x35u, 0x0Cu },
        { 0x37u, 0x0Au },
        { 0x3Au, 0x08u },
        { 0x3Cu, 0x06u },
    },
    { 0 },
};
