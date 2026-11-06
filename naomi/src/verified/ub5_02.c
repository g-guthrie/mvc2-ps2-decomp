#include "objects.h"
extern void func_0c0426c2(struct Actor *, int);
extern void func_0c0427be(struct Actor *, int);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void (*dat_0c24de40[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern int func_0c0427f2(struct Actor *);
extern int func_0c042780(struct Actor *);
extern void (*dat_0c24de4c[])(struct Actor *, struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c03f004(struct Actor *, struct Actor *);
void func_0c12d81c(struct Actor *a, struct Actor *child) {
  func_0c0426c2(child, 56);
  func_0c0427be(a, 2);
  child->s28 = 0;
  func_0c025900(a, 5, 5);
  func_0c02a0c4(a, 15, 2);
}
void func_0c12d856(struct Actor *a, struct Actor *child) {
  func_0c0426c2(child, 56);
  func_0c0427be(a, 2);
  func_0c025900(a, 5, 5);
  func_0c02a0c4(a, 15, 4);
}
void func_0c12d88a(struct Actor *a) {
  a->b1ea = 1;
  a->b1ed = 3;
  dat_0c24de40[a->b1f7](a);
}
void func_0c12d8ac(struct Actor *a) {
  struct ActorSubControlBytes *sub = (struct ActorSubControlBytes *)&a->sub2a4;
  struct Actor *child = a->p1c8;
  if (func_0c02a026(a) < 0 && sub->b12 <= 0) {
    a->b1d2 ^= 1;
    a->w130 = a->b1d2;
    a->b19d = -128;
    a->b1ed = 0;
    func_0c0437b8(a);
    return;
  }
  if (sub->b12 > 0) {
    if (func_0c0427f2(a))
      a->b142 = 1;
    child->s25c--;
    if (func_0c042780(child)) {
      sub->b12 = -1;
      func_0c02a0c4(a, 15, 1);
    }
  }
  dat_0c24de4c[a->b141 >> 1](a, child);
}
void func_0c12d94a(struct Actor *a, struct Actor *child) {
  func_0c03edcc(a, child);
}
void func_0c12d950(struct Actor *a, struct Actor *child) { func_0c03f004(a, child); }
