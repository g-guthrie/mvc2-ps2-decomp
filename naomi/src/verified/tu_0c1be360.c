#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c02a026(struct LinkedActor *);
extern void func_0c034946(struct LinkedActor *,int);
extern unsigned int func_0c02849a(void);
extern float dat_0c25bed4[],dat_0c25bef4[];
void func_0c1be3aa(struct LinkedActor *a);
struct LinkedActor *func_0c1be360(struct Actor *owner,short selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) { a->p16=func_0c1be3aa; a->b32=selector; a->b33=0; a->p24=(struct LinkedActor *)owner; a->b1=owner->p1b4->b1; a->w38=0x3802; }
 return a;
}
void func_0c1be3aa(struct LinkedActor *a) {
 struct Actor *owner=(struct Actor *)a->p24;
 struct LinkedActor *parent=(struct LinkedActor *)owner->p1b4;
 float offset;
 if(a->b4>=2) { func_0c037688(a); return; }
 if(!a->b4) {
  a->b4++; a->b5=0;
  a->sdc=parent->sdc; a->sdc.b12c=1;
  a->b2=parent->b2; a->b1=parent->b1;
  a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
  a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
  a->b48=parent->b48; a->v80=parent->v80;
  a->b36=parent->b36;
  func_0c02a0c4(a,25,4);
  a->b36=parent->b36; a->b49=-8;
 }
 a->b36=parent->b36; func_0c02a026(a);
 if(a->sdc.b141) func_0c034946(parent,4);
 if(owner->b5!=2 || owner->b1f6!=19 || owner->b6>1) { a->b4++; return; }
 if(!a->b5) {
  offset=dat_0c25bed4[func_0c02849a()&7];
  if(owner->w130) offset=-offset;
  a->f52=owner->f52+offset;
  a->f56=owner->f56+dat_0c25bef4[func_0c02849a()&7];
  a->b5++;
 }
}
