#include "objects.h"
extern void (*table_0c23f7a0[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern struct Actor *func_0c037da4(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c044548(struct Actor *, struct Actor *);
void func_0c0578c0(struct Actor *a) { table_0c23f7a0[a->b7](a); }
void func_0c0578d2(struct Actor *a)
{
    a->b7++;
    a->b1a1 = 37;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 10);
    func_0c0442fa(a);
    func_0c02a0c4(a, 15, 15);
}
void func_0c057920(struct Actor *a)
{
    struct LinkedActorVec3 position;
    struct Actor *target;
    if (func_0c02a026(a) < 0) {
        a->b7 = 9;
        a->f92 = a->f92 / 16.0f;
        a->f104 = 0;
        a->f96 = a->f96 / 8.0f;
        a->f108 = a->f108 / 64.0f;
        func_0c02a0c4(a, 15, 16);
    } else if ((target = func_0c037da4(a))) {
        func_0c0344a0(a, 5);
        a->b7++;
        func_0c025900(a, 5, 5);
        position.x = -146.66666f;
        position.y = 171.42856f;
        func_0c1d4610(a, &position);
        func_0c02a0c4(a, 15, 17);
        a->b1f7 = 196;
        func_0c044548(a, target);
    }
}
