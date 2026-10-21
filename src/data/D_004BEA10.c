typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct _UUID {
    u32 Data1;
    u16 Data2;
    u16 Data3;
    u8 Data4[8];
} UUID;
UUID D_004BEA10 = { 0x3B9A9E81u, 0x0DBBu, 0x11D2u, { 0xA6u, 0xBFu, 0x44u, 0x45u, 0x53u, 0x54u, 0x00u, 0x00u } };
typedef char D_004BEA10_size_check[sizeof(UUID) == 0x10 ? 1 : -1];
