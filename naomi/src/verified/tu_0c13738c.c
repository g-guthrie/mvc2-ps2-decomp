#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c028642(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037d0c(struct Actor *),func_0c037688(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24e790[])(struct Actor *);
void func_0c1374c0(struct Actor *);
void func_0c13738c(struct Actor *a)
{
 struct Actor *source=a->p20;int zero=0;
 a->pad178[36]=66;a->b19d=66;a->b1a1=70;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->b36=zero;a->f52=source->f52;a->f56=source->f56;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b13c=16;((struct MeActor *)a)->blk_dc.b13d=16;((struct MeActor *)a)->blk_dc.b13e=16;((struct MeActor *)a)->blk_dc.b13f=64;
 a->f92=a->w130?10.83333302f:-10.83333302f;func_0c02a0c4(a,23,8);
}
void func_0c137412(struct Actor *a){table_0c24e790[a->b32](a);}
void func_0c137426(struct Actor *a)
{
 struct Actor *source=a->p20;
 a->b36=source->b36;a->f52=source->f52;a->f56=source->f56;if(func_0c02a026(a)<0)func_0c1374c0(a);
}
void func_0c13745a(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
 if(a->b19e || !func_0c028642(a))a->b4++;func_0c037d0c(a);
}
void func_0c1374c0(struct Actor *a){a->b4++;a->b12c=0;}
void func_0c1374ce(struct Actor *a){func_0c037688(a);}
