typedef unsigned short u16;
typedef unsigned int u32;

/* Two u16 fields then three zero words. */
typedef struct {
    u16 a;
    u16 b;
    u32 zero[3];
} Rec_0044F790;
typedef char Rec_0044F790_size_check[(sizeof(Rec_0044F790) == 16) ? 1 : -1];
Rec_0044F790 data_u32_0044F790 = { 0x1800u, 0x3800u, { 0x00000000u, 0x00000000u, 0x00000000u } };
