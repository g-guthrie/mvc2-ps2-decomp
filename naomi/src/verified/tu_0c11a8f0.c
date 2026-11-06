#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
typedef void (*ActorSubHandler)(struct Actor *, struct ActorSub2a4 *);
extern ActorHandler table_0c24cda8[], table_0c24cdb0[], table_0c24cdc4[];
extern ActorSubHandler table_0c24cdec[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c11a8f0(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 < a->f41c) {
        a->f56 = a->f41c;
        a->b6++;
        func_0c02a0c4(a, 1, 3);
        func_0c043324(a);
        func_0c0344a0(a, 31);
    }
}

void func_0c11a970(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}

void func_0c11a990(struct Actor *a)
{
    table_0c24cda8[a->b6](a);
}

void func_0c11a9a2(struct Actor *a)
{
    func_0c02a0c4(a, 19, 0);
}

void func_0c11a9aa(struct Actor *a)
{
    func_0c02a0c4(a, 19, 1);
}

void func_0c11a9b2(struct Actor *a)
{
    a->b6++;
    a->b7 = 0;
    table_0c24cdb0[a->b32](a);
}

void func_0c11a9d2(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c0437b8(a);
        return;
    }
    func_0c02a026(a);
}

void func_0c11a9f4(struct Actor *a)
{
    table_0c24cdc4[a->b1e9](a);
}

void func_0c11aa08(struct Actor *a)
{
    table_0c24cdec[a->b6](a, &a->sub2a4);
}
