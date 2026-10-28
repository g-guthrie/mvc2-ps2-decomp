typedef signed char s8;
/* Three 4-byte s8 input-pattern rows (read +0..+3 with lb by func_00184xxx via actor +0x408).
 * move_setup.c stores &row[0..2] at actor +0x408 for cases 0..2 when p[0x210] != 0
 * (0x00263364 / 0x0026339C / 0x002633EC), paired with the rows of data_u32_004C0648. */
s8 data_u32_004C0660[3][4] = {
    { 1, 2, 0, 2 },
    { -1, 2, 1, 2 },
    { -1, -1, -1, 2 },
};
