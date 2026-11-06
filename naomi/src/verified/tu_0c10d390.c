#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a684(struct Actor *, int, int, int);
extern ActorHandler table_0c24bbc4[];

void func_0c10d390(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6 = a->b6 + 1;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f96 = 8.5714283f;
        a->f108 = -0.80357140303f;
        if (a->b1d2 == 0)
            a->f92 = 10.0f;
        else
            a->f92 = -10.0f;
    }
}

void func_0c10d3e6(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c)
        return;
    a->b6 = a->b6 + 1;
    a->f56 = a->f41c;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    func_0c02a0c4(a, 2, 3);
}

void func_0c10d46e(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c10d490(struct Actor *a)
{
    table_0c24bbc4[a->b6](a);
}

void func_0c10d4a2(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b12c = 1;
    func_0c02a684(a, 0, ((unsigned char *)a)[37] << 2, 1);
    func_0c02a684(a, 1, 24, 1);
    func_0c02a0c4(a, 18, 0);
}
