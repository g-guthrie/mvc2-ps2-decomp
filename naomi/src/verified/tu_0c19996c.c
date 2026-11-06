#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern short table_0c2584dc[][3];
extern void (*table_0c258548[])(struct LinkedActor *);
extern void (*table_0c258558[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1999c8(struct LinkedActor *);
void func_0c199aae(struct LinkedActor *);
struct LinkedActor *func_0c19996c(struct LinkedActor *owner,char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->p16=func_0c1999c8;a->p24=owner;a->b32=mode;}return a;}
struct LinkedActor *func_0c19999a(struct LinkedActor *owner,char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,4,0))){a->p16=func_0c1999c8;a->p24=owner;a->b32=mode;}return a;}
void func_0c1999c8(struct LinkedActor *a){table_0c258548[a->b4](a);}
void func_0c1999da(struct LinkedActor *a)
{
 struct LinkedActor *owner;short *entry;
 owner=a->p24;a->b4++;a->w38=0x1000;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 entry=table_0c2584dc[a->b32];a->b36=((char *)entry)[4];
 if(!a->sdc.w130)a->f52=owner->f52+entry[0]*1.66666663f;
 else a->f52=owner->f52-entry[0]*1.66666663f;
 a->f56=owner->f56+entry[1]*2.1428571f;
 func_0c029e70(a,27,((char *)entry)[5]);func_0c199aae(a);
}
void func_0c199aae(struct LinkedActor *a){table_0c258558[a->b32](a,a->p24);}
