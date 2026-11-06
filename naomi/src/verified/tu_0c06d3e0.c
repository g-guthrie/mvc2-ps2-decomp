#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c03f004(struct Actor *, struct Actor *);
extern void (*table_0c240bb8[])(struct Actor *);
extern void func_0c045248(struct Actor *, int);

void func_0c06d3e0(struct Actor *a)
{
    if (a->b141 == 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (func_0c02a026(a) < 0) {
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}

void func_0c06d456(struct Actor *a) { table_0c240bb8[a->b1f7 & 63](a); }

void func_0c06d46e(struct Actor *a)
{
    if (a->p1c8->b6 <= 1) return;
    func_0c03edcc(a->p1c8, a);
}

void func_0c06d490(struct Actor *a)
{
    if (a->p1c8->b6 == 0)
        func_0c03f004(a->p1c8, a);
    else
        func_0c03edcc(a->p1c8, a);
}

void func_0c06d4b6(struct Actor *a) { func_0c03edcc(a->p1c8, a); }

void func_0c06d4c4(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 10; break;
    case 1: a->b1e9 = 10; break;
    case 2: a->b1e9 = 10; break;
    }
    func_0c045248(a, 29);
}

void func_0c06d4e8(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 10; break;
    case 1: a->b1e9 = 10; break;
    case 2: a->b1e9 = 10; break;
    }
    func_0c045248(a, 29);
}
