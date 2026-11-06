#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c03489c(struct Actor *);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void (*table_0c2497a0[])(struct Actor *);
void func_0c0e80d8(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;func_0c02a0c4(a,1,5);}
}
void func_0c0e8148(struct Actor *a)
{
 if(func_0c02a026(a)<0){if(a->b1f9==2)func_0c0438de(a);else func_0c0437b8(a);}
}
void func_0c0e817c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *parent;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b14b){
  a->b14b=0;position.x=53.333332062f;position.y=120.0f;position.z=0.0f;
  func_0c1d4610(a,&position);a->b1a0=10;
 }
 if(a->b141){
  a->b141=0;parent=a->p1c8;parent->p1b4=a;parent->b1f6=2;parent->b1a1=37;
  func_0c03489c(a);
 }
}
void func_0c0e81f8(struct Actor *a){table_0c2497a0[a->b1f7&63](a);}
