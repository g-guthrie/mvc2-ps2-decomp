typedef unsigned int u32;
typedef struct {
    u32 header0[2];
    u32 offset[5];
    u32 header1;
    char name[4][16];
} Data004BEDB8;
typedef char Data004BEDB8_size_check[(sizeof(Data004BEDB8) == 96) ? 1 : -1];
Data004BEDB8 data_u8_004BEDB8 = {
    { 0, 0 },
    { 0x04, 0x08, 0x10, 0x18, 0x20 },
    0,
    {
        "afs00.afs",
        "afs01.afs",
        "afs02.afs",
        "afs03.afs",
    },
};
