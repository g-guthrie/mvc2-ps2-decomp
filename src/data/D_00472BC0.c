typedef short s16;
/* Twelve (x, y) points of a ring: func_003A3940 and func_003A4250 read lh [i*4] and
 * [i*4+2] with i = actor +0x1E, which func_003A4250 wraps at 0xC. The tables after it
 * (D_00472BF0) are reached through D_00472CB0. */
s16 D_00472BC0[12][2] = {
    { 0, 36 }, { -18, 32 }, { -32, 18 }, { -40, 0 }, { -32, -18 }, { -18, -32 },
    { 0, -36 }, { 18, -32 }, { 32, -18 }, { 40, 0 }, { 32, 18 }, { 18, 32 },
};
