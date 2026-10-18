typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct G_002A3E20 { u8 pad0[0x7C]; s16 tab[64]; } G_002A3E20;
typedef struct P_002A3E20 { u8 pad0[2]; u8 b2; u8 pad3[3]; u8 b6; u8 pad7[0x5C-7]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x1B2-0x70]; u8 b1b2; u8 pad1b3[2]; u8 b1b5; u8 pad1b6[1]; u8 b1b7; u8 pad1b8[0x1C0-0x1B8]; s16 s1c0; u8 pad1c2[0x1D8-0x1C2]; s32 w1d8; u8 pad1dc[0x1E6-0x1DC]; u8 b1e6; } P_002A3E20;
extern G_002A3E20 *D_004C2794;
extern void func_001757E0(void *, s32, s32);
void func_002A3E20(P_002A3E20 *p) {
  p->b6 = 7;
  p->b1b5 = (p->b1b7 != 0) ? 0x41 : 0x40;
  p->b1b2 = *(u16 *)&p->s1c0 = 0;
  p->w1d8 = 0;
  D_004C2794->tab[p->b2]++;
  p->f5c = 0;
  p->f60 = 0;
  p->f68 = 0;
  p->f6c = 0;
  p->f5c = (p->b1e6 != 0) ? 14.1666660309f : -14.1666660309f;
  p->f68 = (p->b1e6 != 0) ? -0.7291666269f : 0.7291666269f;
  func_001757E0(p, 0x15, 0x1A);
}

