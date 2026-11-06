#include "objects.h"
extern void func_0c0437b8(struct Actor *), func_0c0346da(struct Actor *, int);
extern unsigned char func_0c044e52(struct Actor *);
extern void (*table_0c24040c[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned char dat_0c2f8338;

void func_0c065d08(struct Actor *a)
{
    a->b1f3 = 3;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b1f3 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}

void func_0c065d86(struct Actor *a) { table_0c24040c[a->b6](a); }

void func_0c065d98(struct Actor *a)
{
    if (dat_0c2f8338 < 2) {
        a->b12c = 0;
        return;
    }
    a->b6++;
    a->b12c = 1;
    a->b1f9 = 2;
    a->f56 += 531.42853f;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = -6.428571224213f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 18, 0);
}


void func_0c065dec(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c0346da(a, 47);
        func_0c02a026(a);
    }
}
