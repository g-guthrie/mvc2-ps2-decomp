#include "objects.h"
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c048ce6(struct Actor *);
extern void (*table_0c241248[])(struct Actor *, struct Actor *);
extern void func_0c0426c2(struct Actor *, int);
extern void func_0c0427be(struct Actor *, int);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c02a0c4(struct Actor *, int, int);
struct Actor *func_0c0756b0(struct Actor *a) {
  struct Actor *target;
  if (a->b200)
    goto rejected;
  if (a->b1f9 == 1)
    goto rejected;
  if (!a->b1a3)
    goto rejected;
  if (!(a->w1fa & 0xc00U))
    return 0;
  if (a->b1fe) {
    if (a->b1f9 == 2) {
    rejected:
      return 0;
    }
    if ((target = func_0c037d54(a)))
      a->b1f7 = 1;
  } else if (a->b1f9 == 2) {
    if ((target = func_0c037d54(a)))
      a->b1f7 = 2;
  } else {
    if ((target = func_0c037d54(a)))
      a->b1f7 = 0;
  }
  return target;
}
void func_0c075740(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  struct Actor *child = a->p1c8;
  func_0c048ce6(a);
  a->b1ed = 3;
  *(char *)&sub->s12 = 0;
  child->w130 = a->w130;
  child->w130 ^= 1;
  child->b1d2 = *(unsigned char *)&child->w130;
  table_0c241248[a->b1f7](a, child);
}
void func_0c075794(struct Actor *a, struct Actor *target) {
  func_0c0426c2(target, 56);
  func_0c0427be(a, 2);
  func_0c025900(a, 6, 6);
  func_0c02a0c4(a, 15, 0);
}
