typedef signed char s8;
/* Per-character byte remap: the reader in rb89_c.c loads lb D_004B6C50[pl->b0] at 0x001E6120.
 * D_004B6C90 and D_004B6CD0 are the two sibling 0x40-entry tables read with the same index. */
s8 D_004B6C50[0x40] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 24, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
};
