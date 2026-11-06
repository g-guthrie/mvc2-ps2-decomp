#include "objects.h"
extern struct Actor dat_0c2d9260;
extern void func_0c029e70(struct LinkedActor *,int,int);
void func_0c19fec0(struct LinkedActor *a)
{
 struct LinkedActor *owner;int one;
 struct Actor *bounds;
 owner=a->p24;a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b36=9;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 if(!a->p24->b1a3){a->f52+=a->sdc.w130?186.66666f:-186.66666f;}
 else {a->f52+=a->sdc.w130?373.333313f:-373.333313f;}
 bounds=&dat_0c2d9260;
 if(a->sdc.w130){float edge=bounds->f140;if(a->f52>edge)a->f52=edge-80.0f;}
 else {float edge=bounds->f136;if(a->f52<edge)a->f52=edge+80.0f;}
 a->s28=40;func_0c029e70(a,27,4);
}
