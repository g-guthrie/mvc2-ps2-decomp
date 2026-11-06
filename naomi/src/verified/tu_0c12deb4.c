#include "objects.h"
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c04b02a(struct Actor *);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
void func_0c12def8(struct Actor *,struct Actor *);
void func_0c12deb4(struct Actor *a,struct Actor *target)
{
 a->b141=12;
 a->f92=(target->f52-a->f52)/32.0f;
 a->f104=0;
 a->f96=8.5714283f;a->f108=-0.5357143f;
 a->f52-=a->f92*4.0f;
 func_0c12def8(a,target);
}
void func_0c12def8(struct Actor *a,struct Actor *target)
{
 struct LinkedActorVec3 position;
 *(char *)&a->b36=*(char *)&target->b36-1;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){
 a->f56=a->f41c;
 a->f52+=a->f92;
 a->b142=1;
 if(a->b141==12){
 func_0c025900(a,1,1);
 position.x=0;position.y=0;
 func_0c1d4610(a,&position);
 a->b1a0=10;
 func_0c0344a0(a,3);
 }
 }
}
void func_0c12dfa0(struct Actor *a,struct Actor *target)
{
 struct LinkedActorVec3 position;
 struct ActorSub2a4 *sub=&a->sub2a4;
 a->b141=0;
 *(char *)&sub->s12=1;
 func_0c03edcc(a,target);
 target->p1b4=a;target->b1a1=36;
 func_0c04b02a(a);func_0c0344a0(a,3);func_0c0346da(a,2);
 position.x=-80.0f;position.y=17.142857f;
 func_0c1cea66(a,&position,2);
}
