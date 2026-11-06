/* Punch/kick selection and attack state routines; reviewed span 0x0c0f5364..0x0c0f5938. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24a470[])(struct Actor *);
extern char dat_0c24a3c0[], dat_0c24a3c4[], dat_0c24a3c8[], dat_0c24a3cc[], dat_0c24a3d0[], dat_0c24a3d4[];
extern char dat_0c24a3d8[], dat_0c24a3dc[], dat_0c24a3e0[], dat_0c24a3e4[], dat_0c24a3e8[], dat_0c24a3ec[];

void func_0c0f538c(struct Actor *a);
static void punch(struct Actor *a);
static void kick(struct Actor *a);

void func_0c0f5364(struct Actor *a)
{
    if ((a->b1fe == 0 && (a->b1d6 & 15) != 0) || (a->b1fe != 0 && (a->b1d6 & 0xf0) != 0))
        func_0c0f538c(a);
}
void func_0c0f538c(struct Actor *a)
{
    if ((unsigned char)a->b1fe == 1)
        kick(a);
    else
        punch(a);
}
static void punch(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 12;
        func_0c0346da(a, 20);
        if (!a->b1fc)
            a->p3f4 = dat_0c24a3c0;
        else
            a->p3f4 = dat_0c24a3d8;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 13;
        func_0c0346da(a, 21);
        if (!a->b1fc)
            a->p3f4 = dat_0c24a3c4;
        else
            a->p3f4 = dat_0c24a3dc;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2;
        a->b1a1 = 14;
        func_0c0346da(a, 22);
        if (!a->b1fc)
            a->p3f4 = dat_0c24a3c8;
        else
            a->p3f4 = dat_0c24a3e0;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 11, a->b158);
    if (a->b1d6 & 15)
        a->b1d6--;
}
static void kick(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 15;
        func_0c0346da(a, 20);
        if (!a->b1fc)
            a->p3f4 = dat_0c24a3cc;
        else
            a->p3f4 = dat_0c24a3e4;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 16;
        func_0c0346da(a, 21);
        if (!a->b1fc)
            a->p3f4 = dat_0c24a3d0;
        else
            a->p3f4 = dat_0c24a3e8;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2;
        a->b1a1 = 17;
        func_0c0346da(a, 22);
        if (!a->b1fc)
            a->p3f4 = dat_0c24a3d4;
        else
            a->p3f4 = dat_0c24a3ec;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 12, a->b158);
    if (a->b1d6 & 0xf0)
        a->b1d6 -= 16;
}
void func_0c0f55d4(struct Actor *a)
{
    dat_0c24a470[a->b1ff](a);
}
void func_0c0f55f6(struct Actor *a);
static void s56a0(struct Actor *a);
static void s570c(struct Actor *a);
static void s572e(struct Actor *a);
static void s5750(struct Actor *a);
void func_0c0f55e8(struct Actor *a)
{
    func_0c043352(a);
    func_0c0f55f6(a);
}
void func_0c0f55f6(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if ((unsigned char)a->b1fe == 1) {
        if (a->b1f9 == 1)
            s5750(a);
        else
            s572e(a);
    } else {
        if (a->b1f9 == 1)
            s570c(a);
        else
            s56a0(a);
    }
}
static void s56a0(struct Actor *a)
{
    if (a->b1e8 == 1) {
        if (func_0c02a026(a) >= 0) {
            if (a->b141) {
                a->b1a1 = 25;
                a->w1ac = 0;
                a->b19e = 0;
                a->p1c4 = 0;
                dat_0c2f83f8->arr[a->b2]++;
                a->b141 = 0;
            }
        } else
            goto die;
    } else if (func_0c02a026(a) < 0) {
    die:
        func_0c0437b8(a);
    }
}
static void s570c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
static void s572e(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
static void s5750(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c0f5788(struct Actor *a);
static void s57f0(struct Actor *a);
static void s5812(struct Actor *a);
void func_0c0f5772(struct Actor *a)
{
    func_0c0421f4(a);
    func_0c0420f8(a);
    func_0c0f5788(a);
}
void func_0c0f5788(struct Actor *a)
{
    func_0c042018(a);
    func_0c0421b8(a);
    if ((unsigned char)a->b1fe == 1)
        s5812(a);
    else
        s57f0(a);
    if (func_0c044e52(a))
        func_0c044f1c(a);
}
static void s57f0(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}
static void s5812(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}
void func_0c0f5834(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        a->b1f9 = 0;
        func_0c02a0c4(a, 20, 5);
        func_0c0346da(a, 22);
        a->b1a1 = 75;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c048bb0(a, 5);
    }
    if (a->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
