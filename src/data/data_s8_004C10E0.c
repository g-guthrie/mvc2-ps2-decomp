typedef signed char s8;
/* 3 4-byte s8 input-pattern rows (D_004C10E0 at 0x002E4DBC / D_004C10E4 / D_004C10E8), stored at actor +0x408
 * and read +0..+3 with lb. Same 3-row grouping as data_s8_004C0898. */
s8 data_s8_004C10E0[3][4] = {
    { 1, 2, 0, 2 },
    { -1, 2, 1, 2 },
    { -1, -1, -1, -1 },
};
