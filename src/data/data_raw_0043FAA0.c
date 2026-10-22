typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Six 3-float vectors (the first three repeat as the next three), then 10 integer words. */
typedef struct { f32 v[6][3]; u32 z0[3]; u32 a; u32 b; u32 z1; u32 c; u32 d; u32 z2[2]; } Rec112;
typedef char Rec112_size[(sizeof(Rec112)==112)?1:-1];
Rec112 data_raw_0043FAA0 = {
  { { 280.0f, 260.0f, -50.0f }, { 260.0f, 260.0f, -245.0f }, { 240.0f, 260.0f, -450.0f }, { 280.0f, 260.0f, -50.0f }, { 260.0f, 260.0f, -245.0f }, { 240.0f, 260.0f, -450.0f } },
  { 0x00000000u, 0x00000000u, 0x00000000u },
  0x000038E4u, 0x00000444u,
  0x00000000u,
  0x0000C71Du, 0x0000FBBDu,
  { 0x00000000u, 0x00000000u },
};
