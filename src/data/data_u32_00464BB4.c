typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {
    u16 a;
    s16 b;
    u16 c;
    s16 d;
    s16 e;
    s16 f;
    u16 g;
    s16 h;
} Rec00464BB4;
typedef char Rec00464BB4_size_check[(sizeof(Rec00464BB4) == 16) ? 1 : -1];
typedef struct {
    u32 pad[3];
} Tab00464BB4Header;
typedef char Tab00464BB4Header_size_check[(sizeof(Tab00464BB4Header) == 12) ? 1 : -1];
typedef struct {
    Tab00464BB4Header header;
    Rec00464BB4 records[4];
} Tab00464BB4;
typedef char Tab00464BB4_size_check[(sizeof(Tab00464BB4) == 76) ? 1 : -1];
Tab00464BB4 data_u32_00464BB4 = {
    { { 0x00000000u, 0x00000000u, 0x00000000u } },
    {
    { 0x8000u, -7, 0x0000u, 0, -50, 13, 0x4E1Eu, 0 },
    { 0x8000u, -5, 0x0000u, 0, -3, 0, 0x3F20u, 0 },
    { 0x8000u, -7, 0x0000u, 0, -50, 13, 0x4A1Eu, 0 },
    { 0x8000u, -5, 0x0000u, 0, -3, 0, 0x4B20u, 0 }
    }
};
