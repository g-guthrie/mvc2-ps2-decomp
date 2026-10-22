typedef signed short s16;
typedef float f32;
/* 16-byte record: two s16 fields, two f32 fields (both 3.0), then two s16 fields. */
typedef struct {
    s16 field_00;
    s16 field_02;
    f32 field_04;
    f32 field_08;
    s16 field_0C;
    s16 field_0E;
} data_u32_00441514_rec;
data_u32_00441514_rec data_u32_00441514 = { 0x00B4, -630, 3.0f, 3.0f, 0x00F0, -765 };
