#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c19d2ac(struct Actor *, int, int);
extern void func_0c02a0c4(struct Actor *, int, int),
    func_0c0437b8(struct Actor *), func_0c0442fa(struct Actor *);
extern void (*table_0c243588[])(struct Actor *);
void func_0c09b5b8(struct Actor *a) {
  a->b3f8 = 2;
  a->b328 = 5;
  func_0c02a026(a);
  if (a->b141) {
    a->b7++;
    a->s28 = 30;
    a->s30 = 9;
    a->b1a1 = 60;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->b34 = 1;
    a->f92 = a->b1d2 ? 11.666666031f : -11.666666031f;
    func_0c19d2ac(a, 5, 0);
  }
}
void func_0c09b63c(struct Actor *a) {
  int zero;
  a->b3f8 = 2;
  a->b328 = 5;
  func_0c02a026(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  zero = 0;
  if (!--a->s28) {
    a->b3f9 = zero;
    a->b3f8 = zero;
    a->b327 = zero;
    a->b328 = zero;
    a->b7++;
    a->f92 = a->b1d2 ? 5.0f : -5.0f;
    a->f104 = a->b1d2 ? -0.1041666642f : 0.1041666642f;
    a->b1a1 = 61;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, 1);
  } else { goto L; L: if (a->b19e && !--a->b34) {
    a->b34 = 1;
    if (!--a->s30)
      a->s28 = 1;
    else {
      a->b1a1 = 60;
      a->w1ac = zero;
      a->b19e = zero;
      *(unsigned int *)&a->p1c4 = zero;
      dat_0c2f83f8->arr[a->b2]++;
    }
  }}
}
void func_0c09b792(struct Actor *a) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c02a026(a) < 0) {
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0437b8(a);
  }
}
void func_0c09b7fe(struct Actor *a) { table_0c243588[a->b7](a); }
void func_0c09b810(struct Actor *a) {
  if (a->b255 == 6) {
    a->b3f0 = 255;
    a->b3f1 = 16;
  }
  a->b7++;
  func_0c0442fa(a);
  a->f92 = 0;
  a->f96 = 0;
  a->f104 = 0;
  a->f108 = 0;
  func_0c02a0c4(a, 22, 2);
}
