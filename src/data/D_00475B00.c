typedef short s16;
/* func_003BE300 reads lh +0/+2 (and the next record fields) at D_00475B00 + 8 * (u8 actor
 * +0x21). Six 8-byte records up to jtbl_00475B30; the last one is zero. */
s16 D_00475B00[6][4] = {
    { -96, 48, 0, 15 }, { 35, -85, 1, 15 },
    { 48, -56, 0, 8 }, { -48, -40, 0, 8 },
    { 16, 16, 0, 8 }, { 0, 0, 0, 0 },
};
