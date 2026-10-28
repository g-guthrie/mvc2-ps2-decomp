typedef signed short s16;
/* func_001DCDE0: when its mode argument is 0 it uses this table with a count of 1
 * (0x001DCE14/0x001DCE18) instead of D_0044EC60 (8) / D_0044EC80 (9); the loop reads
 * lh +0 and lh +2 per 4-byte entry (0x001DCE9C / 0x001DCEBC). One {x, y} offset of zero. */
s16 D_004BFACC[1][2] = { { 0, 0 } };
