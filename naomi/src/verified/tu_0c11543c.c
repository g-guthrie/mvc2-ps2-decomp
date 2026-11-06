/* Actor-state translation unit, including its shared selector and velocity pools. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c043014(struct Actor *, void *);

struct ActorCounts { unsigned char pad[124]; short counts[64]; };
typedef void (*ActorHandler_0c11543c)(struct Actor *);
struct Vec3_0c11543c { float x, y, z; };
extern struct ActorCounts *dat_0c2f83f8;
extern ActorHandler_0c11543c table_0c24c2e8[];
void func_0c11548e(struct Actor *, struct Actor *);
void func_0c115542(struct Actor *, struct Actor *);

void func_0c11543c(struct Actor *a, struct Actor *b)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a0c4(a, 20, 2);
    func_0c11548e(a, b);
}

void func_0c11548e(struct Actor *a, struct Actor *b)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c1154b0(struct Actor *a)
{
    table_0c24c2e8[a->b6](a);
}

void func_0c1154c2(struct Actor *a, struct Actor *b)
{
    register int arg6;

    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    arg6 = 8;
    a->b1a1 = 54;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 21, arg6);
    func_0c115542(a, b);
}

void func_0c115542(struct Actor *a, struct Actor *b)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        struct Vec3_0c11543c v;

        a->b141 = 0;
        v.x = -5.0f;
        v.y = 158.57143f;
        func_0c043014(a, &v);
    }
}
