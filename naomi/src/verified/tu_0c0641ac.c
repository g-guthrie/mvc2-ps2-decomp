#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c240230[])(struct Actor *);
extern void (*table_0c240244[])(struct Actor *);
extern struct Actor *func_0c18cff8(struct Actor *);
extern void func_0c044788(struct Actor *, struct Actor *);

void func_0c0641ac(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b140) {
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (a->f56 <= a->f41c) {
        a->f56 = a->f41c;
        a->b6++;
        func_0c02a0c4(a, 15, 9);
    }
}

void func_0c064208(struct Actor *a)
{
    a->b6++;
    a->f96 = -8.5714283f;
    a->f108 = -1.07142854f;
    func_0c0641ac(a);
}

void func_0c064220(struct Actor *a) { table_0c240230[a->b6](a); }

void func_0c064232(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c025900(a, 0, 0);
        func_0c0437b8(a);
    }
}

void func_0c06425c(struct Actor *a)
{
    a->b6++;
    func_0c02a0c4(a, 20, 2);
}

void func_0c06426a(struct Actor *a) { func_0c02a026(a); }

void func_0c064270(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b6++;
        return;
    }
    if (a->b14b) {
        struct Actor *p;
        a->b14b = 0;
        if ((p = func_0c18cff8(a)) != 0) {
            func_0c044788(a, p);
        } else {
            func_0c025900(a, 0, 0);
            func_0c0437b8(a);
        }
    }
}

void func_0c0642c8(struct Actor *a) { table_0c240244[a->b6](a); }
void func_0c0642da(struct Actor *a) { func_0c0437b8(a); }
