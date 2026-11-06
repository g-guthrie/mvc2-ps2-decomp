#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c025762(void);
extern void (*table_0c2425a4[])(struct Actor *);
void func_0c08adf4(struct Actor *);
void func_0c08ada4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) { func_0c0442fa(a); func_0c0437b8(a); }
}
void func_0c08adca(struct Actor *a) { table_0c2425a4[a->b6](a); }
void func_0c08addc(struct Actor *a)
{
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c08adf4(a);
}
void func_0c08adf4(struct Actor *a)
{
    struct Actor *child;
    if (!a->b7) {
        func_0c02a026(a);
        if (a->b141) {
            a->b7++;
            a->b141 = 0;
            a->b1f9 = 2;
            a->f92 = -3.3333333f;
            a->f104 = 0;
            a->f96 = 11.78571415f;
            a->f108 = -0.5357143f;
            a->b1d6 = 17;
            a->b1d4 = 1;
            if (a->b1d2) a->f92 = -a->f92;
        }
    } else {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c02a026(a);
        if (a->b14b) {
            a->b6++;
            a->b7 = 0;
            child = a->p1c8;
            child->p1b4 = a;
            child->b1f6 = 1;
            child->b1d2 = a->b1d2;
            child->b1f9 = 2;
            child->b1a1 = 33;
            child->w130 ^= 1;
            child->b1d2 ^= 1;
            func_0c025762();
        }
    }
}
