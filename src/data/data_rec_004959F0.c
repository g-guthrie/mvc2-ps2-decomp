typedef unsigned int u32;
/* Hex-digit value table read by decode_hex_length (func_004105D8, 0x004105D8-
 * 0x00410683): each of the 7 text bytes is loaded with lb (so the index is
 * (s8)character), shifted left 2 and added to %lo(D_004959F0) (0x004105E0-
 * 0x004105F0), then loaded with lw. '0'..'9' map to 0..9 and 'A'..'F' and
 * 'a'..'f' to 10..15; every other character maps to 0. The table covers
 * characters 0x00..0x6F (112 words), the extent of the retail span. */
u32 data_rec_004959F0[112] = {
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x00 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x08 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x10 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x18 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x20 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x28 */
     0,  1,  2,  3,  4,  5,  6,  7,  /* 0x30 */
     8,  9,  0,  0,  0,  0,  0,  0,  /* 0x38 */
     0, 10, 11, 12, 13, 14, 15,  0,  /* 0x40 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x48 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x50 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x58 */
     0, 10, 11, 12, 13, 14, 15,  0,  /* 0x60 */
     0,  0,  0,  0,  0,  0,  0,  0,  /* 0x68 */
};
