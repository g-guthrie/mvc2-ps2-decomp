#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
typedef void (*handler_0c0e72b8)(struct Actor *);
extern handler_0c0e72b8 table_0c249704[];
extern int func_0c1ec190(void);
extern short dat_0c2406cc[];
extern void (*table_0c2406c4[])(struct Actor *);
extern void (*table_0c2406d4[])(struct Actor *);
extern void (*table_0c2434fc[])(struct Actor *, struct ActorSub2a4 *);
extern int func_0c146bfc(struct Actor *, int);

void func_0c09a6e4(struct Actor *a) {
  func_0c02a026(a);
  if (!a->b141) {
    a->b1f9 = 2;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
  }
  if (!a->b141 && !(a->f56 > a->f41c)) {
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c043324(a);
    func_0c02a0c4(a, 21, 3);
  }
}

void func_0c09a776(struct Actor *a) {
  if (func_0c02a026(a) >= 0)
    return;
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  func_0c0437b8(a);
}

void func_0c09a7a8(struct Actor *a) { table_0c2434fc[a->b6](a, &a->sub2a4); }

void func_0c09a7be(struct Actor *a) {
  a->b6++;
  if (a->b255 == 3)
    a->b1a1 = 79;
  else {
    goto L; L: a->b1a1 = 49; }
  a->w1ac = 0;
  a->b19e = 0;
  *(unsigned int *)&a->p1c4 = 0;
  dat_0c2f83f8->arr[a->b2]++;
  goto M; M:
  func_0c048bb0(a, 5);
  func_0c0442fa(a);
  a->f56 = a->f41c;
  a->b1f9 = 0;
  a->f92 = 0;
  a->f96 = 0;
  a->f104 = 0;
  a->f108 = 0;
  func_0c0432ca(a);
  func_0c02a0c4(a, 21, 4);
}

void func_0c09a866(struct Actor *a, struct ActorSub2a4 *sub) {
  func_0c02a026(a);
  if (a->b141) {
    a->b6++;
    *(char *)&sub->w4 = 0;
    if (!func_0c146bfc(a, 1)) {
      func_0c0437b8(a);
      return;
    }
    a->b27b = 0;
    a->b27a = 16;
  }
}

void func_0c09a8b6(struct Actor *a, struct ActorSub2a4 *sub) {
  func_0c02a026(a);
  if (!sub->b1) {
    func_0c0437b8(a);
    return;
  }
  if (*(char *)&sub->w4) {
    a->b6++;
    a->s28 = 32;
    func_0c02a0c4(a, 21, 1);
  }
}

void func_0c09a904(struct Actor *a) {
  if (a->b141 == 0)
    func_0c02a026(a);
  if (--a->s28 == 0)
    a->b6++;
}
