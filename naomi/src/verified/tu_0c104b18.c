/* Exact 764-byte Actor group: eight routines and two literal pools. */
#include "objects.h"

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c170378(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void (*table_0c24b318[])(struct Actor *);
extern void (*table_0c24b320[])(struct Actor *);

void func_0c104b18(struct Actor *a)
{
    int zero = 0;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    a->b7 = zero;
    a->f56 = a->f41c;
    a->b1f9 = zero;
    a->s28 = 10;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 62;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 7);
}

void func_0c104ba2(struct Actor *a)
{
    struct LinkedActorVec3 position;
    int zero = 0;

    if (!a->b7) {
        a->b3f8 = 2;
        a->b328 = 5;
        a->b3f1 = a->b255 == 6 ? 2 : 0;
        func_0c02a026(a);
        if (a->b141 & 1) {
            a->b3f0 = zero;
            a->b3f1 = zero;
            a->b7++;
            a->b141 ^= 1;
            position.x = 66.666664124f;
            position.y = -132.857132f;
            func_0c0429a4(a, &position, 1);
        }
    } else {
        a->b3f8 = 2;
        a->b328 = 5;
        if (func_0c02a026(a) >= 0) {
            if (a->b141 & 2) {
                a->b141 ^= 2;
                func_0c170378(a);
            }
        } else {
            if (--a->s28 == 0) {
                a->b3f9 = zero;
                a->b3f8 = zero;
                a->b6++;
                a->b7 = zero;
                func_0c02a0c4(a, 22, 9);
            }
        }
    }
}

void func_0c104cb6(struct Actor *a)
{
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b327 = 0;
        a->b328 = 0;
        func_0c0437b8(a);
    }
}

void func_0c104ce8(struct Actor *a)
{
    table_0c24b318[a->b6](a);
}

void func_0c104cfa(struct Actor *a)
{
    int zero = 0;
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = zero;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 20, zero);
}

void func_0c104d28(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c104d4a(struct Actor *a)
{
    table_0c24b320[a->b6](a);
}

void func_0c104d5c(struct Actor *a)
{
    int zero = 0;
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = zero;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 69;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c02a684(a, 0, a->b37 * 48 + 34, 1);
    func_0c02a0c4(a, 21, 20);
}
