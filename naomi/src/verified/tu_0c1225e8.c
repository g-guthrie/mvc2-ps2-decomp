#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24d5b4[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);

void func_0c1225e8(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141)
        return;
    a->b6++;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = -16.666666031f;
    a->f104 = 0.33854166f;
    if (a->w130) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    a->s28 = 14;
    func_0c0344a0(a, 3);
}

void func_0c122648(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (--a->s28 != 0)
        return;
    a->b6++;
    a->f92 = -9.166666031f;
    a->f104 = 0.2734375f;
    if (a->w130) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    func_0c02a0c4(a, 2, 2);
}

void func_0c1226bc(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) >= 0)
        return;
    func_0c0437b8(a);
}

void func_0c1226fa(struct Actor *a)
{
    table_0c24d5b4[a->b6](a);
}
