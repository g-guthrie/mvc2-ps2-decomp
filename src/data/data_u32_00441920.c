typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
/* Mixed u32/f32 record. */
typedef struct {
    u32 a;
    f32 b[5];
    u32 c[3];
    f32 d[4];
    u32 e[2];
    f32 f[3];
} T00441920;
typedef char T00441920_size_check[(sizeof(T00441920) == 72) ? 1 : -1];
T00441920 data_u32_00441920 = {
    0x0000FFFFu,
    { 25.0f, -3.0f, -12.0f, 1.0f, 0.100000001f },
    { 0x00000000u, 0x00000000u, 0x00000000u },
    { 13.0f, 1.5f, -14.0f, 1.0f },
    { 0x00000000u, 0x00000008u },
    { 7.5f, 1.0f, -14.0f },
};
