#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c240d30[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c06e4f4(struct Actor *a)
{
    if (a->b1 == 6) {
        if (!a->b6) {
            func_0c044cbc(a);
            a->b6++;
            if (a->b1fe == 0) {
                a->b1a1 = 68;
                a->b1f9 = 0;
                func_0c02a0c4(a, 20, 17);
            } else {
                a->b1a1 = 69;
                a->b1f9 = 1;
                func_0c02a0c4(a, 20, 18);
            }
            a->w1ac = 0;
            a->b19e = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            func_0c0346da(a, 21);
            func_0c048bb0(a, 5);
        }
        if (a->b1ff == 3)
            func_0c043352(a);
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c044df4(a);
        if (func_0c02a026(a) >= 0)
            return;
    }
    func_0c0437b8(a);
}

void func_0c06e5e0(struct Actor *a)
{
    table_0c240d30[a->b6](a);
}
