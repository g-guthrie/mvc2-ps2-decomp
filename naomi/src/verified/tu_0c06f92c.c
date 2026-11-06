#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c240e24[];
extern char func_0c02a026(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c06f92c(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (a->f96 > 0.0f)
        return;
    a->b6++;
    a->f108 = -0.80357140303f;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    func_0c02a0c4(a, 20, 3);
}

void func_0c06f9aa(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (!func_0c044e52(a))
        return;
    func_0c043324(a);
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 20, 4);
}

void func_0c06fa30(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c06fa52(struct Actor *a)
{
    table_0c240e24[a->b6](a);
}
