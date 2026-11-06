#include "objects.h"
extern void func_0c0c72d2(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c247d40[];

void func_0c0c9c60(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0c9c82(struct Actor *a)
{
    table_0c247d40[a->b6](a);
}

void func_0c0c9c94(struct Actor *a)
{
    struct Actor *b;
    func_0c0c72d2(a);
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        b = a->p1c8;
        b->p1b4 = a;
        b->b1f6 = 1;
        b->b1f9 = 2;
        b->b1a1 = 33;
        b->b1d2 = a->b1d2 ^ 1;
        if (a->w150 == 0)
            func_0c0438de(a);
    }
}

void func_0c0c9cf0(struct Actor *a)
{
    func_0c0c72d2(a);
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}

void func_0c0c9d16(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c0c9d24(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 7; break;
    case 1: a->b1e9 = 7; break;
    case 2: a->b1e9 = 7; break;
    }
    func_0c045248(a, 29);
}

void func_0c0c9d48(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 7; break;
    case 1: a->b1e9 = 7; break;
    case 2: a->b1e9 = 7; break;
    }
    func_0c045248(a, 29);
}
