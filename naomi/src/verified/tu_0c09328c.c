#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c02849a(void),func_0c043628(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c02a684(struct Actor *,int,int,int),func_0c199414(struct Actor *,int,int),func_0c0344a0(struct Actor *,int);
extern struct ActorInputRecord20 dat_0c2d6f24[];
extern void (*table_0c242e10[])(struct Actor *),(*dat_0c242e24[])(struct Actor *),(*table_0c242e30[])(struct Actor *);
void func_0c09328c(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f41c<a->f56)){a->b6++;a->f56=a->f41c;a->f96=0;a->f108=0;func_0c02a0c4(a,2,3);}
}
void func_0c093306(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c093328(struct Actor *a){table_0c242e10[a->b6](a);}
void func_0c09333a(struct Actor *a)
{
 a->b6++;a->b12c=1;
 if(!(func_0c02849a()&1)){func_0c02a0c4(a,18,0);a->s30=7;}
 else{a->b6++;func_0c02a0c4(a,18,1);func_0c02a684(a,0,a->b37*28,3);}
}
void func_0c093394(struct Actor *a){if(func_0c02a026(a)<0){a->b5++;func_0c02a39a(a,0);}}
void func_0c0933bc(struct Actor *a){if(func_0c02a026(a)<0){a->b5++;func_0c02a39a(a,0);}}
void func_0c093406(struct Actor *a)
{
 unsigned char mode;
 char one=1,two=2;
 int zero=0;
 struct Actor *target;
 mode=func_0c02849a()&1;
 if(!a->b525){if(dat_0c2d6f24[a->b2].buttons&0x200)mode=zero;else if(dat_0c2d6f24[a->b2].buttons&0x100)mode=one;}
 target=a->p20c;if(target->b1==24||target->b1==25||target->b1==26)mode=one;
 if(func_0c043628(a)>=two)mode=two;
 switch(mode){
 case 0:a->b33=zero;func_0c02a0c4(a,0,2);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f92=-5.0f;if(a->w130)a->f92=-a->f92;break;
 case 1:a->b33=one;a->w130=zero;func_0c02a0c4(a,19,1);func_0c02a684(a,3,a->b37*28+3,1);func_0c199414(a,0,0);func_0c199414(a,0,1);break;
 default:a->b33=two;func_0c02a0c4(a,19,0);func_0c0344a0(a,16);
 }
 a->b6++;a->b7=zero;
}
void func_0c093570(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b7){a->f52+=a->f92;a->f92+=a->f104;
 if(!(a->f664>106.666664124f)){a->b7++;func_0c02a0c4(a,19,0);func_0c199414(a,2,0);func_0c199414(a,2,1);func_0c199414(a,2,2);func_0c199414(a,2,3);func_0c0344a0(a,16);}
 }
}
void func_0c0935f2(struct Actor *a){func_0c02a026(a);}
void func_0c0935f8(struct Actor *a){func_0c02a026(a);}
void func_0c0935fe(struct Actor *a){dat_0c242e24[a->b33](a);}
void func_0c093612(struct Actor *a){table_0c242e30[a->b6](a);}
void func_0c093624(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,2);}else func_0c02a026(a);}
void func_0c09363e(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,0);}else func_0c02a026(a);}
void func_0c093658(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,2);}else func_0c02a026(a);}
