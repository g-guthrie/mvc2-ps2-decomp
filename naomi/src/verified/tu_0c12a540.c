/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0438de(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c241100[])(struct Actor *);
extern void (*table_0c24dcc8[])(struct Actor *);

void func_0c12a540(struct Actor *a)
{
    if (!a->b6) {
        a->b6++;
        a->b1f9 = 0;
        a->b1a1 = 20;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c044cbc(a);
        func_0c048bb0(a, 5);
        func_0c02a0c4(a, 20, 1);
        func_0c0346da(a, 22);
    }
    if (a->b1ff == 3) func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}

void func_0c12a606(struct Actor *a) {
    table_0c24dcc8[a->b6](a);
}
