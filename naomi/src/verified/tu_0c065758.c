#include "objects.h"
extern void func_0c044cbc(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2403dc[])(struct Actor *);
extern void (*table_0c2403ec[])(struct Actor *);
void func_0c065758(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        func_0c0346da(a, 22);
        func_0c048bb0(a, 5);
        a->b1a1 = 86;
        a->b1f9 = 1;
        func_0c02a0c4(a, 20, 7);
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
    if (a->b1ff == 3) func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}
void func_0c065820(struct Actor *a) { table_0c2403dc[a->b6](a); }
void func_0c065832(struct Actor *a)
{
    a->b6++;
    a->s28 = 4;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f92 = a->b1d2 ? 12.5f : -12.5f;
    a->f104 = a->b1d2 ? -0.078125f : 0.078125f;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
}
void func_0c0658f2(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) a->b6++;
}
void func_0c06594e(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0 || (!a->b525 && (a->w34a & 0x400))) {
        a->b6++;
        func_0c02a0c4(a, 2, 2);
    }
}
void func_0c0659c6(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c0659e8(struct Actor *a) { table_0c2403ec[a->b6](a); }
