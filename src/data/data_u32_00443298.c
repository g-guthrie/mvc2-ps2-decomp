typedef unsigned int u32;
typedef float f32;
/* 20-byte record: u32 field, two zero u32 fields, two f32 fields. */
typedef struct {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    f32 field_0C;
    f32 field_10;
} data_u32_00443298_rec;
data_u32_00443298_rec data_u32_00443298 = { 0x0000005Fu, 0x00000000u, 0x00000000u, -0.0199999996f, 0.180000007f };
