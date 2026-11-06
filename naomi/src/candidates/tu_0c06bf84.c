/* Candidate: func_0c06bf84, func_0c06bfd2, func_0c06c068, func_0c06c12c, func_0c06c2c2, func_0c06c31a follow retail structure (pool addresses shift only because func_0c06c1a6 differs); func_0c06bfe4 misses retail's hoisted mov #0,r13 delay slot (same zero-hoist issue as tu_0c06b2d4/tu_0c069a10); func_0c06c1a6 loads the 0x0c2d926c float after the first pool flush where retail loads it before the branch. */
#include "objects.h"
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c139b6c(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void (*table_0c24092c[])(struct Actor *);
void func_0c06bf84(struct Actor *a) {
  a->b1ea = 1;
  a->b1ed = 2;
  a->b1f5 = 2;
  if (func_0c02a026(a) < 0) {
    func_0c025900(a, 0, 0);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0437b8(a);
  }
}
void func_0c06bfd2(struct Actor *a) { table_0c24092c[a->b6](a); }
void func_0c06bfe4(register struct Actor *a) {
  register int zero;
  a->b6++;
  zero = 0;
  if (a->b255 == 3)
    a->b1a1 = 91;
  else
    a->b1a1 = 75;
  a->w1ac = zero;
  a->b19e = zero;
  *(unsigned int *)&a->p1c4 = zero;
  dat_0c2f83f8->w7c[a->b2]++;
  func_0c048bb0(a, 13);
  func_0c0442fa(a);
  a->f56 = a->f41c;
  a->b1f9 = zero;
  a->f96 = 0.0f;
  a->f108 = 0.0f;
  func_0c0432ca(a);
  a->s28 = 15;
  func_0c02a0c4(a, 21, 28);
}
void func_0c06c068(struct Actor *a) {
  func_0c02a026(a);
  if (--a->s28 == 0) {
    a->b6++;
    func_0c0451f2(a);
    a->b1f5 = 2;
    a->b1f4 = 2;
    a->s30 = 8;
    func_0c139b6c(a, 0);
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->b1d2 ? -6.66666651f : 6.66666651f;
    a->f96 = 21.42857f;
    func_0c0344a0(a, 6);
    func_0c0346da(a, 50);
    func_0c02a0c4(a, 21, 31);
  }
}
void func_0c06c12c(struct Actor *a) {
  a->b1f5 = 2;
  a->b1f4 = 2;
  if (--a->s30) {
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    return;
  }
  a->b6++;
  func_0c02a0c4(a, 21, 35);
}
void func_0c06c1a6(struct Actor *a) {
  float *p;
  a->b1f4 = 2;
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c02a026(a) < 0) {
    a->b6++;
    if (a->b255 == 8 || a->b255 == 3) {
      a->f52 = a->p20c->f52;
    } else {
      a->f52 = dat_0c2d9260.f12 + (a->b1a3 ? 640.0f : 213.33333f) - 320.0f;
    }
    a->f56 = a->f41c;
    func_0c139b6c(a, 1);
    p = &a->f52;
    *p = *p + (a->b1d2 ? -133.33333f : 133.33333f);
    a->f56 += 342.85712f;
    func_0c02a0c4(a, 21, 47);
  }
}
void func_0c06c2c2(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    a->b6++;
    a->f92 = a->b1d2 ? 6.66666651f : -6.66666651f;
    a->f96 = 21.42857f;
    func_0c0344a0(a, 4);
    func_0c0346da(a, 75);
    func_0c02a0c4(a, 21, 39);
  }
}
void func_0c06c31a(struct Actor *a) {
  func_0c02a026(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (!(a->f56 > a->f41c)) {
    a->b6++;
    a->f56 = a->f41c;
    func_0c043324(a);
    a->b1f9 = 0;
    func_0c02a0c4(a, 1, 3);
  }
}
