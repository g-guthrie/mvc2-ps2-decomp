typedef unsigned char u8;
/* Zero gap after the three-float vector at 0x00444ED8, up to the 16-byte
 * aligned block at 0x00444EF0. No code reads it. */
u8 data_pad_00444EE4[0xC] = { 0 };
