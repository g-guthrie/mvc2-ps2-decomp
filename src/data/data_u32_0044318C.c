typedef unsigned int u32;
typedef float f32;

/* Record: u32 header word, f32, two zero words. */
typedef struct {
    u32 hdr;
    f32 a;
    u32 zero[2];
} Rec_0044318C;
typedef char Rec_0044318C_size_check[(sizeof(Rec_0044318C) == 16) ? 1 : -1];
Rec_0044318C data_u32_0044318C = { 0x00000060u, 13.3999996f, { 0x00000000u, 0x00000000u } };
