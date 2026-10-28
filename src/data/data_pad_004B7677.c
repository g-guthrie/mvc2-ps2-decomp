typedef unsigned char u8;
/* Zero tail after the "STAGE   : %02X" format string, up to data_f32_004B7684. It lies in
 * record 0 of the 28-byte float records based at D_004B7668, which xl9_a.c never indexes
 * (index 1..7). No code reads it. */
u8 data_pad_004B7677[0xD] = { 0 };
