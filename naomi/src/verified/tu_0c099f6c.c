#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c243474[])(struct Actor *);
void func_0c099f6c(struct Actor *a)
{
    func_0c02a026(a);
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->b1d2 ? 15.83333302f : -15.83333302f;
    a->f104 = a->b1d2 ? -0.3125f : 0.3125f;
    a->s28 = 14;
}
void func_0c099fc4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) a->b6++;
}
void func_0c09a01e(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
        a->f92 = a->b1d2 ? 6.66666651f : -6.66666651f;
        a->f104 = a->b1d2 ? -0.20833333f : 0.20833333f;
        a->b159 = 2;
        a->b158 = 2;
        func_0c02a0c4(a, a->b159, a->b158);
    }
}
void func_0c09a0f0(struct Actor *a)
{
    if (!a->b141) {
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    }
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}
void func_0c09a154(struct Actor *a) { table_0c243474[a->b6](a); }
void func_0c09a166(struct Actor *a)
{
    a->b6++;
    func_0c02a026(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->b1d2 ? -21.6666660309f : 21.6666660309f;
    a->f104 = a->b1d2 ? 0.1041666642f : -0.1041666642f;
    a->s28 = 4;
}
