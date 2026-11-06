#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern struct ActorSub2a4 *dat_0c2fb328;
extern unsigned int *dat_0c2fb324;
extern struct ActorMotionFloat2 dat_0c24e9e4[];
extern void (*table_0c24e9d4[])(struct LinkedActor *);
void func_0c139468(struct LinkedActor *);
struct LinkedActor *func_0c13941c(struct LinkedActor *owner)
{
 struct LinkedActor *a;int i;
 for(i=0;i<4;i++){if((a=func_0c0374da(0,1,0))){a->p16=func_0c139468;a->p24=owner;a->b32=i;a->w38=0x504;}}
 return a;
}
void func_0c139468(struct LinkedActor *a)
{
 dat_0c2fb328=&((struct Actor *)a->p24)->sub2a4;dat_0c2fb324=&a->wcc.dword_value;table_0c24e9d4[a->b4](a);
}
void func_0c13948e(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->sdc.w130=0;a->b36=0;a->pad11[0]=66;a->pad11[1]=66;a->f52=a->p24->f52;a->f56=a->p24->f56;
 ((struct MeActor *)a)->blk_dc.b13c=56;((struct MeActor *)a)->blk_dc.b13d=56;((struct MeActor *)a)->blk_dc.b13e=80;((struct MeActor *)a)->blk_dc.b13f=80;
 a->s28=16;a->s30=3;((struct Actor *)a)->f104=0.0f;((struct Actor *)a)->f108=0.0f;
 ((struct Actor *)a)->f92=dat_0c24e9e4[a->b32].x;a->f96=dat_0c24e9e4[a->b32].y;func_0c02a0c4(a,21,a->b32+29);
}
