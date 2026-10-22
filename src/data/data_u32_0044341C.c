typedef unsigned int u32;
typedef float f32;
/* 16-byte record: u32 field, f32 field, two zero u32 fields. */
typedef struct {
    u32 field_00;
    f32 field_04;
    u32 field_08;
    u32 field_0C;
} data_u32_0044341C_rec;
data_u32_0044341C_rec data_u32_0044341C = { 0x00000060u, 13.6999998f, 0x00000000u, 0x00000000u };
