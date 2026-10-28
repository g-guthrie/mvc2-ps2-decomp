/* func_001F51B0 (0x001F531C-0x001F5338 / 0x001F5364-0x001F5380) indexes this table with the signed step counter at
 * +2 of its state block (lb, sll 2, lw) and adds the word to the
 * D_0044F530 / D_0044F550 base selected by actor+0x25 before calling
 * func_00176160. Seventeen words; the zero words up to the next
 * 16-byte boundary are outside this table. */
int data_s32_0044F570[17] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2 };
