typedef int s32;
/* Four 8-byte records of s32 16.16 fixed-point values. func_0019EF00 reads x at base + 8*idx
   and y at base + 8*idx + 4, converts each with cvt.s.w, and divides by 65536.0. */
typedef struct {
    s32 x;
    s32 y;
} data_u32_0044AD10_rec;
typedef char data_u32_0044AD10_rec_size_check[(sizeof(data_u32_0044AD10_rec) == 8) ? 1 : -1];
data_u32_0044AD10_rec data_u32_0044AD10[4] = {
    { 0x00400000, 0x00500000 },
    { 0x00400000, 0x00750000 },
    { 0x00230000, 0x00850000 },
    { 0x00000000, 0x00000000 },
};
