typedef int s32;
typedef unsigned int u32;
typedef struct { s32 x; s32 y; s32 z; } Fixed16Vec3;
typedef struct { Fixed16Vec3 rec[6]; u32 pad[2]; } FixedVecTable;
typedef char FixedVecTable_size_check[(sizeof(FixedVecTable) == 80) ? 1 : -1];
/* 16.16 fixed-point vectors; the last two words are zero padding. */
FixedVecTable data_u32_00472DA0 = {
    {
        { -294912, 4096, -12288 },
        { -425984, 6144, -12288 },
        { -557056, 8192, -12288 },
        { -327680, 4096, -8192 },
        { -458752, 6144, -8192 },
        { -589824, 8192, -8192 },
    },
    { 0x0u, 0x0u }
};
