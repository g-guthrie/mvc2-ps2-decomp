#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c04b02a(struct Actor *),func_0c034946(struct Actor *,int),func_0c04c010(struct Actor *,struct Actor *,int),func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int),func_0c03edcc(struct Actor *,struct Actor *),func_0c03f004(struct Actor *,struct Actor *);
#define FLOOR(a) (((struct ActorSubEffectParameter *)&(a)->sub2a4)->f4)
void func_0c0d0f5c(struct Actor *a,struct Actor *other)
{
 struct LinkedActorVec3 p;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->f96<0){
  if(FLOOR(a)>a->f56){
   goto z;z: a->f56=FLOOR(a);
   a->s28=96;
   a->f92=0;a->f96=0;a->f104=0;a->f108=0;
   a->f108=-1.875f;
   func_0c02a0c4(a,22,15);
   func_0c02a026(a);
   a->b7++;
   other->p1b4=a;
   other->b1a1=62;
   func_0c04b02a(a);
   func_0c034946(other,1);
   func_0c04c010(other,a,1);
   p.x=-53.3333321f;p.y=34.2857132f;
   func_0c1cea66(a,&p,3);
  }
 }
}
void func_0c0d103a(struct Actor *a,struct Actor *other)
{
 register float old_x,old_y;struct LinkedActorVec3 p;
 if(func_0c02a026(a)<0){a->b7++;((unsigned char *)&a->w150)[0]=33;}
 else if(a->b141>=0){
  if(a->b141>0){a->b141=0;a->f96+=10.714285f;other->p1b4=a;other->b1a1=62;func_0c04b02a(a);func_0c034946(other,1);func_0c04c010(other,a,1);p.x=0;p.y=51.42857f;func_0c1cea66(other,&p,3);}
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 }
 old_x=other->f52;old_y=other->f56;func_0c03edcc(a,other);other->f52=old_x;other->f56=old_y;
}
void func_0c0d1142(struct Actor *a,struct Actor *other)
{
 struct LinkedActorVec3 p;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(FLOOR(a)>a->f56){
  a->f56=FLOOR(a);
  ((unsigned char *)&a->w150)[0]=33;
  a->b15a=-1;
  func_0c03f004(a,other);
  ((unsigned char *)&a->w150)[0]=0;
  a->b15a=-1;
  a->s28=96;
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  func_0c02a0c4(a,22,12);
  func_0c02a026(a);
  a->b7++;
 }
}
