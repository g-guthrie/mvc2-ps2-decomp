/* Exact 0x0c19f34c..0x0c19f448: copy owner graphics, apply a mirrored offset, update the owner bank, and initialize the effect. */
#include "objects.h"
extern void func_0c02a684(struct LinkedActor *,int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c1d53e4(struct LinkedActor *);
void func_0c19f34c(struct LinkedActor *a)
{
 struct LinkedActor *owner;int one;float unity;
 a->b4++;owner=a->p24;a->sdc=owner->sdc;
 one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;
 unity=1.0f;a->b36=owner->b36;a->sdc.b12c=one;a->b36=7;
 ((struct Actor *)a)->f264=unity;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 a->f52+=a->p24->sdc.w130?160.0f:-160.0f;
 a->v80.y=unity;
 func_0c02a684(owner,4,4,1);func_0c029e70(a,27,11);func_0c1d53e4(a);
 ((struct Actor *)a)->b0=one;
}
