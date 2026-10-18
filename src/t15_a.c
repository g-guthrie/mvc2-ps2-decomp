typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175C00(u8 *, s32);
extern void func_0029C030(u8 *);
void func_0029BFB0(u8 *p) {
  u8 a;
  func_00175C00(p, 0);
  a = p[0x212];
  if (a == 0) {
    if ((*(s8*)(p+0x1EA) & 0xF) != 0) { func_0029C030(p); return; }
  }
  if (a != 0) {
    if ((*(s8*)(p+0x1EA) & 0xF0) != 0) func_0029C030(p);
  }
}

extern void func_002C0DC0(u8 *);
void func_002C0D40(u8 *p) {
  u8 a;
  if (p[0x215] != 0) func_002C0DC0(p);
  a = p[0x212];
  if (a == 0) {
    if ((*(s8*)(p+0x1EA) & 0xF) != 0) { func_002C0DC0(p); return; }
  }
  if (a != 0) {
    if ((*(s8*)(p+0x1EA) & 0xF0) != 0) func_002C0DC0(p);
  }
}

extern void func_00191210(u8 *);
extern void func_001E3210(void *, s32);
extern void func_00180DD0(u8 *);
extern void func_0011D8F8(u8 *, s32, s32);
extern void func_00181C40(u8 *);
extern void func_003D6820(s32);
extern void func_00169BE0(u8 *);
void func_00180D20(u8 *a, u8 *b) {
  *(s16 *)(b + 0x43A) = 300;
  func_00191210(b);
  func_001E3210(b, 0x2B);
  func_00180DD0(b);
  func_0011D8F8(b + 0x354, 0, 200);
  func_00181C40(a);
  *(s16 *)(a + 0x438) = *(s16 *)(a + 0x434);
  *(s8 *)(a + 0x1B2) = -1;
  *(s16 *)(a + 0x2B4) = 0;
  *(s8 *)(a + 0x407) = 100;
  func_003D6820(a[2]);
  func_00169BE0(a);
}

extern s8 func_00175700(void *);
extern void func_001843A0(u8 *);
extern void func_00183920(u8 *, u32 *);
extern void func_001E3710(void *, s32);
void func_002CB0A0(u8 *p) {
  s8 r = func_00175700(p);
  s8 a;
  u32 v[4];
  if (r < 0) {
    func_001843A0(p);
    return;
  }
  a = *(s8 *)(p + 0x151);
  if (a & 1) {
    *(s8 *)(p + 0x151) = 0;
    v[0] = 0x3FD55555;
    v[1] = 0x42452492;
    v[2] = 0;
    func_00183920(p, v);
  } else if (a & 2) {
    *(s8 *)(p + 0x151) = 0;
    func_001E3710(p, 0x16);
  }
}

typedef struct { u8 pad0[0x38]; f32 f38; } P_00178B00;
extern void func_00178D80(u8 *, s32);
s32 func_00178B00(u8 *p) {
  if (p[0x20D] == 2 && *(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) return 0;
  if (*(s8 *)(p + 0x539) != 0) {
    if ((*(s8 *)(p + 0x211) & (1 << p[0x1E6])) == 0) return 0;
  } else {
    if ((u16)(*(s16 *)(p + 0x35C) & 0x360) == 0) return 0;
  }
  func_00178D80(p, 4);
  return 1;
}

typedef struct R_0018F270 { u8 pad0[0x12]; u8 b12; } R_0018F270;
typedef struct Q_0018F270 { u8 pad0[0x20D]; u8 b20d; u8 pad20e[2]; u8 b210; u8 pad211[0x274-0x211]; s16 s274; u8 pad276[2]; s16 s278; u8 pad27a[0x286-0x27A]; u8 b286; } Q_0018F270;
typedef struct P_0018F270 { u8 pad0[0x1CC]; Q_0018F270 *q1cc; R_0018F270 *r1d0; u8 pad1d4[0x20D-0x1D4]; u8 b20d; } P_0018F270;
s32 func_0018F270(P_0018F270 *p) {
  Q_0018F270 *q;
  u32 t;
  if ((p->r1d0->b12 & 0x80) == 0) return 0;
  if (p->b20d != 2) return 0;
  q = p->q1cc;
  if ((q->s278 & 1) == 0) return 0;
  if (q->b20d != 2) return 0;
  if (q->b210 == 0) return 0;
  if (q->s274 < 2) return 0;
  t = q->b286;
  q->b286 = t + 1;
  return 1;
}

typedef struct P_0021EEA0 { u8 pad0[6]; u8 b6; u8 pad7[0x1C-7]; s16 s1c; u8 pad1e[0x34-0x1E]; f32 f34; f32 f38; u8 pad3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; } P_0021EEA0;
extern s32 func_001864a0(P_0021EEA0 *);
extern void func_001757E0(void *, s32, s32);
void func_0021EEA0(P_0021EEA0 *p) {
  u32 t;
  func_00175700(p);
  p->f34 += p->f5c;
  p->f5c += p->f68;
  p->f38 += p->f60;
  p->f60 += p->f6c;
  if (func_001864a0(p) != 0) {
    t = p->b6;
    p->b6 = t + 1;
    p->f34 = (f32)p->s1c;
    func_001E3710(p, 0x34);
    func_001757E0(p, 0x12, 1);
  }
}

typedef struct V3_001BBA80 { f32 x, y, z; } V3_001BBA80;
typedef struct P_001BBA80 { u8 pad0[1]; u8 b1; u8 pad2[0x34-2]; V3_001BBA80 v34; u8 pad40[0x13C-0x40]; u8 b13c; u8 pad13d[0x161-0x13D]; s8 b161; } P_001BBA80;
extern void func_001BBD30(P_001BBA80 *, P_001BBA80 *);
extern s32 func_001BBD40(P_001BBA80 *);
extern void func_00175670(P_001BBA80 *);
void func_001BBA80(P_001BBA80 *p, P_001BBA80 *q) {
  p->v34 = q->v34;
  if (p->b1 != q->b1) {
    p->b13c = 0;
    func_001BBD30(p, q);
    return;
  }
  if (q->b161 == 1) {
    p->b13c = 0;
    func_001BBD30(p, q);
  } else if (func_001BBD40(p) != 0) {
    p->b13c = 0;
    func_001BBD30(p, q);
  } else {
    func_00175670(p);
  }
}

typedef struct P_0022A190 { u8 pad0[6]; u8 b6; u8 pad7[0x34-7]; f32 f34; f32 f38; u8 pad3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x20D-0x70]; u8 b20d; u8 pad20e[0x2DC-0x20E]; s32 w2dc; u8 pad2e0[0x430-0x2E0]; f32 f430; } P_0022A190;
extern void func_0022C6B0(P_0022A190 *);
void func_0022A190(P_0022A190 *p) {
  u32 t;
  func_00175700(p);
  p->f34 += p->f5c;
  p->f5c += p->f68;
  p->f38 += p->f60;
  p->f60 += p->f6c;
  p->w2dc = 4;
  if (p->f38 <= p->f430) {
    t = p->b6;
    p->b6 = t + 1;
    p->b20d = 0;
    p->f38 = p->f430;
    func_001757E0(p, 0x15, 0x2F);
    func_0022C6B0(p);
  }
}

typedef struct P_00234EF0 { u8 pad0[6]; u8 b6; u8 b7; u8 pad8[0x34-8]; f32 f34; f32 f38; u8 pad3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x151-0x70]; s8 b151; u8 pad152[0x20D-0x152]; u8 b20d; u8 pad20e[0x430-0x20E]; f32 f430; } P_00234EF0;
void func_00234EF0(P_00234EF0 *p) {
  u32 t;
  func_00175700(p);
  if (p->b151 != 0) {
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
      t = p->b6;
      p->b6 = t + 1;
      p->b7 = 0;
      p->f38 = p->f430;
      p->b20d = 0;
      func_001757E0(p, 0x12, 3);
    }
  }
}

typedef struct T_00227ED0 { f32 a; f32 b; } T_00227ED0;
typedef struct P_00227ED0 { u8 pad0[6]; u8 b6; u8 pad7[0x5C-7]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x140-0x70]; s16 s140; u8 pad142[0x1B7-0x142]; u8 b1b7; u8 pad1b8[0x20D-0x1B8]; u8 b20d; } P_00227ED0;
extern T_00227ED0 D_004518C0[];
extern void func_00185490(P_00227ED0 *);
extern void func_00183D10(P_00227ED0 *);
extern void func_0018C4B0(P_00227ED0 *, s32);
void func_00227ED0(P_00227ED0 *p) {
  u32 t;
  f32 a, b;
  T_00227ED0 *e;
  t = p->b6;
  p->b6 = t + 1;
  p->f5c = 0;
  p->f60 = 0;
  p->f68 = 0;
  p->f6c = 0;
  func_00185490(p);
  if (p->b20d != 2) {
    p->b20d = 0;
    func_00183D10(p);
  }
  func_0018C4B0(p, 0x10);
  e = &D_004518C0[p->b1b7];
  a = e->a;
  b = e->b;
  if (p->s140 != 0) { a = -a; b = -b; }
  p->f5c = a;
  p->f68 = b;
  func_001757E0(p, 0x15, (u8)(p->b1b7 * 2));
}

typedef struct P_0019E830 { u8 pad0[5]; u8 b5; u8 pad6[0x1C-6]; s16 s1c; u8 pad1e[0x34-0x1E]; f32 f34; f32 f38; u8 pad3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x140-0x70]; s16 s140; } P_0019E830;
void func_0019E830(P_0019E830 *p) {
  u32 t;
  if (func_00175700(p) < 0) {
    t = p->b5;
    p->b5 = t + 1;
    *(u32 *)&p->f68 = 0x3E855555;
    if (p->s140 == 0) p->f68 = -p->f68;
    p->s1c = 0x30;
    func_001757E0(p, 0x13, 10);
  }
  p->f34 += p->f5c;
  p->f5c += p->f68;
  p->f38 += p->f60;
  p->f60 += p->f6c;
}

typedef struct V3_0021BD50 { f32 x, y, z; } V3_0021BD50;
typedef struct P_0021BD50 { u8 pad0[0x1C]; s16 s1c; u8 pad1e[0x34-0x1E]; V3_0021BD50 v34; u8 pad40[0x5C-0x40]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x151-0x70]; u8 b151; } P_0021BD50;
extern void func_00179160(P_0021BD50 *, P_0021BD50 *);
extern void func_0021BE10(P_0021BD50 *, P_0021BD50 *);
void func_0021BD50(P_0021BD50 *p, P_0021BD50 *q) {
  V3_0021BD50 v;
  p->b151 = 12;
  v = p->v34;
  func_00179160(p, q);
  p->f5c = (p->v34.x - v.x) / 16.0f;
  p->f60 = (p->v34.y - v.y) / 16.0f;
  p->f68 = 0;
  p->f6c = 0;
  p->v34 = v;
  p->s1c = 16;
  func_0021BE10(p, q);
}

typedef struct X_003C8800 { u8 pad0[5]; u8 b5; u8 b6; u8 pad7[0x1E-7]; s8 b1e; u8 pad1f; u8 b20; u8 pad21[3]; s8 b24; u8 pad25[0x31-0x25]; s8 b31; u8 pad32[0x34-0x32]; f32 f34; f32 f38; u8 pad3c[0x151-0x3C]; s8 b151; } X_003C8800;
extern void func_003C8650(X_003C8800 *, X_003C8800 *);
void func_003C8800(X_003C8800 *x, X_003C8800 *y) {
  u32 t;
  if (y->b5 == 1) {
    if (y->b151 != 0) {
      if (x->b20 != 2) goto L;
      t = x->b6;
      x->b6 = t + 1;
      func_001757E0(x, 0x14, 0x15);
    }
    x->f34 = y->f34;
    x->f38 = y->f38;
    x->b24 = y->b24;
    x->b31 = x->b1e;
    func_00175700(x);
    return;
  }
L:
  if (x->b20 == 0) func_001E3210(y, 0x1B);
  func_003C8650(x, y);
}

