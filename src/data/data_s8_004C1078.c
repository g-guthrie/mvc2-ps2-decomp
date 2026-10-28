typedef signed char s8;
/* 3 4-byte s8 input-pattern rows (D_004C1078 at 0x002DCF60 / D_004C107C / D_004C1080), stored at actor +0x408
 * and read +0..+3 with lb. Same 3-row grouping as data_s8_004C0898. */
s8 data_s8_004C1078[3][4] = {
    { 1, 2, 0, 2 },
    { -1, 2, 1, 2 },
    { -1, -1, -1, 2 },
};
