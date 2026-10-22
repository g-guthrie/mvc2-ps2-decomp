typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
/* func_003175D0 stores a pointer into this table at +0x408 of the object, indexed by
   (byte@+0x1FC)*4 + (byte@+0x212)*12, switching to the second half (+0x40) when byte@+0x210 != 0;
   the reader at 0x001847C8 then fetches s8 values at offsets 0..3 of the selected 4-byte entry. */
typedef struct {
    s8 v[4];
} data_u32_0045D660_s8x4;
typedef struct {
    u32 a;
    u32 b;
    u16 h[4];
} data_u32_0045D660_rec;
typedef struct {
    data_u32_0045D660_s8x4 s[24];
    data_u32_0045D660_rec r[8];
} data_u32_0045D660_t;
typedef char data_u32_0045D660_size_check[(sizeof(data_u32_0045D660_t) == 224) ? 1 : -1];
data_u32_0045D660_t data_u32_0045D660 = {
    {
    { 1, 2, 1, 2 },
    { -1, 2, -1, 2 },
    { -1, -1, -1, -1 },
    { 1, 2, 1, 2 },
    { -1, 2, -1, 2 },
    { -1, -1, -1, -1 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 1, 2, 0, 2 },
    { -1, 2, 1, 2 },
    { -1, -1, -1, 2 },
    { 1, 2, 1, 2 },
    { -1, 2, -1, 2 },
    { -1, -1, -1, -1 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 1, 2, 0, 2 },
    { -1, 2, 1, 2 },
    { -1, -1, -1, 2 },
    { 1, 2, 1, 2 },
    { -1, 2, -1, 2 },
    { -1, -1, -1, -1 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 }
    },
    {
    { 0x91000003u, 0x00000000u, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x10000003u, 0x00000001u, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x20000003u, 0x00000004u, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x10000003u, 0x00000002u, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x91000003u, 0x00000006u, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x10000003u, 0x00000008u, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x90000003u, 0x00000008u, { 0x1000, 0x1800, 0x0800, 0x0140 } },
    { 0x10000003u, 0x0000000Cu, { 0x1000, 0x1400, 0x0400, 0x0060 } }
    },
};
