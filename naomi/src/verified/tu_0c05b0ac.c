#include "objects.h"
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c05b0ac(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *child;
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(*(unsigned short *)sub&0x400){
 a->w130=a->w130^1;
 a->b1d2=*(unsigned char *)&a->w130;
 child=a->p1c8;
 child->w130=child->w130^1;
 child->b1d2=*(unsigned char *)&child->w130;
 }
 a->b1a0=10;
 a->b7=0;
 a->b6=0;
 func_0c025900(a,5,5);
 position.x=-146.66666f;
 position.y=171.42856f;
 func_0c1d4610(a,&position);
 func_0c048ce6(a);
 func_0c02a0c4(a,15,0);
}
void func_0c05b132(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b1a0=10;
 a->b7=0;
 a->b6=0;
 func_0c025900(a,5,5);
 position.x=-160.0f;
 position.y=171.42856f;
 func_0c1d4610(a,&position);
 func_0c048ce6(a);
 func_0c02a0c4(a,15,1);
}
void func_0c05b17e(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b1a0=10;
 a->b7=0;
 a->b6=0;
 func_0c025900(a,5,5);
 position.x=-173.33333f;
 position.y=137.142853f;
 func_0c1d4610(a,&position);
 func_0c048ce6(a);
 func_0c02a0c4(a,15,2);
}
