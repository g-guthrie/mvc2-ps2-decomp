#include "objects.h"
extern void (*table_0c243a68[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *),
    func_0c09e43a(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c044548(struct Actor *, struct Actor *);
extern void func_0c1cea66(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c0346da(struct Actor *, int),
    func_0c04af58(struct Actor *, int);
extern void func_0c026980(void);
void func_0c0a1a3a(struct Actor *);
void func_0c0a1864(struct Actor *a) { table_0c243a68[a->b6](a); }
void func_0c0a1876(struct Actor *a) {
  a->b6++;
  a->b1a1 = 67;
  a->w1ac = 0;
  a->b19e = 0;
  *(unsigned int *)&a->p1c4 = 0;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c048bb0(a, 5);
  func_0c0442fa(a);
  a->f92 = 0;
  a->f96 = 0;
  a->f104 = 0;
  a->f108 = 0;
  func_0c0432ca(a);
  func_0c02a0c4(a, 22, 6);
}
void func_0c0a18dc(register struct Actor *a) {
  struct LinkedActorVec3 position;
  short *sub;
  sub = (short *)&a->sub2a4;
  goto L; L:
  func_0c09e43a(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (a->b141 == 1) {
    a->b141 = 0;
    position.x = 13.33333302f;
    position.y = 120.0f;
    {
      if (!*sub) {
        goto C; C: func_0c0429a4(a, &position, 3);
      } else func_0c0429a4(a, &position, 0);
    }
    a->f92 = a->b1d2 ? 20.0f : -20.0f;
    a->f104 = a->b1d2 ? -0.625f : 0.625f;
  }
  if (a->b19e && func_0c0447bc(a)) {
    a->b6++;
    a->b1f7 = 196;
    func_0c044548(a, a->p1b0);
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    func_0c02a0c4(a, 22, 7);
    func_0c0a1a3a(a);
    return;
  }
  if (a->b143 < 0) {
    a->b6 = 7;
    func_0c02a0c4(a, 22, 10);
  }
  func_0c02a026(a);
}
void func_0c0a1a3a(struct Actor *a) {
  struct LinkedActorVec3 position;
  struct Actor *child;
  a->b1ea = 1;
  a->b1ed = 2;
  a->b1f5 = 2;
  func_0c09e43a(a);
  child = a->p1c8;
  if (a->b141) {
    a->b141 = 0;
    position.x = 0;
    position.y = 120.0f;
    func_0c1cea66(child, &position, 13);
    func_0c0346da(a, 6);
    func_0c04af58(child, -1);
  }
  if (a->b143 < 0) {
    a->b6++;
    a->s28 = 100;
    func_0c026980();
  } else {
    goto G; G: func_0c02a026(a); }
}
