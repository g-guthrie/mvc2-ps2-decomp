typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
/* 16-byte record: two u16 fields, then f32/u32/f32 fields. */
typedef struct {
    u16 field_00;
    u16 field_02;
    f32 field_04;
    u32 field_08;
    f32 field_0C;
} data_u32_00442EA4_rec;
data_u32_00442EA4_rec data_u32_00442EA4 = { 0x0071, 0x0002, 8.89999962f, 0x00000000u, 0.00999999978f };
