/* Four actor state routines; reviewed span 0x0c101a7c..0x0c101bc0. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void (*dat_0c24b088[])(struct Actor *);

void func_0c101a7c(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b6 = 3;
        a->s28 = 20;
        func_0c02a0c4(a, 22, 15);
    }
}
void func_0c101aa8(struct Actor *a)
{
    if (!a->b6) {
        func_0c02a0c4(a, 19, 1);
        a->s28 = 60;
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
    }
    (void)func_0c02a026(a);
    if (--a->s28 < 0)
        func_0c0437b8(a);
}
void func_0c101afc(struct Actor *a)
{
    if (!a->b6) {
        a->b6++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->b1f9 = 0;
        a->f56 = a->f41c;
        a->b1a1 = 64;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        (void)func_0c02a39a(a, 0);
        func_0c0442fa(a);
        func_0c02a0c4(a, 21, 23);
    } else if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    }
}
void func_0c101b8a(struct Actor *a)
{
    dat_0c24b088[a->b6](a);
}
