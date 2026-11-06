#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void (*table_0c24245c[])(struct Actor *);
extern void (*table_0c242480[])(struct Actor *);

void func_0c087acc(struct Actor *a)
{
    float dx;
    a->b1f5 = 2;
    func_0c02a026(a);
    if (a->b141 & 1) {
        a->b141 ^= 1;
        dx = -53.3333321f;
        if (a->b1d2)
            dx = 53.3333321f;
        a->f52 += dx;
    }
    if (a->b141 & 2) {
        a->b7++;
        a->b1f9 = 2;
        a->f92 = -16.666666031f;
        a->f104 = 0.5208333135f;
        a->f96 = 5.35714245f;
        a->f108 = -0.5357143f;
        if (a->b1d2) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
}

void func_0c087b5c(struct Actor *a)
{
    a->b1f5 = 2;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->b7++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
    }
}

void func_0c087bde(struct Actor *a) { func_0c02a026(a); }
void func_0c087be4(struct Actor *a) { table_0c24245c[a->b1e9](a); }
void func_0c087bf8(struct Actor *a) { table_0c242480[a->b6](a); }
