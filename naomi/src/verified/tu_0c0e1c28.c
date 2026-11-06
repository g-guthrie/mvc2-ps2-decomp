#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24926c[], table_0c24927c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);

void func_0c0e1c28(struct Actor *a)
{
    func_0c02a026(a);
    a->s28--;
    if (a->s28 <= 0) {
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c0437b8(a);
    }
}

void func_0c0e1c60(struct Actor *a)
{
    table_0c24926c[a->b6](a);
}

void func_0c0e1c72(struct Actor *a)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c048bb0(a, 32);
    a->b1f9 = 0;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f92 = a->w130 ? -3.3333333f : 3.3333333f;
    func_0c02a0c4(a, 21, 18);
}

void func_0c0e1cc8(struct Actor *a)
{
    table_0c24927c[a->b6](a);
}

void func_0c0e1cda(struct Actor *a)
{
    a->b6++;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b1f9 = 0;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f92 = a->w130 ? 3.3333333f : -3.3333333f;
    func_0c02a0c4(a, 21, 19);
}
