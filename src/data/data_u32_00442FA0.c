typedef unsigned int u32;
typedef float f32;

/* Record: u32 header word, five zero words, trailing f32. */
typedef struct {
    u32 hdr;
    u32 zero[5];
    f32 last;
} Rec_00442FA0;
typedef char Rec_00442FA0_size_check[(sizeof(Rec_00442FA0) == 28) ? 1 : -1];
Rec_00442FA0 data_u32_00442FA0 = { 0xFF000063u, { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u }, -0.00999999978f };
