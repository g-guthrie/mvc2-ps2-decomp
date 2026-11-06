#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void (*table_0c258114[])(struct LinkedActor *,struct LinkedActor *,struct ActorSub2a4 *);
void func_0c19795c(struct LinkedActor *a,struct LinkedActor *owner)
{

 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->b36=12;
 ((struct MeActor *)a)->blk_dc.b13c=16;((struct MeActor *)a)->blk_dc.b13d=16;((struct MeActor *)a)->blk_dc.b13e=16;((struct MeActor *)a)->blk_dc.b13f=16;
 a->f52=owner->f52;a->f56=owner->f56;A(a)->f104=-6.66666651f;
 if(a->sdc.w130)A(a)->f104=-A(a)->f104;
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;
 func_0c02a0c4(a,23,19);
}
void func_0c197a14(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *state=&A(owner)->sub2a4;
 if(owner->b1d0==28 || owner->b5 || A(owner)->b1e9!=4 || ((signed char *)state)[4]<0){a->b4=2;a->sdc.b12c=0;return;}
 a->b36=12;table_0c258114[(unsigned char)a->b5](a,owner,state);
}
