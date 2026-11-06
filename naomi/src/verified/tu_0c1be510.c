#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern void func_0c1d53e4(struct LinkedActor *);
extern void (*table_0c25bf14[])(struct LinkedActor *,struct LinkedActor *);
extern float dat_0c25bf24[];
void func_0c1be544(struct LinkedActor *);
struct LinkedActor *func_0c1be510(struct LinkedActor *parent,int selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) { a->p16=func_0c1be544; a->p24=parent; a->w38=0x3a00; a->b32=selector; }
 return a;
}
void func_0c1be544(struct LinkedActor *a) { table_0c25bf14[a->b4](a,a->p24); }
void func_0c1be558(struct LinkedActor *a,struct LinkedActor *parent) {
 int offset,speed;
 float *pair;
 a->b4++;
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 ((struct Actor *)a)->b0=1; a->b36=8;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&parent->f52;
 pair=&dat_0c25bf24[a->b32*2];
 offset=(int)pair[0];
 speed=(int)pair[1];
 if(a->sdc.w130) { offset=-offset; speed=-speed; }
 a->f52+=offset; a->f92=speed;
 ((struct MeActor *)a)->blk_dc.b13c=((struct MeActor *)a)->blk_dc.b13d=((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=32;
 a->wcc.dword_value=parent->sdc.w158.bytes[1];
 func_0c029e70(a,27,(char)a->b32);
 if(!a->b32) { ((struct Actor *)a)->b0=1; ((struct Actor *)a)->b149=26; func_0c1d53e4(a); }
}
