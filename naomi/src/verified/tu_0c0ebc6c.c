#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0427f2(struct Actor *),func_0c042780(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c04b02a(struct Actor *);
extern void func_0c025900(struct Actor *,char,char),func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c1ce916(struct LinkedActorVec3 *,int,int,int);
extern void (*table_0c249c28[])(struct Actor *),(*table_0c249c34[])(struct Actor *);

void func_0c0ebc6c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *p;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(a->b141){
  if(a->b141<0){
   struct Actor *child;
   a->b141=0;child=a->p1c8;child->p1b4=a;child->b1a1=74;
   func_0c04b02a(a);
   position.y=a->f56+122.142853f;
   position.x=a->w130?95.0f:-95.0f;position.x+=a->f52;position.z=a->f60;
   func_0c1ce916(&position,(short)a->w130,1,0);
  }else{
   a->b141=0;p=a->p1c8;p->p1b4=a;p->b1f6=1;p->b1f9=0;
   func_0c025900(a,0,0);p->b1a1=36;
  }
 }
}
void func_0c0ebd22(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *p;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(a->b141){
  if(a->b141<0){
   struct Actor *child;
   a->b141=0;child=a->p1c8;child->p1b4=a;child->b1a1=75;
   func_0c04b02a(a);
   position.y=a->f56+122.142853f;
   position.x=a->w130?95.0f:-95.0f;position.x+=a->f52;position.z=a->f60;
   func_0c1ce916(&position,(short)a->w130,1,0);
  }else{
   a->b141=0;p=a->p1c8;p->p1b4=a;p->b1f6=1;p->b1f9=2;
   func_0c025900(a,0,0);p->b1a1=35;
  }
 }
}
void func_0c0ebe02(struct Actor *a)
{
 a->b1ea=1;table_0c249c28[a->b6](a);
}
void func_0c0ebe1c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *p;
 func_0c02a026(a);
 if(func_0c0427f2(a))a->b142=1;
 a->s28--;
 if(a->b14b){
  if(!a->s30&&func_0c042780(a->p1c8))goto advance;
  if(a->s28>0)goto done;
  if(a->s30)goto done;
advance:
  a->s30=1;a->b6++;func_0c02a0c4(a,15,7);goto done;
 }
 if(a->b141){if(a->b141>0){
  a->b141=0;p=a->p1c8;p->b1a1=38;func_0c04b02a(a);
  if(!p->b1d2)p->f52+=-53.3333321f;else p->f52+=53.3333321f;
  p->f56+=-171.42856f;
  position.y=a->f56+122.142853f;
  position.x=a->w130?95.0f:-95.0f;position.x+=a->f52;position.z=a->f60;
  func_0c1ce916(&position,(short)a->w130,1,0);func_0c0346da(a,0);
 }
}
done:
 ;
}
void func_0c0ebf60(struct Actor *a)
{
 struct Actor *p;
 func_0c02a026(a);
 if(a->b141){
  a->b141=0;p=a->p1c8;p->p1b4=a;p->b1f6=1;p->b1f9=0;
  func_0c025900(a,0,0);p->b1a1=32;p->b1d2=a->b1d2;a->b6++;
 }
}
void func_0c0ebfb0(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0ebfd2(struct Actor *a){table_0c249c34[a->b1f7&63](a);}
void func_0c0ebfea(struct Actor *a){func_0c03edcc(a->p1c8,a);}
void func_0c0ebff8(struct Actor *a){func_0c03edcc(a->p1c8,a);}
