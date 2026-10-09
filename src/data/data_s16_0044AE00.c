/* func_001A0620/001A1910 use field +0x22 as a 0..31 sector; each sector reads two signed (x,y) halfword offsets at 8-byte stride. Constructors bound it with an 8-bit angle shifted right by three; step updates mask the sector with 0x1F. The pairs are converted to float and applied to object coordinates. */
typedef signed short s16;
s16 data_s16_0044AE00[128] = {
    0, 6, 0, -6, 1, 6, -1, -6, 3, 6, -3, -6,
    5, 6, -4, -5, 6, 5, -5, -4, 7, 3, -7, -3,
    8, 2, -7, -2, 8, 1, -7, -1, 8, 0, -7, 0,
    8, -1, -7, 1, 8, -2, -7, 2, 7, -3, -7, 3,
    6, -5, -5, 4, 5, -6, -4, 5, 3, -6, -3, 6,
    1, -6, -1, 6, 0, -6, 0, 6, -1, -6, 1, 6,
    -3, -6, 3, 6, -5, -6, 4, 5, -6, -5, 5, 4,
    -7, -3, 7, 3, -8, -2, 7, 2, -8, -1, 7, 1,
    -8, 0, 7, 0, -8, 1, 7, -1, -8, 2, 7, -2,
    -7, 3, 7, -3, -6, 5, 5, -4, -5, 6, 4, -5,
    -3, 6, 3, -6, -1, 6, 1, -6,
};
