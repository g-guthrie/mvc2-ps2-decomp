#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c043324(struct Actor *);
extern void func_0c03f004(struct Actor *,struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24367c[])(struct Actor *);
void func_0c09cf34(struct Actor *a)
{
 struct LinkedActorVec3 vectors[2];
 
 a->b6++;
 vectors[0]=*(struct LinkedActorVec3 *)((char *)a+52);
 vectors[1]=*(struct LinkedActorVec3 *)((char *)a+52);
 func_0c03f004(a,a->p1c8);
 vectors[0].x=a->f52-vectors[0].x;vectors[0].y=a->f56-vectors[0].y;
 *(struct LinkedActorVec3 *)((char *)a+52)=vectors[1];
 vectors[0].y=vectors[0].y/8.0f;
 if((a->b1f7&63)!=1 && vectors[0].y<0)vectors[0].y=0;
 a->f92=vectors[0].x/8.0f;a->f104=0;
 a->f96=vectors[0].y+2.1428571f;a->f108=-0.5357143f;
}
void func_0c09cfe6(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->b141){a->b6++;a->b141=0;}
}
void func_0c09d042(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *child;
 func_0c02a026(a);
 if(a->b141){
 a->b6++;a->b141=0;
 child=a->p1c8;child->p1b4=a;child->b1f6=1;child->b1f9=2;
 func_0c025900(a,0,0);
 child->b1a1=a->b1f7&1?33:32;
 a->f92=a->b1d2?-5.0f:5.0f;a->f96=12.85714245f;a->f108=-0.80357140303f;
 position.x=-125.0f;position.y=141.428574f;position.z=0;
 func_0c1cea66(a,&position,12);func_0c0346da(a,5);
 }
}
void func_0c09d110(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f96>0)return;
 if(!(a->f56>a->f41c)){
 a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c043324(a);func_0c02a0c4(a,1,5);
 }
}
void func_0c09d192(struct Actor *a)
{
 if(func_0c02a026(a)>=0)return;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);
}
void func_0c09d1c4(struct Actor *a){table_0c24367c[a->b6](a);}
