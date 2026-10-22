typedef unsigned char u8;
/* Two-column byte table: func_001EB130 reads column 0 at base + 2*idx and column 1 at
   base + 1 + 2*idx (D_004BFB60 and D_004BFB61, gp-relative), idx = p[0x1B7]. */
u8 data_u32_004BFB60[4][2] = {
    { 0x01, 0x01 },
    { 0x01, 0x01 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
};
