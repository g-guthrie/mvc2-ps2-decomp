/* Directional attachment construction and render/animation initialization. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void (*table_0c257b54[])(struct LinkedActor *,struct LinkedActor *);
void func_0c193490(struct LinkedActor *);
struct LinkedActor *func_0c193440(struct LinkedActor *owner,int mode,int kind){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){
 a->p16=func_0c193490;a->p24=owner;a->w38=0xa03;a->b1=owner->b1;
 a->b33=mode&127;a->b34=mode&128;A(a)->b1a1=kind;
 }
 return a;
}
void func_0c193490(struct LinkedActor *a){table_0c257b54[a->b4](a,a->p24);}
void func_0c1934a4(struct LinkedActor *a,struct LinkedActor *owner){
 int direction,animation;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;A(a)->b19c=66;A(a)->b19d=66;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 direction=-1;if((unsigned char)a->b33&1)direction=1;
 if(a->b34)direction=-1;
 a->s28=direction;a->s30=32;a->b49=a->s28;
 animation=a->b33+3;if(a->b34)animation+=4;
 func_0c02a0c4(a,23,animation);
}
