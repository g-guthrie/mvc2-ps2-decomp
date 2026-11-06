#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c253ca4[])(struct LinkedActor *,struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c17cedc(struct LinkedActor *);
struct LinkedActor *func_0c17ceb0(struct LinkedActor *owner)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c17cedc;a->p24=owner;a->w38=0x3404;}return a;
}
void func_0c17cedc(struct LinkedActor *a){struct LinkedActor *q=a;table_0c253ca4[q->b4](q,q->p24);}
void func_0c17cef0(struct LinkedActor *a,struct LinkedActor *owner)
{
 unsigned int zero;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad11[0]=66;a->pad11[1]=68;A(a)->f92=211.6666565f;a->f96=240.0f;
 if(!a->sdc.w130)A(a)->f92=-A(a)->f92;
 a->b49=-1;zero=0;A(a)->b1a1=55;A(a)->w1ac=zero;*(unsigned char *)&A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,23,1);
 a->f52=owner->f52+A(a)->f92;a->f56=owner->f56+a->f96;
}
