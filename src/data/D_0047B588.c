/* ring source unit at 0x0047B588, exact bytes preserved. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef struct { u8 b0; u8 b1; u16 h2; s32 w4; s32 w8; s32 wC; } E3FB;
/* Exact writer func_003FB510 wraps its write cursor modulo 256 and fills all six fields. */
E3FB D_0047B588[256] = { { 0, 0, 0, 0, 0, 0 } };
