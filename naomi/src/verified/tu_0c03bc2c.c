#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern int func_0c02850e(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c04be40(struct Actor *),func_0c04aa96(struct Actor *),func_0c042018(struct Actor *),func_0c04217a(struct Actor *),func_0c0421b8(struct Actor *),func_0c0414e8(struct Actor *),func_0c1c1e30(struct Actor *);
extern void (*table_0c23ba54[])(struct Actor *),(*table_0c23ba64[])(struct Actor *);
void func_0c03bed8(struct Actor *),func_0c03bf1c(struct Actor *);
void func_0c03bc2c(struct Actor *a){func_0c02a026(a);if(--a->s28<0){a->b6++;a->b254=1;}}
void func_0c03bc54(struct Actor *a){a->b1f4=2;if(func_0c02a026(a)<0){a->b256=2;a->b6=a->b7=0;}}
void func_0c03bc7e(struct Actor *a){a->b1ed=2;a->b254=1;a->b256=2;}
void func_0c03bc90(struct Actor *a){a->b1ed=2;a->b1f4=2;a->b1f5=2;table_0c23ba54[a->b6](a);}
void func_0c03bcb2(struct Actor *a)
{
 char zero=0;
 float stopped;
 unsigned int character;
 a->b201=zero;a->b7=zero;a->i72=zero;
 *(struct LinkedActorVec3 *)&a->f80=*(struct LinkedActorVec3 *)((char *)a+0x284);
 a->f264=1.0f;func_0c02a39a(a,1);func_0c0344a0(a,43);stopped=0.0f;
 if(a->b1f9==2){a->b6=1;func_0c02a0c4(a,13,30);character=a->b1d1;if(character==21||character==29){a->f92=stopped;a->f104=stopped;a->f96=stopped;a->f108=-0.80357140303f;}}
 else{a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->b1f9=zero;a->f56=a->f41c;a->b6=3;func_0c03bf1c(a);}
 func_0c04be40(a);
}
void func_0c03bd9c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c04aa96(a);
 if(func_0c02a026(a)>=0){
 if(func_0c044e52(a)){a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1f9=0;a->f56=a->f41c;a->b6=3;func_0c03bf1c(a);}
 }else{a->b6++;a->b1fc=a->b1d3=1;a->b1f9=2;a->f108=-0.80357140303f;func_0c02a0c4(a,1,11);}
}
void func_0c03be58(struct Actor *a)
{
 func_0c02a026(a);func_0c042018(a);func_0c04217a(a);func_0c0421b8(a);
 if(func_0c044e52(a)){a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1f9=0;a->f56=a->f41c;a->b6=3;func_0c03bf1c(a);}
}
void func_0c03bed8(struct Actor *a)
{
 a->f56=a->f41c;a->f92=16.666666031f;a->f104=0;
 if(a->b1d2)a->f92=-a->f92;a->f96=17.142857f;a->f108=-0.80357140303f;a->b1f9=2;func_0c02a0c4(a,24,2);
}
void func_0c03bf1c(struct Actor *a)
{
 if(!a->b7){a->b7++;func_0c03bed8(a);}else{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c044e52(a))func_0c03bed8(a);
 if(!func_0c02850e(a)){a->b0=0;a->b12c=0;func_0c0414e8(a);func_0c1c1e30(a);}
}}
void func_0c03bfac(struct Actor *a){a->b1ed=2;a->b1f4=2;a->b3f1=2;table_0c23ba64[a->b6](a);}
