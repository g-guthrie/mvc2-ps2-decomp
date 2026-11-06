/* Actor state machine at 0x0c1aab2c: seven handlers of the object in me_00. */
#include "objects.h"

typedef void (*handler_me01)(struct MeActor *);

extern handler_me01 dat_0c259c58[];
extern int func_0c1abcd4(struct MeActor *a);
extern char func_0c02a026(struct MeActor *a);
extern void func_0c02a0c4(struct MeActor *a, int b, int c);
extern int func_0c028708(struct MeActor *a);

void func_0c1aac00(struct MeActor *a, struct MeActor *b);

void func_0c1aab2c(struct MeActor *a)
{
    if (func_0c1abcd4(a) == 0)
        a->b07++;
}

void func_0c1aab4a(struct MeActor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b06 = 2;
        a->b07 = 0;
    }
}

void func_0c1aab68(struct MeActor *a, struct MeActor *b)
{
    if (!b->b00 || b->b411)
        return;
    a->b06 = 2;
    a->b07 = 0;
    a->b00 = 1;
    a->blk_dc.b12c = 1;
    a->f34 = b->f34 + (b->blk_dc.w130 == 0 ? 80.0f : -80.0f);
    a->f38 = b->f41c;
    func_0c02a0c4(a, 25, 0);
}

void func_0c1aabb4(struct MeActor *a)
{
    dat_0c259c58[a->b07](a);
}

void func_0c1aabc6(struct MeActor *a, struct MeActor *b)
{
    a->b07++;
    a->f5c = 0;
    a->f68 = 0;
    a->f60 = 17.142857f;
    a->f6c = 0;
    func_0c02a0c4(a, 25, 15);
    func_0c1aac00(a, b);
}

void func_0c1aac00(struct MeActor *a, struct MeActor *b)
{
    func_0c02a026(a);
    if (a->blk_dc.b141)
        a->b07++;
}

void func_0c1aac1e(struct MeActor *a)
{
    a->f38 += a->f60;
    a->f60 += a->f6c;
    if (func_0c028708(a) == 0) {
        a->b06 = 5;
        a->b07 = 0;
        a->b00 = 0;
        a->blk_dc.b12c = 0;
    }
}
