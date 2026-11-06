#include "objects.h"
extern void func_0c034922(struct Actor *);
extern void func_0c1d1622(struct LinkedActorVec3 *, int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern int func_0c04daae(struct Actor *, int, int);
extern void func_0c0453c4(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c23bb78[])(struct Actor *);
void func_0c03ea8c(struct Actor *a) {
  int value;
  a->b1eb = 2;
  if ((value = a->s278) >= 0) {
  if (0 < (short)a->w420 && value > 0)
    goto animate;
  a->s278 = -1;
  func_0c034922(a);
  func_0c1d1622((struct LinkedActorVec3 *)&a->f52, a->b2);
  if (a->b233 != 1) {
    value = a->b207;
    value = value < 5 ? 1 : 3;
    dat_0c2d9260.b5 = value;
    dat_0c2d9260.b6 = 1;
  }
  if (a->b235 || !a->w420 || !a->b236)
    goto animate;
  if (a->b525) {
    if (func_0c04daae(a, 29, 2))
      *(char *)&a->b236 = -1;
    else
      *(char *)&a->b236 = 0;
  }
  if ((char)a->b236 < 0) {
    a->b1d3 = 0;
    func_0c0453c4(a, 17);
    return;
  }
  }
animate:
  if (func_0c02a026(a) < 0)
    func_0c0453c4(a, 23);
}
void func_0c03eb60(struct Actor *a) { table_0c23bb78[a->b6](a); }
