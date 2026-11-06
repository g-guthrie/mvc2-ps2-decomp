#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1d1622(struct LinkedActorVec3 *, int);
extern void func_0c03489c(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c240b8c[])(struct Actor *);
void func_0c06ceb8(struct Actor *a) {
  struct Actor *child;
  if (func_0c02a026(a) >= 0) {
    if (a->b141) {
      a->b141 = 0;
      child = a->p1c8;
      child->p1b4 = a;
      child->b1f6 = 1;
      child->b1f9 = 2;
      func_0c025900(a, 0, 0);
      child->b1a1 = 32;
    }
  } else {
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0437b8(a);
  }
}
void func_0c06cf22(struct Actor *a) { table_0c240b8c[a->b6](a); }
void func_0c06cf34(struct Actor *a) {
  func_0c02a026(a);
  if (a->b141) {
    a->b6++;
    a->f92 = 0;
    a->f104 = 0;
    a->f96 = -17.142857f;
    a->f108 = -0.80357140303f;
  }
}
void func_0c06cf6c(struct Actor *a) {
  struct LinkedActorVec3 position;
  int displacement;
  func_0c02a026(a);
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (!(a->f56 > a->f41c)) {
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    dat_0c2d9260.b5 = 3;
    dat_0c2d9260.b6 = 1;
    position = *(struct LinkedActorVec3 *)&a->f52;
    displacement = a->b1d2 ? -8 : 8;
    position.x += displacement;
    func_0c1d1622(&position, -1);
    func_0c03489c(a);
    func_0c02a0c4(a, 15, 4);
  }
}
void func_0c06d030(struct Actor *a) {
  struct Actor *child;
  if (func_0c02a026(a) < 0) {
    a->b6++;
    child = a->p1c8;
    child->p1b4 = a;
    child->b1f6 = 1;
    child->b1f9 = 2;
    func_0c025900(a, 0, 0);
    child->b1a1 = 33;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f92 = a->b1d2 ? -13.33333302f : 13.33333302f;
    a->f104 = a->b1d2 ? 0.20833333f : -0.20833333f;
    func_0c02a0c4(a, 2, 1);
  }
}
void func_0c06d0c2(struct Actor *a) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c02a026(a) < 0) {
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c02a0c4(a, 2, 3);
  }
}
