#include "objects.h"

struct Vec3_0c0a1f44 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243a98[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043014(struct Actor *, struct Vec3_0c0a1f44 *);

void func_0c0a1f44(struct Actor *a)
{
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 66;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 2);
}

void func_0c0a1fba(struct Actor *a)
{
    struct Vec3_0c0a1f44 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        v.x = 13.33333302f;
        v.y = 222.857132f;
        func_0c043014(a, &v);
    }
}

void func_0c0a2004(struct Actor *a)
{
    table_0c243a98[a->b6](a);
}

void func_0c0a2016(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 65;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&*(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
