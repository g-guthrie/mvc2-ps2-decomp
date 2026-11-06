#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c24240c[])(struct Actor *);

void func_0c087258(struct Actor *a)
{
    a->b6++;
    a->f92 = -15.83333302f;
    a->f104 = 0.3125f;
    a->f96 = 6.428571224213f;
    a->f108 = -0.5357143f;
    if (a->w130) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
}

void func_0c08729a(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 <= a->f41c) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 2, 2);
    }
}

void func_0c08731c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    } else if (a->b141) {
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
}

void func_0c087388(struct Actor *a) { table_0c24240c[a->b6](a); }
