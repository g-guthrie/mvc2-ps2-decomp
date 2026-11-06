#include "objects.h"
extern float dat_0c2d92f0;
extern int func_0c028642(struct LinkedActor *);
extern void func_0c0344a0(struct LinkedActor *,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c1d53e4(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c259d30[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1abf44(struct LinkedActor *,struct LinkedActor *);
void func_0c1abe8c(struct LinkedActor *a,struct LinkedActor *parent) {
 float positive,negative;
 a->b7++;
 a->sdc.w130=parent->sdc.w130^1;
 positive=160.0f; negative=-160.0f;
 if(!parent->sdc.w130) a->f52=parent->f52+negative;
 else a->f52=parent->f52+positive;
 a->f56=dat_0c2d92f0+68.57143f;
 a->f92=0.0f; a->f104=0.0f;
 a->f96=-17.142857f; a->f108=-0.80357140303f;
 if(!func_0c028642(a)) {
  a->sdc.w130=0;
  if(!parent->sdc.w130) a->f52=parent->f52+positive;
  else a->f52=parent->f52+negative;
 }
 func_0c0344a0(a,33);
 func_0c02a0c4(a,25,23);
 ((struct Actor *)a)->b0=1;
 func_0c1d53e4(a);
 func_0c1abf44(a,parent);
}
void func_0c1abf44(struct LinkedActor *a,struct LinkedActor *parent) {
 a->f56+=a->f96; a->f96+=a->f108;
 if(((struct Actor *)parent)->f41c<a->f56) return;
 a->b7++; a->f56=((struct Actor *)parent)->f41c;
 func_0c02a026(a);
}
void func_0c1abf82(struct LinkedActor *a) {
 if(func_0c02a026(a)<0) { a->b6=2; a->b7=0; }
}
void func_0c1abfa0(struct LinkedActor *a,struct LinkedActor *parent) { table_0c259d30[a->b7](a,parent); }
