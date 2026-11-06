#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern int func_0c168fe0(struct Actor *, int);
extern void (*table_0c249fe0[])(struct Actor *);

void func_0c0f0760(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->s28 = 0;
        if (!func_0c168fe0(a, 2))
            func_0c0437b8(a);
    }
}

void func_0c0f07ae(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    a->b3f8 = 2;
    a->b328 = 5;
    if (!a->b141)
        func_0c02a026(a);
    if (!a->s28 && a->b19e) {
        func_0c02a0c4(a, 22, 1);
        a->b141 = 0;
        a->s28 = 1;
    }
    if (((unsigned char *)sub)[13]) {
        a->b6++;
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
    }
}

void func_0c0f0822(struct Actor *a)
{
    if (func_0c02a026(a) >= 0)
        return;
    func_0c0437b8(a);
}

void func_0c0f0844(struct Actor *a)
{
    struct Actor *p;
    p = a;
    table_0c249fe0[p->b6](a);
}
