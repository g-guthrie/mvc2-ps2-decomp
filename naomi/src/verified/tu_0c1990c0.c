#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern struct Dat_13bb5c dat_0c2f8338;
extern void (*table_0c258448[])(struct LinkedActor *,struct LinkedActor *),(*table_0c258454[])(struct LinkedActor *,struct LinkedActor *),(*table_0c258460[])(struct LinkedActor *);
void func_0c1990f4(struct LinkedActor *);
struct LinkedActor *func_0c1990c0(struct LinkedActor *owner,int mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,1))){a->w38=0xe06;a->b32=mode;a->p16=func_0c1990f4;a->p24=owner;}return a;}
void func_0c1990f4(register struct LinkedActor *a){table_0c258448[a->b32](a,a->p24);}
void func_0c19910a(struct LinkedActor *a,struct LinkedActor *owner){table_0c258454[a->b4](a,owner);}
void func_0c19911c(struct LinkedActor *a,struct LinkedActor *owner)
{
 float dx;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->b36=owner->b36;A(a)->f92=20.0f;A(a)->f104=0;A(a)->f96=0;A(a)->f108=-0.80357140303f;
 dx=193.33333f;if(a->sdc.w130){A(a)->f92=-A(a)->f92;A(a)->f104=-A(a)->f104;dx=-193.33333f;}
 a->f52=owner->f52+dx;a->f56=owner->f56+214.28571f;func_0c02a0c4(a,23,44);
}
void func_0c1991d0(register struct LinkedActor *a,struct LinkedActor *owner)
{
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))goto done;
 if(func_0c02a026(a)<0){a->b4=2;a->sdc.b12c=0;goto done;}
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 if(a->f56<A(owner)->f41c){a->f56=A(owner)->f41c;A(a)->f92=0;A(a)->f96=0;A(a)->f104=0;A(a)->f108=0;}
 done:;
}
void func_0c1992b6(struct LinkedActor *a){table_0c258460[a->b4](a);}
