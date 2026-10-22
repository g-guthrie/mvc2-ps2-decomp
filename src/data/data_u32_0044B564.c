typedef unsigned int u32;
typedef signed short s16;
typedef float f32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {
    s16 a[2];
    s16 b[2];
    f32 value;
    u16 c;
    u8 c_tail[2];
} Rec0044B564;
typedef char Rec0044B564_size_check[(sizeof(Rec0044B564) == 16) ? 1 : -1];
typedef struct {
    u32 pad[3];
} Tab0044B564Header;
typedef char Tab0044B564Header_size_check[(sizeof(Tab0044B564Header) == 12) ? 1 : -1];
typedef struct {
    Tab0044B564Header header;
    Rec0044B564 records[11];
} Tab0044B564;
typedef char Tab0044B564_size_check[(sizeof(Tab0044B564) == 188) ? 1 : -1];
Tab0044B564 data_u32_0044B564 = {
    { { 0x00000000u, 0x00000000u, 0x00000000u } },
    {
    { { -8, 56 }, { -42, 26 }, 21.42857f, 0xFFF8u, { 0x0Fu, 0x00u } },
    { { 16, 40 }, { 99, 20 }, 20.357141f, 0x0008u, { 0x0Fu, 0x01u } },
    { { 0, 48 }, { 10, 34 }, 17.142857f, 0x0003u, { 0x0Eu, 0x02u } },
    { { 24, 40 }, { 63, 13 }, 19.285713f, 0x0005u, { 0x0Du, 0x03u } },
    { { -24, 40 }, { -61, 15 }, 19.553572f, 0xFFFBu, { 0x0Cu, 0x04u } },
    { { -16, 40 }, { 104, 2 }, 20.357141f, 0x0005u, { 0x0Bu, 0x05u } },
    { { -8, 40 }, { 71, -11 }, 21.5625f, 0xFFF8u, { 0x0Au, 0x06u } },
    { { 0, 40 }, { 54, -9 }, 24.642857f, 0x0009u, { 0x09u, 0x07u } },
    { { 8, 40 }, { -34, 5 }, 19.821428f, 0xFFF9u, { 0x09u, 0x08u } },
    { { 12, 40 }, { -56, -5 }, 22.5f, 0x000Au, { 0x09u, 0x09u } },
    { { -12, 16 }, { -26, -9 }, 18.75f, 0xFFFCu, { 0x08u, 0x0Au } }
    }
};
