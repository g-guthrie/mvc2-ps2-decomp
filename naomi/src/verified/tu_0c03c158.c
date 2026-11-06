#include "objects.h"
extern void (*table_0c23ba74[])(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c1d8bfc(struct LinkedActorVec3 *, int);
extern void func_0c0346da(struct Actor *, int);
void func_0c03c158(struct Actor *a) {
  struct { struct ActorVec2 xy; float z; } position;
  a->b6++;
  a->f56 = a->f41c;
  a->b1f9 = 0;
  func_0c02a0c4(a, 24, 1);
  a->b254 = 3;
  position.xy = a->position24c;
  position.z = a->f60;
  func_0c1d8bfc((struct LinkedActorVec3 *)&position, (short)a->w130);
  func_0c0346da(a, 63);
}
void func_0c03c1b2(struct Actor *a) {
  a->b256 = 2;
  a->b6 = a->b7 = 0;
}
void func_0c03c1c0(struct Actor *a) {
  a->b1ed = 2;
  a->b1f4 = 2;
  a->b3f1 = 2;
  table_0c23ba74[a->b6](a);
}
void func_0c03c1e2(struct Actor *a) {
  a->b3f0 = 0xff;
  a->b3f1 = 16;
  a->b6++;
  a->b1fd = 0;
  a->b12c = 1;
  a->b1e1 = 80;
  func_0c02a0c4(a, 1, 1);
  func_0c02a39a(a, 1);
}
void func_0c03c222(register struct Actor *a) {
  void *zero;
  func_0c02a026(a);
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
    ((void (**)(struct Actor *))a->p428)[19](a);
    a->pad7fc[0] = 60;
    func_0c043324(a);
  }
}
