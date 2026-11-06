#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243a88[], table_0c243a90[];
extern void func_0c09e43a(struct Actor *);
extern void func_0c09e45e(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);

void func_0c0a1ddc(struct Actor *a)
{
    func_0c09e43a(a);
    if (a->b143 < 0) {
        a->b6++;
        a->w130 ^= 1;
        func_0c02a0c4(a, 22, 10);
    }
    func_0c02a026(a);
}

void func_0c0a1e12(struct Actor *a)
{
    func_0c09e45e(a);
    if (a->f92 * a->f104 < 0.0f) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    } else {
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a1e94(struct Actor *a)
{
    table_0c243a88[a->b6](a);
}

void func_0c0a1ea6(struct Actor *a)
{
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c02a0c4(a, 21, 7);
}

void func_0c0a1ee6(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a1f08(struct Actor *a)
{
    table_0c243a90[a->b6](a);
}
