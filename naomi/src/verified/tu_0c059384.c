#include "objects.h"
struct BytePair_0c23f88c { unsigned char b0, b1; };
extern struct BytePair_0c23f88c table_0c23f88c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1d357a(struct LinkedActorVec3 *, int);
extern void func_0c1d330c(struct Actor *, struct LinkedActorVec3 *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c025900(struct Actor *, char, char);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c23f894[])(struct Actor *);

void func_0c059384(struct Actor *a) {
  struct LinkedActorVec3 position;
  struct Actor *child;
  if (a->b141) {
    a->b141 = 0;
    child = a->p1c8;
    position.x = child->f52;
    position.y = a->f41c;
    if (!a->b202) {
      func_0c1d357a(&position, 1);
      func_0c0346da(a, 73);
    } else {
      func_0c1d357a(&position, 1);
      func_0c1d330c(a, &position, 4, 126);
      func_0c0346da(a, 74);
    }
  }
  if (func_0c02a026(a) < 0) {
    a->b7++;
    func_0c02a0c4(a, 15, 14);
  }
}
void func_0c0593fe(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  struct Actor *child;
  int zero;
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c02a026(a) < 0) {
    a->b7++;
    a->f92 = 6.66666651f;
    a->f104 = -0.1041666642f;
    a->f96 = 19.2857132f;
    a->f108 = -0.66964281f;
    if (a->b1d2) {
      a->f92 = -a->f92;
      a->f104 = -a->f104;
    }
    func_0c02a0c4(a, 15, 33);
    return;
  }
  if (a->b141) {
    zero = 0;
    a->b141 = zero;
    func_0c025900(a, zero, zero);
    child = a->p1c8;
    child->b1f6 = table_0c23f88c[(char)sub->b2 / 4].b0;
    child->b1a1 = table_0c23f88c[(char)sub->b2 / 4].b1;
    a->b1a1 = table_0c23f88c[(char)sub->b2 / 4].b1;
    a->b3f9 = zero;
    a->b3f8 = zero;
    a->b327 = zero;
    a->b328 = zero;
    a->b205 = (char)sub->b2 / 2 + 32;
  }
}
void func_0c059558(struct Actor *a) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c044e52(a)) {
    a->b7++;
    func_0c043324(a);
    func_0c02a0c4(a, 15, 34);
  }
}
void func_0c0595c2(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    a->b205 = 0;
    func_0c02a39a(a, 0);
    func_0c0437b8(a);
  }
}
void func_0c0595f0(struct Actor *a) {
  a->b1ea = 1;
  a->b1ed = 2;
  a->b1f5 = 2;
  a->b3f8 = 2;
  a->b328 = 5;
  table_0c23f894[a->b7](a);
}
