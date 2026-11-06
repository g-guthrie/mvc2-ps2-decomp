#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c02a18c(struct Actor *, int, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern float dat_0c2d926c;
void func_0c0d6c2a(struct Actor *a);
extern void (*table_0c2487f8[])(struct Actor *);
void func_0c0d6d2e(struct Actor *a);

void func_0c0d6bd0(struct Actor *a)
{
    table_0c2487f8[a->b6](a);
}

void func_0c0d6be2(struct Actor *a)
{
    a->b6++;
    a->pad7f2++;
    a->b1d4 = 0;
    a->b1d6 = 17;
    a->b1f9 = 2;
    a->s28 = 60;
    a->w130 = a->b1d2 ^ 1;
    func_0c02a0c4(a, 20, 2);
    func_0c0d6c2a(a);
}

void func_0c0d6c2a(struct Actor *a)
{
    int k;
    func_0c0d6d2e(a);
    if (--a->s28 == 0 || (a->w340 & 0x1000)) {
        a->b6++;
        k = 3;
    } else {
        if (a->w34a & 0x400)
            return;
        a->b6 += 2;
        k = 4;
    }
    func_0c02a0c4(a, 20, k);
}

void func_0c0d6c7a(struct Actor *a)
{
    func_0c0d6d2e(a);
    a->f56 -= 2.1428571f;
    if (a->f56 > a->f41c + 102.85714f && (a->w34a & 0x400))
        return;
    a->b6++;
    func_0c02a0c4(a, 20, 4);
}
void func_0c0d6ce8(struct Actor *a)
{
    func_0c0d6d2e(a);
    if (func_0c02a026(a) < 0) {
        func_0c045248(a, 2);
        a->b6 = 1;
        a->b1f9 = 2;
        a->w130 = a->b1d2;
        func_0c02a18c(a, 1, 1, 3);
        return;
    }
}

void func_0c0d6d2e(struct Actor *a)
{
    float k;

    k = dat_0c2d926c;
    if (a->w130)
        a->f52 = k + 288.333344f;
    else
        a->f52 = k + -288.333344f;
}
