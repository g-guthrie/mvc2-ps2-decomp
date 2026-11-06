#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24b568[], table_0c24b584[], table_0c24b58c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0348ca(struct Actor *);
extern void func_0c043324(struct Actor *);
extern unsigned int func_0c02849a(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c10729c(struct Actor *a)
{
    func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c < a->f56)
        return;
    func_0c0348ca(a);
    a->f56 = a->f41c;
    a->b5++;
    func_0c043324(a);
}

void func_0c1072f2(struct Actor *a)
{
    table_0c24b568[a->b6](a);
}

void func_0c107304(struct Actor *a)
{
    if ((func_0c02849a(a) & 1) == 0)
        a->b158 = 0;
    else
        a->b158 = 1;
    func_0c02a0c4(a, 19, a->b158);
    a->b6++;
}

void func_0c107338(struct Actor *a)
{
    func_0c02a026(a);
}

void func_0c10733e(struct Actor *a)
{
    table_0c24b584[a->b6](a);
}

void func_0c107350(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else {
        func_0c02a026(a);
    }
}

void func_0c10736a(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 0);
    } else {
        func_0c02a026(a);
    }
}

void func_0c107384(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else {
        func_0c02a026(a);
    }
}

void func_0c10739e(struct Actor *a)
{
    if (func_0c03916c(a))
        func_0c0437b8(a);
    else
        table_0c24b58c[a->b32](a);
}
