#include "objects.h"

struct Vec3_0c12852c { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24da54[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043014(struct Actor *, struct Vec3_0c12852c *);

void func_0c12852c(struct Actor *a)
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
    a->b1a1 = 87;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 38);
}

void func_0c1285a2(struct Actor *a)
{
    struct Vec3_0c12852c v;
    float delta;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    } else {
        if (a->b141) {
            a->b141 = 0;
            v.x = 0.0f;
            v.y = 171.42856f;
            func_0c043014(a, &v);
        }
        if (a->b140) {
            a->b140 = 0;
            delta = -53.3333321f;
            if (a->w130)
                delta = 53.3333321f;
            a->f52 += delta;
        }
    }
}

void func_0c12860a(struct Actor *a)
{
    table_0c24da54[a->b6](a);
}
