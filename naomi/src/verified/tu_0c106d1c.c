#include "objects.h"

struct Byte1ff {
    unsigned char pad[0x1ff];
    unsigned char b1ff;
};

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c172474(struct Actor *, int, int);
extern void (*table_0c24b550[])(struct Actor *);
extern void (*table_0c24b55c[])(struct Actor *);

void func_0c106d1c(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6 = a->b6 + 1;
        func_0c048bb0(a, 5);
        a->b1f9 = 0;
        func_0c02a0c4(a, 20, 6);
        a->b1a1 = 28;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c0346da(a, 22);
    }
    if (((struct Byte1ff *)a)->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c172474(a, 1, 4);
    }
}

void func_0c106e02(struct Actor *a)
{
    table_0c24b550[a->b6](a);
}

void func_0c106e14(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6 = a->b6 + 1;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f92 = a->b1d2 ? 13.33333302f : -13.33333302f;
        a->s28 = 20;
    }
}

void func_0c106e9a(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (--a->s28 == 0) {
        a->b6 = a->b6 + 1;
        a->f104 = a->b1d2 ? -0.41666666f : 0.41666666f;
        func_0c02a0c4(a, 2, 2);
    }
}

void func_0c106efc(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c106f56(struct Actor *a)
{
    table_0c24b55c[a->b6](a);
}

void func_0c106f68(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6 = a->b6 + 1;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f92 = a->b1d2 ? -13.33333302f : 13.33333302f;
        a->s28 = 20;
    }
}
