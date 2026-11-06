#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c2525cc[])(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,char);
void func_0c16e280(struct LinkedActor *);
struct LinkedActor *func_0c16e24c(struct LinkedActor *owner,int mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,1))){a->w38=0x2b02;a->b32=mode;a->p16=func_0c16e280;a->p24=owner;}
 return a;
}
void func_0c16e280(struct LinkedActor *a){table_0c2525cc[a->b4](a);}
void func_0c16e292(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;unsigned int zero;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad11[0]=66;a->pad11[1]=66;a->b36=owner->b36;a->b49+=a->b32?4:-4;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;a->f56+=137.142853f;zero=0;*(unsigned char *)&a->b33=zero;
 if(!a->b32){
 if((unsigned char)A(owner)->b1e9==3)A(a)->b1a1=56;else{goto alternate_effect;alternate_effect:A(a)->b1a1=65;}
 A(a)->w1ac=zero;*(unsigned char *)&A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;goto render;render:func_0c037d0c(a);
 }
 func_0c02a0c4(a,23,a->b32+18);
}
