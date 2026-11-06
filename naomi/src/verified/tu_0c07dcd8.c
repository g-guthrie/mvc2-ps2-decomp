#include "objects.h"
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c08183c(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2419b0[])(struct Actor *);
void func_0c07dcd8(struct Actor *a)
{
    float displacement;
    if (!a->b6) {
        a->b6++;
        func_0c044cbc(a);
        func_0c048bb0(a, 5);
        a->b1f9 = 0;
        a->b1a1 = 120;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 20, 23);
    }
    if (a->b1ff == 3) func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0) func_0c08183c(a);
    else if ((char)a->b140 > 0) {
        displacement = (char)a->b140 * 1.66666663f;
        if (a->w130) displacement = -displacement;
        a->f52 += displacement;
        a->b140 = 0;
    }
}
void func_0c07ddc8(struct Actor *a) { table_0c2419b0[a->b6](a); }
