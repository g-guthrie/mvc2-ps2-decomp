#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *);
void func_0c0ee7ec(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(a->f96<0){a->b6++;a->b1a1=57;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,8);}}
void func_0c0ee87a(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(a->f56>a->f41c){if(a->b19e)a->b6++;return;}a->b6=8;a->f56=a->f41c;a->b1f9=1;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c043324(a);func_0c02a0c4(a,21,12);}
