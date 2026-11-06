#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c240d3c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c06e624(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = a->b1d2 ? 13.33333302f : -13.33333302f;
    }
}
void func_0c06e66a(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->b141) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = a->b1d2 ? 1.66666663f : -1.66666663f;
    }
}
void func_0c06e6e8(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c06e742(struct Actor *a) { table_0c240d3c[a->b6](a); }
