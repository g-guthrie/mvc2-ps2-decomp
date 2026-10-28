typedef unsigned char u8;
/* Two-byte rows indexed by p[0x1B7]: fb25_b.c reads D_004B7130[p[0x1B7] * 2 + a2]
 * (0x0021F57C) and the launch initializers read rows 0, 1 and 2 directly
 * (D_004B7130 at 0x0021F8E4, D_004B7132 at 0x0021F744, D_004B7134 at 0x0021F814). */
u8 D_004B7130[3][2] = {
    { 0x40, 0x41 },
    { 0x44, 0x45 },
    { 0x42, 0x43 },
};
