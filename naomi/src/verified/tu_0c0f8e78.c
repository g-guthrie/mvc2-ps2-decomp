#include "objects.h"

struct Glob_0c0f8e78 {
    unsigned char pad[124];
    short w7c[1];
};

extern signed char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c1b3e6c(struct Actor *, int);
extern unsigned char dat_0c2f8384;
extern struct Glob_0c0f8e78 *dat_0c2f83f8;
extern unsigned char dat_0c2d9260[];
typedef void (*Handler_0c0f8e78)(struct Actor *);
extern Handler_0c0f8e78 table_0c24a778[];

void func_0c0f8e78(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0f8ed2(struct Actor *a)
{
    table_0c24a778[a->b6](a);
}

void func_0c0f8ee4(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b12c = 1;
    a->s28 = 60;
    func_0c02a0c4(a, 18, 0);
}

void func_0c0f8efc(struct Actor *a)
{
    func_0c02a026(a);
    if (!a->s28)
        a->b5 = a->b5 + 1;
    else
        a->s28 = a->s28 - 1;
}

void func_0c0f8f20(struct Actor *a)
{
    if (func_0c03916c(a))
        func_0c0437b8(a);
}

void func_0c0f8f40(struct Actor *a)
{
    switch (a->b7) {
    case 0:
        a->b7 = a->b7 + 1;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = -3.3333333f;
        if (a->w130)
            a->f92 = -a->f92;
        func_0c02a0c4(a, 0, 2);
        break;
    case 1:
        a->f52 += a->f92;
        a->f92 += a->f104;
        func_0c02a026(a);
        if (dat_0c2f8384) {
            a->b1a1 = 4;
            a->w1ac = 0;
            a->b19e = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->w7c[a->b2]++;
            a->b7 = a->b7 + 1;
            func_0c02a0c4(a, 8, 1);
        }
        break;
    case 2:
        if (func_0c02a026(a) < 0) {
            a->b7 = a->b7 + 1;
            func_0c02a0c4(a, 19, 1);
        } else if (a->b141) {
            a->b141 = 0;
            dat_0c2d9260[5] = 1;
            dat_0c2d9260[6] = 1;
        }
        break;
    case 3:
        func_0c02a026(a);
        break;
    }
    func_0c0f8f20(a);
}

void func_0c0f9060(struct Actor *a)
{
    if (a->b7 == 0) {
        a->s28 = 60;
        a->b7 = a->b7 + 1;
        func_0c02a0c4(a, 19, 6);
    } else
        func_0c02a026(a);
    func_0c0f8f20(a);
}

void func_0c0f9092(struct Actor *a)
{
    if (a->b7 == 0) {
        a->s28 = 60;
        a->b7 = a->b7 + 1;
        func_0c02a0c4(a, 19, 7);
    } else {
        func_0c02a026(a);
        if (a->b141) {
            a->b141 = 0;
            func_0c1b3e6c(a, 7);
        }
    }
    func_0c0f8f20(a);
}

void func_0c0f90d8(struct Actor *a)
{
    func_0c02a026(a);
    func_0c0f8f20(a);
}
