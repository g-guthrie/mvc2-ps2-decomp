#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c044548(struct Actor *,struct Actor *);
void func_0c059c58(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *target;
 a->w3e4=2;
 a->b3f8=2;
 a->b328=5;
 if(func_0c02a026(a)<0){a->b6=4;func_0c02a0c4(a,15,54);return;}
 if((target=func_0c037d54(a))){
 a->b6++;
 a->b7=0;
 func_0c025900(a,5,5);
 a->b1f7=205;
 position.x=-146.66666f;
 position.y=171.42856f;
 func_0c1d4610(a,&position);
 func_0c02a0c4(a,15,29);
 func_0c044548(a,target);
 }
}
void func_0c059cec(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b7++;func_0c02a0c4(a,15,30);}
}
void func_0c059d16(struct Actor *a)
{
 if(func_0c02a026(a)<0){
 a->b7++;
 a->f92=8.33333302f;
 a->f104=0;
 a->f96=26.7857132f;
 a->f108=-1.33928561211f;
 if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,15,57);
 }
}
