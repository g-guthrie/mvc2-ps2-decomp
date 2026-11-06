#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f6dc[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,char);
void func_0c140f30(struct LinkedActor *);
struct LinkedActor *func_0c140f04(struct LinkedActor *owner)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c140f30;a->w38=0xc02;a->p24=owner;}return a;
}
void func_0c140f30(struct LinkedActor *a){table_0c24f6dc[a->b4](a,a->p24);}
void func_0c140f44(struct LinkedActor *a,struct LinkedActor *owner)
{
 float offset;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->pad11[0]=70;a->pad11[1]=64;offset=-83.33333f;if(((struct Actor *)owner)->b1d2)offset=83.33333f;a->f52=owner->f52+offset;a->f56=owner->f56+90.0f;
 ((struct Actor *)a)->b1a1=99;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;func_0c037d0c(a);func_0c02a0c4(a,23,23);
}
