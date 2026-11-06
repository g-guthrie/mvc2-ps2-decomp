#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c0437b8(struct Actor *),
    func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0445fe(struct Actor *, struct Actor *),
    func_0c04bad8(struct Actor *, struct Actor *);
extern short dat_0c242108[];
extern void func_0c1cea66(struct Actor *, struct LinkedActorVec3 *, int),
    func_0c0346da(struct Actor *, int);
void func_0c08516e(struct Actor *, struct ActorSub2a4 *);
void func_0c0851d4(struct Actor *, struct ActorSub2a4 *);
void func_0c085088(struct Actor *a) {
  struct Actor *child;
  float distance;
  func_0c02a026(a);
  if (a->b141 < 0)
    return;
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c044e52(a)) {
    func_0c025900(a, 0, 0);
    func_0c0437b8(a);
    return;
  }
  child = a->p1c8;
  if (child->b1f9 != 2)
    return;
  distance = child->f52 - a->f52;
  if (distance < 0)
    distance = -distance;
  if (distance > 106.666664124f)
    return;
  if (child->f56 - a->f56 + 68.57143f < 0) {
    func_0c02a0c4(a, 15, 4);
    a->b1f7 = 196;
    func_0c0445fe(a, child);
    func_0c04bad8(child, a);
    func_0c025900(a, 5, 5);
    child->b236 = 0;
    a->b7++;
  }
}
void func_0c08516e(struct Actor *a, struct ActorSub2a4 *sub) {
  a->b7++;
  a->b1f9 = 2;
  a->f92 = 0;
  a->f104 = 0;
  a->f96 = 51.42857f;
  a->f108 = -0.80357140303f;
  func_0c02a0c4(a, 22, 6);
}
void func_0c0851d4(struct Actor *a, struct ActorSub2a4 *sub) {
  char command;
  struct Actor *child;
  int zero = 0;
  if (func_0c02a026(a) < 0) {
    a->b7++;
    func_0c08516e(a, sub);
    return;
  }
  if (a->b140) {
    a->b140 = zero;
    if (a->w130)
      a->f52 += 53.3333321f;
    else
      a->f52 -= 53.3333321f;
  }
  command = a->b141 & 127;
  if (command) {
    if (a->w130)
      a->f52 += dat_0c242108[command] * 1.66666663f / 256.0f;
    else
      a->f52 -= dat_0c242108[command] * 1.66666663f / 256.0f;
  }
  if (a->b141 < 0) {
    char *facing;
    a->b141 = zero;
    child = a->p1c8;
    facing = (char *)a + 0x1d2;
    child->p1b4 = a;
    child->b1a1 = 35;
    child->b1f9 = 2;
    child->b1f6 = 17;
    child->b1d2 = a->b1d2;
    *facing = a->b1d2 ^ 1;
  }
}
void func_0c0852aa(struct Actor *a, struct ActorSub2a4 *sub) {
  struct LinkedActorVec3 position;
  a->b7++;
  a->f92 = 0;
  a->f96 = 0;
  a->f104 = 0;
  a->f108 = 0;
  position.x = -76.666664124f;
  position.y = 199.28571f;
  func_0c1cea66(a, &position, 0);
  func_0c0346da(a, 35);
  func_0c0851d4(a, sub);
}
