/* Linked actor spawner and handlers sharing two literal pools around 0x0c159ae0. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2509a4[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *),func_0c037d0c(struct LinkedActor *);
void func_0c159b0e(struct LinkedActor *),func_0c159bc8(struct LinkedActor *);
struct LinkedActor *func_0c159ae0(struct LinkedActor *owner,unsigned char mode)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c159b0e;a->p24=owner;a->b32=mode;}return a;
}
void func_0c159b0e(struct LinkedActor *a){table_0c2509a4[a->b4](a);}
void func_0c159b20(struct LinkedActor *record)
{
 struct LinkedActor *a=record;record=a->p24;
 a->b4++;a->w38=0x1901;a->sdc=record->sdc;a->sdc.b12c=1;a->b2=record->b2;a->b1=record->b1;
 a->v80.x=record->v80.x;a->v80.y=record->v80.y;a->b1a3=record->b1a3;a->b1a4=record->b1a4;a->b48=record->b48;a->v80=record->v80;
 a->b36=record->b36;
 a->b36=9;
 *(unsigned char *)((char *)a+0x19c)=66;
 ((struct Actor *)a)->b19d=66;
 {
 unsigned int zero=0;
 ((struct Actor *)a)->b1a1=a->b32+55;
 if(1){((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;((struct Actor *)a)->p1c4=zero;}
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,0);
 }
 func_0c159bc8(a);
}
void func_0c159bc8(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(owner->b4>=2){a->b4++;a->sdc.b12c=0;return;}
 a->f52=owner->f52+(!((struct Actor *)owner)->w130 ? -96.666664124f : 96.666664124f);
 a->f56=owner->f56+180.0f;
 if(!((struct Actor *)owner)->b141){a->b4++;a->v80.x=1.0f;func_0c02a0c4(a,23,1);return;}
 func_0c02a026(a);
 if(((struct Actor *)a)->b141){
  if(a->b32)a->v80.x=2.0f;
  else a->v80.x=1.0f;
 }
 if(a->b32&&((struct Actor *)a)->b140){
  ((struct Actor *)a)->b140=0;
  ((struct Actor *)a)->b1a1=56;
  ((struct Actor *)a)->w1ac=0;
  ((struct Actor *)a)->b19e=0;
  ((struct Actor *)a)->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
 }
 func_0c037d0c(a);
}
void func_0c159ce6(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0){a->b4=a->b4+1;a->sdc.b12c=0;}
}
void func_0c159d08(struct LinkedActor *a){func_0c037688(a);}
