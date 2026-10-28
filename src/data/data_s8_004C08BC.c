typedef signed char s8;
/* Three 4-byte s8 input-pattern rows (D_004C08BC / D_004C08C0 / D_004C08C4), each stored at actor +0x408
 * by its own gp_rel reference and read +0..+3 with lb; same 3-row grouping as data_s8_004C0898. */
s8 data_s8_004C08BC[3][4] = {
    { 1, 2, 1, 2 },
    { -1, 2, -1, 2 },
    { -1, -1, -1, -1 },
};
