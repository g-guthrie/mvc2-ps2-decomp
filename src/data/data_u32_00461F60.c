typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct u32_00461F60_rec {
    u16 a;
    u16 b;
    s16 c;
    s16 d;
} u32_00461F60_rec;
typedef char u32_00461F60_rec_size_check[(sizeof(u32_00461F60_rec) == 8) ? 1 : -1];
u32_00461F60_rec data_u32_00461F60[5] = {
    { 0x000B, 0x0008, 4096, -512 },
    { 0x000D, 0x0009, 4608, -480 },
    { 0x000F, 0x000A, 5120, -448 },
    { 0x0011, 0x000B, 5632, -416 },
    { 0x0013, 0x000C, 6144, -384 },
};
