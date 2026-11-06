/* Owner-following linked actor states: drift, settle and expire. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern void (*table_0c251f9c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1673ec(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c1671f4(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;
 if(!a->b5){
  func_0c02a026(a);
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(func_0c028642(a)){
   if(A(a)->b19e){a->b5++;func_0c02a0c4(a,23,12);}
   func_0c037d0c(a);return;
  }
 }else if(func_0c02a026(a)>=0)return;
 func_0c1673ec(a,owner);
}
void func_0c167298(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;table_0c251f9c[(unsigned char)a->b5](a,owner);
}
void func_0c1672c8(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->b32==7&&A(owner)->f41c>a->f56)goto hit;
 if(A(a)->b19e||A(a)->b19f||--a->s28==0){hit:
  a->b5++;
  a->f92/=4.0f;a->f104/=4.0f;a->f96/=4.0f;a->f108/=4.0f;
  if(a->b32==6)func_0c02a0c4(a,23,29);else func_0c02a0c4(a,23,31);
 }
 func_0c037d0c(a);
}
void func_0c167392(struct LinkedActor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0)func_0c037688(a);
}
void func_0c1673ec(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c1673fa(struct LinkedActor *a){func_0c037688(a);}
