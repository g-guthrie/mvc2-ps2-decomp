#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c04b02a(struct Actor *);
extern void func_0c04bad8(struct Actor *,struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c1d357a(struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c03489c(struct Actor *);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
void func_0c084ef8(struct Actor *a,void *context)
{
 struct LinkedActorVec3 position;
 struct Actor *child;
 func_0c02a026(a);
 if(!a->b141){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}
 if(a->f56>a->f41c){
 if(!a->b32 && !(a->f56>a->f41c+274.28571f)){a->b32++;func_0c0344a0(a,5);}
 }else{
 a->f56=a->f41c;a->b7++;a->s28=16;
 child=a->p1c8;child->p1b4=a;child->b1a1=37;
 func_0c04b02a(a);func_0c04bad8(child,a);
 dat_0c2d9260.b5=3;dat_0c2d9260.b6=1;
 position.x=child->f52;position.y=child->f41c;
 func_0c1d357a(&position,1);
 func_0c0346da(a,74);func_0c03489c(a);
 }
}
void func_0c084fe6(struct Actor *a,void *context)
{
 struct LinkedActorVec3 position;
 int zero=0;
 a->b7++;a->f92=0;a->f104=0;
 a->f96=-8.5714283f;a->f108=-2.1428571f;
 a->b32=zero;
 position.x=-0.0f;position.y=57.85714f;
 func_0c1cea66(a,&position,zero);
 func_0c0346da(a,35);
 func_0c084ef8(a,context);
}
