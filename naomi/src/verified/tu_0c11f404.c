#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c044df4(struct Actor *),func_0c120c24(struct Actor *),func_0c043352(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24d308[])(struct Actor *);
void func_0c11f474(struct Actor *);
void func_0c11f404(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if(!a->l320){if(func_0c02a026(a)<0)func_0c120c24(a);}else func_0c11f474(a);
}
void func_0c11f474(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c120c24(a);
 else if(a->b141){int zero=0;*(unsigned int *)&a->l320=zero;a->b1a1=25;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}
}
void func_0c11f4c6(struct Actor *a){func_0c043352(a);func_0c11f404(a);}
void func_0c11f4d6(struct Actor *a){table_0c24d308[(unsigned char)a->b1ff](a);}
