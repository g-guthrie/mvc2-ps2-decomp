/* Verified: exact. */
#include "objects.h"
extern void (*table_0c23f864[])(struct Actor *);
extern void (*table_0c23f87c[])(struct Actor *);
extern void func_0c056bb8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c04b5cc(struct Actor *, int, int, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c043352(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c044548(struct Actor *, struct Actor *);
void func_0c05898c(struct Actor *a) {
  a->b1ea = 1;
  a->b1ed = 2;
  a->b1f5 = 2;
  table_0c23f864[a->b7](a);
}

void func_0c0589b0(struct Actor *a) { table_0c23f87c[a->b6](a); }

void func_0c0589c2(struct Actor *a) {
  if (a->b255 == 6) {
    a->b3f0 = 255;
    a->b3f1 = 16;
  }
  a->b6++;
  func_0c056bb8(a);
  a->f92 = 6.66666651f;
  a->f104 = -0.1041666642f;
  if (!a->b1d2) {
    a->f92 = -a->f92;
    a->f104 = -a->f104;
  }
  a->s28 = 40;
  func_0c02a0c4(a, 15, 35);
  func_0c04b5cc(a, 10, 50, 60);
}
void func_0c058a30(struct Actor *a) {
  struct LinkedActorVec3 position;
  struct Actor *target;
  short two = 2;
  int zero;
  unsigned char *animation;

  a->w3e4 = two;
  a->b3f8 = two;
  a->b328 = 5;
  zero = 0;
  if (a->b141 > 0) {
    a->b3f0 = zero;
    a->b3f1 = zero;
    a->b141 = zero;
    position.x = -40.0f;
    position.y = 154.28571f;
    func_0c0429a4(a, &position, 1);
    goto done;
  } else if (a->b141 != 0)
    a->b3f1 = a->b255 == 6 ? 2 : 0;
  if (!((unsigned char *)&a->w150)[1]) {
    func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
  }
  func_0c02a026(a);
  if ((target = func_0c037d54(a))) {
    a->b6++;
    a->b7 = zero;
    func_0c025900(a, 5, 5);
    a->b1f7 = 202;
    position.x = -146.66666f;
    position.y = 171.42856f;
    func_0c1d4610(a, &position);
    func_0c02a0c4(a, 15, 37);
    func_0c044548(a, target);
  } else {
    if (a->b1d2) {
      if ((char)a->b1fd & 1)
        goto timeout;
      goto check;
    } else if ((char)a->b1fd & two)
      goto timeout;
    check:
    if (--a->s28 == 0) {
    timeout:
      a->b6 = 3;
      func_0c02a0c4(a, 15, 36);
    }
  }
done:
  return;
}
void func_0c058ba2(struct Actor *a) {
  struct ActorSub2a4 *sub;
  sub = &a->sub2a4;
  goto call;
call:
  if (func_0c02a026(a) < 0) {
    a->b7++;
    sub->b2 = 0;
    func_0c02a0c4(a, 15, 38);
  }
}
