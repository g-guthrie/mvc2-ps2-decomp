typedef short s16;
/* func_003A8ED0 (and src/sLa2_a.c, src/s8d_a.c as E8 { x, y, f, an }) reads lh +0/+2/+4/+6
 * of D_00473040 + 8 * (actor +0xDC); func_003A8DB0 sets +0xDC from rows of D_00472FD0.
 * Eight records up to the jump table jtbl_00473080; their last field runs 0x15..0x1C. */
typedef struct { s16 x, y, f, an; } E8;
E8 D_00473040[8] = {
    { 0, 72, 0, 21 }, { 48, 48, 0, 22 },
    { 0, 56, 0, 23 }, { 48, 40, 1, 24 },
    { 72, 32, 0, 25 }, { 80, 8, 0, 26 },
    { 72, 0, 0, 27 }, { 48, 48, 0, 28 },
};
