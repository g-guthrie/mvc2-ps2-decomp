#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct ActorSub2a4 *dat_0c2fb3c4;
extern union LinkedActorWcc *dat_0c2fb3c0;
extern void (*table_0c2521c8[])(struct LinkedActor *),(*table_0c2521d8[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c16a746(struct LinkedActor *);
struct LinkedActor *func_0c16a708(struct LinkedActor *owner,unsigned char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c16a746;a->p24=owner;a->b32=mode;a->w38=0x2602;owner->p20=a;}
 return a;
}
void func_0c16a746(struct LinkedActor *a)
{
 dat_0c2fb3c4=&A(a->p24)->sub2a4;dat_0c2fb3c0=&a->wcc;A(a)->b19f=0;table_0c2521c8[a->b4](a);
}
void func_0c16a772(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->f52=a->p24->f52;a->f56=a->p24->f56;table_0c2521d8[a->b32](a);
}
void func_0c16a802(struct LinkedActor *a)
{
 a->pad11[0]=66;a->pad11[1]=66;dat_0c2fb3c0->short_value=a->p24->sdc.w158.short_value;a->b36=0;
 a->f52+=A(a->p24)->b1d2?120.0f:-120.0f;func_0c02a0c4(a,23,5);
}
void func_0c16a84c(struct LinkedActor *a){dat_0c2fb3c0->short_value=a->p24->sdc.w158.short_value;a->b36=0;func_0c02a0c4(a,21,32);}
