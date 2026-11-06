#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2427d0[])(struct Actor *);
void func_0c08ca24(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (!a->s30) {
        if (a->b35) { a->b6++; a->b7 = 0; return; }
    } else a->s30--;
    if (--a->s28 == 0) {
        a->b7++;
        a->b159 = 21;
        a->b158 = a->b1a3 + 2;
        func_0c02a0c4(a, a->b159, a->b158);
        a->f92 = a->b1d2 ? 6.66666651f : -6.66666651f;
        a->f104 = a->b1d2 ? -0.20833333f : 0.20833333f;
    }
}
void func_0c08cace(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->b141) a->f92 = 0;
    a->f104 = 0;
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}
void func_0c08cb3a(struct Actor *a) { table_0c2427d0[a->b7](a); }
