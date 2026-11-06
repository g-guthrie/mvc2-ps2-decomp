#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c04a9b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c04be40(struct Actor *),func_0c03484c(struct Actor *),func_0c1d1622(struct LinkedActorVec3 *,int),func_0c1b3be8(struct Actor *,int),func_0c04aad4(struct Actor *);
extern char dat_0c2f836c[];
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c23bc34[])(struct Actor *),(*table_0c23bc48[])(struct Actor *);
void func_0c03feee(struct Actor *),func_0c03ff44(struct Actor *),func_0c03fd44(struct Actor *),func_0c040032(struct Actor *);
void func_0c03fcf4(struct Actor *a)
{
 a->b1f4=2;a->b1f5=2;a->b12c=1;func_0c03feee(a);table_0c23bc34[a->b6](a);
}
void func_0c03fd20(struct Actor *a)
{
 a->b6++;a->f92=a->f218;a->f96=a->f21c;a->f104=0;a->f108=-1.4732143f;func_0c03fd44(a);
}
void func_0c03fd44(struct Actor *a)
{
 func_0c04a9b8(a);func_0c02a026(a);
 if(a->s28 && --a->s28<=0)func_0c02a0c4(a,13,34);
 if(a->f96>0)return;
 if(func_0c044e52(a)){func_0c03ff44(a);a->b6++;a->b1f9=3;if(a->f92>0)a->f92=10.0f;else a->f92=-10.0f;a->f104=0;func_0c02a0c4(a,13,13);}
}
void func_0c03fdc8(struct Actor *a){if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,13,34);}}
void func_0c03fe1c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!a->b12c){a->b6++;a->s28=30;return;}
 func_0c02a026(a);if(!(a->f96>0) && func_0c044e52(a))func_0c03ff44(a);
}
void func_0c03fe9c(struct Actor *a)
{
 a->b1ed=2;if(a->b1f1)return;
 if(!a->b411){if(dat_0c2f836c[a->b2]!=1)return;if(--a->s28>0)return;}
 a->b254=9;a->b257=a->b29f;a->b29f=0;a->w2a0=300;func_0c04be40(a);
}
void func_0c03feee(struct Actor *a)
{
 struct MotionGlobal_0c2d9260 *global=&dat_0c2d9260;
 float lower=global->f12+(-460.0f);
 if(a->f52>lower){float upper=global->f12+460.0f;if(upper>a->f52)return;}
 a->b12c=0;
}
void func_0c03ff44(struct Actor *a)
{
 int kind;
 func_0c03484c(a);func_0c1d1622((struct LinkedActorVec3 *)((char *)a+52),a->b2);
 /* Retail samples this flag before the strength comparison. */
 if(a->b12c){}
 kind=a->b207<(unsigned char)5?1:3;
 dat_0c2d9260.b5=kind;dat_0c2d9260.b6=1;a->f96=10.714285f;a->f108=-0.80357140303f;
}
void func_0c03ff94(struct Actor *a)
{
 if(!a->b6){a->b6++;a->s30=(unsigned char)a->b1a3*4+3;a->s28=0;}
 if(--a->s28<0){a->s28=2;if(a->s30){func_0c1b3be8(a,a->s30);if(!--a->s30)a->s28=10;}else func_0c04aad4(a);}
}
void func_0c03fff8(struct Actor *a){table_0c23bc48[a->b6](a);}
void func_0c04000a(struct Actor *a)
{
 a->b6++;a->s28=16;func_0c03484c(a);func_0c1d1622((struct LinkedActorVec3 *)((char *)a+52),a->b2);func_0c040032(a);
}
void func_0c040032(struct Actor *a){if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,13,31);}}
void func_0c04005c(struct Actor *a){if(--a->s28<0){a->b6++;func_0c02a0c4(a,17,0);}}
