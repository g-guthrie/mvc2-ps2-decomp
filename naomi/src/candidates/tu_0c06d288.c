#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c1d1622(struct LinkedActorVec3 *, int);
extern void func_0c03489c(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, char, char);
void func_0c06d288(struct Actor *a) {
  struct LinkedActorVec3 position;
  int offset;
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
    if (a->b1d2)
      offset = -8;
    else
      offset = 8;
    position.x = position.x + offset;
    func_0c1d1622(&position, -1);
    func_0c03489c(a);
    func_0c02a0c4(a, 15, 7);
  }
}
void func_0c06d31e(struct Actor *a) {
  struct Actor *child;
  if (func_0c02a026(a) < 0) {
    a->b6++;
    child = a->p1c8;
    child->p1b4 = a;
    child->b1f6 = 1;
    child->b1f9 = 2;
    child->b1a1 = 35;
    func_0c025900(a, 0, 0);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f92 = a->b1d2 ? 13.33333302f : -13.33333302f;
    a->f104 = a->b1d2 ? 0.20833333f : -0.20833333f;
    func_0c02a0c4(a, 15, 8);
  }
}
