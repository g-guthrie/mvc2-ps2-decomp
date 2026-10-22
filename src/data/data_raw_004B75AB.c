typedef unsigned char u8;
typedef short s16;
/* Five lead bytes (unread), a 16-byte u8 table at +5 indexed by a[0x15B] (w175_d.c), and twelve
   packed (x, z) s16 pairs at +21 read as XZ_e by w20b2_e.c (D_004B75C0[p->h1e]). The pairs start at
   an odd offset, so the record array is packed. */
#pragma pack(1)
typedef struct {
    s16 x;
    s16 z;
} data_raw_004B75AB_xz;
typedef struct {
    u8 lead[5];
    u8 idTable[16];
    data_raw_004B75AB_xz xz[12];
} data_raw_004B75AB_t;
#pragma pack()
typedef char data_raw_004B75AB_size_check[(sizeof(data_raw_004B75AB_t) == 69) ? 1 : -1];
data_raw_004B75AB_t data_raw_004B75AB = {
    { 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x35, 0x35, 0x37, 0x38, 0x3A, 0x3B, 0x3C, 0x00, 0x12, 0x14, 0x0E, 0x0C, 0x00, 0x00, 0x00, 0x00 },
    {
        { 0, 128 }, { -128, 192 }, { 128, 192 }, { -256, 0 }, { 256, 0 }, { 0, 128 },
        { -64, 128 }, { 64, 128 }, { -128, 0 }, { 128, 0 }, { 0, 0 }, { 0, 0 },
    },
};
