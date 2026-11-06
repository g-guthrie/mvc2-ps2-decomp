/* Copy an actor's render state, place the child from a directional offset table,
 * and select the corresponding animation. */
#include "objects.h"
extern short *dat_0c2583d0[];
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern signed char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c198764(struct LinkedActor *a,struct LinkedActor *owner){
 int variant,selector;short *point;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 owner=a->p20;a->b4++;a->b36=owner->b36;a->b49=owner->b49-4;
 selector=(unsigned char)a->b33;variant=(selector&128)>>5;
 point=dat_0c2583d0[a->b35];
 point+=(selector&127)*4+(variant>>1);
 variant+=31;
 a->f52=owner->f52+*point++*1.66666663f;
 a->f56=owner->f56+*point*2.1428571f;
 func_0c02a0c4(a,23,variant);
}
void func_0c19882a(struct LinkedActor *a){
 if(func_0c02a026(a)<0){a->b4=2;a->sdc.b12c=0;}
}
void func_0c19884a(struct LinkedActor *a){func_0c037688(a);}
