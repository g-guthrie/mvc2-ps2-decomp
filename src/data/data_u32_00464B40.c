typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
/* First 16 bytes are halfwords read with lh by one reader (index<<1). */
typedef struct {
    s16 halves[16];
    s8 tail[12];
    u8 pad[4];
} Data00464B40;
typedef char data_00464B40_size_check[(sizeof(Data00464B40) == 48) ? 1 : -1];
Data00464B40 data_u32_00464B40 = {
    { 0, 1, 0, 2, 0, 0, 0, 1, 2, 0, 1, 0, 2, 0, 0, 0 },
    { 2, 19, -2, 21, 1, 22, -1, 23, -1, 24, 0, 0 },
    { 0x00u, 0x00u, 0x00u, 0x00u }
};
