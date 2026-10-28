typedef signed short s16;
/* Per-variant (x, y) offset tables. func_001A5BC0 selects one with the u8 at actor +0x23
 * (gp_rel D_004BF748, lw), then loads two halfwords (lh +0/+2) at
 * ((actor +0x21 & 0x7F) * 4 + (bit 7 ? 2 : 0)) * 2: 8-byte records holding a normal and an
 * alternate (x, y) pair. Both tables start mid-unit (0x0044B350 sits in the gap before
 * jtbl_0044B358, 0x0044B370 inside it). */
extern const s16 D_0044B350[];
extern const s16 D_0044B370[];
const s16 *const D_004BF748[2] = {
    D_0044B350,
    D_0044B370,
};
