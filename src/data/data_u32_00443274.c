typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
/* Six-word record: byte id 0x57 with 0xFF in the top byte, two zero words, f32 -0.9,
 * zero word, f32 -0.02. */
typedef struct {
    u8 id;
    u8 pad_01;
    u8 pad_02;
    u8 flag_03;
    u32 zero_04;
    u32 zero_08;
    f32 f0C;
    u32 zero_10;
    f32 f14;
} data_u32_00443274_t;
typedef char data_u32_00443274_size_check[(sizeof(data_u32_00443274_t) == 24) ? 1 : -1];

data_u32_00443274_t data_u32_00443274[1] = {
    { 0x57, 0, 0, 0xFF, 0u, 0u, -0.899999976f, 0u, -0.0199999996f },
};
