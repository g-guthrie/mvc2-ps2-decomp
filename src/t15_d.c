typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Q_0018CCD0 { u8 pad0[0x34]; f32 f34; } Q_0018CCD0;
typedef struct P_0018CCD0 { u8 pad0[0x34]; f32 f34; u8 pad38[0x68-0x38]; f32 f68; u8 pad6c[0x1C8-0x6C]; Q_0018CCD0 *q1c8; Q_0018CCD0 *q1cc; u8 pad1d0[0x220-0x1D0]; Q_0018CCD0 *q220; u8 pad224[0x22C-0x224]; f32 f22c; } P_0018CCD0;
extern s16 D_00446C40[];
void func_0018CCD0(P_0018CCD0 *p, u32 idx) {
  Q_0018CCD0 *a;
  f32 r;
  if (p->q1c8 == p->q1cc) *((u8 *)p->q1cc + 0x209) = 3;
  a = p->q1c8;
  if (a == 0) a = p->q220;
  r = 1.66666663f * (f32)D_00446C40[(u8)idx] / 256.0f;
  *(u32 *)&p->f68 = 0x3FFD5555;
  if (p->f34 < a->f34) {
    r = -r;
    p->f68 = -p->f68;
  }
  p->f22c = r;
}

typedef struct Q_00266510 { u8 pad0[0x1C]; s16 s1c; } Q_00266510;
typedef struct P_00266510 { u8 pad0[6]; u8 b6; u8 pad7[0x14-7]; Q_00266510 *q14; u8 pad18[0x38-0x18]; f32 f38; u8 pad3c[0x5C-0x3C]; f32 f5c; u8 pad60[0x140-0x60]; s16 s140; u8 pad142[0x151-0x142]; u8 b151; u8 pad152[0x33B-0x152]; u8 b33b; u8 b33c; u8 pad33d[0x40C-0x33D]; u8 b40c; u8 b40d; u8 pad40e[0x430-0x40E]; f32 f430; } P_00266510;
extern s8 func_00175700(void *);
extern void func_001757E0(void *, s32, s32);
void func_00266510(P_00266510 *p) {
  u32 t;
  f32 v;
  p->b40c = 2;
  p->b33c = 5;
  if (func_00175700(p) < 0) {
    p->b40d = 0;
    p->b40c = 0;
    p->b33b = 0;
    p->b33c = 0;
    p->b151 = 0;
    t = p->b6;
    p->b6 = t + 1;
    p->f5c = (p->s140 != 0) ? -8.0357141495f : 8.0357141495f;
    func_001757E0(p, 0x16, 10);
    p->q14->s1c--;
    p->f38 = p->f430;
  }
}

