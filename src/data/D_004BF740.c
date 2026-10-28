/* func_001A4CB0 (0x001A4CD8 gp_rel) stores entry [actor byte +0x20] at actor +0x14
 * (src/q10_c.c); each entry is a motion-step pointer table. */
typedef const unsigned char *Mvc2Address;
extern Mvc2Address const jtbl_0044B2A0[];
extern Mvc2Address const jtbl_0044B2D0[];

const void * const D_004BF740[2] = {
    jtbl_0044B2A0,
    jtbl_0044B2D0,
};
