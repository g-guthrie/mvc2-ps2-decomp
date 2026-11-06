#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0439c4(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c048ce6(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct Vec3_tu5_03 *);
extern ActorHandler table_0c2404d8[];

void func_0c0676fc(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c06776a(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0439c4(a);
    }
}

int func_0c067792(void)
{
    return 0;
}

void func_0c067796(struct Actor *a)
{
    struct Vec3_tu5_03 v;

    if (a->b255 != 8 && a->b255 != 3)
        func_0c025900(a, 1, 1);
    func_0c048ce6(a);
    a->s28 = 12;
    a->b1ea = 1;
    v.x = a->f100;
    v.y = 0.61104912f;
    func_0c1d4610(a, &v);
    if (a->b1f9 != 2) {
        int r6;
        if (a->b255 != 8) {
            r6 = 11;
            func_0c02a0c4(a, 21, r6);
        } else {
            r6 = 21;
            func_0c02a0c4(a, r6, r6);
        }
    } else
        func_0c02a0c4(a, 21, 16);
}

void func_0c067820(struct Actor *a)
{
    a->b1ea = 1;
    table_0c2404d8[a->b6](a);
}
