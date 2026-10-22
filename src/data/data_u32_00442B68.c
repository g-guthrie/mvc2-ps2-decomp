typedef unsigned int u32;
typedef float f32;

/* Record: u32 header word then three f32 values. */
typedef struct {
    u32 hdr;
    f32 v[3];
} Rec_00442B68;
typedef char Rec_00442B68_size_check[(sizeof(Rec_00442B68) == 16) ? 1 : -1];
Rec_00442B68 data_u32_00442B68 = { 0x80000056u, { -5.0f, 3.0f, -13.0f } };
