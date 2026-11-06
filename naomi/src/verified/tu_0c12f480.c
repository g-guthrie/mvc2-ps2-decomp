#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c13150c(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24e150[])(struct Actor *);
void func_0c12f480(struct Actor *a)
{
 int zero;
 a->b6++;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->b1f9=1;a->f56=a->f41c;func_0c0442fa(a);func_0c0432ca(a);
 a->b1a1=120;zero=0;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,zero);
}
void func_0c12f4ec(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);if(a->b141){a->b6++;position.x=-46.666664124f;position.y=34.2857132f;func_0c043014(a,&position);}
}
void func_0c12f524(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c13150c(a);
 else if(a->b14b){float offset=-6.66666651f;if(a->w130)offset=6.66666651f;a->f52+=offset;}
}
void func_0c12f564(struct Actor *a){table_0c24e150[a->b6](a);}
