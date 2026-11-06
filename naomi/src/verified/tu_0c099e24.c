#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c044cbc(struct Actor *), func_0c043352(struct Actor *),
    func_0c044df4(struct Actor *), func_0c0437b8(struct Actor *),
    func_0c0346da(struct Actor *, int), func_0c048bb0(struct Actor *, short),
    func_0c02a0c4(struct Actor *, int, int);
extern void (*table_0c243464[])(struct Actor *);
void func_0c099e24(struct Actor *a) {
  float event;
  if (!a->b6) {
    func_0c044cbc(a);
    a->b6++;
    a->b1f9 = 1;
    func_0c02a0c4(a, 20, 3);
    a->b1a1 = 53;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0346da(a, 22);
    func_0c048bb0(a, 5);
  }
  if (a->b1ff == 3)
    func_0c043352(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c044df4(a);
  if (func_0c02a026(a) < 0) {
    func_0c0437b8(a);
    return;
  }
  event = (float)a->b141;
  if (event) {
    a->b141 = 0;
    event *= a->b1d2 ? 1.66666663f : -1.66666663f;
    a->f52 += event;
  }
}
void func_0c099f1e(struct Actor *a) { table_0c243464[a->b6](a); }
