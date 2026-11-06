#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c0438de(struct Actor *),func_0c17323c(struct Actor *,int),func_0c1b80d8(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24b950[])(struct Actor *);
void func_0c10a0e0(struct Actor *a)
{
 int zero=0;
 if(!a->b6){
  a->b6++;func_0c0442fa(a);
  a->b1a1=50;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  a->b1f9=2;func_0c048bb0(a,10);func_0c02a0c4(a,21,((char *)a)[0x2c0]+60);
  a->f92/=16.0f;a->f96/=8.0f;a->f108/=64.0f;a->f104=0.0f;func_0c0344a0(a,4);
 }
 if(!(a->f56<a->f41c+-34.2857132f)){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}
 if(func_0c02a026(a)<0){a->f108=-0.80357140303f;func_0c0438de(a);}
 else if(a->b141){a->b141=zero;func_0c0344a0(a,32);func_0c17323c(a,0);func_0c1b80d8(a,0);a->b27b=zero;a->b27a=16;}
}
void func_0c10a214(struct Actor *a){table_0c24b950[a->b6](a);}
