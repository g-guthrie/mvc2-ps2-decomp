#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047b98(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c05bbd6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a684(struct Actor *, int, int, int);
extern int table_0c23f464[];
extern int table_0c23f4a8[];
extern int table_0c23f4c0[];
void func_0c059220(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  int *tbl;
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
    if (*(char *)&sub->b2 > 15)
      *(char *)&sub->b2 = 15;
  }
  if (func_0c044e52(a)) {
    a->b7++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    dat_0c2d9260.b5 = 3;
    dat_0c2d9260.b6 = 1;
    func_0c05bbd6(a);
    func_0c02a0c4(a, 15, 46);
  } else if (*(char *)&sub->b2 > 3) {
    tbl = table_0c23f464;
    if (!a->b202)
      func_0c02a684(a, 0, table_0c23f4a8[a->b37] + tbl[*(char *)&sub->b2], 1);
    else
      func_0c02a684(a, 0, table_0c23f4c0[a->b37] + tbl[*(char *)&sub->b2], 1);
  }
}
