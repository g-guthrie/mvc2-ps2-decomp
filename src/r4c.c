typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 004161D0 */
typedef struct H_004161D0 { s32 w0; s32 p4; s32 w8; u16 hc; u8 pad[3]; u8 b11; } H_004161D0;
typedef struct { s32 w0; s8 *w4; H_004161D0 *w8; s32 wc; s32 w10; s32 w14; s32 w18; } S_004161D0;
s32 func_004161D0(S_004161D0 *p, s8 *buf) {
  s8 *c;
  p->w0 = (s32)buf;
  p->w4 = buf;
  c = p->w4;
  if (c[0] != 0x54 || c[1] != 0x49 || c[2] != 0x4D || c[3] != 0x32) return 0;
  p->w8 = (H_004161D0 *)(buf + 0x10);
  if (p->w8->b11 > 1) p->wc = (s32)p->w8 + 0x30;
  p->w10 = (s32)p->w8 + p->w8->hc;
  p->w14 = p->w10 + p->w8->w8;
  p->w18 = p->w8->w0 + 0x10;
  return 1;
}

