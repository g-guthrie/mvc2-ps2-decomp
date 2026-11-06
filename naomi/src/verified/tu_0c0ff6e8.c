/* Actor state routines; reviewed span 0x0c0ff6e8..0x0c0ff95c. */
#include "objects.h"
extern void func_0c045248(struct Actor *, int);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24ae00[])(struct Actor *);

void func_0c0ff6e8(struct Actor *a)
{
    a->b5 = 0;
    a->b6 = 0;
    a->b7 = 0;
    a->b1e9 = 3;
    switch (a->b4c9) {
    case 0: a->b1e9 = 3; break;
    case 1: a->b1e9 = 4; break;
    case 2: a->b1e9 = 4; break;
    }
    func_0c045248(a, 29);
}
void func_0c0ff71c(struct Actor *a)
{
    a->b5 = 0;
    a->b6 = 0;
    a->b7 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 3; break;
    case 1: a->b1e9 = 4; break;
    case 2: a->b1e9 = 4; break;
    }
    func_0c045248(a, 29);
}
void func_0c0ff74c(struct Actor *a)
{
    int zero = 0, one = 1;
    a->b5 = zero;
    a->b6 = zero;
    a->b7 = zero;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = zero;
        goto set;
    case 1:
        a->b1e9 = one;
        a->b1a3 = zero;
        break;
    case 2:
        a->b1e9 = 7;
    set:
        a->b1a3 = one;
        break;
    }
    func_0c045248(a, 21);
}
void func_0c0ff78e(struct Actor *a)
{
    int zero = 0, one = 1;
    a->b5 = zero;
    a->b6 = zero;
    a->b7 = zero;
    switch (a->b4c9) {
    case 0: a->b1e9 = zero; break;
    case 1: a->b1e9 = one; break;
    case 2: goto two; two: a->b1e9 = 7; break;
    default: goto call;
    }
    a->b1a3 = one;
call:
    goto tail;
tail:
    func_0c045248(a, 21);
}
void func_0c0ff7d8(struct Actor *a)
{
    dat_0c24ae00[a->b6](a);
}
void func_0c0ff7ea(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 2;
    (void)func_0c02a39a(a, 0);
    a->f92 = -30.0f;
    a->f96 = -9.642857f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    if (a->b1d2) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    a->b1a1 = 66;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
void func_0c0ff86a(struct Actor *a)
{
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c + -85.71428f > a->f56) {
        a->b6++;
        a->b1f9 = 0;
        a->f56 = a->f41c;
        a->s28 = 6;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 20, 1);
    }
}
void func_0c0ff8fc(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        if (--a->s28 == 0)
            func_0c0437b8(a);
    }
}
