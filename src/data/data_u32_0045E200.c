typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
/* Bit masks (3 per row) and a parallel u8 id table at 0x0045E220 (stride 12); func_0032D970 walks
   both by row*12 and tests the masks against a u32 at +0x20 of a record. */
typedef struct {
    u32 mask[2][3];
    u32 pad0[2];
    u32 id[2][3];
    u32 pad1[2];
} data_u32_0045E200_t;
typedef char data_u32_0045E200_size_check[(sizeof(data_u32_0045E200_t) == 64) ? 1 : -1];
data_u32_0045E200_t data_u32_0045E200 = {
    { { 0x00080000u, 0x00100000u, 0x00200000u }, { 0x00800000u, 0x00400000u, 0x00000040u } },
    { 0u, 0u },
    { { 19u, 20u, 21u }, { 23u, 22u, 6u } },
    { 0u, 0u },
};
