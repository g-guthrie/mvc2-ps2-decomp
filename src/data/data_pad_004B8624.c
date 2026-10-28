typedef unsigned char u8;
/* Zero alignment gap between the boot path format string (ends 0x004B8624) and
 * the first table at 0x004B8630. No code reads it. */
u8 data_pad_004B8624[0xC] = { 0 };
