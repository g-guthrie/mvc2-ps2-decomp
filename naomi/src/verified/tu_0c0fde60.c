#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c043352(struct Actor *),func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct LinkedActor *func_0c16db78(struct Actor *,int);
extern void (*table_0c24ad60[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0fde60(struct Actor *a)
{
 register float zero;
 a->f52+=a->f92;a->f92+=a->f104;zero=0.0f;
 if(!(a->f92*a->f104<0.0f)){a->f92=zero;a->f104=zero;}else if(dat_0c2d6f84->flags&1)func_0c043352(a);
 if(func_0c02a026(a)<0){a->f56=a->f41c;a->b1f9=0;a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;func_0c0437b8(a);}
}
void func_0c0fdeec(struct Actor *a){table_0c24ad60[a->b6](a,&a->sub2a4);}
void func_0c0fdf02(struct Actor *a)
{
 int zero=0;
 a->b6++;a->b1f9=zero;a->f56=a->f41c;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1a1=50;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c048bb0(a,5);func_0c02a0c4(a,21,5);
}
void func_0c0fdf74(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;func_0c16db78(a,0);}
}
