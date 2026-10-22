typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
/* Four sub-tables, each read by index: a[] as s16 at base + 2*idx (func_003AE370, idx = word at 0xD0);
   b[] as u8 at base + 8 + idx (func_003AF650, idx = u16 at 0x2B8); c[] as u8 at base + 16 + idx
   (func_003AFE10); d[][2] as s8 pairs at base + 24 + 2*idx (func_003B0160, idx = p[0x1B7]). */
typedef struct {
    s16 a[4];
    u8 b[8];
    u8 c[8];
    s8 d[8][2];
} data_raw_004C1F50_t;
typedef char data_raw_004C1F50_t_size_check[(sizeof(data_raw_004C1F50_t) == 40) ? 1 : -1];
data_raw_004C1F50_t data_raw_004C1F50 = {
    { 16, 8, 24, 0 },
    { 0x06, 0x05, 0x04, 0x00, 0x09, 0x08, 0x07, 0x00 },
    { 0x1D, 0x18, 0x13, 0x0D, 0x08, 0x03, 0x00, 0x00 },
    { { -6, 0 }, { 0, 8 }, { 0, 0 }, { 0, 0 }, { -2, 2 }, { -2, 2 }, { -1, 1 }, { -1, 1 } },
};
