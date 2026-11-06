#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047b98(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c05bbd6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned char *dat_0c23f4a8[], *dat_0c23f4c0[];
extern int dat_0c23f4d8[];
extern void func_0c02a684(struct Actor *, int, unsigned char *, int);
extern void func_0c1d357a(struct LinkedActorVec3 *, int);
extern void func_0c1d330c(struct Actor *, struct LinkedActorVec3 *, int, int);
extern void func_0c0346da(struct Actor *, int);
void func_0c05a3b4(struct Actor *a) {
  struct ActorSub2a4 *sub;
  sub = &a->sub2a4;
  goto call;
call:
  if (func_0c02a026(a) < 0) {
    a->b7++;
    sub->b2 = 0;
    func_0c02a0c4(a, 15, 44);
  }
}
void func_0c05a3f2(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    a->b7++;
    a->f92 = 0;
    a->f104 = 0;
    a->f96 = -6.428571224213f;
    a->f108 = -1.2053571f;
    func_0c02a0c4(a, 15, 45);
  }
}
void func_0c05a436(struct Actor *a) {
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
    if (*(char *)&sub->b2 > 16)
      *(char *)&sub->b2 = 16;
  }
  if (func_0c044e52(a)) {
    a->b7++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    dat_0c2d9260.b5 = 3;
    dat_0c2d9260.b6 = 1;
    func_0c05bbd6(a);
    func_0c02a0c4(a, 15, 46);
    return;
  }
  if ((char)sub->b2 > 5) {
    if (!a->b202)
      func_0c02a684(a, 0, dat_0c23f4a8[a->b37] + dat_0c23f4d8[(char)sub->b2],
                    1);
    else
      func_0c02a684(a, 0, dat_0c23f4c0[a->b37] + dat_0c23f4d8[(char)sub->b2],
                    1);
  }
}
void func_0c05a586(struct Actor *a) {
  struct LinkedActorVec3 position;
  struct Actor *child;
  if (a->b141) {
    a->b141 = 0;
    child = a->p1c8;
    position.x = child->f52;
    position.y = a->f41c;
    func_0c1d357a(&position, 1);
    func_0c1d330c(a, &position, 4, 126);
    func_0c0346da(a, 74);
  }
  if (func_0c02a026(a) < 0) {
    a->b7++;
    func_0c02a0c4(a, 15, 14);
  }
}
