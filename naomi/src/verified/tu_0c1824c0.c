#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c255708[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c255724[])(struct LinkedActor *);
extern float table_0c255718[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c1824f2(struct LinkedActor *);
struct LinkedActor *func_0c1824c0(struct LinkedActor *parent)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))!=0){a->p16=func_0c1824f2;a->p24=parent;a->b1=parent->b1;a->w38=0x3603;}
 return a;
}
void func_0c1824f2(struct LinkedActor *a){table_0c255708[a->b4](a,a->p24);}
void func_0c182506(struct LinkedActor *a,struct LinkedActor *owner)
{
 short dx;
 float speed;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=8;a->b33=0;
 a->pad11[0]=66;a->pad11[1]=66;A(a)->b1a1=51;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 A(a)->w1ac|=0x200;
 *(int *)&A(owner)->sub2a4.b20=4;
 a->wcc.pointer_value=0;A(a)->b13e=A(a)->b13f=32;
 dx=-72;if(a->sdc.w130)dx=72;
 a->f52=owner->f52+dx*1.66666663f;
 a->f56=owner->f56+137.142853f;
 speed=table_0c255718[a->b1a3];
 if(a->sdc.w130)speed=-speed;
 a->f92=speed;
 a->f104=a->f96=a->f108=0.0f;
 func_0c02a0c4(a,23,5);
}
void func_0c182612(struct LinkedActor *a,struct LinkedActor *owner)
{
 ((int *)owner)[0x2b8/4]=4;
 table_0c255724[(unsigned char)a->b5](a);
}
