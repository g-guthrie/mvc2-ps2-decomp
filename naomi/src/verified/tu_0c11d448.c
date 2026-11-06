#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern void func_0c1bb1d0(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern struct ActorSub2a4 *dat_0c2fb2f0;
extern void (*table_0c24d03c[])(struct Actor *),(*table_0c24d044[])(struct Actor *);
void func_0c11d448(struct Actor *a)
{
 dat_0c2fb2f0=&a->sub2a4;
 if(!a->b141){
  a->b12c=1;if(!(a->s28&15))func_0c1bb1d0(a);
  a->f56+=a->f96;a->f96+=a->f108;
  if(a->f41c<a->f56){a->b6++;dat_0c2fb2f0->b7=1;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,18,11);return;}
  if(--a->s30==0){a->s30=4;if(++a->s28>=11)a->s28=11;func_0c02a0c4(a,18,a->s28);return;}
 }else a->b12c=0;
 func_0c02a026(a);
}
void func_0c11d4fc(struct Actor *a){if(func_0c02a026(a)<0)a->b5++;}
void func_0c11d51c(struct Actor *a){if(func_0c03916c(a))func_0c0437b8(a);else table_0c24d03c[a->b6](a);}
void func_0c11d546(struct Actor *a){a->b6++;table_0c24d044[a->b32](a);}
