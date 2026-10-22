typedef unsigned int u32;
typedef float f32;

/* Record: u32 header word then three f32 values. */
typedef struct {
    u32 hdr;
    f32 v[3];
} Rec_00443788;
typedef char Rec_00443788_size_check[(sizeof(Rec_00443788) == 16) ? 1 : -1];
Rec_00443788 data_u32_00443788 = { 0x01000003u, { -9.0f, 6.51999998f, -13.0900002f } };
