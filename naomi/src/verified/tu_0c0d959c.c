#include "objects.h"
struct Pos_0d959c {float x,y,z;};
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct Pos_0d959c *),func_0c0346da(struct Actor *,int);
void func_0c0d959c(struct Actor *a){int zero=0;a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;a->b1f9=zero;func_0c02a39a(a,zero);func_0c0442fa(a);func_0c0432ca(a);a->b1a1=84;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,24);}
void func_0c0d9612(struct Actor *a){struct Pos_0d959c v;if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->b141&1){a->b141=0;v.x=25;v.y=188.57143f;v.z=0;func_0c043014(a,&v);}}
void func_0c0d9664(struct Actor *a){func_0c02a026(a);if(a->b141){a->b6++;a->b141=0;if(a->b1d2)a->f92=5;else a->f92=-5;a->f104=0;a->f96=8.5714283f;a->f108=-1.0044643f;func_0c0346da(a,21);}}
