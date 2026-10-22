typedef unsigned int u32;
typedef float f32;

/* 16-byte record: one u32 tag followed by three f32 values. The same layout
   is shared by the adjacent units at 0x00442BD8, 0x00443070, 0x004433E4 and
   0x004437F8; reader functions were not traced for this record. */
typedef struct {
    u32 tag;
    f32 x;
    f32 y;
    f32 z;
} data_rec16;
typedef char data_rec16_size_check[(sizeof(data_rec16) == 16) ? 1 : -1];

data_rec16 data_u32_00442BD8 = { 0x01000056u, -5.5f, -3.0f, -13.0f };
