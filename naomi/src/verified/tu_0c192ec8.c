#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c257b24[])(struct LinkedActor *,struct LinkedActor *);
extern int func_0c02849a(void);
extern void func_0c029e70(struct LinkedActor *,int,int);
void func_0c192efc(struct LinkedActor *);
struct LinkedActor *func_0c192ec8(struct LinkedActor *owner,char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c192efc;a->p24=owner;a->b32=mode;a->w38=0x0a00;}
 return a;
}
void func_0c192efc(struct LinkedActor *a){table_0c257b24[a->b4](a,a->p24);}
void func_0c192f10(register struct LinkedActor *a,register struct LinkedActor *owner)
{
 register short dx;short dy;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;a->b49=-1;
 dx=0;dy=0;
 if(a->b32){dx=15;if(a->sdc.w130)dx=-15;dx+=func_0c02849a()&7;dy=(func_0c02849a()&7)+37;*(short *)((unsigned char *)a+0x12e)-=3;}
 a->f52=owner->f52+dx*1.66666663f;a->f56=owner->f56+dy*2.1428571f;
 A(a)->i204=(unsigned short)owner->sdc.w158.short_value;func_0c029e70(a,27,(signed char)a->b32+26);
}
