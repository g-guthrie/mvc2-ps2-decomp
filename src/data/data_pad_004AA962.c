typedef unsigned char u8;
/* Zero gap after the effect text stream at 0x004AA8A0, up to the 16-byte
 * aligned table at 0x004AA970. No code reads it. */
u8 data_pad_004AA962[0xE] = { 0 };
