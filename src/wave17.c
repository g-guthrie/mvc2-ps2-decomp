typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern u8 *D_004C2840;
extern void func_003D3080(int);
extern int func_003760D0(u8 *);


void func_003A41E0(u8 *p) {
  int r = (s8)func_00175700(p);
  if (r >= 0) {
    if ((s8)p[0x151] == 0) return;
  }
  p[4] = 2; p[0x13C] = 0;
}

extern void (*D_00473C10[])(u8 *, u8 *);
void func_003AE900(u8 *p) {
  p[0x24] = ((s8 *)*(u8 **)(p + 0x18))[0x24];
  if (p[0x20] == 0 || *(s16 *)(p + 0x1C) == 0) {
    p[0x13C] = 0;
    D_00473C10[p[4]](p, p + 0x88);
  }
}

void func_00376200(u8 *p) {
  if (func_003760D0(p) == 0) {
    if ((s8)func_00175700(p) < 0) { p[5]++; func_001757E0(p, 0x17, 2); }
  }
}

extern int func_00174170(void);
extern void func_001E24E0(u8 *, u8);
void func_001E33D0(u8 *p) {
  if (*(s16 *)(p + 0x434) != 0) {
    u8 v;
    if (p[1] == 0x20) v = 1;
    else v = (func_00174170() & 1) + 1;
    func_001E24E0(p, v);
  }
}

void func_001C3900(u8 *p, u8 *q) {
  *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
  *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
  if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
    p[7]++;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    func_00175700(p);
  }
}

extern void func_0034DC00(u8 *);
extern void (*D_00462200[])(u8 *);
void func_0034D820(u8 *p) {
  if (*(s8 *)(*(u8 **)(p + 0x18) + 0x13C) == 0) {
    if (p[0x20] != 0) *(s16 *)(p + 0x1C) = 0;
    func_0034DC00(p);
  } else {
    D_00462200[p[5]](p);
  }
}

extern void func_001863F0(u8 *);
extern void (*D_00450CF0[])(u8 *);
void func_00213F60(u8 *p) {
  *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
  *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
  func_001863F0(p);
  D_00450CF0[p[6]](p);
}

extern void func_001E3710(u8 *, int);
void func_003A63D0(u8 *p) {
  func_00175700(p);
  if (--*(s16 *)(p + 0x1C) == 0) {
    p[5]++;
    func_001757E0(p, 0x17, 0xD);
    func_001E3710(p, 0x49);
  }
}

void func_003885F0(u8 *p) {
  *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
  *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
  *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
  *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
  if (--*(s16 *)(p + 0x1C) == 0) p[4]++;
  p[0x13C] = (s8)p[0x1C] & 1;
}

extern u8 *func_003DA750(int, int, int);
extern void func_001D27A0(void);
extern void func_00186A60(u8 *, int);
void func_0023EF30(u8 *p) {
  p[5] = 0; p[7] = 0; p[6] = 0;
  switch ((s8)p[0x4DD]) {
  case 0: p[0x1FD] = 2; p[0x1B7] = 0; break;
  case 1: p[0x1FD] = 0; p[0x1B7] = 0; p[6] = 0; break;
  case 2: p[0x1FD] = 5; p[0x1B7] = 0; break;
  }
  func_00186A60(p, 0x15);
}

extern void func_0022C5C0(u8 *);
void func_00229AC0(u8 *p) {
  p[0x40C] = 2;
  p[0x33C] = 5;
  func_0022C5C0(p);
  p[0x1FE] = 1;
  p[0x201] = 2;
  p[0x209] = 2;
  func_00175700(p);
  if ((s8)p[0x151] != 0) {
    p[6]++;
    p[0x151] = 0;
    (*(u8 **)(p + 0x1DC))[0x20B] = 0xC3;
    p[0x20B] = 0xC3;
  }
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void func_003AF300(u8 *, u8 *);
extern void func_003AF4B0(u8 *, u8 *);
void func_003AF280(u8 *p, u8 *q) {
  if ((s8)(*(u8 **)(p + 0x18))[0x1B4] != 0 || (D_004D18DC & (1 << D_004D18DB)) != 0) {
    p[0x13C] = 1;
    *(s16 *)(p + 0x1C) = 1;
  } else if (p[5] == 0) {
    func_003AF300(p, q);
  } else {
    func_003AF4B0(p, q);
  }
}

extern void func_00176160(u8 *, int, int, int);
void func_00313120(u8 *p, u8 *q) {
  if (q[8] == 0) {
    u8 t = q[0xA];
    q[0xA] = t - 1;
    if (t == 0) {
      q[0xA] = 4;
      func_00176160(p, 0, p[0x25] * 6 + 0x24 + q[9], 1);
      if (q[9] < 4) q[9]++;
    }
  }
}

extern void func_00175670(u8 *);
extern void func_001B5350(u8 *, u8 *);
extern void func_001B4C00(u8 *, u8 *);
extern void func_001B4B30(u8 *);
void func_001B4A50(u8 *p) {
  u8 *s = *(u8 **)(p + 0x18);
  func_00175670(p);
  if (p[0x22] & 1) *(s16 *)(s + 0x140) ^= 1;
  func_001B5350(s, p);
  if (p[0x22] & 1) *(s16 *)(s + 0x140) ^= 1;
  func_001B4C00(s, p);
  func_001B4B30(p);
}

extern void func_001DB390(u8 *, int);
extern void func_001DB5D0(u8 *);
void func_001DB540(u8 *p) {
  u8 *s = *(u8 **)(p + 0x18) + 0x2B8;
  func_00175700(p);
  if (p[0x20] == 0 && (s8)p[0x151] != 0) {
    p[0x151] = 0;
    func_001DB390(p, 1);
    func_001DB390(p, 2);
  }
  if (s[7] != 0) {
    p[4]++;
    func_001DB5D0(p);
  }
}

extern void func_00183D50(u8 *);
void func_002589F0(u8 *p) {
  *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
  *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
  func_00175700(p);
  if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
    p[7]++;
    func_00183D50(p);
    p[0x20D] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_001757E0(p, 0x12, 2);
  }
}

extern void func_0018C6E0(void *);
void func_002BEB50(u8 *p) {
  u8 *o;
  s16 t;
  func_0018C6E0(p);
  t = p[0x1E6] ^ 1;
  *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
  (*(u8 **)(p + 0x1DC))[0x1E6] = t;
  if (p[0x22] & 2) {
    t = p[0x1E6] ^ 1;
    *(s16 *)(p + 0x140) = t;
    p[0x1E6] = t;
    t = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
    (*(u8 **)(p + 0x1DC))[0x1E6] = t;
  }
  func_001757E0(p, 0xF, 5);
}

extern void func_001C8410(u8 *, u8 *);
void func_001C8380(u8 *p, u8 *q) {
  p[7]++;
  *(s16 *)(p + 0x1C) = 0x30;
  if (*(s16 *)(p + 0x140) == 0) *(u32 *)(p + 0x5C) = 0xC0D55555; else *(u32 *)(p + 0x5C) = 0x40D55555;
  *(f32 *)(p + 0x68) = 0;
  *(f32 *)(p + 0x60) = 0;
  *(f32 *)(p + 0x6C) = 0;
  func_001757E0(p, 0x19, 0x15);
  func_001C8410(p, q);
}

extern void func_00183920(u8 *, u32 *);
extern void func_001E3710(u8 *, int);
extern void func_001843A0(u8 *);
void func_00238DF0(u8 *p) {
  if ((s8)func_00175700(p) < 0) {
    func_001843A0(p);
  } else {
    if ((s8)p[0x151] & 1) {
      u32 v[4];
      p[0x151] = (s8)p[0x151] ^ 1;
      v[0] = 0x41D55555;
      v[1] = 0x43272492;
      func_00183920(p, v);
    }
    if ((s8)p[0x151] & 2) func_001E3710(p, 0x16);
  }
}
