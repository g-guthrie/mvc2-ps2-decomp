#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c244900[])(struct Actor *);
extern int (*table_0c244908[])(struct Actor *);

void func_0c0af96c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0af98e(struct Actor *a)
{
    table_0c244900[a->b6](a);
}

void func_0c0af9a0(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    (void)func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 62;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 17);
}

void func_0c0afa16(struct Actor *a)
{
    struct LinkedActorVec3 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        v.x = -80.0f;
        v.y = 137.142853f;
        func_0c043014(a, &v);
    }
}

int func_0c0afa60(struct Actor *a)
{
    return table_0c244908[a->b1f9](a);
}
