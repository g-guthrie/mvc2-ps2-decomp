#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2430c0[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c048bb0(struct Actor *,int),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
extern struct LinkedActor *func_0c19996c(struct LinkedActor *,char);
void func_0c096526(struct Actor *);
void func_0c0964d0(struct Actor *a)
{
 int zero=0;
 a->b6++;func_0c044cbc(a);a->b1a1=22;a->b1f9=1;func_0c02a0c4(a,20,3);
 a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);func_0c096526(a);
}
void func_0c096526(struct Actor *a)
{
 if(a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);func_0c02a026(a);
 if(a->b141){a->b6++;func_0c19996c((struct LinkedActor *)a,17);}
}
void func_0c0965a0(struct Actor *a)
{
 if(a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c096610(struct Actor *a){table_0c2430c0[a->b6](a);}
