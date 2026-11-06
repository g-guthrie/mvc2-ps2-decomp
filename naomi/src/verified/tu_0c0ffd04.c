#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1d1622(struct LinkedActorVec3 *,int),func_0c03489c(struct Actor *),func_0c025762(void),func_0c02a0c4(struct Actor *,int,int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c0ffd04(struct Actor *a)
{
 struct LinkedActorVec3 position;struct Actor *child;int two;
 func_0c02a026(a);
 if(!a->b140){a->f56+=a->f96;a->f96+=a->f108;}
 if(a->f56<a->f41c){
 child=a->p1c8;position.x=child->f52;position.y=child->f41c;func_0c1d1622(&position,child->b2);
 func_0c03489c(a);two=2;dat_0c2d9260.b5=two;dat_0c2d9260.b6=1;
 child->p1b4=a;child->b1f6=two;child->b1a1=33;child->w130=a->w130;child->b1d2=a->b1d2;func_0c025762();
 a->b7++;a->f56=a->f41c;a->f92=4.16666651f;a->f96=12.85714245f;a->f104=0.0f;a->f108=-0.80357140303f;
 if(a->b1d2)a->f92=-a->f92;func_0c02a0c4(a,15,4);
 }
}
