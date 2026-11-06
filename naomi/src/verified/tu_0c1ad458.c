#include "objects.h"
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern unsigned char dat_0c2f833e;
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c1d53e4(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c1ad4f2(struct LinkedActor *,struct LinkedActor *);
void func_0c1ad458(struct LinkedActor *a,struct LinkedActor *parent) {
 a->b7++;
 ((struct MeActor *)a)->blk_dc.b13c=32;
 ((struct MeActor *)a)->blk_dc.b13d=32;
 ((struct MeActor *)a)->blk_dc.b13e=32;
 ((struct MeActor *)a)->blk_dc.b13f=32;
 if(!(a->sdc.w130=parent->sdc.w130)) {
  a->f52=dat_0c2d9260.f8c+80.0f; a->f92=-6.66666651f;
 } else {
  a->f52=dat_0c2d9260.f88-80.0f; a->f92=6.66666651f;
 }
 a->f56=((struct Actor *)parent)->f41c+68.57143f;
 a->f104=0.0f; a->f96=2.1428571f; a->f108=-0.80357140303f;
 func_0c02a0c4(a,25,16);
 ((struct Actor *)a)->b0=1;
 func_0c1d53e4(a);
 func_0c1ad4f2(a,parent);
}
void func_0c1ad4f2(struct LinkedActor *a,struct LinkedActor *parent) {
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 if(a->f56>((struct Actor *)parent)->f41c) return;
 a->b7++; a->f56=((struct Actor *)parent)->f41c; a->s28=32;
 func_0c02a026(a);
}
void func_0c1ad550(struct LinkedActor *a,struct LinkedActor *parent) {
 if(!(dat_0c2f833e & (1<<(parent->b2^1)))) {
  if(--a->s28==0) a->b7++;
  func_0c02a026(a);
 }
}
