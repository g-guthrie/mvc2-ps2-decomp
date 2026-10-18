typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2890[2];
extern void func_003DF850(s32, s32);
extern void func_003EA660(s32, s32 *);
void func_0016E8F0(void) {
  func_003DF850(0xD, 0);
  func_003DF850(0x5D, 0x32);
  func_003DF850(0x63, 0x20000);
  func_003EA660(1, D_004C2890);
  func_003DF850(4, D_004C2890[0]);
  func_003DF850(0x62, 0);
}

typedef struct G_00128690 { u8 pad0[2]; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; s8 b7; u8 pad8[2]; s16 s0a; u8 pad0c[0x19-0xC]; u8 b19; } G_00128690;
extern G_00128690 *D_004C2840;
extern void func_003DA410(void);
extern void func_00122840(u32);
extern void func_001E40E0(void);
extern void func_001E4140(void);
extern void func_001E4150(void);
void func_00128690(void) {
  s8 *q;
  s8 t;
  u8 one;
  q = &D_004C2840->b7;
  t = *q;
  if (t != 0) *q = t - 1;
  if (D_004C2840->s0a-- == 0) {
    one = 1;
    D_004C2840->b2 = 0;
    D_004C2840->b3 = 0;
    D_004C2840->b4 = 0;
    D_004C2840->b3 = 0;
    D_004C2840->b5 = 0;
    D_004C2840->b6 = 0;
    D_004C2840->b7 = 0;
    D_004C2840->b19 = one;
    func_003DA410();
    func_00122840(0xFF000000);
    func_001E40E0();
    func_001E4140();
    func_001E4150();
  }
}

typedef struct G_002D24A0 { u8 pad0[0x7C]; s16 tab[64]; } G_002D24A0;
typedef struct P_002D24A0 { u8 pad0[2]; u8 b2; u8 pad3[0x151-3]; s8 b151; u8 pad152[0x1B2-0x152]; u8 b1b2; u8 pad1b3[2]; u8 b1b5; u8 pad1b6[0x1C0-0x1B6]; s16 s1c0; u8 pad1c2[0x1D8-0x1C2]; s32 w1d8; u8 pad1dc[0x1FC-0x1DC]; u8 b1fc; } P_002D24A0;
extern G_002D24A0 *D_004C2794;
extern s8 func_00175700(void *);
extern void func_001843A0(P_002D24A0 *);
void func_002D24A0(P_002D24A0 *p) {
  if (p->b1fc == 1) {
    if (func_00175700(p) < 0) {
      func_001843A0(p);
      return;
    }
    if (p->b151 != 0) {
      p->b1b5 = 0x19;
      p->b1b2 = *(u16 *)&p->s1c0 = 0;
      p->w1d8 = 0;
      D_004C2794->tab[p->b2]++;
      p->b151 = 0;
    }
  } else {
    if (func_00175700(p) < 0) func_001843A0(p);
  }
}

