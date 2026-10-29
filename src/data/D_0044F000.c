typedef short s16;
/* func_001E1700 copies these 0x28 bytes to the stack (lq +0, lq +0x10, ld +0x20) and reads
 * lh [n] and lh [10 + n] of the copy (sp +0x30/+0x44) with n = the u8 at +0x21. */
s16 D_0044F000[2][10] = {
    { 0, 32, 64, 96, 128, 16, 48, 80, 112, 144 },
    { 40, -40, 32, -32, 24, -24, 16, -16, 8, -8 },
};
