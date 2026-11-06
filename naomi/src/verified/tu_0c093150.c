#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c242e04[])(struct Actor *);

void func_0c093150(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c < a->f56)
        return;
    {
        a->b6++;
        a->f56 = a->f41c;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 2, 2);
    }
}

void func_0c0931ca(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0931ec(struct Actor *a)
{
    table_0c242e04[a->b6](a);
}

void func_0c0931fe(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = 20.0f;
        a->f104 = -0.3125f;
        a->f96 = 6.428571224213f;
        a->f108 = -0.5357143f;
        if (a->b1d2) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
}
