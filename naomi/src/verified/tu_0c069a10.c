/* The shared zero lives in r13 (`register void *zero` cast at each use, `a` as a register parameter). The b1a3 ternary and the following sub store each sit behind a label, which makes the compiler number the condition before the result as retail does. */
#include "objects.h"
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c06c9ba(struct Actor *);
extern void (*table_0c24076c[])(struct Actor *);
extern void (*table_0c2407c8[])(struct Actor *, struct ActorSub2a4 *);
extern void (*table_0c2407d4[])(struct Actor *);
void func_0c069a10(struct Actor *a) { table_0c24076c[a->b1e9](a); }
void func_0c069a24(struct Actor *a) { table_0c2407c8[a->b6](a, &a->sub2a4); }
void func_0c069a3a(register struct Actor *a, struct ActorSub2a4 *sub) {
  register void *zero;
  a->b6++;
  zero = 0;
  func_0c048bb0(a, 10);
  func_0c0442fa(a);
  a->f56 = a->f41c;
  a->b1f9 = (int)zero;
  a->f96 = 0.0f;
  a->f108 = 0.0f;
  if (a->b255 == 3)
    a->b1a1 = 90;
  else if (a->b1e9)
    a->b1a1 = 52;
  else
    { goto set; set: a->b1a1 = a->b1a3 ? 50 : 48; }
  a->w1ac = (int)zero;
  a->b19e = (int)zero;
  *(unsigned int *)&a->p1c4 = (int)zero;
  dat_0c2f83f8->w7c[a->b2]++;
  goto s2; s2: sub->b6 = (int)zero;
  a->f92 = a->b1d2 ? 16.666666031f : -16.666666031f;
  a->f104 = a->b1d2 ? -0.3125f : 0.3125f;
  a->s28 = a->b1a3 ? 12 : 1;
  func_0c0432ca(a);
  func_0c02a0c4(a, 21, 0);
}
void func_0c069b60(struct Actor *a) {
  func_0c02a026(a);
  if (a->b141)
    return;
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c06c9ba(a);
  if (--a->s28 == 0) {
    a->b6++;
    a->f92 = a->b1d2 ? 10.0f : -10.0f;
    a->f104 = a->b1d2 ? -0.20833333f : 0.20833333f;
    func_0c02a0c4(a, 21, 1);
  }
}
void func_0c069c02(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    func_0c0437b8(a);
    return;
  } else if (a->b141) {
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c06c9ba(a);
  }
}
void func_0c069c6c(struct Actor *a) { table_0c2407d4[a->b6](a); }
