#include "objects.h"
struct EffectTrajectory_1458a0 {int x_speed,y_speed;short x_offset,y_offset;char draw_mode,pad,animation,effect;};
extern struct EffectTrajectory_1458a0 dat_0c24fb34[];
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24fb44[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c037688(struct LinkedActor *);
extern void func_0c19d034(struct Actor *,struct Actor *,unsigned char),func_0c0344a0(struct Actor *,int),func_0c037d0c(struct Actor *);
void func_0c1458ce(struct LinkedActor *),func_0c145a80(struct Actor *);
struct LinkedActor *func_0c1458a0(struct LinkedActor *owner,unsigned char mode)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c1458ce;a->p24=owner;a->b32=mode;}return a;
}
void func_0c1458ce(struct LinkedActor *a){table_0c24fb44[a->b4](a);}
void func_0c1458e0(struct LinkedActor *record)
{
 struct LinkedActor *a=record;struct EffectTrajectory_1458a0 *entry;
 record=a->p24;a->b4++;a->w38=0x1002;a->sdc=record->sdc;a->sdc.b12c=1;a->b2=record->b2;a->b1=record->b1;a->v80.x=record->v80.x;a->v80.y=record->v80.y;a->b1a3=record->b1a3;a->b1a4=record->b1a4;a->b48=record->b48;a->v80=record->v80;a->b36=record->b36;
 ((struct MeActor *)a)->blk_dc.b13c=32;((struct MeActor *)a)->blk_dc.b13d=32;((struct MeActor *)a)->blk_dc.b13e=32;((struct MeActor *)a)->blk_dc.b13f=32;
 entry=&dat_0c24fb34[a->b32];a->b36=entry->draw_mode;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&record->f52;
 if(!((struct Actor *)record)->w130){a->f52+=entry->x_offset*1.66666663f;((struct Actor *)a)->f92=entry->x_speed*1.66666663f/65536.0f;}
 else{a->f52-=entry->x_offset*1.66666663f;((struct Actor *)a)->f92=-(entry->x_speed*1.66666663f/65536.0f);}
 a->f56+=entry->y_offset*2.1428571f;((struct Actor *)a)->f104=0.0f;a->f96=entry->y_speed*2.1428571f/65536.0f;((struct Actor *)a)->f108=0.0f;a->pad11[0]=68;a->pad11[1]=68;
 ((struct Actor *)a)->b1a1=entry->effect;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,23,entry->animation);func_0c145a80((struct Actor *)a);
}
void func_0c145a80(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;unsigned char i;int zero=0;
 if(owner->b4>=2){a->b4++;a->b12c=zero;return;}
 a->i72+=-2048;a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->b19e || a->b19f || !(a->f56>owner->f41c+34.2857132f)){a->b4++;a->b12c=zero;for(i=zero;i<6;i++)func_0c19d034(owner,a,i);func_0c0344a0(owner,39);return;}
 func_0c037d0c(a);
}
void func_0c145b88(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c145b96(struct LinkedActor *a){func_0c037688(a);}
