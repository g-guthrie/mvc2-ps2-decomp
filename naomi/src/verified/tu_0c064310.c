#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c240254[];
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c03efea(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c1fba00(void *, int, int);
void func_0c064310(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}
void func_0c06431e(struct Actor *a)
{
    struct Actor *c = a->p1c8;
    if (((char *)&c->w150)[1]) {
        if (c->b140)
            func_0c03edcc(a->p1c8, a);
        else
            func_0c03efea(a->p1c8, a);
    }
}
void func_0c064354(struct Actor *a)
{
    struct Actor *c = a->p1c8;
    if (!c->b140)
        func_0c03edcc(a->p1c8, a);
}
void func_0c064374(void) {}
void func_0c064378(struct Actor *a)
{
    struct Actor *c = a->p1c8;
    if (!c->b140)
        func_0c03edcc(a->p1c8, a);
    else
        func_0c03efea(a->p1c8, a);
}
void func_0c0643a0(struct Actor *a)
{
    table_0c240254[a->b1f7 & 63](a);
}
void func_0c0643b8(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 9; break;
    case 1: a->b1e9 = 7; break;
    case 2: a->b1e9 = 9; break;
    }
    func_0c045248(a, 29);
}
void func_0c0643e8(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 9; break;
    case 1: a->b1e9 = 7; break;
    case 2: a->b1e9 = 9; break;
    }
    func_0c045248(a, 29);
}
void func_0c064436(struct Actor *a)
{
    int zero = 0, one = 1;
    a->b5 = zero;
    a->b7 = zero;
    a->b6 = zero;
    switch (a->b4c9) {
    case 0: a->b1e9 = 2; break;
    case 1: a->b1e9 = one; break;
    case 2: *(volatile unsigned char *)&a->b1e9 = one; break;
    default: goto call;
    }
    a->b1a3 = one;
call: goto tail;
tail: func_0c045248(a, 21);
}
void func_0c064470(struct Actor *a)
{
    int zero = 0, one = 1, two = 2;
    a->b5 = zero;
    a->b7 = zero;
    a->b6 = zero;
    switch (a->b4c9) {
    case 0: a->b1e9 = two; break;
    case 1: a->b1e9 = one; break;
    case 2: *(volatile unsigned char *)&a->b1e9 = two; break;
    default: goto call;
    }
    a->b1a3 = one;
call: goto tail;
tail: func_0c045248(a, 21);
}
void func_0c0644aa(struct Actor *a)
{
    struct ActorSubControlBytes *sub = (struct ActorSubControlBytes *)&a->sub2a4;
    void *volatile p = sub;
    char t = sub->b12;
    func_0c1fba00(p, 0, 128);
    sub->b12 = t;
}
