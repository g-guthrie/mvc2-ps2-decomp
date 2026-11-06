#include "objects.h"

struct Sub_0c07a71c {
    unsigned char pad[34];
    short s34;
};

struct Obj_0c07a71c {
    unsigned char pad0[5];
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[0x1a3 - 8];
    char b1a3;
    unsigned char pad2[0x1e9 - 0x1a4];
    unsigned char b1e9;
    unsigned char pad3[0x2a4 - 0x1ea];
    struct Sub_0c07a71c sub;
    unsigned char pad4[0x4c9 - 0x2a4 - 36];
    char b4c9;
};

extern void func_0c045248(struct Obj_0c07a71c *, int);

void func_0c07a71c(struct Obj_0c07a71c *a)
{
    int zero = 0;

    a->b5 = zero;
    a->b7 = zero;
    a->b6 = zero;
    switch (a->b4c9) {
    case 0: a->b1e9 = 6; break;
    case 1: a->b1e9 = 2; break;
    case 2: a->b1e9 = 3; break;
    }
    a->b1a3 = 1;
    func_0c045248(a, 29);
}

void func_0c07a75e(struct Obj_0c07a71c *a)
{
    int zero = 0;

    a->b5 = zero;
    a->b7 = zero;
    a->b6 = zero;
    switch (a->b4c9) {
    case 0: a->b1e9 = 6; break;
    case 1: a->b1e9 = 2; break;
    case 2: a->b1e9 = 3; break;
    }
    a->b1a3 = 1;
    func_0c045248(a, 29);
}

void func_0c07a7a0(struct Obj_0c07a71c *a)
{
    int one = 1;
    int zero = 0;
    struct Sub_0c07a71c *s;

    a->b5 = zero;
    a->b7 = zero;
    a->b6 = zero;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = one;
        s = &a->sub;
        s->s34 = one;
        break;
    case 1:
    case 2:
        a->b1e9 = zero;
        break;
    }
    a->b1a3 = one;
    func_0c045248(a, 21);
}
