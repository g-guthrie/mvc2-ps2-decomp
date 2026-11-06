#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047b98(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c05bbd6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c04b02a(struct Actor *);
extern void func_0c1cea66(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c1d357a(struct LinkedActorVec3 *, int);
extern void func_0c0346da(struct Actor *, int);
void func_0c058e68(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
  if (func_0c047b98(a)) {
    if (a->b525) {
      if (a->b141) {
        a->b141 = 0;
        if (a->b142 != 1)
          a->b142--;
      }
    } else
      a->b142 = 1;
    (*(char *)&sub->b2)++;
    if (*(char *)&sub->b2 > 15)
      *(char *)&sub->b2 = 15;
  }
  if (func_0c044e52(a)) {
    a->b7++;
    dat_0c2d9260.b5 = 2;
    dat_0c2d9260.b6 = 1;
    func_0c05bbd6(a);
    func_0c02a0c4(a, 15, 42);
  }
}
void func_0c058f36(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  struct LinkedActorVec3 position;
  struct Actor *child;
  int divisor;
  if (func_0c02a026(a) < 0) {
    a->b7++;
    func_0c02a0c4(a, 15, 4);
    return;
  }
  if (a->b141) {
    a->b141 = 0;
    divisor = 4;
    child = a->p1c8;
    child->p1b4 = a;
    a->b1a1 = (char)sub->b2 / divisor + 72;
    child->b1a1 = (char)sub->b2 / divisor + 72;
    func_0c04b02a(a);
    a->b205 = 0;
    child = a->p1c8;
    if (!a->b202) {
      position.x = -106.666664124f;
      position.y = 0;
      func_0c1cea66(a, &position, 2);
    } else {
      position.x = child->f52;
      position.y = a->f41c;
      func_0c1d357a(&position, 1);
      func_0c0346da(a, 73);
    }
  }
}
void func_0c059020(struct Actor *a) {
  struct Actor *p;
  if (func_0c02a026(a) < 0) {
    a->b7++;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = 31.07143f;
    a->f108 = -0.66964281f;
    func_0c02a0c4(a, 15, 43);
    return;
  }
  if (a->b141) {
    a->b141 = 0;
    p = a->p1c8;
    p->p1b4 = a;
    a->b1a1 = 71;
    p->b1a1 = 71;
    p->b1f6 = 17;
  }
}

char func_0c059086(struct Actor *a) {
  register struct ActorSub2a4 *sub = &a->sub2a4;
  if (a->b141 != 0) {
    a->b7++;
    sub->b2 = 0;
  }
  return func_0c02a026(a);
}
