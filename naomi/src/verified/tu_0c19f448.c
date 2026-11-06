#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c02a684(struct LinkedActor *,int,int,int),func_0c029e70(struct LinkedActor *,int,int),func_0c1d53e4(struct LinkedActor *);
void func_0c19f448(struct LinkedActor *a)
{
 struct LinkedActor *parent;int one;
 a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
 a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;
 a->b36=parent->b36;a->sdc.b12c=one;a->b36=7;A(a)->f264=1.0f;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 a->f52+=a->p24->sdc.w130?160.0f:-160.0f;a->v80.y=1.0f;
 func_0c02a684(parent,3,3,1);func_0c02a684(parent,5,5,1);
 func_0c029e70(a,27,12);func_0c1d53e4(a);a->pad0=one;
}
