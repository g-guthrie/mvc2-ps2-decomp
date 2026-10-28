typedef signed int s32;
/* Six slot words: func_00176300 clears each (sw 0x00176304-0x00176330),
 * func_00176340 stores slot[a1] (sll 2), func_00176360 loads each word and
 * compares it to -1. */
s32 D_00446BF0[6] = { 0, 0, 0, 0, 0, 0 };
