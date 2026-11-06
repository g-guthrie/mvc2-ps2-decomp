#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c044cbc(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1bc460(struct Actor *,int),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c120c24(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24d318[])(struct Actor *);
void func_0c11f50c(struct Actor *a)
{
 if(!a->b6){int zero;a->b6++;func_0c044cbc(a);func_0c048bb0(a,5);a->b1f9=1;a->b1a1=71;
  zero=0;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,20,6);func_0c1bc460(a,2);}
 if((unsigned char)a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if(func_0c02a026(a)<0)func_0c120c24(a);
}
void func_0c11f5d4(struct Actor *a){table_0c24d318[a->b6](a);}
