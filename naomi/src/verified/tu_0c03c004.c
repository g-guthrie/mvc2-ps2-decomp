#include "objects.h"
extern void (*table_0c23ba6c[])(struct Actor *);
extern void func_0c044fbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
void func_0c03c004(struct Actor *a) {
  a->b3f0 = 0xff;
  a->b3f1 = 16;
  a->b6++;
  a->b1fd = 0;
  a->b12c = 1;
  func_0c044fbe(a);
  a->b1e1 = 80;
  func_0c02a0c4(a, 1, 1);
  func_0c02a39a(a, 1);
  a->s28 = (a->b411 - 1) * 10;
}
void func_0c03c05e(struct Actor *a) {
  void *zero;
  if (a->s28) {
    a->s28--;
  } else {
    goto c; c: func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f56 > a->f41c)) {
      zero = 0;
      a->f56 = a->f41c;
      a->b1f9 = (int)zero;
      a->f92 = 0;
      a->f96 = 0;
      a->f104 = 0;
      a->f108 = 0;
      a->b3f0 = (int)zero;
      a->b3f1 = (int)zero;
      func_0c02a0c4(a, (int)zero, (int)zero);
      ((void (**)(struct Actor *))a->p428)[17](a);
      func_0c043324(a);
    }
  }
}
void func_0c03c110(struct Actor *a) {
  a->b1ed = 2;
  table_0c23ba6c[a->b6](a);
}
