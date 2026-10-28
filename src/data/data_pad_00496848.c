typedef unsigned char u8;
/* Zero gap after the 256-byte text buffer, up to the 16-byte aligned object at
 * 0x00496850. No code reads it. */
u8 data_pad_00496848[8] = { 0 };
