/* func_001F38C0 (0x001F3A2C-0x001F3A48 / 0x001F3A74-0x001F3A90) indexes this table with the signed step counter at
 * +2 of its state block (lb, sll 2, lw) and adds the word to the
 * D_0044F530 / D_0044F550 base selected by actor+0x25 before calling
 * func_00176160. Seventeen words; the zero words up to the next
 * 16-byte boundary are outside this table. */
int data_s32_0044F4E0[17] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
