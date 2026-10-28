typedef unsigned char u8;
/* Zero gap after the three-entry jump table at 0x00446C08, up to the 16-byte
 * aligned block at 0x00446C20. No code reads it. */
u8 data_pad_00446C14[0xC] = { 0 };
