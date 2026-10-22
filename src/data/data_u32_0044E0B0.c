typedef unsigned char u8;
typedef unsigned short u16;
/* Head of a 20-byte record: the reader around 001D3D54 reads u8 at +0 (stored to actor+0x13C) and u16 at +2. */
typedef struct { u8 animation; u8 unused; u16 argument; } Mv_0044E0B0;
typedef char Mv_0044E0B0_size_check[(sizeof(Mv_0044E0B0) == 4) ? 1 : -1];
Mv_0044E0B0 data_u32_0044E0B0 = { 1, 0, 0 };
