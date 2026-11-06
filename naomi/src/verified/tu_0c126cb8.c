#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c24d938[])(struct Actor *);
void func_0c126cb8(struct Actor *a)
{
 float stopped=0.0f;
 if(func_0c02a026(a)>=0){
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(!(0.0f>a->f92*a->f104)){a->f92=stopped;a->f104=stopped;}
 }else{a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);}
}
void func_0c126d40(struct Actor *a){table_0c24d938[a->b6](a);}
void func_0c126d52(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){float stopped;a->b6++;stopped=0.0f;a->f96=stopped;a->f108=stopped;a->s28=10;
  a->f92=15.83333302f;a->f104=-0.3125f;if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}}
}
