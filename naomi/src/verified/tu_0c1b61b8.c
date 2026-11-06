#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c029e70(struct LinkedActor *,unsigned char,unsigned char),func_0c0344a0(struct LinkedActor *,int),func_0c037688(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
void func_0c1b61b8(struct LinkedActor *a,struct LinkedActor *owner)
{
 short dx;
 if(!a->b4){
  a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
  a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
  a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
  a->b36=owner->b36;a->f52=owner->f52;a->b49=-4;
  func_0c029e70(a,27,5);func_0c0344a0(a,33);
 }
 a->b36=owner->b36;
 if((unsigned char)owner->b5!=1||!A(owner)->b140)func_0c037688(a);
 else{
 if(owner->sdc.w130)dx=72;else dx=-72;
 a->f52=owner->f52+dx*1.66666663f;
 a->f56=owner->f56+248.57143f;
 func_0c029fc4(a);
 if(dat_0c2d6f84->flags&1)a->sdc.b12c=0;else a->sdc.b12c=1;
 }
}
