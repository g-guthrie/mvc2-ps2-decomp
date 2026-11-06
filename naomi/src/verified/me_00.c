/* Actor state machine handlers at 0x0c1aa884 share this object with me_01. */
#include "objects.h"

typedef void (*handler_me00)(struct MeActor *);

extern struct Glob_me00 *dat_0c2d6f84;
extern unsigned char dat_0c2f833e;
extern handler_me00 dat_0c259bf4[];
extern handler_me00 dat_0c259c04[];
extern handler_me00 dat_0c259c48[];
extern handler_me00 dat_0c259bc4[];
extern struct MeActor *func_0c0374da(int a, int b, int c);
extern void func_0c02a0c4(struct MeActor *a, int b, int c);
extern void func_0c1d53e4(struct MeActor *a);
extern void func_0c1abc64(struct MeActor *a, struct MeActor *b, handler_me00 *t);
extern void func_0c1abcd4(struct MeActor *a, struct MeActor *b);
extern char func_0c02a026(struct MeActor *a);

void func_0c1aa8aa(struct MeActor *a);
void func_0c1aa9c4(struct MeActor *a);
void func_0c1aaa86(struct MeActor *a, struct MeActor *b);

struct MeActor *func_0c1aa884(struct MeActor *a)
{
    struct MeActor *q;

    if ((q = func_0c0374da(0, 4, 0)) != 0) {
        q->p10 = func_0c1aa8aa;
        q->p18 = a;
    }
    return q;
}

void func_0c1aa8aa(struct MeActor *a)
{
    dat_0c259bf4[a->b04](a);
}

void func_0c1aa8bc(struct MeActor *a)
{
    struct MeActor *b;

    if (dat_0c2d6f84->l14 == 0x80) {
        a->b04 = 2;
        a->b05 = 0;
        return;
    }
    a->b04++;
    a->w26 = 0x1c03;
    b = a->p18;
    a->blk_dc = b->blk_dc;
    a->blk_dc.b12c = 1;
    a->b02 = b->b02;
    a->b01 = b->b01;
    a->v50.x = b->v50.x;
    a->v50.y = b->v50.y;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b30 = b->b30;
    a->v50 = b->v50;
    a->b24 = b->b24;
    a->blk_dc.b13c = 24;
    a->blk_dc.b13d = 24;
    a->blk_dc.b13e = 32;
    a->blk_dc.b13f = 32;
    a->b24 = 12;
    func_0c02a0c4(a, 25, 0);
    func_0c1d53e4(a);
    a->w1e = 4;
    if (b->b411) {
        a->b06 = 5;
        a->b00 = 0;
        a->blk_dc.b12c = 0;
    }
    func_0c1aa9c4(a);
}

void func_0c1aa9c4(struct MeActor *a)
{
    register unsigned char m = dat_0c2f833e;
    struct MeActor *b = a->p18;

    if (m & (1 << (b->b02 ^ 1)))
        return;
    if (m) {
        if (b->b1d0 == 29 && b->b1e9 == 8)
            return;
    }
    dat_0c259c04[a->b06](a);
}

void func_0c1aaa0e(struct MeActor *a)
{
    dat_0c259c48[a->b07](a);
}

void func_0c1aaa20(struct MeActor *a, struct MeActor *b)
{
    a->b07++;
    a->b00 = 1;
    a->f34 = b->f34 + (b->blk_dc.w130 == 0 ? 80.0f : -80.0f);
    a->f38 = b->f41c + 548.571411133f;
    a->f5c = 0;
    a->f68 = 0;
    a->f60 = 0;
    a->f6c = -0.80357143f;
    func_0c02a0c4(a, 25, 12);
    func_0c1aaa86(a, b);
}

void func_0c1aaa86(struct MeActor *a, struct MeActor *b)
{
    a->f38 += a->f60;
    a->f60 += a->f6c;
    if (b->f41c < a->f38)
        return;
    a->b07++;
    a->f38 = b->f41c;
    a->blk_dc.w130 = b->blk_dc.w130;
    func_0c1abc64(a, b, dat_0c259bc4);
    func_0c1abcd4(a, b);
    func_0c02a026(a);
}
