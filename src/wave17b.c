typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void (*D_004BF538[2])(u8 *, u8 *, u8);
void func_00193B20(u8 *a, u8 *b) {
  if (b[5] != 0 || b[0x1E4] != 0x1D) { a[4]++; a[0x13C] = 0; } else { D_004BF538[a[5]](a, b, b[0x1E4]); }
}


extern u8 *D_004C2840;
extern void func_0018FCA0(u8 *, int);
extern void func_0018F550(u8 *, int, int);
int func_003BCEB0(u8 *p) {
  u8 *s = *(u8 **)(p + 0xD0);
  if (s[5] != 0) return -1;
  if (*(u32 *)(D_004C2840 + 0x1C) & 1) func_0018FCA0(s, -1);
  if (*(s16 *)(s + 0x434) > 0) return -1;
  func_0018F550(s, 0xB, 0x1C);
  return 0;
}


extern int func_00174470(const void *);
extern void (*D_004C19A8[2])(u8 *, u8 *);
void func_003489F0(u8 *p, u8 *q) {
  u8 *s = q + 0x2B8;
  *(s8 *)(p + 0x31) = -6;
  if (func_00174470(p) == 0) {
    s[0x1A] = 0;
    p[4]++;
    p[0x13C] = 0;
  } else {
    D_004C19A8[p[5]](p, q);
  }
}
