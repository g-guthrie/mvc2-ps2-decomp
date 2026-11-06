#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void (*table_0c240ba0[])(struct Actor *);

void func_0c06d164(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c06d186(struct Actor *a) { table_0c240ba0[a->b6](a); }

void func_0c06d198(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = 34.2857132f;
        a->f108 = -1.07142854f;
    }
}

void func_0c06d1d0(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f96 <= 0.0f) {
        a->b6++;
        func_0c02a0c4(a, 15, 6);
    }
}

void func_0c06d232(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = -21.42857f;
        a->f108 = -1.07142854f;
    }
}
