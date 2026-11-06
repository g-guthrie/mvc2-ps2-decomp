/* Reviewed actor state group, 0x0c101564..0x0c101930. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c044df4(struct Actor *);
extern void func_0c1004a0(struct Actor *, int);
extern void func_0c16e480(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24b068[])(struct Actor *);
extern void (*dat_0c24b070[])(struct Actor *);
void func_0c1016fe(struct Actor *);
void func_0c1016a4(struct Actor *);

void func_0c101564(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    (void)func_0c02a026(a);
    if (--a->s28 < 0) {
        a->b6++;
        func_0c02a0c4(a, 22, 2);
    }
}
void func_0c1015a2(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        (void)func_0c02a39a(a, 0);
        func_0c0437b8(a);
    }
}
void func_0c1015ea(struct Actor *a)
{
    dat_0c24b068[a->b6](a);
}
void func_0c1015fc(struct Actor *a)
{
    if (a->b201) {
        func_0c1016fe(a);
        return;
    }
    a->b6++;
    if (a->b1f9 != 2)
        func_0c0432ca(a);
    a->b201 = 255;
    a->b1f9 = 2;
    a->b1fc = 0;
    a->f96 = 12.85714245f;
    a->f108 = -0.2678571343422f;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    *(short *)&a->sub2a4.b6 = 600;
    a->s28 = 16;
    func_0c02a0c4(a, 26, 0);
    func_0c1016a4(a);
}
void func_0c1016a4(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c1016fe(struct Actor *a)
{
    a->b201 = 0;
    a->f92 = a->f96 = a->f104 = 0.0f;
    a->f108 = -0.80357140303f;
    func_0c0438de(a);
}
void func_0c10171e(struct Actor *a)
{
    if (!a->b6) {
        a->b6++;
        func_0c048bb0(a, 2);
        func_0c0442fa(a);
        (void)func_0c02a39a(a, 0);
        a->b1a1 = 54;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 21, 18);
        a->b1d6 = 0;
        a->f92 /= 8.0f;
        a->f104 /= 8.0f;
        a->f96 /= 8.0f;
        a->f108 /= 8.0f;
    }
    if (a->b1f9 != 2) {
        func_0c044df4(a);
    } else {
        if (a->f41c <= a->f56) {
            a->f52 += a->f92;
            a->f92 += a->f104;
            a->f56 += a->f96;
            a->f96 += a->f108;
        }
    }
    if (func_0c02a026(a) < 0) {
        func_0c1004a0(a, 2);
    } else if (a->b141) {
        a->b141 = 0;
        *(unsigned char *)&a->sub2a4.s12 = 1;
        a->b27b = 0;
        a->b27a = 16;
        func_0c16e480(a, 0);
    }
}
void func_0c101876(struct Actor *a)
{
    dat_0c24b070[a->b6](a);
    if (a->b14b) {
        a->b1a1 = a->b14b;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = 0;
    }
}
void func_0c1018c2(struct Actor *a)
{
    a->b6++;
    (void)func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1f9 = 0;
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, 19);
}
