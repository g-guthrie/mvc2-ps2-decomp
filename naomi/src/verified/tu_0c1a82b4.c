#include "objects.h"
struct ChildOffset6 { short x,y; char flag,step; };
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c029f0e(struct LinkedActor *,unsigned char,unsigned char,int);
extern unsigned char dat_0c25948c[];
extern struct ChildOffset6 dat_0c2593f0[];
extern void (*table_0c2594dc[])(struct LinkedActor *);
extern void (*table_0c2594ec[])(struct LinkedActor *);
void func_0c1a82e2(struct LinkedActor *);
void func_0c1a83d2(struct LinkedActor *);
struct LinkedActor *func_0c1a82b4(struct LinkedActor *parent,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) { a->p16=func_0c1a82e2; a->p24=parent; a->b32=selector; }
 return a;
}
void func_0c1a82e2(struct LinkedActor *a) { table_0c2594dc[a->b4](a); }
void func_0c1a82f4(struct LinkedActor *a) {
 struct LinkedActor *parent;
 struct ChildOffset6 *offset;
 parent=a->p24;
 a->b4++;
 a->w38=0x1801;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 a->sdc.b12c=0; ((struct Actor *)a)->f264=0.0f;
 a->s28=dat_0c25948c[a->b32];
 offset=&dat_0c2593f0[a->b32];
 a->b36=7; a->b49=offset->flag;
 a->f52=parent->f52+offset->x*1.66666663f;
 a->f56=parent->f56+offset->y*2.1428571f;
 func_0c029f0e(a,27,offset->step,1);
 func_0c1a83d2(a);
}
void func_0c1a83d2(struct LinkedActor *a) {
 struct LinkedActor *parent=a->p24;
 if(parent->b4>0 || parent->b6>2) { a->b4++; a->sdc.b12c=0; return; }
 table_0c2594ec[(unsigned char)a->b5](a);
}
