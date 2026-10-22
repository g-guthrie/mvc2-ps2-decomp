typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Five 48-byte records (u16 a, u16 b, f32 c, f32 d, u32 z[5], f32 e, u32 n, f32 f, f32 g), then a 10-word tail. */
typedef unsigned short u16;
typedef struct { u16 a; u16 b; f32 c; f32 d; u32 z[5]; f32 e; u32 n; f32 f; f32 g; } Rec48;
typedef char Rec48_size[(sizeof(Rec48)==48)?1:-1];
typedef struct { Rec48 rec[5]; u32 tail[10]; } Rec48Table;
typedef char Rec48Table_size[(sizeof(Rec48Table)==280)?1:-1];
Rec48Table data_u32_00441B28 = {
  {
      { 0xFFFFu, 0x0000u, 1.0f, 0.100000001f, { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u }, 1.0f, 0x00000007u, 1.10000002f, 1.0f },
      { 0xFFFFu, 0x0000u, 1.0f, 0.100000001f, { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u }, 1.0f, 0x00000007u, 1.5f, 1.0f },
      { 0xFFFFu, 0x0000u, 1.0f, 0.100000001f, { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u }, 1.0f, 0x00000007u, 1.79999995f, 1.0f },
      { 0xFFFFu, 0x0000u, 1.0f, 0.100000001f, { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u }, 1.0f, 0x00000007u, 0.25f, 1.0f },
      { 0xFFFFu, 0x0000u, 1.0f, 0.100000001f, { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u }, 1.0f, 0x00000007u, 0.25f, 1.0f },
  },
  { 0x0000FFFFu, 0x3F800000u, 0x3DCCCCCDu, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x3F800000u, 0x0000000Au },
};
