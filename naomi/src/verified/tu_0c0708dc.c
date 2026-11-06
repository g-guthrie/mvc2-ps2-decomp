#include "objects.h"
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c240ea4[])(struct Actor *);
extern void (*table_0c240ebc[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern short dat_0c240ecc[];
extern void func_0c03489c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c07098a(struct Actor *);
void func_0c0708dc(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-53.3333321f;position.y=171.42856f;
 func_0c1d4610(a,&position);a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,8);
}
void func_0c070918(struct Actor *a)
{
 a->b1ea=1;table_0c240ea4[a->b1f7&63](a);
}
void func_0c070936(struct Actor *a)
{
 table_0c240ebc[a->b6](a);
}
void func_0c070948(struct Actor *a)
{
 a->b6++;a->s28=0;
 a->f92=16.666666031f;a->f104=-0.41666666f;a->f96=12.85714245f;a->f108=-1.07142854f;
 if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c07098a(a);
}
void func_0c07098a(struct Actor *a)
{
 float displacement;
 short *row;
 func_0c02a026(a);
 if(a->b141==24){a->b6++;a->f56=a->f41c;return;}
 if(a->s28>12){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}
 if(a->b141){
 a->s28=a->b141;a->b141=0;
 displacement=dat_0c240ecc[a->s28/2]*1.66666663f;
 if(!a->b1d2)displacement=-displacement;
 a->f52=a->f52+displacement;
 row=&dat_0c240ecc[a->s28/2];
 displacement=row[1]*2.1428571f;
 a->f56=a->f56-displacement;
 }
}
void func_0c070a96(struct Actor *a)
{
 struct Actor *child;
 int zero;
 if(a->b141){
 zero=0;a->b141=zero;
 child=a->p1c8;
 child->p1b4=a;child->b1f6=2;child->b1a1=32;a->b1f9=3;a->w1e6=zero;
 child->w130=child->b1d2=*(unsigned char *)&a->w130^1;
 func_0c03489c(child);
 }else if(func_0c02a026(a)<0){
 a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 func_0c02a0c4(a,17,0);
 }
}
void func_0c070b1a(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
