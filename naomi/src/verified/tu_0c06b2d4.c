/* Actor state handlers at 0x0c06b2d4; all functions and literal pools match retail. */
#include "objects.h"
struct ActorSubByte8 {
  unsigned char pad[8], b8;
};
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *, int), func_0c0442fa(struct Actor *),
    func_0c0432ca(struct Actor *), func_0c02a0c4(struct Actor *, int, int),
    func_0c0437b8(struct Actor *), func_0c137534(struct Actor *),
    func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c137500(struct Actor *, char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2408b8[])(struct Actor *),
    (*table_0c2408c0[])(struct Actor *),
    (*table_0c2408d4[])(struct Actor *, struct ActorSub2a4 *);
int func_0c06b2d4(struct Actor *a, struct ActorSub2a4 *s) {
  if (a->w34e & 1024) {
    s->b7++;
    ((struct ActorSubByte8 *)s)->b8 = 15;
  }
  return 0;
}
unsigned char func_0c06b2ee(struct Actor *a, struct ActorSub2a4 *s) {
  int zero = 0;
  if (!--((struct ActorSubByte8 *)s)->b8) {
    s->b7 = zero;
    goto fail;
  }
  goto test;
test:
  if ((a->w34e & 2048) == zero) {
  fail:
    return 0;
  }
  s->b7 = zero;
  return 1;
}
void func_0c06b320(struct Actor *a) { table_0c2408b8[a->b6](a); }
void func_0c06b332(register struct Actor *a) {
  register void *zero;
  a->b6++;
  zero = 0;
  if (a->b255 == 3)
    a->b1a1 = 92;
  else
    { goto set; set: a->b1a1 = a->b1a3 ? 93 : 68; }
  a->w1ac = (int)zero;
  a->b19e = (int)zero;
  *(unsigned int *)&a->p1c4 = (int)zero;
  dat_0c2f83f8->arr[a->b2]++;
  goto call; call: func_0c048bb0(a, 8);
  func_0c0442fa(a);
  a->f56 = a->f41c;
  a->b1f9 = (int)zero;
  func_0c0432ca(a);
  func_0c02a0c4(a, 21, 17);
}
void func_0c06b3b4(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    func_0c0437b8(a);
    return;
  }
  if (a->b141) {
    a->b141 = 0;
    {char argument=a->b1a3?6:0;goto call;
call:func_0c137500(a,argument);}
  }
}
void func_0c06b432(struct Actor *a) { table_0c2408c0[a->b6](a); }
void func_0c06b444(struct Actor *a) {
  int zero;
  if (a->b255 == 6) {
    a->b3f0 = 255;
    a->b3f1 = 16;
  }
  a->b6++;
  a->b1a1 = 69;
  zero = 0;
  a->w1ac = zero;
  a->b19e = zero;
  *(unsigned int *)&a->p1c4 = zero;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c0442fa(a);
  a->b1f9 = zero;
  a->f56 = a->f41c;
  func_0c0432ca(a);
  func_0c02a0c4(a, 22, zero);
}
void func_0c06b4b6(struct Actor *a) {
  struct LinkedActorVec3 vector;
  a->b3f8 = 2;
  a->b328 = 5;
  a->b3f1 = a->b255 == 6 ? 2 : 0;
  func_0c02a026(a);
  if (a->b141) {
    a->b6++;
    a->b141 = 0;
    a->s28 = 111;
    a->b3f0 = 0;
    a->b3f1 = 0;
    vector.x = 25.0f;
    vector.y = 199.28571f;
    vector.z = 0;
    func_0c0429a4(a, &vector, 1);
  }
}
void func_0c06b52a(struct Actor *a) {
  int zero;
  a->b3f8 = 2;
  a->b328 = 5;
  func_0c02a026(a);
  zero = 0;
  if (--a->s28 <= 0) {
    a->b6++;
    a->b3f9 = zero;
    a->b3f8 = zero;
    a->b327 = zero;
    a->b328 = zero;
    a->s28 = 40;
    return;
  }
  if (a->b141) {
    a->b141 = zero;
    func_0c137534(a);
  }
}
void func_0c06b5c6(struct Actor *a) {
  func_0c02a026(a);
  if (--a->s28 <= 0) {
    a->b6++;
    func_0c02a0c4(a, 22, 33);
  }
}
void func_0c06b5f6(struct Actor *a) {
  if (func_0c02a026(a) >= 0)
    return;
  a->f92 = 0;
  a->f96 = 0;
  a->f104 = 0;
  a->f108 = 0;
  func_0c0437b8(a);
}
void func_0c06b628(struct Actor *a) { table_0c2408d4[a->b6](a, &a->sub2a4); }
void func_0c06b63e(struct Actor *a, struct ActorSub2a4 *sub) {
  int command;
  a->b6++;
  func_0c048bb0(a, 10);
  func_0c0442fa(a);
  a->f92 = 0;
  a->f96 = 0;
  a->f104 = 0;
  a->f108 = 0;
  a->b1f9 = 2;
  ((struct ActorSubCommandPrefix *)sub)->command = 5;
  command = a->b1fe ? 79 : 76;
  command += (unsigned char)a->b1a3 * 2;
  a->b1a1 = command;
  a->w1ac = 0;
  a->b19e = 0;
  *(unsigned int *)&a->p1c4 = 0;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a, 21, (unsigned char)a->b1a3 * 2 + 18);
}
