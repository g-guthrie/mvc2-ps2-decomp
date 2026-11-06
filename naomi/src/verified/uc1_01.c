/* Actor landing/recovery handlers and three b4c9 mode selectors sharing two literal pools. */
#include "objects.h"

typedef void (*handler_uc1_01)(struct Actor *);
extern handler_uc1_01 dat_0c241234[];

extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c191980(struct Actor *, int);
extern void func_0c043014(struct Actor *, void *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c045248(struct Actor *, int);

struct V2_uc1_01 { float x, y, z; };

void func_0c075338(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    } else {
        if (a->b141 & 1) {
            a->b141 ^= 1;
            func_0c0344a0(a, 32);
            func_0c191980(a, 1);
        }
        if (a->b141 & 2) {
            struct V2_uc1_01 v;

            a->b141 ^= 2;
            v.x = -106.666667f;
            v.y = 102.85714f;
            func_0c043014(a, &v);
        }
    }
}

void func_0c0753a6(struct Actor *a)
{
    dat_0c241234[a->b6](a);
}

void func_0c0753b8(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0442fa(a);
    func_0c02a0c4(a, 20, 0);
}

void func_0c0753f8(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    } else if (a->b141) {
        a->b141 = 0;
        func_0c191980(a, 6);
    }
}

void func_0c075430(struct Actor *a)
{
    unsigned char six = 6;
    a->b7 = a->b6 = a->b5 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 5;
        break;
    case 1:
    case 2:
        a->b1e9 = six;
        break;
    }
    func_0c045248(a, 29);
}

void func_0c075492(struct Actor *a)
{
    unsigned char six = 6;
    a->b7 = a->b6 = a->b5 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 5;
        break;
    case 1:
    case 2:
        a->b1e9 = six;
        break;
    }
    func_0c045248(a, 29);
}

void func_0c0754c2(struct Actor *a)
{
    unsigned char zero = 0; int one = 1; int two = 2;
    a->b7 = a->b6 = a->b5 = zero;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = two;
        goto common;
    case 1:
        a->b1e9 = zero;
    common:
        a->b1a3 = one;
        break;
    case 2:
        a->b1e9 = one;
        a->b1a3 = one;
        a->b34 = two;
        if (!a->b1d2)
            a->b34 = 6;
        break;
    }
    func_0c045248(a, 21);
}

void func_0c075516(struct Actor *a)
{
    unsigned char zero = 0; int one = 1; int two = 2;
    a->b7 = a->b6 = a->b5 = zero;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = two;
        goto common;
    case 1:
        a->b1e9 = zero;
    common:
        a->b1a3 = one;
        break;
    case 2:
        a->b1e9 = one;
        a->b1a3 = one;
        a->b34 = two;
        if (!a->b1d2)
            a->b34 = 6;
        break;
    }
    func_0c045248(a, 21);
}

