typedef unsigned int u32;
typedef float f32;

/* Record: u32 header word, zero word, three f32 values. */
typedef struct {
    u32 hdr;
    u32 zero;
    f32 v[3];
} Rec_004438C8;
typedef char Rec_004438C8_size_check[(sizeof(Rec_004438C8) == 20) ? 1 : -1];
Rec_004438C8 data_u32_004438C8 = { 0x00000026u, 0x00000000u, { -9.14000034f, 6.5f, -13.0f } };
