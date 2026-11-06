#include "objects.h"
extern struct Actor *func_0c1977f8(struct Actor *, char);
extern char func_0c02a026(struct Actor *);
extern void func_0c19715c(struct Actor *, int, int),
    func_0c02a39a(struct Actor *, int), func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *), func_0c0437b8(struct Actor *),
    func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c2f6830;
extern void (*table_0c242bd8[])(struct Actor *),
    (*table_0c242be4[])(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int),
    func_0c142be0(struct Actor *, int, struct Actor *);
void func_0c090b30(struct Actor *a, struct ActorSub2a4 *sub) {
  int zero;
  a->b3f8 = 2;
  a->b328 = 5;
  a->b1f5 = 2;
  func_0c02a026(a);
  zero = 0;
  if (a->b14b) {
    a->b1a1 = a->b14b;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->b14b = zero;
  }
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (a->f56 < a->f41c) {
    a->b3f9 = zero;
    a->b3f8 = zero;
    a->b327 = zero;
    a->b328 = zero;
    a->b6++;
    a->b7 = zero;
    a->f56 = a->f41c;
    a->b1f9 = 1;
    sub->b3 = zero;
    func_0c19715c(a, 1, 0);
    func_0c043324(a);
    func_0c02a0c4(a, 22, 3);
  }
}
void func_0c090c20(struct Actor *a) {
  if (!a->b7) {
    if (func_0c02a026(a) < 0)
      func_0c0437b8(a);
  } else {
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
      a->b7--;
      a->f56 = a->f41c;
      a->b1f9 = 0;
      func_0c043324(a);
      func_0c02a0c4(a, 22, 5);
    }
  }
}
void func_0c090ce4(struct Actor *a) { table_0c242bd8[a->b6](a); }
void func_0c090cf6(struct Actor *a) { table_0c242be4[a->b7](a); }
void func_0c090d08(struct Actor *a) {
  struct ActorSubByteState *sub = (struct ActorSubByteState *)&a->sub2a4;
  int zero, command;
  unsigned int type;
  if (a->b255 == 6) {
    a->b3f0 = 255;
    a->b3f1 = 16;
  }
  a->b7++;
  zero = 0;
  a->b1f9 = zero;
  a->f56 = a->f41c;
  a->s28 = zero;
  func_0c02a39a(a, zero);
  func_0c0442fa(a);
  func_0c0432ca(a);
  if (dat_0c2f6830 <= 2) {
    a->b6 = 2;
    a->b7 = zero;
    func_0c02a0c4(a, 22, 8);
  } else {
    goto first;
first:
    func_0c1977f8(a,0);func_0c1977f8(a,1);
    sub->b4 = zero;
    sub->b5 = 14;
    command = 61;
    type = a->b255;
    if (type == 4 || type == 5)
      command = 68;
    a->b1a1 = command;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c02a0c4(a, 22, 7);
  }
}
void func_0c090e1c(struct Actor *a) {
  struct LinkedActorVec3 position;
  a->b3f8 = 2;
  a->b328 = 5;
  a->b3f1 = a->b255 == 6 ? 2 : 0;
  func_0c02a026(a);
  if (a->b141) {
    a->b3f0 = 0;
    a->b3f1 = 0;
    a->b7++;
    a->b141 = 0;
    position.x = 26.666666031f;
    position.y = 205.71428f;
    func_0c0429a4(a, &position, 1);
  }
}
void func_0c090e86(struct Actor *a) {
  a->b3f8 = 2;
  a->b328 = 5;
  func_0c02a026(a);
  if (a->b141) {
    a->b6++;
    a->b7 = 0;
    a->b141 = 0;
    a->s28 = 360;
    func_0c142be0(a, 0, a);
  }
}
