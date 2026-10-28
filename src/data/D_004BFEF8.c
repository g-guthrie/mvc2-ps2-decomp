typedef int s32;
/* 16.16 fixed-point speeds: func_00219A20 (0x00219A60 gp_rel) reads entry
 * [actor byte +0x1B7] (sll 2, lwc1 + cvt.s.w, / 65536.0f) into motion vx. */
s32 D_004BFEF8[2] = { -20 * 0x10000, -52 * 0x10000 };
