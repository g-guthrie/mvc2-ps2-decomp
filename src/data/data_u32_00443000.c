typedef unsigned int u32;
typedef float f32;

/* Five words: integer 0x5F, float 9.5, two zero words, float 1.08. Reader not located. */
typedef struct { u32 field_00; f32 field_04; u32 field_08; u32 field_0C; f32 field_10; } data_u32_00443000_rec;
typedef char data_u32_00443000_rec_size_check[(sizeof(data_u32_00443000_rec) == 20) ? 1 : -1];
data_u32_00443000_rec data_u32_00443000 = { 0x0000005Fu, 9.5f, 0x00000000u, 0x00000000u, 1.08000004f };
