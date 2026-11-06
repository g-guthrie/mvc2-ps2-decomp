#include "objects.h"
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c03f004(struct Actor *,struct Actor *);
extern void func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c04b02a(struct Actor *);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c025762(void);
#pragma inline(one)
static float one(void){return 1.0f;}
void func_0c12e228(struct Actor *p,struct Actor *target);
void func_0c12e1a0(struct Actor *a,struct Actor *target)
{
 struct LinkedActorVec3 position;
 func_0c025900(a,6,6);
 position=*(struct LinkedActorVec3 *)((char *)a+52);
 func_0c03f004(a,target);
 if((int)a->f52!=(int)position.x||(int)a->f56!=(int)position.y){
  float two=one();two+=two;
  a->f52=position.x+(a->f52-position.x)/two;
  a->f56=position.y+(a->f56-position.y)/two;
  a->b142=8;
 }
}
void func_0c12e228(struct Actor *p,struct Actor *target) { p->f52 += p->f92; p->f92 += p->f104; p->f56 += p->f96; p->f96 += p->f108; }
void func_0c12e262(struct Actor *a,struct Actor *target)
{
 struct LinkedActorVec3 position;
 struct ActorSubControlBytes *c=(struct ActorSubControlBytes *)&a->sub2a4;
 a->b141=0;
 c->b12=1;
 func_0c03edcc(a,target);
 target->p1b4=a;target->b1a1=38;
 func_0c04b02a(a);
 func_0c0346da(a,5);
 position.x=-80.0f;position.y=17.142857f;
 func_0c1cea66(a,&position,2);
}
void func_0c12e2be(struct Actor *a,struct Actor *target)
{
 a->b141=10;
 func_0c0346da(a,5);
 func_0c025762();
 func_0c12e228(a,target);
}
