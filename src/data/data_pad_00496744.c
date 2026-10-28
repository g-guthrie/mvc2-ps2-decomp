typedef unsigned char u8;
/* Zero gap between the seven-entry service-mode table (ends 0x00496744) and the
 * 8-byte aligned text buffer at 0x00496748. No code reads it. */
u8 data_pad_00496744[4] = { 0 };
