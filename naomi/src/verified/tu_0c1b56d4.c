/* Owner-driven animation effect allocation, initialization, update, and cleanup. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25b0f0[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c02a18c(struct LinkedActor *,int,int,int),func_0c037688(struct LinkedActor *);
void func_0c1b5708(struct LinkedActor *),func_0c1b5786(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1b56d4(struct LinkedActor *owner,int mode){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,1))){a->w38=0x2b05;a->b32=mode;a->p16=func_0c1b5708;a->p24=owner;}return a;
}
void func_0c1b5708(struct LinkedActor *a){table_0c25b0f0[a->b4](a,a->p24);}
void func_0c1b571c(struct LinkedActor *a,struct LinkedActor *owner){
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=0;a->sdc.w130=owner->sdc.w130;a->b36=12;func_0c1b5786(a,owner);
}
void func_0c1b5786(struct LinkedActor *a,struct LinkedActor *owner){
 a->sdc.b12c=0;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 a->sdc.w130=((short *)owner)[0x130/2];
 if((unsigned char)owner->b5!=1)a->b4=2;
 if((unsigned char)((struct Actor *)owner)->b159!=15)a->b4=2;
 if(owner->sdc.b141 && a->b4!=2){a->sdc.b12c=1;func_0c02a18c(a,23,(signed char)a->b32+24,owner->sdc.b141-1);}
}
void func_0c1b5802(struct LinkedActor *a){func_0c037688(a);}
