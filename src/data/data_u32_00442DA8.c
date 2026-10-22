typedef unsigned int u32;
typedef float f32;

/* Record: u32 header word, f32, zero word, f32. */
typedef struct {
    u32 hdr;
    f32 a;
    u32 zero;
    f32 b;
} Rec_00442DA8;
typedef char Rec_00442DA8_size_check[(sizeof(Rec_00442DA8) == 16) ? 1 : -1];
Rec_00442DA8 data_u32_00442DA8 = { 0x00000061u, 5.75f, 0x00000000u, 0.0199999996f };
