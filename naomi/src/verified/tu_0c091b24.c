#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c1d1622(struct LinkedActorVec3 *,int);
extern void func_0c03489c(struct Actor *);
extern void func_0c025762(void);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c091b44(struct Actor *);
void func_0c091b24(struct Actor *a)
{
 a->b6++;
 a->f96=4.28571415f;a->f108=-1.60714281f;
 a->f92=0;a->f104=0;
 func_0c091b44(a);
}
void func_0c091b44(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *child;
 char two;
 if(!a->b7){
 func_0c02a026(a);
 a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){
 a->b7++;
 a->f56=a->f41c;a->b1f9=0;a->f96=0;a->f108=0;
 func_0c02a0c4(a,15,3);
 }
 }else if(func_0c02a026(a)<0){
 two=2;
 child=a->p1c8;
 child->p1b4=a;child->b1f6=two;child->b1d2=a->b1d2;child->w130=a->w130;
 child->b1f9=two;child->b1a1=34;
 position.x=child->f52;position.y=child->f41c;
 func_0c1d1622(&position,child->b2);
 func_0c03489c(a);func_0c025762();
 dat_0c2d9260.b5=two;dat_0c2d9260.b6=1;
 a->b6++;a->b7=0;a->b1f9=two;
 a->f92=5.0f;a->f104=-0.0390625f;a->f96=18.75f;a->f108=-0.8705357f;
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,15,4);
 }
}
