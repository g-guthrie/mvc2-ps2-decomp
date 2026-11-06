#include "objects.h"
extern void func_0c1929b0(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1ce916(struct LinkedActorVec3 *,int,int,int);
extern void func_0c0346da(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0344a0(struct Actor *,int);
void func_0c07cbac(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *child;
 if(!a->b6 && a->b141){a->b6++;func_0c1929b0(a);}
 if(a->b141<0){
 a->b141&=15;
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=1;
 child->b1f9=2;
 func_0c025900(a,0,0);
 child->b1a1=33;
 child->b1d2=a->b1d2;
 position.y=a->f56+105.0f;
 position.x=!a->w130?31.666666031f:-31.666666031f;
 position.x+=a->f52;
 position.z=a->f60;
 func_0c1ce916(&position,(short)a->w130,2,0);
 func_0c0346da(a,1);
 a->f56=a->f41c;
 }
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c07cc76(struct Actor *a)
{
 struct Actor *child;
 if(a->b141){
 a->b141=0;
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=1;
 child->b1f9=2;
 func_0c025900(a,0,0);
 child->b1a1=34;
 child->b1d2=a->b1d2;
 func_0c0344a0(a,32);
 }
 if(func_0c02a026(a)<0)func_0c0438de(a);
}
