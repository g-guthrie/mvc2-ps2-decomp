#include "objects.h"

struct Vec3_0c067488 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2404c4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct Vec3_0c067488 *);

void func_0c067488(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2)
            func_0c0438de(a);
        else
            func_0c0437b8(a);
    }
}
void func_0c0674bc(struct Actor *a) { table_0c2404c4[a->b6](a); }
void func_0c0674ce(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c0346da(a, 22);
    a->b1a1 = 85;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 2);
}
void func_0c067544(struct Actor *a)
{
    struct Vec3_0c067488 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        v.x = 0.0f;
        v.y = 137.142853f;
        func_0c043014(a, &v);
    }
    if (a->b140) {
        a->b140 = 0;
        func_0c0346da(a, 22);
    }
}
