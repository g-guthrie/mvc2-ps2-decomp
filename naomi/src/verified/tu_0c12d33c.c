#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0346da(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24de20[])(struct Actor *);
void func_0c12d33c(struct Actor *a){table_0c24de20[a->b6](a);}
void func_0c12d34e(struct Actor *a)
{
 int zero=0;
 a->b6++;a->b7=zero;a->f56=a->f41c;a->b1f9=zero;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1a1=102;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,20,4);
}
void func_0c12d3be(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 else{
  if(a->b141&1){a->b141^=1;a->f92=-7.91666651f;a->f104=0.15625f;if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}func_0c0346da(a,41);}
  a->f52+=a->f92;a->f92+=a->f104;
  if(a->b141&2){float offset;a->b141^=2;a->f92=0.0f;a->f104=0.0f;offset=-53.3333321f;if(a->b1d2)offset=53.3333321f;a->f52+=offset;}
 }
}
