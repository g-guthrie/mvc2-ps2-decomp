typedef unsigned char u8;
typedef float f32;
/* 16-byte record: 4 raw bytes (7F 00 00 01, i.e. 127.0.0.1 in network order), then three f32 fields. */
typedef struct {
    u8 field_00[4];
    f32 field_04;
    f32 field_08;
    f32 field_0C;
} data_u32_00443628_rec;
data_u32_00443628_rec data_u32_00443628 = { { 0x7F, 0x00, 0x00, 0x01 }, -9.14000034f, 6.5f, -13.0100002f };
