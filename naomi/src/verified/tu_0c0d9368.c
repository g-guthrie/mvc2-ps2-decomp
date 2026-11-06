#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c248a60[][4],dat_0c248a64[][4];
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct LinkedActor *func_0c165b30(struct Actor *,unsigned char,unsigned char);
void func_0c0d9368(struct Actor *a)
{
 int zero=0;
 a->b6++;a->b1a1=a->b1a3?72:70;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);func_0c0442fa(a);a->b1f9=2;
 a->f92=a->b1d2?dat_0c248a60[(unsigned char)a->b1a3][0]:-dat_0c248a60[(unsigned char)a->b1a3][0];
 a->f104=a->b1d2?dat_0c248a64[(unsigned char)a->b1a3][0]:-dat_0c248a64[(unsigned char)a->b1a3][0];
 a->f96=dat_0c248a60[(unsigned char)a->b1a3][2];a->f108=dat_0c248a60[(unsigned char)a->b1a3][3];
 func_0c165b30(a,9,0);a->b158=a->b1a3?23:21;func_0c02a0c4(a,21,a->b158);
}
