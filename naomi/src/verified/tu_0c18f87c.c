#include "objects.h"

struct Obj_18f87c {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char b5;
    unsigned char pad1[0x31 - 6];
    char b31;
    unsigned char pad2[0x34 - 0x32];
    float f52, f56;
    unsigned char pad3[0x5c - 0x3c];
    float f92, f96, f100, f104, f108;
    unsigned char pad4[0x12c - 0x70];
    unsigned char b12c;
    unsigned char pad5[0x141 - 0x12d];
    char b141;
};

typedef void (*handler_18f87c)(struct Obj_18f87c *);

extern char func_0c02a026(struct Obj_18f87c *);
extern int func_0c02850e(struct Obj_18f87c *);
extern handler_18f87c table_0c257338[];
extern handler_18f87c table_0c257344[];
extern void func_0c037688(struct Obj_18f87c *);

void func_0c18f87c(struct Obj_18f87c *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (func_0c02850e(a) == 0) {
        a->b12c = 0;
        a->b4 = a->b4 + 1;
    }
}

void func_0c18f8dc(struct Obj_18f87c *a)
{
    a->b31 = -4;
    table_0c257338[a->b5](a);
}

void func_0c18f8f6(struct Obj_18f87c *a)
{
    func_0c02a026(a);
    if (a->b141 == 0)
        a->b5 = a->b5 + 1;
    a->f56 -= 10.714285f;
}

void func_0c18f922(struct Obj_18f87c *a)
{
    func_0c02a026(a);
}

void func_0c18f928(struct Obj_18f87c *a)
{
    a->b31 = 4;
    table_0c257344[a->b5](a);
}

int func_0c18f942(struct Obj_18f87c *p)
{
    p->b4++;
    p->b12c = 0;
}

void func_0c18f950(struct Obj_18f87c *a)
{
    func_0c037688(a);
}
