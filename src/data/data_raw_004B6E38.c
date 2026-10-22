typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {
    u32 a;
    u32 b;
} Data004B6E38Pair;
typedef char data_004B6E38_size_check[(sizeof(Data004B6E38Pair) == 8) ? 1 : -1];
Data004B6E38Pair data_raw_004B6E38[5] = {
    { 0x000000B0u, 0x00000010u },
    { 0x000000C0u, 0x00000010u },
    { 0x000000D0u, 0x00000010u },
    { 0x000000E0u, 0x00000010u },
    { 0x00000000u, 0x00000020u }
};
