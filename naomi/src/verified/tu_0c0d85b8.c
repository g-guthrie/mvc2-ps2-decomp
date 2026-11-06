#include "objects.h"

struct Vec3_0c0d85b8 { float x, y, z; };
struct ActorRecord_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };

typedef void (*ActorSubHandler_0c0d85b8)(struct Actor *, struct ActorSub2a4 *);

extern struct ActorRecord_0c2f83f8 *dat_0c2f83f8;
extern ActorSubHandler_0c0d85b8 dat_0c2489ec[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c0d85b8 *, int);

void func_0c0d85b8(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0d85da(struct Actor *a)
{
    dat_0c2489ec[a->b6](a, &a->sub2a4);
}

void func_0c0d85f0(struct Actor *a, unsigned char *state)
{
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b6 = a->b6 + 1;
    a->b1a1 = 0x56;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->s28 = 0;
    a->s30 = 2;
    *state = 14;
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 25);
}

void func_0c0d868a(struct Actor *a)
{
    struct Vec3_0c0d85b8 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6 = a->b6 + 1;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 88.33333f;
        v.y = 162.857132f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    }
}
