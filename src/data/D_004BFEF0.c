typedef unsigned char u8;
/* func_00219490 (0x00219494 gp_rel) loads entry [actor byte +0x22] (lbu) into
 * actor +0x1E6 / +0x140. The table runs up to D_004BFEF8; no reader bounds the
 * index, so all 8 bytes are kept as entries. */
u8 D_004BFEF0[8] = { 0, 1, 1, 1, 0, 0, 0, 0 };
