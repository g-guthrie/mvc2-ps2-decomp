#include "objects.h"

typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorFactory table_0c241754[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c13c814(struct Actor *, int);
extern struct Actor *func_0c037d54(struct Actor *);

void func_0c07c648(struct Actor *a)
{
    struct LinkedActorVec3 v;

    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b140) {
        a->b140 = 0;
        func_0c02a39a(a, 0);
        v.x = 73.33333f;
        v.y = 102.85714f;
        func_0c043014(a, &v);
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c13c814(a, 5);
    }
}

#pragma noregsave(func_0c07c6ae)
struct Actor *func_0c07c6ae(struct Actor *a)
{
    return table_0c241754[a->b1f9](a);
}

struct Actor *func_0c07c6c6(struct Actor *a)
{
    struct Actor *r;

    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 0;
            return r;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 1;
            return r;
        }
    }
    return 0;
}

struct Actor *func_0c07c73e(struct Actor *a)
{
    return 0;
}
