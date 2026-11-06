#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a684(struct Actor *,int,int,int),func_0c17d3f4(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24d0bc[])(struct Actor *);
void func_0c11dab4(struct Actor *a)
{
 float stopped;int zero;
 a->b6++;func_0c0442fa(a);stopped=0.0f;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 zero=0;a->b1a1=zero;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 a->f56=a->f41c;a->b1f9=zero;func_0c048bb0(a,10);a->s28=80;func_0c0432ca(a);a->b158=1;func_0c02a0c4(a,21,1);
}
void func_0c11db2e(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s28){if(a->b141){a->b141=0;func_0c02a684(a,1,5,1);func_0c17d3f4(a);}}
 else{a->b6++;func_0c02a0c4(a,21,2);}
}
void func_0c11db80(struct Actor *a){table_0c24d0bc[a->b6](a);}
