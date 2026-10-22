typedef unsigned int u32;
/* Two 16-byte library signature strings around a 64-byte block of words. */
typedef struct {
    char sig0[16];
    u32 body[16];
    char sig1[16];
} Data00438180;
typedef char Data00438180_size_check[(sizeof(Data00438180) == 96) ? 1 : -1];
Data00438180 data_u32_00438180 = {
    "PsIIlibgraph2500",
    { 0x00020001u, 0x00030001u, 0, 0, 0x01000404u, 0x20000000u, 0, 0x05000000u, 0x06000000u, 0x03000000u, 0x02000000u, 0x04000000u, 0x06000000u, 0, 0, 0 },
    "PsIIlibdma  2500",
};
