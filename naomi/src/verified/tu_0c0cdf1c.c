#include "objects.h"
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern char func_0c02a026(struct Actor *);
extern void func_0c1d1622(struct LinkedActorVec3 *,int),func_0c03489c(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c025900(struct Actor *,char,char);
void func_0c0cdf1c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(!a->b6){
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
  if(!(a->f56>a->f41c)){
   a->b6++;a->f56=a->f41c;position.x=a->f52;position.y=a->f56;position.z=a->f60;
   position.x+=a->b1d2?13.33333302f:-13.33333302f;func_0c1d1622(&position,a->p1c8->b2);
   dat_0c2d9260.b5=2;dat_0c2d9260.b6=1;func_0c03489c(a->p1c8);func_0c02a0c4(a,15,5);
  }
 }else{
  if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
  if(a->b141){struct Actor *other;a->b141=0;other=a->p1c8;other->p1b4=a;other->b1f6=1;other->b1f9=2;func_0c025900(a,0,0);other->b1a1=36;other->b1d2=a->b1d2;}
 }
}
