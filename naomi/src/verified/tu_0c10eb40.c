#include "objects.h"

struct Vec3_0c10eb40 { float x, y, z; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043014(struct Actor *, struct Vec3_0c10eb40 *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1769b0(struct Actor *, int, int);

void func_0c10eb40(struct Actor *a)
{
    struct Vec3_0c10eb40 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        v.x = 95.0f;
        v.y = 60.0f;
        func_0c043014(a, &v);
    }
}

void func_0c10eb8a(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        a->b1a1 = 60;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 21, 61);
        a->s28 = -1;
        func_0c1769b0(a, 1, 1);
    }
    if (!a->b7) {
        func_0c02a026(a);
        if (a->s28 == 0) {
            a->b7++;
            func_0c02a0c4(a, 21, 62);
        } else {
            a->s28 = *(volatile short *)&a->s28 - 1;
        }
    } else {
        if (func_0c02a026(a) < 0)
            func_0c0437b8(a);
    }
}
