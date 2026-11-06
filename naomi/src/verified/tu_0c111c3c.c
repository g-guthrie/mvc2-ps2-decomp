/* Actor state routines; reviewed span 0x0c111c3c..0x0c111e60. */
#include "objects.h"
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
extern struct Actor *func_0c037da4(struct Actor *);
extern void func_0c044548(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern char dat_0c24be14[];
void func_0c111da8(struct Actor *, struct Actor *);
extern void (*dat_0c24c048[])(struct Actor *);

void func_0c111c3c(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
    case 1:
        a->b158 = 1;
        a->p3f4 = dat_0c24be14;
        func_0c0346da(a, 20);
        break;
    case 2:
        a->b158 = 2;
        a->p3f4 = dat_0c24be14;
        func_0c0346da(a, 22);
        break;
    }
    func_0c02a0c4(a, 22, a->b158);
}
void func_0c111c8a(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
    case 1:
        a->b158 = 3;
        a->p3f4 = dat_0c24be14;
        func_0c0346da(a, 20);
        break;
    case 2:
        a->b158 = 4;
        a->p3f4 = dat_0c24be14;
        func_0c0346da(a, 22);
        break;
    }
    func_0c02a0c4(a, 22, a->b158);
}
void func_0c111cd8(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
    case 1:
        a->b158 = 5;
        a->p3f4 = dat_0c24be14;
        func_0c0346da(a, 20);
        break;
    case 2:
        a->b158 = 6;
        a->p3f4 = dat_0c24be14;
        func_0c0346da(a, 22);
        break;
    }
    func_0c02a0c4(a, 22, a->b158);
    if (a->b1d6 & 15)
        a->b1d6--;
}
void func_0c111d4c(struct Actor *a)
{
    struct Actor *b;
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2)
            func_0c0438de(a);
        else
            func_0c0437b8(a);
        return;
    }
    if (!a->b141)
        return;
    if ((b = func_0c037d54(a)) == 0) {
        goto g;
    g:
        if ((b = func_0c037da4(a)) == 0)
            return;
    }
    func_0c111da8(a, b);
}
void func_0c111da8(struct Actor *a, struct Actor *b)
{
    a->b5 = 0;
    a->b6 = 1;
    a->b7 = 0;
    a->b1f7 = 4;
    a->b1f7 |= 64;
    a->b1f7 |= 0x80;
    func_0c044548(a, b);
    a->b1e9 = 4;
    func_0c045248(a, 29);
    b->b6 = 0;
    b->f92 = b->f96 = b->f104 = b->f108 = 0.0f;
}
void func_0c111e14(struct Actor *a)
{
    dat_0c24c048[a->b6](a);
}
