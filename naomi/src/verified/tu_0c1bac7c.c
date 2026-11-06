#include "objects.h"

struct Vec3_0c1bac7c {
    float x, y, z;
};

struct Region_0c1bac7c {
    unsigned char pad0[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad1[3];
    unsigned short w130;
    unsigned char pad2[0x158 - 0x132];
    short s158;
    unsigned char pad3[0xc0 - (0x15a - 0xdc)];
};

struct Obj_0c1bac7c {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char pad3;
    unsigned char b4;
    unsigned char pad5[16 - 5];
    void (*p16)(struct Obj_0c1bac7c *);
    unsigned char pad20[24 - 20];
    struct Obj_0c1bac7c *p24;
    short s28;
    unsigned char pad30[32 - 30];
    unsigned char b32;
    unsigned char pad33;
    unsigned char b34;
    unsigned char pad35;
    unsigned char b36;
    unsigned char pad37;
    unsigned short w38;
    unsigned char pad40[48 - 40];
    unsigned char b48;
    unsigned char pad49[52 - 49];
    float f52, f56;
    unsigned char pad60[80 - 60];
    struct Vec3_0c1bac7c v80;
    unsigned char pad92[0xdc - 92];
    struct Region_0c1bac7c region;
    unsigned char pad19c[0x1a3 - 0x19c];
    unsigned char b1a3;
    unsigned char b1a4;
};

extern struct Obj_0c1bac7c *func_0c0374da(int, int, int);
extern void func_0c02a0c4(struct Obj_0c1bac7c *, int, int);
extern void (*table_0c25b924[])(struct Obj_0c1bac7c *);
extern void (*table_0c25b934[])(struct Obj_0c1bac7c *);

void func_0c1bacca(struct Obj_0c1bac7c *a);

struct Obj_0c1bac7c *func_0c1bac7c(struct Obj_0c1bac7c *a, unsigned char c)
{
    struct Obj_0c1bac7c *p;

    if ((p = func_0c0374da(0, 3, 0)) != 0) {
        p->p16 = func_0c1bacca;
        p->p24 = a;
        p->b1 = a->b1;
        p->b32 = c;
        p->w38 = 0x3500;
        p->f52 = a->f52;
        p->f56 = a->f56;
        p->s28 = a->region.s158;
    }
    return p;
}

void func_0c1bacca(struct Obj_0c1bac7c *a)
{
    struct Obj_0c1bac7c *p = a;

    table_0c25b924[p->b4](p);
}

void func_0c1bacdc(struct Obj_0c1bac7c *a)
{
    struct Obj_0c1bac7c *b = a->p24;

    a->b4 = a->b4 + 1;
    a->region = b->region;
    a->region.b12c = 1;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->v80.x = b->v80.x;
    a->v80.y = b->v80.y;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b48 = b->b48;
    a->v80 = b->v80;
    a->b36 = b->b36;
    table_0c25b934[a->b32](a);
}

void func_0c1bad4c(struct Obj_0c1bac7c *a)
{
    a->b36 = 11;
    func_0c02a0c4(a, 23, 3);
}

void func_0c1bad5a(struct Obj_0c1bac7c *a)
{
    a->b36 = 11;
    a->b34 = 0;
    func_0c02a0c4(a, 23, 7);
}

void func_0c1bad6e(struct Obj_0c1bac7c *a)
{
    float d;

    a->b36 = 11;
    d = 236.66666f;
    if (a->region.w130 == 0)
        d = -236.66666f;
    a->f52 += d;
    a->f56 += 160.71428f;
    func_0c02a0c4(a, 23, 8);
}

void func_0c1bada2(struct Obj_0c1bac7c *a)
{
    float d;

    a->b36 = 11;
    d = 161.66666f;
    if (a->region.w130 == 0)
        d = -161.66666f;
    a->f52 += d;
    a->f56 += 210.0f;
    func_0c02a0c4(a, 23, 8);
}
