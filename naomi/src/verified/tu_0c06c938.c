#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorFactory table_0c240974[];
extern ActorHandler table_0c240984[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c190d1c(struct Actor *, int, int);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c048ce6(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);

void func_0c06c938(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0439c4(a);
    else if (a->b141)
        a->b141 = 0;
}

void func_0c06c964(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 20, 16);
    } else if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}

void func_0c06c9ba(struct Actor *a)
{
    struct ActorSub2a4 *s;

    s = &a->sub2a4;
    if ((signed char)--s->b6 < 0) {
        s->b6 = 8;
        func_0c190d1c(a, 1, 12);
    }
}

#pragma noregsave(func_0c06c9da)
struct Actor *func_0c06c9da(struct Actor *a)
{
    return table_0c240974[a->b1f9](a);
}

struct Actor *func_0c06c9f2(struct Actor *a)
{
    struct Actor *r;

    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 3;
            return r;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 0;
            return r;
        }
    }
    return 0;
}

struct Actor *func_0c06ca98(struct Actor *a)
{
    return 0;
}

struct Actor *func_0c06ca9c(struct Actor *a)
{
    int z;
    struct Actor *q;

    z = 0;
    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return (struct Actor *)z;
    if (a->b1fe)
        return (struct Actor *)z;
    if ((unsigned char)a->b1a3 != 1)
        return (struct Actor *)z;
    if (a->f56 > 137.142853f) {
        if ((q = func_0c037d54(a)) != 0) {
            a->b1f7 = 1;
            return q;
        }
    }
    return (struct Actor *)z;
}

void func_0c06cafc(struct Actor *a)
{
    table_0c240984[a->b1f7 & 63](a);
}

void func_0c06cb14(struct Actor *a)
{
    func_0c025900(a, 5, 5);
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 0);
}

void func_0c06cb36(struct Actor *a)
{
    struct LinkedActorVec3 v;

    func_0c025900(a, 5, 5);
    a->b1a0 = 10;
    func_0c048ce6(a);
    v.x = -71.666664124f;
    v.y = 137.142853f;
    v.z = 0.0f;
    func_0c1d4610(a, &v);
    func_0c02a0c4(a, 15, 3);
}
