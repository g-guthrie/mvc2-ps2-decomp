#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c03489c(struct Actor *,int),func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int),func_0c1d357a(struct LinkedActorVec3 *,int),func_0c0346da(struct Actor *,int),func_0c04b02a(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c058c14(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0){float distance;a->b7++;distance=160.0f;if(a->b1d2)a->f52+=distance;else a->f52-=distance;func_0c02a0c4(a,15,39);return;}
 if(a->b141){struct Actor *child;a->b141=0;dat_0c2d9260.b5=1;dat_0c2d9260.b6=1;func_0c03489c(a,1);child=a->p1c8;child->p1b4=a;a->b1a1=69;child->b1a1=69;
 if(!a->b202){position.x=-160.0f;position.y=0;func_0c1cea66(a,&position,2);}else{position.x=child->f52;position.y=a->f41c;func_0c1d357a(&position,1);func_0c0346da(a,73);}func_0c04b02a(a);}
}
void func_0c058cd6(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0){float distance;a->b7++;distance=160.0f;if(a->b1d2)a->f52+=distance;else a->f52-=distance;func_0c02a0c4(a,15,40);return;}
 if(a->b141){struct Actor *child;a->b141=0;dat_0c2d9260.b5=1;dat_0c2d9260.b6=1;func_0c03489c(a,1);child=a->p1c8;child->p1b4=a;a->b1a1=70;child->b1a1=70;
 if(!a->b202){position.x=-160.0f;position.y=0;func_0c1cea66(a,&position,2);}else{position.x=child->f52;position.y=a->f41c;func_0c1d357a(&position,1);func_0c0346da(a,73);}func_0c04b02a(a);}
}
void func_0c058dc8(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b7++;a->f92=5.83333302f;a->f104=-0.0520833321f;a->f96=31.07143f;a->f108=-1.33928561211f;if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}func_0c02a0c4(a,15,41);}
}
