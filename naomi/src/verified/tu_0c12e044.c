#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern int func_0c0427f2(struct Actor *);
extern int func_0c042780(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c03f004(struct Actor *,struct Actor *);
extern void func_0c191980(struct Actor *,int);
extern void (*dat_0c24de98[])(struct Actor *,struct Actor *);
void func_0c12e044(struct Actor *a)
{
 struct ActorSubControlBytes *c=(struct ActorSubControlBytes *)&a->sub2a4;
 struct Actor *target=a->p1c8;
 if(func_0c02a026(a)<0&&c->b12<=0){a->b19d=-128;a->b1ed=0;func_0c0438de(a);return;}
 if(c->b12>0){
  if(func_0c0427f2(a))a->b142=1;
  target->s25c--;
  if(func_0c042780(target)){c->b12=-1;func_0c02a0c4(a,15,5);}
 }
 dat_0c24de98[a->b141>>1](a,target);
}
void func_0c12e0d0(struct Actor *a,struct Actor *target)
{
 func_0c025900(a,1,1);
 func_0c03edcc(a,target);
}
void func_0c12e0ee(struct Actor *a,struct Actor *target){func_0c03f004(a,target);}
void func_0c12e0f4(struct Actor *a,struct Actor *target)
{
 a->b141=14;
 a->f92=5.0f;a->f104=0;
 a->f96=10.714285f;a->f108=-0.66964281f;
 func_0c191980(a,0);
 target->p1b4=a;target->b1f6=1;target->b1d2=a->b1d2^1;target->b1a1=37;target->b1f9=2;
}
void func_0c12e154(void) {}
