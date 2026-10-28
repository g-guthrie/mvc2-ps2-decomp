typedef unsigned char u8;
/* func_001EADD0 (0x001EADD4 gp_rel) loads entry [actor byte +0x20] (lbu) as the
 * func_001757E0 parameter; for index 0 it substitutes data_u8_004BFB48[rand & 7].
 * The table runs up to jtbl_004BFB58; no reader bounds the index, so all 8 bytes
 * are kept as entries. */
u8 D_004BFB50[8] = { 4, 4, 0, 4, 4, 0, 0, 0 };
