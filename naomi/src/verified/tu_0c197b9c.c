#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Dat_13bb5c dat_0c2f8338;
extern int func_0c028642(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c197b9c(register struct LinkedActor *a,struct LinkedActor *owner,struct ActorSubByteState *context)
{

 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 {struct Actor *parent=A(a)->p20;a->f52=parent->f52+A(a)->f92;}
 if(!context->b4 && a->b33){
  if(func_0c028642(a))return;
  a->b4=2;a->sdc.b12c=0;
  {struct Actor *child=A(a)->p12;child->b33=1;child->p20=A(owner);}return;
 }
 a->b5++;A(a)->f104=26.666666031f;
 if(a->sdc.w130)A(a)->f104=-A(a)->f104;
}
void func_0c197c26(struct LinkedActor *a,struct LinkedActor *owner,struct ActorSubByteState *context)
{

 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 owner=a->p20;a->f52=owner->f52;
 if(a->b34){a->f52+=A(a)->f92;goto done;}
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;
 if(A(a)->f92*A(a)->f104<0)return;
 a->b4=2;a->sdc.b12c=0;
 {struct Actor *parent=A(a)->p20;if(!parent->b3)*(signed char *)&context->b4=-1;else parent->b34=0;}
 done:;
}
void func_0c197ca8(struct LinkedActor *a){func_0c037688(a);}
