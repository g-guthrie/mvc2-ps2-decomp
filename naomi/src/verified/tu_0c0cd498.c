#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0cb70c(struct Actor *),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *);
void func_0c0cd498(struct Actor *a){a->b6++;func_0c0442fa(a);func_0c048bb0(a,10);a->f104=0;a->f108=0;a->b1a1=21;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;if(a->b1d2)a->f92=13.33333302f;else a->f92=-13.33333302f;a->f96=-17.142857f;func_0c02a0c4(a,21,(char)a->b1a3+25);func_0c0cb70c(a);}
void func_0c0cd518(struct Actor *a){func_0c02a026(a);if(!a->b141){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,21,(char)a->b1a3+27);func_0c043324(a);}func_0c0cb70c(a);}
void func_0c0cd5a0(struct Actor *a){if(func_0c02a026(a)<0){a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);return;}func_0c0cb70c(a);}
