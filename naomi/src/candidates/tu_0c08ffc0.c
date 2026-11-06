/* Ten functions and all four literal pools match. func_0c0903b6 remains
 * 55/60 bytes and stays a candidate. */
#include "objects.h"
struct ActorSubAngularMotion32 {
  unsigned char pad[6];
  char event6;
  unsigned char pad7[5];
  float f12, f16, angle20, angle24, velocity28;
};
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *),
    func_0c0437b8(struct Actor *), func_0c025762(void),
    func_0c048bb0(struct Actor *, int), func_0c142f44(struct Actor *),
    func_0c0426c2(struct Actor *, int), func_0c0427be(struct Actor *, int),
    func_0c025900(struct Actor *, char, char),
    func_0c02a0c4(struct Actor *, int, int), func_0c04b02a(struct Actor *),
    func_0c1d1622(struct LinkedActorVec3 *, int), func_0c03489c(struct Actor *),
    func_0c1990c0(struct Actor *, int);
extern int func_0c042780(struct Actor *), func_0c0427f2(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern short dat_0c242a64[];
extern void (*table_0c242b98[])(struct Actor *,
                                struct ActorSubAngularMotion32 *),
    (*table_0c242ba8[])(struct Actor *, struct ActorSubAngularMotion32 *),
    (*table_0c242bb4[])(struct Actor *, struct ActorSubAngularMotion32 *);
void func_0c0903b6(struct Actor *, struct ActorSubAngularMotion32 *),
    func_0c0903f2(struct Actor *, struct ActorSubAngularMotion32 *);
void func_0c08ffc0(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  int zero = 0;
  a->b6++;
  a->b7 = zero;
  a->b1f9 = zero;
  a->f56 = a->f41c;
  a->s28 = zero;
  a->b34 = a->b1a3 ? 28 : 24;
  s->event6 = zero;
  s->angle24 = (float)a->b34;
  s->angle20 = (float)a->b34;
  s->velocity28 = 0;
  a->b1a1 = a->b1a3 + 50;
  a->w1ac = zero;
  a->b19e = zero;
  *(unsigned int *)&a->p1c4 = zero;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c0442fa(a);
  func_0c0432ca(a);
  func_0c02a0c4(a, 21, a->b1a3 + 5);
}
void func_0c090066(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  table_0c242b98[a->b7](a, s);
}
void func_0c090078(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  func_0c02a026(a);
  if (a->b140) {
    a->b7++;
    a->s30 = 360;
    a->b27b = 1;
    a->b27a = 16;
    func_0c048bb0(a, 5);
    func_0c142f44(a);
    func_0c0903b6(a, s);
  }
}
void func_0c0900f4(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  int zero;
  func_0c02a026(a);
  func_0c0903b6(a, s);
  zero = 0;
  if (s->event6 > 0) {
    struct Actor *child;
    a->b7++;
    a->b1ea = 1;
    a->b1f7 = 195;
    a->b1f2 = 3;
    a->s28 = zero;
    a->s30 = zero;
    child = a->p1c8;
    child->b1f4 = 2;
    child->b1f7 = a->b1f7;
    func_0c0426c2(child, 35);
    func_0c0427be(a, 20);
    func_0c025900(a, 0, 5);
    func_0c02a0c4(a, 21, 9);
    func_0c0903b6(a, s);
    func_0c0903f2(a, s);
  } else if (s->event6 < 0 || !--a->s30) {
    a->b6++;
    a->b7 = zero;
    func_0c02a0c4(a, 21, a->b1a3 + 7);
  }
}
void func_0c0901ac(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  struct LinkedActorVec3 position;
  struct Actor *child;
  int one = 1, zero;
  a->b1ea = one;
  a->b1f2 = 3;
  child = a->p1c8;
  func_0c0903f2(a, s);
  zero = 0;
  if (a->b140) {
    a->b140 = zero;
    child->p1b4 = a;
    child->b1a1 = 53;
    if (a->s28)
      child->b1a1 = 54;
    func_0c04b02a(a);
    position.x = child->f52;
    position.y = child->f41c;
    func_0c1d1622(&position, child->b2);
    func_0c03489c(a);
    dat_0c2d9260.b5 = one;
    dat_0c2d9260.b6 = one;
    return;
  }
  if (func_0c042780(child)) {
    a->s28 = zero;
    func_0c0426c2(child, 35);
  }
  if (func_0c0427f2(a) && !a->s28) {
    a->s28++;
    func_0c0427be(a, 20);
  }
  if (func_0c02a026(a) < 0) {
    if (!a->s28 || a->s30) {
      a->b7++;
      child->b6++;
      s->event6 = -1;
      func_0c02a0c4(a, 21, 11);
      return;
    }
    a->s28 = zero;
    a->s30 = one;
    func_0c02a0c4(a, 21, 9);
  }
  func_0c0903b6(a, s);
}
void func_0c0902f4(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  int one = 1;
  a->b1ea = one;
  func_0c0903f2(a, s);
  func_0c02a026(a);
  if (a->b141) {
    struct Actor *child;
    int zero = 0;
    a->b6++;
    a->b7 = zero;
    a->b1f2 = one;
    child = a->p1c8;
    child->p1b4 = a;
    child->b1f6 = one;
    child->b1d2 = a->b1d2;
    child->b1f9 = 2;
    child->b1a1 = 35;
    child->b6 = zero;
    child->b1fd = zero;
    func_0c025762();
    func_0c1990c0(a, 0);
  }
}
void func_0c090390(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    func_0c0442fa(a);
    func_0c0437b8(a);
  }
}
void func_0c0903b6(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  short *values = dat_0c242a64;
  float x, y;
  values += (a->b141 >> 1);
  x = (float)*values++ * 1.66666663f;
  y = (float)*values * 2.1428571f;
  if (a->b1d2)
    x = -x;
  s->f12 = x;
  s->f16 = y;
}
void func_0c0903f2(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  float angle = (float)(a->b14b & 127), full;
  full = 32.0f;
  if (s->angle20 != angle) {
    s->angle24 = s->angle20;
    s->angle20 = angle;
    s->velocity28 = s->angle20 - s->angle24;
    if (!(s->velocity28 < 16.0f))
      s->velocity28 -= full;
    if (!(s->velocity28 > -16.0f))
      s->velocity28 += full;
    s->velocity28 /= (float)a->b142;
  }
  if (s->angle20 == s->angle24)
    s->velocity28 = 0;
  s->angle24 += s->velocity28;
  if (s->angle24 < 0)
    s->angle24 += full;
  if (!(s->angle24 < full))
    s->angle24 -= full;
  a->b34 = (int)s->angle24;
}
void func_0c09049c(struct Actor *a, struct ActorSubAngularMotion32 *s) {
  table_0c242ba8[a->b6](a, s);
}
void func_0c0904ae(struct Actor *a) {
  table_0c242bb4[a->b7](a, (struct ActorSubAngularMotion32 *)&a->sub2a4);
}
