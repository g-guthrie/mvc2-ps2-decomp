typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
/* Five 16-byte records: signed halfword pair, zero word, signed halfword pair, u16 value and a
 * zero halfword. */
typedef struct {
    s16 a_00;
    s16 b_02;
    u32 zero_04;
    s16 c_08;
    s16 d_0A;
    u16 e_0C;
    u16 pad_0E;
} data_u32_00464820_rec_t;
typedef char data_u32_00464820_size_check[(sizeof(data_u32_00464820_rec_t) == 16) ? 1 : -1];

data_u32_00464820_rec_t data_u32_00464820[5] = {
    { 0, -6, 0u, -24, 46, 0x3000, 0 },
    { 0, -6, 0u, -24, 34, 0x3000, 0 },
    { 0, -6, 0u, -29, 68, 0x3C00, 0 },
    { 0, -6, 0u, -35, 39, 0x3102, 0 },
    { 0, -6, 0u, -41, 47, 0x3D02, 0 },
};
