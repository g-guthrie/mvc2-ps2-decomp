typedef short s16;
/* Selected through D_004BF5E8[u8 actor +0x20] by func_0019FCE0 (gp_rel lw, then lh +0/+2).
 * Each 8-byte record holds a normal and an alternate (x, y) pair; the record index is
 * the u8 at actor +0x21 & 0x7F and bit 7 selects the second pair. Four records: the
 * sibling table starts 0x20 later and the table after it is a separate object. */
s16 D_0044ADC0[4][2][2] = {
    { { 0, 36 }, { 0, 22 } },
    { { -19, 64 }, { 0, 50 } },
    { { -19, 92 }, { 5, 78 } },
    { { 0, 120 }, { 0, 106 } },
};
