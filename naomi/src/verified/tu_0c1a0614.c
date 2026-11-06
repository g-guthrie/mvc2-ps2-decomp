#include "objects.h"
extern float dat_0c2d92e8,dat_0c2d92ec;
extern void func_0c02a684(struct LinkedActor *,int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int);
void func_0c1a0614(struct LinkedActor *a)
{
 struct LinkedActor *parent;
 a->b4++;
 parent=a->p24;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2;
 a->b1=parent->b1;
 a->v80.x=parent->v80.x;
 a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;
 a->b1a4=parent->b1a4;
 a->b48=parent->b48;
 a->v80=parent->v80;
 a->b36=parent->b36;
 a->sdc.b12c=1;
 a->b36=15;
 a->sdc.w130=a->p24->sdc.w130;
 a->f52=a->p24->f52;
 a->f56=a->p24->f56;
 a->f60=a->p24->f60;
 a->f52=a->sdc.w130?dat_0c2d92e8:dat_0c2d92ec;
 a->f52+=a->sdc.w130?176.66666f:-176.66666f;
 a->f56=a->p24->f56+41.666664124f;
 a->f104=0.0f;
 a->f108=0.0f;
 ((struct Actor *)a)->f264=0.0f;
 a->s28=30;
 func_0c02a684(parent,2,2,1);
 func_0c029e70(a,27,12);
}
