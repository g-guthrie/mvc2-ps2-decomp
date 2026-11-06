#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c025762(void);
extern void (*table_0c2425b0[])(struct Actor *);
void func_0c08afa8(struct Actor *);
void func_0c08af18(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 < a->f41c) {
        a->f56 = a->f41c;
        a->b1f9 = 0;
        func_0c044f1c(a);
    }
}
void func_0c08af86(struct Actor *a) { table_0c2425b0[a->b6](a); }
void func_0c08af98(struct Actor *a)
{
    a->b6++;
    a->f92 = 0;
    a->f104 = 0;
    func_0c08afa8(a);
}
void func_0c08afa8(struct Actor *a)
{
    struct Actor *child;
    func_0c02a026(a);
    if (a->b14b) {
        a->b6++;
        a->b14b = 0;
        child = a->p1c8;
        child->p1b4 = a;
        child->b1f6 = 1;
        child->b1d2 = a->b1d2;
        child->b1f9 = 2;
        child->b1a1 = 34;
        child->w130 ^= 1;
        child->b1d2 ^= 1;
        func_0c025762();
        a->f92 = 6.66666651f;
        a->f104 = -0.20833333f;
        if (a->b1d2) { a->f92 = -a->f92; a->f104 = -a->f104; }
        a->f96 = 10.714285f;
        a->f108 = -0.80357140303f;
    }
}
