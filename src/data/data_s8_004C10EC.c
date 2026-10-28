typedef signed char s8;
/* 3 4-byte s8 input-pattern rows (D_004C10EC at 0x002E4F30 / D_004C10F0 / D_004C10F4), stored at actor +0x408
 * and read +0..+3 with lb. Same 3-row grouping as data_s8_004C08BC. */
s8 data_s8_004C10EC[3][4] = {
    { 1, 2, 1, 2 },
    { -1, 2, -1, 2 },
    { -1, -1, -1, -1 },
};
