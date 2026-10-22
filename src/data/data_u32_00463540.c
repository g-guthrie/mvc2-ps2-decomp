typedef unsigned int u32;
typedef signed short s16;
typedef struct { s16 a; s16 b; u32 z; s16 c; s16 d; s16 e; s16 f; } Record16;
typedef char Record16_size_check[(sizeof(Record16) == 16) ? 1 : -1];
Record16 data_u32_00463540[4] = {
    { 0, -2, 0x00000000u, -48, 36, 12, 1815 },
    { 0, -2, 0x00000000u, -48, 36, 11, 1816 },
    { 0, -2, 0x00000000u, -48, 36, 12, 15383 },
    { 0, -2, 0x00000000u, -48, 36, 11, 15384 },
};
