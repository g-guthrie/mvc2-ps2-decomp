#include "objects.h"

struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };

extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
typedef void (*handler_0c0f8a70)(struct Actor *);
extern handler_0c0f8a70 table_0c24a75c[];

void func_0c0f8a70(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        a->b1a1 = 65;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->w7c[a->b2]++;
        a->b1f9 = 0;
        func_0c048bb0(a, 5);
        func_0c02a0c4(a, 20, 6);
        func_0c0346da(a, 22);
    }
    if (((unsigned char *)a)[0x1ff] == 3)
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
}

void func_0c0f8b36(struct Actor *a)
{
    table_0c24a75c[a->b6](a);
}

void func_0c0f8b48(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 == 0) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = a->b1d2 ? 10.0f : -10.0f;
    }
}
