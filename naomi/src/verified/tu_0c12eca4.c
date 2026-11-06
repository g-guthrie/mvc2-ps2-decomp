/* Throw/launch state handlers 0x0c12eca4..0x0c12f088. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c2f8338;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c13150c(struct Actor *);
extern void func_0c18b864(struct Actor *, int);
extern unsigned int func_0c02849a(void);
extern void func_0c1be510(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern void func_0c025762(void);
extern void (*table_0c24e094[])(struct Actor *);
extern void (*table_0c24e0a0[])(struct Actor *);

void func_0c12eca4(struct Actor *a)
{
    void *zero;
    zero = 0;
    if (!a->b6) {
        a->b6++;
        func_0c044cbc(a);
        func_0c048bb0(a, 5);
        a->b1f9 = (int)zero;
        a->b1a1 = 118;
        a->w1ac = (int)zero;
        a->b19e = (int)zero;
        *(void **)&a->p1c4 = zero;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 20, 1);
    }
    if (a->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0) {
        func_0c13150c(a);
    } else if (a->b141) {
        func_0c18b864(a, a->b141 - 1);
        a->b141 = (int)zero;
    }
}

void func_0c12ed7e(struct Actor *a)
{
    float dx;
    if (!a->b6) {
        a->b6++;
        a->s28 = 30;
        dx = -10.83333302f;
        if (a->b1d2)
            dx = 10.83333302f;
        a->f92 = dx;
        a->f104 = 0.0f;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
    } else {
        func_0c02a026(a);
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (--a->s28 == 0)
            func_0c13150c(a);
    }
}

void func_0c12ee46(struct Actor *a)
{
    float dx;
    if (!a->b6) {
        a->b6++;
        dx = 10.83333302f;
        if (a->w130)
            dx = -10.83333302f;
        a->f92 = dx;
        a->f104 = 0.0f;
        a->s28 = 30;
    }
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (--a->s28 == 0)
        func_0c13150c(a);
}

void func_0c12eeb4(struct Actor *a) { table_0c24e094[a->b6](a); }

void func_0c12eec6(struct Actor *a)
{
    struct Actor *p;
    unsigned int v;
    a->b12c = 0;
    if (dat_0c2f8338 < 2)
        return;
    a->b12c = 1;
    p = a->p20c;
    v = func_0c02849a() & 1;
    if (p->b1 == 58)
        v = a->b2;
    if (!v) {
        a->b6 = 2;
        a->b1f9 = 0;
        func_0c1be510(a, 0);
    } else {
        a->b6 = 1;
        a->b1f9 = 2;
        a->f56 += 548.571411133f;
        a->f96 = 0.0f;
        a->f108 = -0.401785702f;
    }
    func_0c02a0c4(a, 18, v);
}

void func_0c12ef96(struct Actor *a)
{
    func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->b6++;
        a->b1f9 = 0;
        a->f56 = a->f41c;
        dat_0c2d9260.b5 = 1;
        dat_0c2d9260.b6 = 1;
        func_0c0346da(a, 44);
        func_0c043324(a);
        func_0c02a0c4(a, 18, 2);
    }
}

void func_0c12f006(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}

void func_0c12f026(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c025762();
        func_0c13150c(a);
    } else
        table_0c24e0a0[a->b32](a);
}
