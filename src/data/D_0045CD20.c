typedef int s32;
/* func_00308AB0 reads lwc1 [n*8] (D_0045CD20) and [n*8+4] (D_0045CD24) and converts them
 * with cvt.s.w; n = (s8 actor +0x151) - 1 from func_003053D0. The last pair is zero; the
 * index is not bounded here, so it stays a row up to the input records at 0x0045CD40. */
s32 D_0045CD20[4][2] = {
    { 0x00400000, 0x00300000 }, { 0x00780000, 0x00540000 },
    { 0x00600000, 0x009E0000 }, { 0x00000000, 0x00000000 },
};
