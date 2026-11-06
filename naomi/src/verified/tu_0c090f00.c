#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c242bf0[];
extern ActorHandler table_0c242bf8[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1990c0(struct Actor *, int);

void func_0c090f00(struct Actor *a)
{
    register struct Actor *p = a;
    register struct ActorSub2a4 *sub = &p->sub2a4;
    p->b3f8 = 2;
    p->b328 = 5;
    func_0c02a026(p);
    /* The state byte is read twice across the sign and zero checks. */
    if (*(volatile signed char *)&sub->w4 < 0 || (*(volatile signed char *)&sub->w4 != 0 && --p->s28 == 0)) {
        p->b3f9 = 0;
        p->b3f8 = 0;
        p->b327 = 0;
        p->b328 = 0;
        p->b6++;
        p->b7 = 0;
        func_0c02a0c4(p, 22, 8);
    }
}
void func_0c090f6c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c090f8e(struct Actor *a) { table_0c242bf0[a->b6](a); }
void func_0c090fa0(struct Actor *a)
{
    a->b6++;
    a->b7 = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c1990c0(a, 1);
    func_0c02a0c4(a, 20, 2);
}
void func_0c090fe8(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c09100a(struct Actor *a) { table_0c242bf8[a->b6](a); }
