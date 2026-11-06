#include "objects.h"

typedef void (*ActorHandler_0c0567e8)(struct Actor *);
extern ActorHandler_0c0567e8 table_0c23f680[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern void func_0c0346da(struct Actor *, int);

void func_0c0567e8(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        func_0c048bb0(a, 5);
        if (a->b1fe == 0) {
            int r1, r3;

            r1 = 24;
            r3 = 1;
            a->b1a1 = r1;
            a->b1f9 = r3;
            func_0c02a0c4(a, 20, 3);
            a->w1ac = 0;
            a->b19e = 0;
            *(unsigned int *)&a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
        }
    }
    if (a->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (a->b14b) {
        func_0c0346da(a, 21);
        a->b14b = 0;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0568ca(struct Actor *a)
{
    table_0c23f680[a->b6](a);
}
