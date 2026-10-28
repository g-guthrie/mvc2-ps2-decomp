typedef unsigned char u8;
/* Zero gap after the callback table at 0x00457FF8, before the first descriptor
 * at 0x00458008. No code reads it. */
u8 data_pad_00458004[4] = { 0 };
