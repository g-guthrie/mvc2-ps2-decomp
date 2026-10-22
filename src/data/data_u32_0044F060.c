typedef unsigned char u8;
typedef signed short s16;
typedef struct { s16 x; s16 y; } S16Pair;
typedef struct {
    S16Pair head[6];
    u8 mid[24];
    S16Pair tail[16];
} Tab0044F060;
typedef char Tab0044F060_size_check[(sizeof(Tab0044F060) == 112) ? 1 : -1];
Tab0044F060 data_u32_0044F060 = {
    {
        { 48, 80 },
        { -48, 80 },
        { 32, 96 },
        { -32, 96 },
        { 16, 112 },
        { -16, 112 }
    },
    {
        0x0Fu, 0x0Fu, 0x12u, 0x12u, 0x12u, 0x12u, 0x11u, 0x11u, 0x11u, 0x11u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    },
    {
        { 2048, 0 },
        { -2048, 0 },
        { 1792, 256 },
        { -1792, 256 },
        { 1536, 768 },
        { -1536, 768 },
        { 896, 1280 },
        { -896, 1280 },
        { 256, 1536 },
        { -256, 1536 },
        { 0, 1024 },
        { -1024, 0 },
        { -4096, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 }
    }
};
