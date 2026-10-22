typedef short s16;
/* Signed {x, y} halfword pairs indexed by the byte at offset 0x21 (index * 4): the x
 * component is read at +0 and the y component at +2. */
typedef struct {
    s16 x;
    s16 y;
} data_u32_0044ED20_pt_t;
typedef char data_u32_0044ED20_size_check[(sizeof(data_u32_0044ED20_pt_t) == 4) ? 1 : -1];

data_u32_0044ED20_pt_t data_u32_0044ED20[4] = {
    { 59, 23 },
    { 15, -61 },
    { -55, -29 },
    { -15, 65 },
};
