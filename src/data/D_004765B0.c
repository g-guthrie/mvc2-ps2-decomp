typedef short s16;
/* func_003CA340 reads lh [n*2] and lh [0x10 + n*2] of D_004765B0 with n = u8 actor +0x20,
 * like the [2][8] table at D_00476580 (followed by D_004765A0 at +0x20). */
s16 D_004765B0[2][8] = {
    { -768, -544, -512, -64, -256, -512, -768, -768 },
    { 48, 32, 48, 0, 64, 48, 96, 16 },
};
