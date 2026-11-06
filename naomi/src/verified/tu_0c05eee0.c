#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c03489c(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c04b02a(struct Actor *);
extern void func_0c1cea66(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c0437b8(struct Actor *);
void func_0c05eee0(struct Actor *a) {
  struct LinkedActorVec3 position;
  struct Actor *child;
  register int zero = 0;
  if (!a->b6) {
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!a->b141)
      func_0c02a026(a);
    if (!(a->f56 > a->f41c)) {
      if (!a->b7 && !(a->f56 > 342.85712f))
        a->b7++;
      a->b6++;
      func_0c02a0c4(a, 15, 4);
      a->f56 = a->f41c;
      a->b1f9 = zero;
      func_0c03489c(a);
      func_0c0346da(a, 2);
    }
  } else if (func_0c02a026(a) >= 0) {
    if (a->b141 < 0) {
      a->b141 = zero;
      child = a->p1c8;
      child->b1a1 = 36;
      func_0c04b02a(a);
      position.x = -53.3333321f;
      position.y = 68.57143f;
      position.z = 0;
      func_0c1cea66(a, &position, 1);
    } else if (a->b141 > 0) {
      a->b141 = zero;
      child = a->p1c8;
      child->p1b4 = a;
      child->b1f6 = 1;
      child->b1a1 = 34;
    }
  } else
    goto knock;
  return;
knock:
  func_0c0437b8(a);
}
