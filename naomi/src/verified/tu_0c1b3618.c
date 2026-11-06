#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c02a026(struct LinkedActor *);
extern void (*table_0c25af78[])(struct LinkedActor *);
void func_0c1b3698(struct LinkedActor *);
void func_0c1b3734(struct LinkedActor *);
struct LinkedActor *func_0c1b3618(struct LinkedActor *parent) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,4,0))!=0) { a->p16=func_0c1b3698; a->p24=parent; a->w38=0x2700; }
 return a;
}
void func_0c1b3644(struct LinkedActor *a) {
 int state=((char *)&((struct Actor *)a->p24)->w150)[1];
 if(state) {
  a->sdc.b12c=1;
  if(a->s28!=state) { func_0c02a0c4(a,23,state); a->s28=state; return; }
  func_0c02a026(a);
 }
 if(((struct Actor *)a->p24)->b0) a->s28=((char *)&((struct Actor *)a->p24)->w150)[1];
}
void func_0c1b3698(struct LinkedActor *a) { table_0c25af78[a->b4](a); }
void func_0c1b36aa(struct LinkedActor *a) {
 a->b4++;
 a->sdc=a->p24->sdc; a->sdc.b12c=1;
 a->b2=a->p24->b2; a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x; a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3; a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48; a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 a->sdc.b12c=0; a->b36=0; a->s28=0;
 a->f52=a->p24->f52; a->f56=a->p24->f56;
 func_0c1b3734(a);
}
void func_0c1b3734(struct LinkedActor *a) {
 a->sdc.b12c=0;
 if(a->p24->sdc.b12c) {
  a->f52=a->p24->f52; a->f56=a->p24->f56;
  a->sdc.w130=a->p24->sdc.w130;
  func_0c1b3644(a);
 }
}
