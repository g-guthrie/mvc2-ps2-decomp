#include "objects.h"
struct Pair_0c069630 { unsigned char pad0[4]; unsigned char b4; unsigned char pad5[16 - 5]; float f16; float f20; };
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern int func_0c02849a(void);
extern int func_0c043628(struct Actor *);
extern void func_0c1385f8(struct Actor *, int);
extern void func_0c1906c4(struct Actor *);
extern void (*table_0c240714[])(struct Actor *);
extern void (*table_0c24071c[])(struct Actor *);
extern void (*table_0c240738[])(struct Actor *);
extern void (*table_0c24074c[])(struct Actor *);
extern char dat_0c2f837e;
extern unsigned char table_0c240730[];
extern unsigned char table_0c240734[];
void func_0c069630(struct Actor *a, struct Pair_0c069630 *b) {
  if (func_0c02a026(a) < 0) {
    a->b7++;
    a->b1d2 ^= 1;
    a->w130 = a->b1d2;
    b->b4 = 0;
    a->f52 = b->f16;
    a->f56 = b->f20;
    func_0c02a0c4(a, 21, 3);
  }
}
void func_0c069688(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    a->b7++;
    func_0c02a0c4(a, 1, 3);
  }
}
void func_0c0696b2(struct Actor *a) {
  if (func_0c02a026(a) < 0)
    a->b5++;
}
void func_0c0696d2(struct Actor *a) {
  if (func_0c03916c(a)) {
    func_0c0437b8(a);
    return;
  }
  table_0c240714[a->b6](a);
}
void func_0c0696fc(struct Actor *a) {
  a->b6++;
  table_0c24071c[a->b32](a);
}
void func_0c069718(struct Actor *a) {
  if (!a->b525 && (a->w340 & 0x360)) {
    if (a->w340 & 0x200)
      a->s28 = 0;
    else if (a->w340 & 0x100)
      a->s28 = 1;
    else if (a->w340 & 0x40)
      a->s28 = 2;
    else
      a->s28 = 3;
  } else
    a->s28 = func_0c02849a() & 3;
  if (dat_0c2f837e)
    a->s28 = table_0c240730[a->s28];
  else
    a->s28 = table_0c240734[a->s28];
  if (func_0c043628(a) >= 2)
    a->s28 = 1;
  switch (a->s28) {
  case 0:
    func_0c1385f8(a, 6);
    func_0c02a0c4(a, 19, 0);
    break;
  case 1:
    func_0c02a0c4(a, 19, 1);
    break;
  case 2:
    func_0c02a0c4(a, 19, 2);
    break;
  case 3:
    func_0c02a0c4(a, 19, 4);
    break;
  default:
    func_0c02a0c4(a, 19, 1);
    break;
  }
}
void func_0c0697fc(struct Actor *a) { func_0c02a0c4(a, 19, 2); }
void func_0c069804(struct Actor *a) {
  a->b12c = 0;
  func_0c1906c4(a);
  func_0c02a0c4(a, 19, 3);
}
void func_0c069824(struct Actor *a) {
  a->b12c = 0;
  func_0c1906c4(a);
  func_0c02a0c4(a, 19, 3);
}
void func_0c069844(struct Actor *a) { table_0c240738[a->b32](a); }
void func_0c069858(struct Actor *a) { table_0c24074c[a->s28](a); }
void func_0c069868(struct Actor *a) { func_0c02a026(a); }
