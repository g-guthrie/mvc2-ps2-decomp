#include "objects.h"
extern unsigned char dat_0c2d9260[];
extern void (*dat_0c243af8[])(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c03489c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c0a2914(struct Actor *a)
{
    struct Actor *o;
    if (a->b141 == 2) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (a->b141 == 1) {
        func_0c025900(a, 0, 0);
        a->b141 = 0;
        o = a->p1c8;
        o->p1b4 = a;
        o->b1d2 = a->b1d2;
        o->b1a1 = 33;
        o->b1f6 = 1;
        dat_0c2d9260[5] = 2;
        dat_0c2d9260[6] = 1;
        func_0c03489c(o);
        return;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c0a29bc(struct Actor *a)
{
    *((unsigned char *)a + 0x1ea) = 1;
    dat_0c243af8[a->b6](a);
}
void func_0c0a29d6(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6 = a->b6 + 1;
        a->b141 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f108 = -1.6071429f;
    }
}
