#include "objects.h"
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0432ca(struct Actor *);
extern void (*table_0c23f9e8[])(struct Actor *);
void func_0c05b1f8(struct Actor *a)
{
 struct LinkedActorVec3 position;
 int zero=0;
 a->b7=zero;a->b6=zero;
 a->s28=60;a->s30=zero;
 func_0c025900(a,5,5);
 position.x=-160.0f;position.y=171.42856f;
 func_0c1d4610(a,&position);
 func_0c048ce6(a);
 func_0c02a0c4(a,15,6);
}
void func_0c05b24c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *child;
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(*(unsigned short *)sub&0x800){
 a->w130=a->w130^1;
 a->b1d2=*(unsigned char *)&a->w130;
 child=a->p1c8;
 child->w130=child->w130^1;
 child->b1d2=*(unsigned char *)&child->w130;
 }
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1a0=10;
 a->b7=0;
 a->b6=0;
 func_0c025900(a,5,5);
 position.x=-133.33333f;
 position.y=222.857132f;
 func_0c1d4610(a,&position);
 func_0c048ce6(a);
 func_0c02a0c4(a,15,3);
}
void func_0c05b2e4(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-120.0f;position.y=102.85714f;
 func_0c1d4610(a,&position);
 func_0c048bb0(a,5);
 func_0c02a0c4(a,15,4);
 func_0c0432ca(a);
}
void func_0c05b322(struct Actor *a)
{
 table_0c23f9e8[a->b1f7&63](a);
}
