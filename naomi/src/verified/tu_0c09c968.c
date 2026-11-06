#include "objects.h"

struct Vec3_0c09c968 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243624[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct Vec3_0c09c968 *);
extern void func_0c0346da(struct Actor *, int);

void func_0c09c968(struct Actor *a)
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
    a->b1a1 = 52;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 25);
}

void func_0c09c9de(struct Actor *a)
{
    struct Vec3_0c09c968 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 = 0;
        v.x = 0.0f;
        v.y = 53.57143f;
        v.z = 0.0f;
        func_0c043014(a, &v);
    } else if (a->b141 & 2) {
        a->b141 = 0;
        func_0c0346da(a, 22);
    }
}

void func_0c09ca44(struct Actor *a) { table_0c243624[a->b6](a); }
