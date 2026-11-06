#include "objects.h"

struct Vec3_0c085ac8 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2421c8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct Vec3_0c085ac8 *);
extern void func_0c0346da(struct Actor *, int);

void func_0c085ac8(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 86;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 15);
}

void func_0c085b3e(struct Actor *a)
{
    struct Vec3_0c085ac8 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        v.x = 26.666666031f;
        v.y = 102.85714f;
        func_0c043014(a, &v);
    }
    if (a->b14b) {
        a->b14b = 0;
        func_0c0346da(a, 22);
    }
}

void func_0c085b9c(struct Actor *a) { table_0c2421c8[a->b6](a); }
