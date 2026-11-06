#include "objects.h"
extern int func_0c03916c(struct Actor *);
extern void func_0c0fc938(struct Actor *),func_0c0438de(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c16ce38(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24aad8[])(struct Actor *),(*dat_0c24aaec[])(struct Actor *),(*table_0c24ab20[])(struct Actor *);

void func_0c0fb3f0(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c0fc938(a);
    } else {
        table_0c24aad8[a->b32](a);
    }
}

void func_0c0fb41c(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 0);
    } else {
        func_0c02a026(a);
    }
}

void func_0c0fb436(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 1);
    } else {
        func_0c02a026(a);
    }
}

void func_0c0fb450(struct Actor *a){dat_0c24aaec[a->b1e9](a);}
void func_0c0fb464(struct Actor *a)
{
 int z=0;
 if(!a->b6){
  a->b6++;
  func_0c0442fa(a);func_0c048bb0(a,5);func_0c02a0c4(a,21,a->b1a3);
  a->b1a1=48;a->w1ac=z;a->b19e=z;*(unsigned int *)&a->p1c4=z;
  dat_0c2f83f8->arr[a->b2]++;
  if(a->b1f9!=2){
   a->b1f9=z;func_0c0432ca(a);
   a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
  }else{
   a->f92/=16.0f;a->f96/=8.0f;a->f108/=64.0f;a->f104=0.0f;
  }
 }
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c)a->f56=a->f41c;
 if(func_0c02a026(a)<0){
  if(a->b1f9==2)func_0c0438de(a);else func_0c0fc938(a);
 }else if(a->b141){
  a->b141=z;func_0c16ce38(a);a->b27b=z;a->b27a=16;
 }
}
void func_0c0fb5e2(struct Actor *a){table_0c24ab20[a->b6](a);}
