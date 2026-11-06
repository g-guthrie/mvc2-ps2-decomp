#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c243da8[];
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a684(struct Actor *,int,int,int);
void func_0c0a6520(register struct Actor *a)
{
    register float *values;
    unsigned char *sub;
    a->b6=a->b6+1;
    a->b1a1=71;
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c02a39a(a,0);
    values=dat_0c243da8;
    func_0c02a0c4(a,22,0);
    a->b35=a->w130 ? 1 : 2;
    values+=a->w130 ? 7 : 14;
    if (a->b1f9!=2) func_0c0432ca(a);
    func_0c02a684(a,4,7,1);
    a->f92=values[0];
    a->f104=values[1];
    a->f96=values[2];
    a->f108=values[3];
    a->s28=90;
    sub=(unsigned char *)&a->sub2a4;
    sub[10]=0;
    *(short *)(sub+12)=0;
}
