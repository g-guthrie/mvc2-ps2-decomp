#include "objects.h"
#define OWNER(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037d0c(struct Actor *);
void func_0c16a2f4(struct Actor *a)
{
 struct Tbl_ub3_01 **counts;unsigned int zero;int effect;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);effect=63;counts=&dat_0c2f83f8;zero=0;
 if(a->b141){*(unsigned char *)&a->b141=zero;a->b1a1=effect;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;*(void **)&a->p1c4=(void *)zero;(*counts)->arr[a->b2]++;a->s30=2;}
 if(! --a->s30 &&a->b19e){a->b1a1=effect;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;*(void **)&a->p1c4=(void *)zero;(*counts)->arr[a->b2]++;}
 if(!(a->f56>OWNER(a)->f41c)){
 a->b5++;a->f56=OWNER(a)->f41c;a->b1a1=effect;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;*(void **)&a->p1c4=(void *)zero;(*counts)->arr[a->b2]++;
 a->f92=a->w130?21.666666031f:-21.666666031f;a->f104=a->w130?-0.3125f:0.3125f;a->f96=6.428571224213f;a->f108=-0.80357140303f;func_0c02a0c4(a,21,19);
 }
 func_0c037d0c(a);
}
