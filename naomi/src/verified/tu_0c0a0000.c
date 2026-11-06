#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243908[];
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c0a0000(struct Actor *a)
{
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f92 = a->b1d2 ? 15.83333302f : -15.83333302f;
        a->f104 = a->b1d2 ? -0.41666666f : 0.41666666f;
    }
    func_0c02a026(a);
}

void func_0c0a0058(struct Actor *a)
{
    if (a->b141) {
        a->b6++;
        func_0c043324(a);
        a->b141 = 0;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
}

void func_0c0a00ba(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a0114(struct Actor *a)
{
    table_0c243908[a->b6](a);
}
