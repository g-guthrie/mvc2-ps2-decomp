typedef unsigned char u8;
typedef signed short s16;
#pragma pack(1)
typedef struct {
    s16 quad[4];
} data_u32_00475C00_quad;
typedef struct {
    data_u32_00475C00_quad quads[10];
    u8 pairs[10][2];
    u8 zero[12];
    s16 progression[12];
    u8 tail[8];
} data_u32_00475C00_layout;
#pragma pack()
typedef char data_u32_00475C00_size_check[(sizeof(data_u32_00475C00_layout) == 144) ? 1 : -1];
data_u32_00475C00_layout data_u32_00475C00 = {
    {
        { -37, 23, 23, 15 },
        { -27, 44, 24, 17 },
        { -2, 45, 26, 19 },
        { -31, 82, 28, 11 },
        { -17, 88, 30, 13 },
        { -4, 59, 0, 20 },
        { 11, 84, 2, 14 },
        { 34, 84, 4, 12 },
        { 13, 41, 6, 18 },
        { 25, 26, 8, 16 },
    },
    {
        { 2, 4 },
        { 2, 5 },
        { 2, 6 },
        { 2, 4 },
        { 2, 4 },
        { 2, 6 },
        { 1, 5 },
        { 1, 3 },
        { 1, 4 },
        { 1, 2 },
    },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 1900, 2100, 2300 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
