typedef unsigned int u32;
typedef float f32;

/* Four words: three integers, then the float 0.01. Reader not located. */
typedef struct { u32 field_00; u32 field_04; u32 field_08; f32 field_0C; } data_u32_00442C68_rec;
typedef char data_u32_00442C68_rec_size_check[(sizeof(data_u32_00442C68_rec) == 16) ? 1 : -1];
data_u32_00442C68_rec data_u32_00442C68 = { 0x00000057u, 0x00000000u, 0x00000000u, 0.00999999978f };
