#include "objects.h"

struct Obj_0c162a18 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[24 - 7];
    struct Obj_0c162a18 *p24;
    unsigned char pad2[0x34 - 28];
    float f52, f56;
    unsigned char pad3[0x5c - 0x3c];
    float f92, f96, f100, f104, f108;
    unsigned char pad4[0x130 - 0x70];
    unsigned short w130;
    unsigned char pad5[0x141 - 0x132];
    char b141;
    unsigned char pad6[0x41c - 0x142];
    float f41c;
};

extern char func_0c02a026(struct Obj_0c162a18 *);

void func_0c162a18(struct Obj_0c162a18 *a)
{
    if (a->b141) {
        a->b6 = a->b6 + 1;
        a->b141 = 0;
        a->f92 = -5.0f;
        a->f104 = 0.0520833321f;
        a->f96 = 3.21428561211f;
        a->f108 = -0.5357143f;
        if (a->w130) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
    func_0c02a026(a);
}

void func_0c162a6a(struct Obj_0c162a18 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->p24->f41c) {
        a->b6 = a->b6 + 1;
        a->f56 = a->p24->f41c;
        a->f96 = 3.21428561211f;
        a->f108 = -0.5357143f;
    }
    func_0c02a026(a);
}

void func_0c162ad6(struct Obj_0c162a18 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->p24->f41c) {
        a->b6 = a->b6 + 1;
        a->f56 = a->p24->f41c;
    }
    func_0c02a026(a);
}

void func_0c162b32(struct Obj_0c162a18 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (a->b141) {
        a->b6 = a->b6 + 1;
        a->b141 = 0;
    }
    func_0c02a026(a);
}
