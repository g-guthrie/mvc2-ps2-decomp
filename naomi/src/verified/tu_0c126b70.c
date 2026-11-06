#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c126b70(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){float stopped;a->b6++;stopped=0.0f;a->f96=stopped;a->f108=stopped;a->s28=10;
  a->f92=-15.83333302f;a->f104=0.3125f;if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}}
}
void func_0c126bc4(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(--a->s28<=0)a->b6++;
}
void func_0c126c20(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<=0){a->b6++;a->f104=0.625f;if(a->w130)a->f104=-a->f104;func_0c02a0c4(a,2,2);}
}
