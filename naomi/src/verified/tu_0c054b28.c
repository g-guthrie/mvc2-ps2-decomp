#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);

void func_0c054b28(struct Actor *a)
{
    struct Actor *o;
    if (a->b141) {
        a->b141 = 0;
        o = a->p1c8;
        o->p1b4 = a;
        o->b1f6 = 1;
        o->b1f9 = 2;
        func_0c025900(a, 0, 0);
        o->b1a1 = 32;
        o->b1d2 = a->b1d2;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c054b86(struct Actor *a)
{
    struct Actor *o;
    if (a->b141) {
        a->b141 = 0;
        o = a->p1c8;
        o->p1b4 = a;
        o->b1f6 = 1;
        o->b1f9 = 2;
        func_0c025900(a, 0, 0);
        o->b1a1 = 33;
        o->b1d2 = a->b1d2;
        a->b1d2 = a->b1d2 ^ 1;
    }
    if (func_0c02a026(a) < 0) {
        func_0c0442fa(a);
        func_0c0437b8(a);
    }
}
