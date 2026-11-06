#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c19fadc(struct Actor *,int);
extern void (*dat_0c2440d8[])(struct Actor *);
void func_0c0a40dc(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!a->s28) {
        a->b6=a->b6+1;
        a->f104 += a->b1d2 ? 0.3125 : -0.3125;
        a->f108=-0.5357143f;
        func_0c02a0c4(a,2,3);
    }
    a->s28=a->s28-1;
}
void func_0c0a416c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->b6=a->b6+1;
        a->f92=0;
        a->f96=0;
        a->f104=0;
        a->f108=0;
        a->f56=a->f41c;
    }
    if (!a->b141) func_0c02a026(a);
}
void func_0c0a41e2(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a4204(struct Actor *a)
{
    dat_0c2440d8[a->b6](a);
}
void func_0c0a4216(struct Actor *a)
{
    a->b6=a->b6+1;
    a->b12c=1;
    func_0c19fadc(a,13);
    func_0c02a0c4(a,18,0);
}
