/* Whole unit 0x0c14d3d4..0x0c14d91c. */
#include "objects.h"
#define OWN(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
#define PP(a) (*(struct Actor **)&(*(struct Actor **)&(a)->pad7e[0])->pad7e[0])

struct Ctx { int l0, l4; };

extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0445fe(struct Actor *, struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c04b57c(struct Actor *, int, int);
extern void func_0c1d5da8(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c1c1678(struct Actor *, unsigned short *, int);
extern void func_0c14fb9c(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char dat_0c25010c[];
extern int (*dat_0c250334[])(struct Actor *, struct Actor *, void *);

int func_0c14d3d4(struct Actor *a, struct Actor *owner, struct Ctx *ctx);
void func_0c14d508(struct Actor *a, struct Actor *owner, struct Ctx *ctx);
void func_0c14d5ac(struct Actor *a, struct Actor *owner, struct Ctx *ctx);
void func_0c14d5c4(struct Actor *a);
void func_0c14d61c(struct Actor *a, struct Actor *owner, struct Ctx *ctx);
void func_0c14d644(struct Actor *a, struct Actor *owner, struct Ctx *ctx);
int func_0c14d690(struct Actor *a, struct Actor *owner, struct Ctx *ctx);
int func_0c14d6d2(struct Actor *a, struct Actor *owner, struct Ctx *ctx);
void func_0c14d77a(struct Actor *a);
void func_0c14d88a(struct Actor *a);

int func_0c14d3d4(struct Actor *a, struct Actor *owner, struct Ctx *ctx)
{
    struct Actor *t = owner->p20c;

    if (a->b19e < 0 && (a->b19e & 0x80)) {
        a->b19e |= -0x80;
        func_0c14d61c(a, owner, ctx);
        if (ctx->l4) {
        a->b5++;
        func_0c14d644(a, owner, ctx);
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f108 = -0.401785702f;
        a->w130 = owner->w130 ^ 1;
        { char n = dat_0c25010c[t->b1]; func_0c02a0c4(a, 23, n + 37); }
        return func_0c14d690(a, owner, ctx);
        }
        a->b5 = 3;
        return;
    }
    if (a->s28-- == 0) {
        a->b4++;
        a->b12c = 0;
        return;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    func_0c037d0c(a);
}

void func_0c14d508(struct Actor *a, struct Actor *owner, struct Ctx *ctx)
{
    struct Actor *p = owner->p1c8;

    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (p->f56 < owner->f41c) {
        a->b5++;
        a->s30 = 20;
        p->f56 = owner->f41c;
        p->b1f9 = 0;
        a->w130 = owner->w130 ^ 1;
        { char n = dat_0c25010c[p->b1]; func_0c02a0c4(a, 23, n + 37); }
        func_0c02a026(a);
        return;
    }
    a->s30 = 2;
    func_0c14d6d2(a, owner, ctx);
}

void func_0c14d5ac(struct Actor *a, struct Actor *owner, struct Ctx *ctx)
{
    struct Actor *p = owner->p1c8;

    a->f56 = owner->f41c + a->f56 - p->f56;
    func_0c14d6d2(a, owner, ctx);
}

void func_0c14d5c4(struct Actor *a)
{
    if (a->s28-- == 0) {
        a->b4++;
        a->b12c = 0;
        return;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
}

void func_0c14d61c(struct Actor *a, struct Actor *owner, struct Ctx *ctx)
{
    if (func_0c0447bc(a)) {
        func_0c0344a0(a, 36);
        ctx->l4 = 1;
    }
}

void func_0c14d644(struct Actor *a, struct Actor *owner, struct Ctx *ctx)
{
    struct Actor *p = a->p1b0;

    owner->b1f7 = p->b1f7 = 0xc2;
    func_0c0445fe(a, p);
    p->b1f6 = 6;
}

int func_0c14d690(struct Actor *a, struct Actor *owner, struct Ctx *ctx)
{
    struct Actor *t;

    if (ctx->l4) {
        t = owner->p20c;
        if (PP(a) != a) {
            func_0c0442fa(t);
            a->b4++;
            a->b12c = 0;
            return;
        }
    }
    return ctx->l4;
}

int func_0c14d6d2(struct Actor *a, struct Actor *owner, struct Ctx *ctx)
{
    struct Actor *t;
    void (*fn)(struct Actor *);

    if (ctx->l4) {
        t = owner->p20c;
        fn = func_0c0442fa;
        if (PP(a) != a) {
            fn(t);
            a->b4++;
            a->b12c = 0;
            return;
        }
        func_0c03edcc(a, t);
        if (t->b19f) {
            a->b4++;
            a->b12c = 0;
            t->b1f6 = 0;
            fn(t);
            return;
        }
        if (a->s30-- <= 0) {
            a->b4++;
            a->b12c = 0;
            fn(t);
            if (t->w420)
                func_0c0437b8(t);
            return;
        }
    }
    return ctx->l4;
}

void func_0c14d77a(struct Actor *a)
{
    struct Actor *o = OWN(a);
    struct Actor *p;

    func_0c02a026(a);
    a->f52 = o->f52;
    a->f52 += OWN(a)->w130 ? 112 : -112;
    if (a->b19e) {
        p = a->p1b0;
        if (p->b411 == 0) {
            func_0c04b57c(a->p1b0, 0x12c, 40);
            func_0c1d5da8(a->p1b0, 0);
            func_0c0346da(a, 42);
            a->b4++;
            a->b12c = 0;
            func_0c1c1678(a->p1b0, &p->w3e6, 0);
            return;
        }
        a->b1a1 = 50;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b2 ^= 1;
        a->b19c = 102;
        a->b19d = 6;
    }
    func_0c037d0c(a);
    if (a->s28-- == 0) {
        a->b4++;
        a->b12c = 0;
    }
}

void func_0c14d88a(struct Actor *a)
{
    struct Actor *o;
    void *c = &a->f136;

    dat_0c250334[a->b5](a, o = OWN(a), c);
    if (a->b1 != OWN(a)->b1) {
        func_0c14fb9c(a);
        return;
    }
    if (o->b1d0 != 21 || o->b1e9 != 6) {
        a->b4++;
        a->b12c = 0;
    }
}
