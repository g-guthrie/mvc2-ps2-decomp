#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0453c4(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0432ca(struct Actor *),func_0c15846c(struct Actor *,struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c2450a8[])(struct Actor *),(*table_0c2450c4[])(struct Actor *);
void func_0c0b7084(struct Actor *),func_0c0b712e(struct Actor *);
void func_0c0b706c(struct Actor *a){func_0c0453c4(a,21);a->b1e9=4;func_0c0b7084(a);}
void func_0c0b7084(struct Actor *a){table_0c2450a8[a->b1e9](a);}
void func_0c0b7098(struct Actor *a){table_0c2450c4[a->b6](a);}
void func_0c0b70aa(struct Actor *a){int zero;a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;zero=0;a->f56=a->f41c;a->b1fc=zero;a->b1f9=zero;func_0c048bb0(a,5);a->b1a1=59;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,zero);func_0c0432ca(a);func_0c0b712e(a);}
void func_0c0b712e(struct Actor *a){func_0c02a026(a);if(a->b141){a->b6++;func_0c15846c(a,a,a->b1a3);}if(a->w150){if(!a->w130)a->f52+=*(short *)&a->w150*1.66666663f;else a->f52-=*(short *)&a->w150*1.66666663f;a->w150=0;}}
