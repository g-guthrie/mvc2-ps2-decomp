#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c0437b8(struct Actor *);
extern void (*table_0c24a480[])(struct Actor *),(*table_0c24a48c[])(struct Actor *);
void func_0c0f5938(struct Actor *a){table_0c24a480[a->b6](a);}
void func_0c0f594a(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;a->f96=6.428571224213f;a->f108=-0.5357143f;
  a->f92=-15.83333302f;a->f104=0.3125f;
  if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 }
}
void func_0c0f59a0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;func_0c02a0c4(a,2,2);func_0c0346da(a,52);}
}
void func_0c0f5a1a(struct Actor *a)
{
 if(func_0c02a026(a)<0){float stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);}
}
void func_0c0f5a4c(struct Actor *a){table_0c24a48c[a->b6](a);}
