#include "objects.h"
#define A(a) ((struct Actor *)(a))
/* Four-byte spawn offset rows at 0x0c250a34, indexed by the actor's direction byte. */
struct SpawnOffset_250a34 { short x, y; };
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct SpawnOffset_250a34 table_0c250a34[];
extern int table_0c2509b4[];
extern void (*table_0c250ab4[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern void func_0c02894c(struct LinkedActor *,int);
extern int func_0c02850e(struct LinkedActor *);
void func_0c159d60(struct LinkedActor *),func_0c159efa(struct LinkedActor *);
struct LinkedActor *func_0c159d24(struct LinkedActor *owner,unsigned char mode,unsigned char dir)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))!=0){a->p16=func_0c159d60;a->p24=owner;a->b32=mode;a->b35=dir;}
 return a;
}
void func_0c159d60(struct LinkedActor *a){table_0c250ab4[a->b4](a);}
void func_0c159d72(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->b4++;a->w38=0x1902;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=8;
 a->sdc.b12c=1;a->sdc.w130=0;
 A(a)->b13c=16;((unsigned char *)a)[0x13d]=16;A(a)->b13e=16;A(a)->b13f=16;
 a->s28=20;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 if(!owner->sdc.w130)a->f52+=table_0c250a34[a->b35].x*1.66666663f;
 else a->f52-=table_0c250a34[a->b35].x*1.66666663f;
 a->f56+=table_0c250a34[a->b35].y*2.1428571f;
 if(owner->sdc.w130)a->b35=(32-a->b35)&31;
 a->b34=a->b35;
 A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=49;
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,2);
 func_0c159efa(a);
}
void func_0c159efa(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(owner->b4>=2)goto done;
 func_0c02894c(a,0x708);
 if(a->s28)a->s28--;
 else if(!func_0c02850e(a)){done:a->b4++;a->sdc.b12c=0;return;}

 A(a)->i72=table_0c2509b4[a->b34];
 func_0c037d0c(a);
}
void func_0c159f5e(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c159f6c(struct LinkedActor *a){func_0c037688(a);}
