typedef unsigned int u32;
typedef float f32;
/* 12-byte record: f32 0.5, then two zero u32 fields. */
typedef struct {
    f32 field_00;
    u32 field_04;
    u32 field_08;
} data_raw_00444C14_rec;
data_raw_00444C14_rec data_raw_00444C14 = { 0.5f, 0x00000000u, 0x00000000u };
