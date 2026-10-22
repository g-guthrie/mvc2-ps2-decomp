typedef short s16;
/* 40 bytes of s16 pairs. func_003B5B30 (asm, 0x003B5C4C..) reads a[row][col] at
   base + 6*row + 2*col with row = p[0x20] and col = p[0x21]; a second column b[row][1]
   (base + 24 + 4*row + 2) and b[row][0] (base + 24 + 4*row) feed the same routine. */
typedef struct {
    s16 a[4][3];
    s16 b[4][2];
} data_u32_00474100_t;
typedef char data_u32_00474100_t_size_check[(sizeof(data_u32_00474100_t) == 40) ? 1 : -1];
data_u32_00474100_t data_u32_00474100 = {
    {
        { 0x1000, 0x4000, 0x7000 },
        { 0x1000, 0x2000, 0x3000 },
        { 0x7000, 0x4000, 0x1000 },
        { 0x0000, 0x0000, 0x0000 },
    },
    {
        { 0x0700, -384 },
        { 0x0300, 0x0000 },
        { 0x1000, 0x0000 },
        { 0x0000, 0x0000 },
    },
};
