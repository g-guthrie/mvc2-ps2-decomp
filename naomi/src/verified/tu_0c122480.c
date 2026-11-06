#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1bc740(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24d594[])(struct Actor *),(*table_0c24d59c[])(struct Actor *),(*table_0c24d5a8[])(struct Actor *);
void func_0c122480(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141&2){a->b141&=253;func_0c1bc740(a,9,0);}
 if(a->b141&4){a->b141&=251;func_0c1bc740(a,9,1);}
 if(a->b141&8){int zero=0;a->b141&=247;a->b1a1=23;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}
 if(!(a->f41c<a->f56)){float stopped=0.0f;a->f56=a->f41c;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);}
}
void func_0c122534(struct Actor *a)
{
 if((unsigned char)a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);table_0c24d594[a->b7](a);
}
void func_0c12259a(struct Actor *a){table_0c24d59c[a->b6](a);}
void func_0c1225ac(struct Actor *a){table_0c24d5a8[a->b6](a);}
