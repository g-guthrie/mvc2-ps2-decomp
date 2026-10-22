typedef int s32;
typedef struct { s32 x; s32 y; s32 z; s32 w; } data_u32_004526A0_t;
typedef char data_u32_004526A0_t_size_check[(sizeof(data_u32_004526A0_t) == 16) ? 1 : -1];

/* 16.16 fixed-point values. */
data_u32_004526A0_t data_u32_004526A0[3] = {
    { 0x00000000, 0x00000000, 0x000C0000, (s32)0xFFFFB800u },
    { (s32)0xFFF80000u, 0x00002000, 0x000C0000, (s32)0xFFFFB800u },
    { 0x00080000, (s32)0xFFFFE000u, 0x000A0000, (s32)0xFFFFB800u },
};
