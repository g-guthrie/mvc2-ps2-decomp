typedef unsigned int u32;

/* Record: u32 header word followed by three zero words. */
typedef struct {
    u32 hdr;
    u32 zero[3];
} Rec_00443470;
typedef char Rec_00443470_size_check[(sizeof(Rec_00443470) == 16) ? 1 : -1];
Rec_00443470 data_u32_00443470 = { 0xFF000063u, { 0x00000000u, 0x00000000u, 0x00000000u } };
