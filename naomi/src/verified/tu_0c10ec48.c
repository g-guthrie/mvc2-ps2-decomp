#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24bd90[])(struct Actor *);
void func_0c10ec48(struct Actor *a)
{
 if(!a->b6){int zero;a->b6++;func_0c02a0c4(a,21,65);zero=0;
  a->b1a1=67;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c10eca6(struct Actor *a)
{
 if(!a->b6){int zero;a->b6++;func_0c02a0c4(a,21,67);zero=0;
  a->b1a1=68;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c10ed04(struct Actor *a)
{
 if(!a->b6){float stopped;a->b6++;func_0c02a0c4(a,21,56);stopped=0.0f;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;}
 else if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c10ed50(struct Actor *a){table_0c24bd90[a->b6](a);}
