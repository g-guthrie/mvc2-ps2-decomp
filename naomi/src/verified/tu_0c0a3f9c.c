#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*dat_0c2440c8[])(struct Actor *);
void func_0c0a3f9c(struct Actor *a)
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
void func_0c0a4012(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a4034(struct Actor *a)
{
    dat_0c2440c8[a->b6](a);
}
void func_0c0a4046(struct Actor *a)
{
    if (a->b141) {
        a->b6=a->b6+1;
        a->f92=0;
        a->f96=0;
        a->f104=0;
        a->f108=0;
        if (a->b1d2) a->f92=-15.83333302f;
        else a->f92=15.83333302f;
        if (a->b1d2) a->f104=0.3125f;
        else a->f104=-0.3125f;
        a->f96=6.428571224213f;
        a->f108=-0.5357143f;
        a->s28=18;
        a->b141=0;
    }
    func_0c02a026(a);
}
