#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c0437b8(struct Actor *);
extern void (*table_0c24a498[])(struct Actor *);
void func_0c0f5a8c(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;a->f96=6.428571224213f;a->f108=-0.5357143f;
  a->f92=15.83333302f;a->f104=-0.3125f;
  if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 }
}
void func_0c0f5ae2(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;func_0c02a0c4(a,2,3);func_0c0346da(a,52);}
}
void func_0c0f5b5c(struct Actor *a)
{
 if(func_0c02a026(a)<0){float stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);}
}
void func_0c0f5b8e(struct Actor *a){table_0c24a498[a->b6](a);}
