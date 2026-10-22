typedef unsigned int u32;
typedef float f32;
/* 8-byte record: f32 field, then u32 all-ones field. */
typedef struct {
    f32 field_00;
    u32 field_04;
} data_u8_00443BB8_rec;
data_u8_00443BB8_rec data_u8_00443BB8 = { 14.9799995f, 0xFFFFFFFFu };
