#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0442fa(struct Actor *),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *);
extern void (*table_0c248e78[])(struct Actor *);
void func_0c0dd0e0(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(a->b14b){a->b1a1=a->b14b;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;a->b14b=0;}if(a->f56<a->f41c){a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,21,a->b1a3+14);func_0c0442fa(a);func_0c043324(a);}}
void func_0c0dd1aa(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0dd1cc(struct Actor *a){table_0c248e78[a->b6](a);}
