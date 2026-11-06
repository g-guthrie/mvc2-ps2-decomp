#include "objects.h"

struct Byte1ff {
    unsigned char pad[0x1ff];
    unsigned char b1ff;
};

typedef void (*handler_0c0a83f8)(struct Actor *);

extern void func_0c044cbc(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c1a286c(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern handler_0c0a83f8 table_0c244440[];
extern handler_0c0a83f8 table_0c24444c[];

void func_0c0a83f8(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6 = a->b6 + 1;
        a->b1a1 = 29;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b1f9 = 0;
        func_0c02a0c4(a, 20, 3);
        func_0c0346da(a, 22);
        func_0c048bb0(a, 5);
        func_0c1a286c(a, 0, 2);
    }
    if (((struct Byte1ff *)a)->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) >= 0)
        return;
    func_0c0437b8(a);
}

void func_0c0a84ce(struct Actor *a)
{
    table_0c244440[a->b6](a);
}

void func_0c0a84e0(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        a->b6 = a->b6 + 1;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = a->b1d2 ? 15.83333302f : -15.83333302f;
        a->f52 += a->b1d2 ? 26.666666031f : -26.666666031f;
    }
}

void func_0c0a8588(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->b141) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = a->b1d2 ? 1.66666663f : -1.66666663f;
    }
}

void func_0c0a8606(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a8660(struct Actor *a)
{
    table_0c24444c[a->b6](a);
}
