#include "objects.h"
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c025762(void);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c249320[])(struct Actor *);
void func_0c0e2b18(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b1a0=10;
 if(!((a->b34<<10)&0x800)){a->w130^=1;a->b1d2^=1;}
 position.x=-80.0f;position.y=171.42855835f;
 func_0c1d4610(a,&position);func_0c048ce6(a);func_0c02a0c4(a,15,2);
}
void func_0c0e2b76(struct Actor *a){func_0c02a0c4(a,15,3);}
void func_0c0e2b7e(struct Actor *a){a->b1ea=1;table_0c249320[a->b1f7&63](a);}
void func_0c0e2b9c(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);}
 else if(a->b141){
  a->b141=0;a->p20c->p1b4=a;a->p20c->b1f6=1;
  a->p20c->b1d2=a->b1d2;a->p20c->b1a1=32;
  func_0c025762();
 }
}
