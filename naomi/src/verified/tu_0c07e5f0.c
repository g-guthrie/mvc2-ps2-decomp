#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0818cc(struct Actor *);
extern void func_0c08183c(struct Actor *);
extern void func_0c08191c(struct Actor *);
extern void (*table_0c241a88[])(struct Actor *);

void func_0c07e5f0(struct Actor *a)
{
    if (a->f96 < 0.0f) {
        a->f92 = a->f104 = 0.0f;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c) {
        func_0c02a026(a);
        return;
    }
    a->b6++;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a0c4(a, 21, a->b1a3 + 3);
    func_0c0818cc(a);
}

void func_0c07e682(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c08183c(a);
}

void func_0c07e6a4(struct Actor *a) { func_0c08183c(a); }
void func_0c07e6aa(struct Actor *a) { func_0c08183c(a); }
void func_0c07e6b0(struct Actor *a) { func_0c08183c(a); }
void func_0c07e6b6(struct Actor *a) { func_0c08183c(a); }

void func_0c07e6bc(struct Actor *a)
{
    table_0c241a88[a->b6](a);
    func_0c08191c(a);
}
