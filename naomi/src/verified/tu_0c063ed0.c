#include "objects.h"
struct ActorSubByte28 {
  unsigned char pad[28], b28;
};
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void (*table_0c24021c[])(struct Actor *);
void func_0c063ed0(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  goto call;
call:
  func_0c02a026(a);
  if (!a->b141) {
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
  }
  if (a->f96 < 0) {
    a->f104 = a->f108 = 0;
    a->f92 = 0.8333333135f;
    a->f96 = 1.07142854f;
    if (!a->w130)
      a->f92 = -a->f92;
  }
  if (--a->s28 == 0) {
    a->b6++;
    a->f92 = 6.66666651f;
    a->f104 = -0.1041666642f;
    a->f96 = 12.85714245f;
    a->f108 = -0.5357143f;
    if (a->w130) {
      a->f92 = -a->f92;
      a->f104 = -a->f104;
    }
    ((struct ActorSubByte28 *)sub)->b28 = 0;
    func_0c0344a0(a, 43);
    func_0c02a0c4(a, 15, 2);
  }
}
void func_0c063fc8(struct Actor *a) {
  a->b6++;
  a->f92 = 3.3333333f;
  a->f104 = 0;
  a->f96 = 17.142857f;
  a->f108 = -0.2678571343422f;
  if (!a->w130)
    a->f92 = -a->f92;
  a->s28 = 90;
  func_0c063ed0(a);
}
void func_0c064002(struct Actor *a) { table_0c24021c[a->b6](a); }
