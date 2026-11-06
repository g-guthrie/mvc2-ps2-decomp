#include "objects.h"
extern void func_0c044f1c(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *,
                                   unsigned char *);
extern void func_0c047aac(struct Actor *, unsigned char *);
extern unsigned char dat_0c24231a[], dat_0c242244[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2424c4[])(struct Actor *, struct ActorSub2a4 *);
extern void (*table_0c2424d0[])(struct Actor *);
void func_0c088854(struct Actor *, struct ActorSub2a4 *);
void func_0c088764(struct Actor *a, struct ActorSub2a4 *sub) {
  if (!a->b7) {
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f56 > a->f41c)) {
      a->f56 = a->f41c;
      a->b1f9 = 0;
      if (!a->b32) {
        func_0c044f1c(a);
        return;
      }
      a->b7++;
      func_0c0442fa(a);
      func_0c043324(a);
      func_0c02a0c4(a, 1, 3);
      return;
    }
    func_0c02a026(a);
    if (a->b141)
      func_0c088854(a, sub);
  } else if (func_0c02a026(a) < 0)
    func_0c0437b8(a);
}
void func_0c088854(struct Actor *a, struct ActorSub2a4 *sub) {
  if (!a->b32 || a->b1f9 != 2 || a->b525 || !sub->b6)
    return;
  a->b1d0 = 3;
  if (func_0c046e7e(a, dat_0c24231a, a->x3cc)) {
    goto L; L: sub->b6--;
    a->w130 ^= 1;
    a->b1d2 ^= 1;
    func_0c047aac(a, a->x3cc);
    a->b6 = 0;
    a->b7 = 0;
    a->b1e9 = 2;
  }
  a->b1d0 = 21;
}
void func_0c0888da(struct Actor *a) { table_0c2424c4[a->b6](a, &a->sub2a4); }
void func_0c0888f0(struct Actor *a, struct ActorSub2a4 *sub) {
  a->b6++;
  a->b1f9 = 0;
  a->f56 = a->f41c;
  a->b1fc = 0;
  sub->b7 = 0;
  func_0c0442fa(a);
  func_0c0432ca(a);
  a->b34 = dat_0c242244[(unsigned char)a->b1a3];
  a->b1a1 = a->b1a3 + 66;
  a->w1ac = 0;
  a->b19e = 0;
  *(unsigned int *)&a->p1c4 = 0;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a, 21, a->b1a3 + 18);
}
void func_0c08896c(struct Actor *a) { table_0c2424d0[a->b7](a); }
