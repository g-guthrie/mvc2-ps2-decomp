typedef signed short s16;
typedef unsigned int u32;

/* Two s16 fields then three zero words. */
typedef struct {
    s16 a;
    s16 b;
    u32 zero[3];
} Rec_00462880;
typedef char Rec_00462880_size_check[(sizeof(Rec_00462880) == 16) ? 1 : -1];
Rec_00462880 data_u32_00462880 = { -11, 22, { 0x00000000u, 0x00000000u, 0x00000000u } };
