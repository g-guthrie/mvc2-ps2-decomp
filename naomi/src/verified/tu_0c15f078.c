#include "objects.h"
struct EffectTrajectory_15f078 { int x_speed,y_speed; short x_offset,y_offset; unsigned char animation,effect,pad14,pad15; };
extern struct EffectTrajectory_15f078 dat_0c250fcc[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,char);
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *);
void func_0c15f194(struct Actor *,struct Actor *);
void func_0c15f078(struct Actor *a, struct Actor *owner)
{
 struct EffectTrajectory_15f078 *entry;
 a->b5=a->b5+1;
 ((struct MeActor *)a)->blk_dc.b13c=16;((struct MeActor *)a)->blk_dc.b13d=16;((struct MeActor *)a)->blk_dc.b13e=16;((struct MeActor *)a)->blk_dc.b13f=16;
 entry=&dat_0c250fcc[a->b32];
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 if(!a->w130){a->f52+=entry->x_offset*1.66666663f;a->f92=entry->x_speed*1.66666663f/65536.0f;}
 else{a->f52+=-(entry->x_offset*1.66666663f);a->f92=-(entry->x_speed*1.66666663f/65536.0f);}
 a->f56+=entry->y_offset*2.1428571f;
 a->f96=entry->y_speed*2.1428571f/65536.0f;
 a->f104=0.0f;a->f108=0.0f;
 *(unsigned char *)((char *)a+0x19c)=68;a->b19d=68;
 a->b1a1=entry->effect;
 a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,entry->animation);
 func_0c15f194(a,owner);
}
void func_0c15f194(struct Actor *a,struct Actor *owner)
{
 func_0c02a026(a);
 if(!a->b141){a->b5=a->b5+1;a->f52+=a->f92;a->f92+=a->f104;}
 func_0c037d0c(a);
}
