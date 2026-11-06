#include "objects.h"
struct Pos_0d1f48 {float x,y,z;};
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0ce574(struct Actor *),func_0c043014(struct Actor *,struct Pos_0d1f48 *),func_0c0432ca(struct Actor *);
void func_0c0d1f48(struct Actor *a){int zero;a->b6++;func_0c0344a0(a,43);a->f92=0;a->f96=0;a->f104=0;a->f108=0;zero=0;a->b1f9=zero;a->f56=a->f41c;a->f92=-10;a->f104=0.15625f;if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}func_0c0442fa(a);a->b1a1=65;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,20,2);}
void func_0c0d1fe2(struct Actor *a){struct Pos_0d1f48 v;if(func_0c02a026(a)<0){func_0c0ce574(a);}else {float previous=a->f92;a->f52+=previous;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(a->b141){a->b141=0;v.x=-30;v.y=171.42856f;func_0c043014(a,&v);func_0c0432ca(a);}if(0>a->f92*previous){a->f92=0;a->f96=0;a->f104=0;a->f108=0;}}}
