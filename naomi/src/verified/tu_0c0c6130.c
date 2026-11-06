#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c048bb0(struct Actor *,int),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
extern void (*table_0c2477f4[])(struct Actor *);
void func_0c0c6130(struct Actor *a){if(!a->b6){int zero;func_0c044cbc(a);zero=0;a->b6++;a->b1a1=22;a->b1f9=zero;func_0c02a0c4(a,20,3);a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);}if(a->b1ff==3)func_0c043352(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0c61f4(struct Actor *a){table_0c2477f4[a->b6](a);}
void func_0c0c6206(struct Actor *a){func_0c02a026(a);if(a->b141){a->b6++;if(!a->b1d2){a->f92=-10;a->f104=0.15625f;}else {a->f92=10;a->f104=-0.15625f;}a->f96=4.28571415f;a->f108=-0.2678571343422f;}}
