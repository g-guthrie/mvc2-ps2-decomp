#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c029e70(struct LinkedActor *,int,int);
void func_0c19f1d0(struct LinkedActor *a)
{
 struct LinkedActor *parent;int one;
 a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
 a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
 a->sdc.b12c=one;a->b36=15;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 a->f52+=a->p24->sdc.w130?-175.0f:175.0f;
 a->f56-=17.142857f;a->s28=120;func_0c029e70(a,27,10);
}
void func_0c19f28c(struct LinkedActor *a)
{
 struct LinkedActor *parent;int one;
 a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
 a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
 a->sdc.b12c=one;a->b36=0;A(a)->f264=1.0f;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 a->v80.x=0.800000012f;a->v80.y=0.800000012f;
 func_0c029e70(a,27,14);
}
