typedef signed char s8;
/* Trailing cell, then an 8x8 signed-byte grid at 0x0043F9A0 read with lb (indexed [row<<3 + col]); -1 marks an unmapped cell. */
s8 data_u8_0043F99F[65] = {
    -1,  /* last cell of the previous grid row */
    -1, 32, 28, 56, 7, 45, 54, -1,
    -1, 35, 2, 21, 6, 57, 46, -1,
    39, 31, 0, 20, 22, 8, 47, 43,
    33, 30, 1, 19, 23, 9, 40, 53,
    37, 55, 4, 18, 11, 12, 41, 49,
    38, 3, 34, 16, 15, 14, 44, 50,
    -1, 36, 5, 17, 10, 13, 51, -1,
    -1, 58, 29, 27, 48, 42, 52, -1,
};
