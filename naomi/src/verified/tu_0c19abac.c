/* Seven linked actor callbacks and their two retail literal pools. */
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
extern handler_me00 dat_0c258734[];
extern handler_me00 table_0c258724[];
void func_0c19abe4(struct MeActor *a);
void func_0c19ad00(struct MeActor *a);
extern handler_me00 table_0c258780[];

struct MeActor *func_0c19abac(struct MeActor *a)
{
    struct MeActor *q;
    struct MeActor **slot = &a->p2a4;
    if ((q = func_0c0374da(0, 4, 0)) != 0) {
        q->p10 = func_0c19abe4;
        q->p18 = a;
        ((unsigned char *)slot)[4] = 1;
        *slot = q;
    }
    return q;
}

void func_0c19abe4(struct MeActor *a)
{
    table_0c258724[a->b04](a);
}

void func_0c19abf6(struct MeActor *a)
{
    struct MeActor *b;

    if (dat_0c2d6f84->l14 == 0x80) {
        a->b04 = 2;
        a->b05 = 0;
        return;
    }
    a->b04++;
    a->w26 = 0x1003;
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
    a->blk_dc.b13e = 16;
    a->blk_dc.b13f = 16;
    a->b24 = 12;
    func_0c02a0c4(a, 23, 0);
    func_0c1d53e4(a);
    a->w1e = 4;
    if (b->b411) {
        a->b06 = 5;
        a->b00 = 0;
        a->blk_dc.b12c = 0;
    }
    func_0c19ad00(a);
}

void func_0c19ad00(struct MeActor *a)
{
    register unsigned char m = dat_0c2f833e;
    struct MeActor *b = a->p18;

    if (m & (1 << (b->b02 ^ 1)))
        return;
    if (m) {
        if (b->b1d0 == 29 && b->b1e9 == 6)
            return;
    }
    dat_0c258734[a->b06](a);
}

void func_0c19ad4a(struct MeActor *a)
{
    table_0c258780[a->b07](a);
}

void func_0c19ad5c(struct MeActor *a)
{
    a->b07++;
    a->blk_dc.b12c = 0;
    a->b00 = 0;
    func_0c02a0c4(a, 23, 17);
}

void func_0c19ad72(struct MeActor *a, struct MeActor *b)
{
    if (b->b04 == 0 && b->blk_dc.b159 == 18 && b->blk_dc.b141 != 0)
        return;
    a->b07++;
    a->blk_dc.b12c = 1;
    a->b00 = 1;
    a->b24 = 0;
    a->blk_dc.w130 = b->blk_dc.w130 ^ 1;
    if (b->blk_dc.w130 == 0) {
        a->f34 = b->f34 - 36.666664124f;
        a->f5c = 3.3333333f;
    } else {
        a->f34 = b->f34 + 36.666664124f;
        a->f5c = -3.3333333f;
    }
    a->f38 = b->f38 + 64.2857132f;
    a->f68 = 0.0f;
    a->f60 = 12.857142448425293f;
    a->f6c = -0.80357140303f;
    func_0c02a0c4(a, 23, 17);
}
