#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c052d2e(struct Actor *);
void func_0c052d28(struct Actor *a)
{
    a->b6++;
    func_0c052d2e(a);
}
void func_0c052d2e(struct Actor *a)
{
    func_0c02a026(a);
    if (!a->b141) {
        a->b6++;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f92 = a->b1d2 ? 13.33333302f : -13.33333302f;
        a->f104 = a->b1d2 ? -0.13020833f : 0.13020833f;
        a->s28 = 24;
    }
}
void func_0c052d8e(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 <= 0) {
        a->b6++;
        a->f92 = a->b1d2 ? 4.16666651f : -4.16666651f;
        a->f104 = a->b1d2 ? -0.33854167f : 0.33854167f;
        func_0c02a0c4(a, 2, 2);
    }
}
