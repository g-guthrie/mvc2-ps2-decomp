typedef signed char s8;
/* func_00182C30 masks a random selector with 0x1F and loads a signed byte from D_00448DF0+index (0x00182C44-5C). func_00182DB0 does the same from the interior base D_00448E10 (=D_00448DF0+0x20) at 0x00182DC4-DC. The two 32-entry lookup views consume this full 0x40-byte span. */
s8 data_s8_00448DF0[64] = {
    3, -2, -1, 0, -3, -2, -1, -1,
    -1, 4, 3, -2, 4, 2, -4, 1,
    -2, 1, -3, 1, -4, 0, 2, 0,
    1, 3, 0, -2, 1, 2, 0, -3,
    3, -2, -1, 0, 0, 1, 2, -1,
    1, 0, -3, 2, 0, 0, -2, -3,
    0, 2, 0, 0, 0, -1, 0, 1,
    -1, 0, -2, 1, 0, 0, 0, 3,
};
