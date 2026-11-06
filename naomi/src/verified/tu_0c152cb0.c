#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c250534[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c1d53e4(struct LinkedActor *);
void func_0c152d06(struct LinkedActor *);
struct LinkedActor *func_0c152cb0(struct Actor *owner,unsigned char mode)
{
 struct ActorSub2a4 *sub=&owner->sub2a4;struct LinkedActor *a;
 if(sub->b0>=2)return (struct LinkedActor *)0;
 if((a=func_0c0374da(0,1,1))){a->w38=0x1501;a->p16=func_0c152d06;a->p24=(struct LinkedActor *)owner;a->b1=owner->b1;a->b32=mode;sub->b0++;}
 return a;
}
void func_0c152d06(struct LinkedActor *a){table_0c250534[a->b4](a,a->p24);}
void func_0c152d1a(struct LinkedActor *a,struct LinkedActor *owner)
{
 float offset;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad0=1;a->b36=0;((struct Actor *)a)->b1a1=((struct Actor *)owner)->b1fe+48;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=68;a->pad11[1]=68;((struct Actor *)a)->w1ac|=0x200;((struct MeActor *)a)->blk_dc.b13e=48;((struct MeActor *)a)->blk_dc.b13f=48;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 offset=-140.0f;if(((struct Actor *)a)->w130)offset=140.0f;a->f52+=offset;func_0c02a0c4(a,23,4);func_0c1d53e4(a);
}
