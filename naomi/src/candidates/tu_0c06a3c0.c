/* Candidate: two functions and the pool tail match; func_0c06a450 differs only in the literal-pool order of the 0x0c2d926c pointer relative to the -333.33 float (retail pools the pointer first) and the scratch register of the pointer in the second branch. 379/392 bytes. */
#include "objects.h"
struct Sub_0c06a450 { unsigned char pad[9]; unsigned char b9, b10, b11; };
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0438de(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void (*table_0c240818[])(struct Actor *, struct ActorSub2a4 *);
void func_0c06a3c0(struct Actor *a) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (a->f56 <= a->f41c) {
    a->f56 = a->f41c;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
  }
  if (func_0c02a026(a) < 0)
    func_0c0438de(a);
}
void func_0c06a43a(struct Actor *a) { table_0c240818[a->b6](a, &a->sub2a4); }
void func_0c06a450(struct Actor *a, struct Sub_0c06a450 *sub) {
  int zero;
  float target;
  a->b6++;
  func_0c048bb0(a, 4);
  func_0c0442fa(a);
  zero = 0;
  a->b1f9 = zero;
  a->f56 = a->f41c;
  func_0c0432ca(a);
  func_0c025900(a, 1, 13);
  a->s28 = 32;
  sub->b9 = zero;
  sub->b10 = zero;
  sub->b11 = 2;
  target = a->b1d2 ? dat_0c2d9260.f12 + -333.333344f : dat_0c2d9260.f12 + 333.333344f;
  a->f92 = (target - a->f52) / 32.0f;
  a->f104 = 0.0f;
  a->f96 = a->b1a3 ? 21.42857f : 12.85714245f;
  a->f108 = -0.5357143f;
  func_0c02a0c4(a, 1, 8);
}
