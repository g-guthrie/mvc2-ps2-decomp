/* Special normal-attack state routines; reviewed span 0x0c126578..0x0c126b70. */
#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern void func_0c044cbc(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern unsigned char func_0c044ede(struct Actor *);
extern void func_0c02a18c(struct Actor *, int, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c24d828[], dat_0c24d868[];
extern unsigned char dat_0c24d7f8[], dat_0c24d7e0[], dat_0c24d810[];
extern void (*dat_0c24d918[])(struct Actor *);
extern void (*dat_0c24d928[])(struct Actor *);
void func_0c1266e4(struct Actor *);
void func_0c1267fc(struct Actor *);
void func_0c126840(struct Actor *);

int func_0c126578(struct Actor *a)
{
    if (func_0c046e7e(a, dat_0c24d828, a->x364) && *a->p40c) {
        a->b258 = 0;
        goto one;
    }
    if (func_0c046e7e(a, dat_0c24d868, a->x384) && *a->p40c) {
        a->b258 = 6;
    one:
        return 1;
    }
    return 0;
}
void func_0c1265d2(struct Actor *a)
{
    if (a->sub2a4.b7)
        a->sub2a4.b7--;
}
void func_0c1265e4(struct Actor *a)
{
    func_0c044cbc(a);
    a->p3f4 = dat_0c24d7f8 + ((unsigned char)a->b1fe * 12 + a->b1e8 * 4);
    a->b1a7 = a->b1e8;
    if (a->b1fe && a->b1e8 == 2 && !a->b1f9)
        a->b1a1 = 25;
    else {
        goto e;
    e:
        a->b1a1 = a->b1f9 * 6 + a->b1fe * 3 + a->b1e8;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    goto call;
call:
    func_0c02a0c4(a, a->b1f9 * 2 + a->b1fe + 7, (char)a->b1e8);
    if (a->b1fe || a->b1e8 != 2)
        func_0c0346da(a, (char)a->b1e8 + 20);
}
void func_0c1266e4(struct Actor *a)
{
    int n = (unsigned char)a->b1fe * 12 + a->b1e8 * 4;
    int o = (short)n;
    unsigned char *p;
    if (!a->b1fc) p = dat_0c24d7e0; else p = dat_0c24d810;
    p += o;
    a->p3f4 = p;
    a->b1a7 = a->b1e8;
    a->b1a1 = a->b1fe * 3 + a->b1e8 + 12;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, a->b1fe + 11, (char)a->b1e8);
    func_0c0346da(a, (char)a->b1e8 + 20);
    if (!a->b1fe) {
        if (a->b1d6 & 15)
            a->b1d6--;
    } else if (a->b1d6 & 0xf0)
        a->b1d6 -= 16;
}
void func_0c1267c4(struct Actor *a)
{
    if (!a->b1fe) {
        if (a->b1d6 & 0x0f)
            goto call;
    } else if (a->b1d6 & 0xf0) {
    call:
        func_0c1266e4(a);
    }
}
void func_0c1267e8(struct Actor *a) { dat_0c24d918[a->b1ff](a); }
void func_0c1267fc(struct Actor *a)
{
    float d;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    goto x;
x:
    if (a->b140) {
        a->b140 = 0;
        d = -53.3333321f;
        if (a->w130)
            d = 53.3333321f;
        a->f52 += d;
    }
}
void func_0c126840(struct Actor *a)
{
    if (!a->b6) {
        func_0c02a026(a);
        if (!a->b141) {
            a->b6++;
            a->f92 = -6.66666651f;
            a->f104 = 0.41666666f;
            a->f96 = 8.5714283f;
            a->f108 = -0.80357140303f;
            if (a->b1d2) {
                a->f92 = -a->f92;
                a->f104 = -a->f104;
            }
        }
    } else if (a->b6 == 1) {
        func_0c02a026(a);
        if (func_0c044ede(a)) {
            a->b1f9 = 0;
            a->b6++;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            func_0c02a18c(a, 8, 2, 7);
            func_0c043324(a);
        }
    } else if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c12693c(struct Actor *a)
{
    switch (a->b1ff) {
    case 3:
        func_0c043352(a);
    case 0:
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c044df4(a);
        if (!a->b1f9 && a->b1e8 == 2) {
            if (!a->b1fe)
                func_0c1267fc(a);
            else
                func_0c126840(a);
        } else if (func_0c02a026(a) < 0)
            func_0c0437b8(a);
        break;
    case 2:
        func_0c0421f4(a);
        func_0c0420f8(a);
    case 1:
        func_0c042018(a);
        func_0c0421b8(a);
        if (func_0c02a026(a) < 0)
            func_0c0438de(a);
        if (func_0c044e52(a))
            func_0c044f1c(a);
        break;
    }
}
void func_0c126a4a(struct Actor *a)
{
    if (a->b1ff == 3)
        func_0c043352(a);
    if (!a->b6) {
        a->b6++;
        func_0c044cbc(a);
        a->b1a1 = 88;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b1f9 = 1;
        func_0c048bb0(a, 5);
        func_0c02a0c4(a, 20, 27);
        func_0c0346da(a, 21);
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c126b12(struct Actor *a) { dat_0c24d928[a->b6](a); }
