/* Tail padding after the "0" string at 0x004ACA68, then the "." string at
   0x004ACA70 (D_004ACA70, a 1-byte iovec string in the vfprintf code) with its
   zero fill. */
typedef char c8;
c8 data_u8_004ACA69[23] = { 0, 0, 0, 0, 0, 0, 0, '.' };
