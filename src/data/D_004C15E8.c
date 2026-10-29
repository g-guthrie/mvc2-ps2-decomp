typedef signed char s8;
/* Six 4-byte rows; D_0045CFD0 points at each, and func_0030CE90 loads D_0045CFD0[n % 6]
 * into actor +0x408. */
s8 D_004C15E8[6][4] = {
    { 1, 2, 0, 2 }, { -1, 2, 1, 2 }, { -1, -1, -1, 2 },
    { 1, 2, 1, 2 }, { -1, 2, -1, 2 }, { -1, -1, -1, -1 },
};
