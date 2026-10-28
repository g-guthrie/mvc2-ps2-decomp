typedef signed char s8;
/* Two 4-byte s8 input patterns: move_setup.c stores row 0 (0x0026BCE0) and row 1
 * (0x0026BD1C, D_004C06A8) at actor +0x408 for cases 1 and 2. All -1 (no step). */
s8 data_ff_004C06A4[2][4] = {
    { -1, -1, -1, -1 },
    { -1, -1, -1, -1 },
};
