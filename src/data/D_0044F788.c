typedef short s16;
/* func_001F0D50 reads lh at D_0044F784 + (s8 actor +0x161)*4 + (u8 actor +0x1B7)*2 after
 * skipping +0x161 == 0, i.e. D_0044F788[n - 1][side]. Rows 3..5 are zero; this reader does
 * not bound n, so they stay rows of the table up to jtbl_0044F7A0. */
s16 D_0044F788[6][2] = {
    { 0x1000, 0x1400 }, { 0x1400, 0x1C00 }, { 0x1800, 0x3800 },
    { 0x0000, 0x0000 }, { 0x0000, 0x0000 }, { 0x0000, 0x0000 },
};
