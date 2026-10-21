typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct _UUID {
    u32 Data1;
    u16 Data2;
    u16 Data3;
    u8 Data4[8];
} UUID;
UUID D_004BE9D0 = { 0xDD9EEE41u, 0x1679u, 0x11D2u, { 0x93u, 0x6Cu, 0x00u, 0x60u, 0x08u, 0x94u, 0x48u, 0xBCu } };
typedef char D_004BE9D0_size_check[sizeof(UUID) == 0x10 ? 1 : -1];
