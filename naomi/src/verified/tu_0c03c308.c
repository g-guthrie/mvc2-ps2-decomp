#include "objects.h"

extern void (*table_0c23ba7c[])(struct Actor *);
extern void (*table_0c23ba84[])(struct Actor *);
extern void func_0c045144(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0453c4(struct Actor *, int);
void func_0c03c308(struct Actor *a) {
  a->b1ed = 2;
  a->b1f4 = 2;
  table_0c23ba7c[a->b6](a);
}
void func_0c03c326(struct Actor *a) {
  a->b6++;
  a->b1fd = 0;
  a->b12c = 1;
  func_0c045144(a);
  a->b1e1 = 80;
  func_0c02a0c4(a, 1, 1);
  func_0c02a39a(a, 1);
}
void func_0c03c360(struct Actor *a) {

  func_0c02a026(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (!(a->f56 > a->f41c)) {
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c02a0c4(a, 0, 0);
    func_0c043324(a);
    if ((&((struct DirectionState *)dat_0c2f83f8)->entry[0])[a->b2].actor->b5 >= 2)
      func_0c0453c4(a, 0);
    else
      ((void (**)(struct Actor *))a->p428)[18](a);
  }
}
void func_0c03c41e(struct Actor *a) {
  a->b1ed = 2;
  a->b1f4 = 2;
  a->b3f1 = 2;
  table_0c23ba84[a->b6](a);
}
