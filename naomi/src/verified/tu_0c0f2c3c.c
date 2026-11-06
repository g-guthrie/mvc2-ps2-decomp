#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c24a22c[])(struct Actor *);
void func_0c0f2c90(struct Actor *);
void func_0c0f2c3c(struct Actor *a){struct Actor *p=a;table_0c24a22c[p->b6](a);}
void func_0c0f2c4e(struct Actor *a)
{
 int zero;
 a->b6++;func_0c0442fa(a);zero=0;a->b1f9=zero;a->f56=a->f41c;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 func_0c02a0c4(a,2,zero);func_0c0f2c90(a);
}
void func_0c0f2c90(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;a->b141=0;a->f96=4.28571415f;a->f108=-0.5357143f;
  if(a->b1a3){
   a->f92=a->b1d2?15.83333302f:-15.83333302f;
   a->f104=a->b1d2?-0.390625f:0.390625f;
  }else{
   a->f92=a->b1d2?15.83333302f:-15.83333302f;
   a->f104=a->b1d2?-0.5208333135f:0.5208333135f;
  }
 }
}
