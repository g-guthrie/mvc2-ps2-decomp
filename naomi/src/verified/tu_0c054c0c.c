#include "objects.h"
extern void func_0c025900(struct Actor *, char, char);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char dat_0c23f24c[], dat_0c23f25c[], dat_0c23f26c[];
extern void (*table_0c23f44c[])(struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
int func_0c054cee(struct Actor *);
int func_0c054d58(struct Actor *);
int func_0c054d8e(struct Actor *);
void func_0c054c0c(struct Actor *a)
{
    struct Actor *other;
    a->b6 = 0;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f56 > a->f41c + 66.666664124f))
        a->f56 = a->f41c + 66.666664124f;
    if (a->b141) {
        a->b141 = 0;
        other = a->p1c8;
        other->p1b4 = a;
        other->b1f6 = 1;
        other->b1f9 = 2;
        func_0c025900(a, 0, 0);
        other->b1a1 = 34;
        other->b1d2 = a->b1d2;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
int func_0c054cc2(struct Actor *a)
{
    if (func_0c054d8e(a) || func_0c054cee(a) || func_0c054d58(a))
        return 1;
    return 0;
}
int func_0c054cee(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c23f24c, (unsigned char *)a + 0x38c) || !*a->p40c || a->b1f9 == 2)
        return 0;
    a->b258 = 5;
    return 1;
}
int func_0c054d58(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c23f25c, (unsigned char *)a + 0x394))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 6;
    return 1;
}
int func_0c054d8e(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c23f26c, (unsigned char *)a + 0x39c))
        return 0;
    else if (*a->p40c < 3)
        return 0;
    a->b258 = 11;
    return 1;
}
void func_0c054dc6(struct Actor *a)
{
    table_0c23f44c[a->b1f7 & 63](a);
}
void func_0c054dde(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}
void func_0c054dec(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 5; break;
    case 1: a->b1e9 = 5; break;
    case 2: a->b1e9 = 6; break;
    }
    func_0c045248(a, 29);
}
void func_0c054e1c(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 5; break;
    case 1: a->b1e9 = 5; break;
    case 2: a->b1e9 = 6; break;
    }
    func_0c045248(a, 29);
}
