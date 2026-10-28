/* 256-byte formatted text buffer of the runtime service. func_004112D8
 * (0x004112D8) clears it with func_0011D8F8(buf, 0, 0x100) (0x004112F0-0x004112F8)
 * and formats into it with func_00122340 (0x00411348); func_00411380 and
 * func_004113D0 (0x00411380, 0x004113D0) copy at most 255 bytes into it
 * (func_00120440 / func_001200D8 with limit 0xFF, 0x00411394 and 0x00411408) so
 * the final byte stays NUL. Each then passes the buffer to the callback in
 * D_004C2B20 (0x004113B4). Initially all zero. */
unsigned char gRuntimeTextBuffer_00496748[256] = { 0 };
