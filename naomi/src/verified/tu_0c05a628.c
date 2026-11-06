#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c025900(struct Actor *,char,char);
extern char dat_0c23f930[][2];
void func_0c05a628(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 struct Actor *child;
 int zero;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){
 a->b7++;a->f92=6.66666651f;a->f104=-0.1041666642f;a->f96=19.2857132f;a->f108=-0.66964281f;
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,15,33);return;
 }
 if(a->b141){
 zero=0;a->b141=zero;
 func_0c025900(a,zero,zero);
 child=a->p1c8;
 child->b1f6=dat_0c23f930[*(char *)&sub->b2][0];
 child->b1a1=dat_0c23f930[*(char *)&sub->b2][1];
 a->b1a1=dat_0c23f930[*(char *)&sub->b2][1];
 a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
 a->b205=(*(char *)&sub->b2)/2+32;
 }
}
