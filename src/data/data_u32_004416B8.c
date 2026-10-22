typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 a;
    f32 b[2];
    u32 c[4];
} T004416B8;
typedef char T004416B8_size_check[(sizeof(T004416B8) == 28) ? 1 : -1];
T004416B8 data_u32_004416B8 = {
    0x02D0FFFEu,
    { 3.0f, 3.0f },
    { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u },
};
