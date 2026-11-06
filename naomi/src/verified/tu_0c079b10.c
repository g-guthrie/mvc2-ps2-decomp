/* Exact 0x0c079b10..0x0c079c88: initialize motion and process the mutually exclusive animation-transition and feedback paths. */
#include "objects.h"
extern void func_0c0442fa(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
void func_0c079b10(struct Actor *a) {
  int zero;
  a->b6++;
  func_0c0442fa(a);
  func_0c0451f2(a);
  a->f92 = 0;
  a->f96 = 0;
  a->f104 = 0;
  a->f108 = 0;
  a->b1a1 = 80;
  zero = 0;
  a->w1ac = zero;
  a->b19e = zero;
  *(unsigned int *)&a->p1c4 = zero;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c048bb0(a, 5);
  func_0c0432ca(a);
  func_0c02a0c4(a, 21, 47);
  if (a->b1d2) {
    a->f52 += 80.0f;
    a->f92 = 6.66666651f;
    a->f104 = -0.1171875f;
  } else {
    a->f52 += -80.0f;
    a->f92 = -6.66666651f;
    a->f104 = 0.1171875f;
  }
  a->f96 = 19.2857132f;
  a->f108 = -0.80357140303f;
}
void func_0c079bd0(struct Actor *a) {
  char previous = a->b141;
  int zero;
  if (func_0c02a026(a) >= 0 && previous < 0) {
    a->b6++;
    a->f104 = 0;
    func_0c02a0c4(a, 1, 9);
    return;
  }
  else if (a->b141 > 0) {
    zero = 0;
    a->b141 = zero;
    a->b1a1 = 80;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
  }
}
