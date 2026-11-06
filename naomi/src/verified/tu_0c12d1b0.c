#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c0346da(struct Actor *,int),func_0c191980(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24de18[])(struct Actor *);
void func_0c12d1b0(struct Actor *a)
{
 int zero=0;
 a->b6++;a->b7=zero;a->f56=a->f41c;a->b1f9=zero;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1a1=100;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c0344a0(a,32);func_0c02a0c4(a,20,2);
}
void func_0c12d228(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);else if(a->b141){a->b141=0;func_0c191980(a,1);}
}
void func_0c12d260(struct Actor *a){table_0c24de18[a->b6](a);}
void func_0c12d272(struct Actor *a)
{
 int zero=0;
 a->b6++;a->b7=zero;a->f56=a->f41c;a->b1f9=zero;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1a1=101;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c0346da(a,22);func_0c02a0c4(a,20,3);
}
void func_0c12d2ea(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
