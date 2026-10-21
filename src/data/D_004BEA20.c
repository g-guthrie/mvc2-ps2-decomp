typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct _UUID {
    u32 Data1;
    u16 Data2;
    u16 Data3;
    u8 Data4[8];
} UUID;
UUID D_004BEA20 = { 0x2E534FA3u, 0xAF97u, 0x11D2u, { 0xA5u, 0x27u, 0x00u, 0x60u, 0x08u, 0x94u, 0x48u, 0xBCu } };
typedef char D_004BEA20_size_check[sizeof(UUID) == 0x10 ? 1 : -1];
