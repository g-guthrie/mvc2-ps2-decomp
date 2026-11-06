#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern void (*table_0c2598c8[])(struct LinkedActor *);
extern void (*table_0c2598d8[])(struct LinkedActor *,struct LinkedActor *);
struct MotionRow9cf0 { char count,delta; short flag,x,y; char sequence,step; };
extern struct MotionRow9cf0 dat_0c25968c[];
void func_0c1a9d58(struct LinkedActor *);
void func_0c1a9e42(struct LinkedActor *);
struct LinkedActor *func_0c1a9cf0(struct LinkedActor *parent,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) { a->p16=func_0c1a9d58; a->p24=parent; a->b32=selector; }
 return a;
}
struct LinkedActor *func_0c1a9d1e(struct LinkedActor *parent,int slot,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(slot,3,2))!=0) { a->p16=func_0c1a9d58; a->p24=parent; a->p20=(void *)slot; a->b32=selector; }
 return a;
}
void func_0c1a9d58(struct LinkedActor *a) { table_0c2598c8[a->b4](a); }
void func_0c1a9d6a(struct LinkedActor *a) {
 struct LinkedActor *parent;
 struct MotionRow9cf0 *row;
 a->b4++; a->w38=0x1c00;
 a->sdc.b12c=1;
 parent=a->p24;
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 row=&dat_0c25968c[a->b32];
 if(row->count) { ((struct LinkedActorPrefix12c *)&a->sdc.b12c)->b12d=row->count; ((struct LinkedActorPrefix12c *)&a->sdc.b12c)->w12e+=row->delta; }
 a->b49=row->flag;
 a->f92=row->x*1.66666663f;
 a->f96=-(row->y*2.1428571f);
 func_0c029e70(a,row->sequence,row->step);
 func_0c1a9e42(a);
}
void func_0c1a9e42(struct LinkedActor *a) { table_0c2598d8[a->b32](a,a->p24); }
