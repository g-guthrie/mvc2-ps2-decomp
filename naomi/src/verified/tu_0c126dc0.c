#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void (*table_0c24d944[])(struct Actor *);
void func_0c126dc0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){a->b6++;a->f104=-1.4583333f;if(a->w130)a->f104=-a->f104;func_0c02a0c4(a,2,3);}
 else if(a->b140){ /* Retail tests this flag without taking an action. */ }
}
void func_0c126e42(struct Actor *a)
{
 float stopped=0.0f;
 if(func_0c02a026(a)>=0){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(!(0.0f>a->f92*a->f104)){a->f92=stopped;a->f104=stopped;}}
 else{a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);}
}
void func_0c126eca(struct Actor *a){table_0c24d944[a->b6](a);}
