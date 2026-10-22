typedef unsigned int u32;
typedef float f32;

/* Record: u32 header word, f32, zero word, f32. */
typedef struct {
    u32 hdr;
    f32 a;
    u32 zero;
    f32 b;
} Rec_00442E88;
typedef char Rec_00442E88_size_check[(sizeof(Rec_00442E88) == 16) ? 1 : -1];
Rec_00442E88 data_u32_00442E88 = { 0x00010071u, 6.80000019f, 0x00000000u, 0.00999999978f };
