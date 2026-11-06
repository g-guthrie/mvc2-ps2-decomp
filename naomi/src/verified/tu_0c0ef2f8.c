#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
void func_0c0ef2f8(struct Actor *a,char *p){int zero=0;a->b3f8=2;a->b328=5;a->b6++;a->s28=4;a->f56=a->f41c;a->b1f9=zero;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1a1=61;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;p[12]=1;func_0c02a0c4(a,21,18);}
void func_0c0ef35e(struct Actor *a,char *p){a->b3f8=2;a->b328=5;if(--a->s28<0){func_0c02a026(a);if(((char *)&a->w150)[1]){a->b6++;a->b1f9=2;p[2]=0;if(a->b1d2)a->f92=13.33333302f;else a->f92=-13.33333302f;if(a->b1d2)a->f104=-0.3125f;else a->f104=0.3125f;a->f96=6.428571224213f;a->f108=-0.80357140303f;}}}
