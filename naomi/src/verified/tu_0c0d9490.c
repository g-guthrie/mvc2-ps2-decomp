#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c248a80[])(struct Actor *);
void func_0c0d9490(struct Actor *a){float zero=0;if(!a->b141){unsigned char mirror;a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;mirror=a->b1d2;if((mirror && a->f92<0)||(!mirror && a->f92>0)){a->f92=zero;a->f104=zero;}if(!(a->f56>a->f41c))a->f56=a->f41c;}if(func_0c02a026(a)<0){a->f92=zero;a->f104=zero;func_0c0438de(a);return;}if(a->b14b){a->b14b=0;a->b1a1=73;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}}
void func_0c0d9572(struct Actor *a){table_0c248a80[a->b6](a);}
