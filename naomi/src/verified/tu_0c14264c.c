#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f87c[])(struct LinkedActor *,struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,char);
void func_0c14267e(struct LinkedActor *);
struct LinkedActor *func_0c14264c(struct LinkedActor *source,struct LinkedActor *owner)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,1))){a->w38=0xe00;a->p16=func_0c14267e;a->p20=source;a->p24=owner;}return a;
}
void func_0c14267e(struct LinkedActor *a){table_0c24f87c[a->b4](a,a->p24);}
void func_0c142692(struct LinkedActor *record,struct LinkedActor *owner)
{
 struct LinkedActor *a=record;struct ActorSub2a4 *sub=&((struct Actor *)owner)->sub2a4;int zero;
 record=a->p20;a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b36=owner->b36;a->b49=-8;a->pad11[0]=66;a->pad11[1]=66;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&record->f52;
 ((struct MeActor *)a)->blk_dc.b13e=32;((struct MeActor *)a)->blk_dc.b13f=32;zero=0;
 if(!func_0c028642(a)){a->b4=2;a->sdc.b12c=zero;sub->b0=1;return;}
 ((struct Actor *)a)->b1a1=65;((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c037d0c(a);func_0c02a0c4(a,23,20);
}
