typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 00408078 */
extern void func_00411288();
extern void func_004112B0(void);
extern void func_0011EB60();
extern u8 D_004BD598[], D_004BD5B8[];
typedef struct { s32 w0; s32 w4; } S_00408078;
void func_00408078(S_00408078 *p) {
  func_00411288((s32)p);
  if (p == 0) { func_0011EB60(D_004BD598); func_004112B0(); return; }
  if (p->w4 == 1) func_0011EB60(D_004BD5B8); else p->w4 = 1;
  func_004112B0();
  __asm__ volatile("");
}

/* 0040D848 */
extern s32 func_00400650(s32);
extern s32 func_004006A0(s32);
extern void func_0040D5A0(void *);
extern u8 D_004BE430[];
typedef struct { u8 b0; s8 b1; u8 pad[0x1E]; s32 w20; u8 pad24[4]; s32 w28; s32 w2c; } S_0040D848;
void func_0040D848(S_0040D848 *p) {
  u8 *q;
  s32 v;
  if (p->w28 == 0) { func_0040D5A0(D_004BE430); return; }
  q = (u8 *)p + (p->w20 << 6) + 0x38;
  v = func_00400650(p->w28);
  if (v == 4) p->b1 = 3;
  else if (v == 2) *(s32 *)(q + 0x3C) = func_004006A0(p->w28);
  else if (v == 3) { s32 t = p->w2c; *(s32 *)(q + 0x38) = 2; *(s32 *)(q + 0x3C) = t; }
}

/* 004062F8 */
extern void func_00405DC8(void *);
extern s32 func_0011FFA0(void);
extern void func_004061C0(s32);
extern s32 func_004063B0(s32, s32);
extern void func_0011D740(void *, s32, s32);
extern u8 D_004BC950[], D_004BC978[];
extern s8 D_0062FD48[];
void func_004062F8(s32 a) {
  s32 n;
  if (a == 0) { func_00405DC8(D_004BC950); return; }
  n = func_0011FFA0();
  if (n == 0) D_0062FD48[0] = 0;
  else {
    func_004061C0(a);
    if (func_004063B0(a, n) == 1) { func_0011D740(D_0062FD48, a, n + 1); return; }
    func_00405DC8(D_004BC978);
    __asm__ volatile("");
  }
}

/* 004118B8 */
typedef struct { s32 (*fn)(s32); s32 arg; } E_004118B8;
extern E_004118B8 D_00632360[][4];
extern s32 D_00496728[];
extern s32 D_00496708[];
s32 func_004118B8(s32 idx) {
  s32 *flag = &D_00496728[idx];
  E_004118B8 *e = D_00632360[idx];
  s32 r = 0;
  s32 i;
  for (i = 3; i >= 0; i--, e++) {
    if (e->fn) {
      *flag = 1;
      r |= e->fn(e->arg);
      *flag = 0;
    }
  }
  D_00496708[idx]++;
  return r;
}

/* 00409A10 */

extern void func_004112B0(void);
extern void func_00409948(void *);
typedef struct { s8 b0; u8 pad[0x47]; } E_00409A10;
extern volatile u8 D_00488320[];
extern E_00409A10 D_00488390[];
void func_00409A10(void) {
  s32 i;
  func_00411288();
  if ((s8)D_00488320[0] == 1) { func_004112B0(); return; }
  D_00488320[0] = 1;
  func_004112B0();
  for (i = 0; i < 40; i++) {
    if (D_00488390[i].b0 == 1) func_00409948(&D_00488390[i]);
  }
  D_00488320[0] = 0;
}

/* 0040ED28 */

extern u8 D_004BE888[];
typedef struct { u8 pad[0x28]; s32 w28; } S_0040ED28;
void func_0040ED28(S_0040ED28 *p, s32 rate) {
  if (48000 % rate != 0) {
    func_0011EB60(D_004BE888, rate);
    for (;;) { __asm__ volatile("nop"); }
  }
  if (rate != 48000) {
    if ((48000 / rate) & 1) {
      func_0011EB60(D_004BE888, rate);
      for (;;) { __asm__ volatile("nop"); }
    }
  }
  p->w28 = rate;
}

