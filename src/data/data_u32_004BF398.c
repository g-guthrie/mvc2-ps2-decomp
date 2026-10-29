typedef unsigned char u8;
/* Two 1-based u8 lookups indexed by the u8 at actor +0x20 (1..4): func_00148390 reads
 * [gp D_004BF397 + n] (also func_00148700 at 0x0014873C) and [gp D_004BF39B + n], i.e.
 * data_u32_004BF398[0][n - 1] and data_u32_004BF398[1][n - 1]. */
const u8 data_u32_004BF398[2][4] = {
    { 0x00, 0x00, 0x04, 0x07 }, { 0x71, 0x00, 0x75, 0x78 },
};
