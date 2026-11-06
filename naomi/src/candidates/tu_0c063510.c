/* Candidate (1270/1364): fourteen functions, full linked extent. The 2.0f
   divisor in func_0c0636be is now a plain literal (fldi1; fadd in fr3, exact).
   Residuals: func_0c0636be swaps two pointer temporaries (r1/r2 vs r3/r1);
   func_0c063768 rotates r1/r2/r3 around the dat_0c2f83f8 counter; func_0c06397a
   tests b1a3 in r2 not r3; func_0c0639a6 places its shared `return 0` block
   before the final b1f7=0 store instead of after it, which shifts
   func_0c063a2c by 4 bytes and leaves the pool order one slot off. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern ActorHandler table_0c2401c0[], table_0c2401d0[], table_0c2401d8[], table_0c2401e0[], table_0c2401ec[];
extern const unsigned int dat_0c23fe00[], dat_0c23fe18[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c043324(struct Actor *);
extern int func_0c037d54(struct Actor *);


struct Sub2a4View_0c063510 { unsigned char pad[12]; unsigned char b12, b13, b14; char b15; };
#define B12(s) ((s)->b12)
#define B15(s) ((s)->b15)

void func_0c063510(struct Actor *a)
{
    struct Sub2a4View_0c063510 *s = (struct Sub2a4View_0c063510 *)&a->sub2a4;
    float v;
    v = a->f92;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if ((a->f92 < 0.0f && v > 0.0f) || (a->f92 > 0.0f && v < 0.0f)) {
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
    if (func_0c02a026(a) < 0) {
        B12(s) = 0;
        func_0c0437b8(a);
    }
}

void func_0c06359c(struct Actor *a)
{
    table_0c2401c0[a->b6](a);
}

void func_0c0635ae(struct Actor *a)
{
    table_0c2401d0[a->b6](a);
}

void func_0c0635c0(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 58;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 17);
}

void func_0c063636(struct Actor *a)
{
    struct LinkedActorVec3 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        v.x = -53.3333321f;
        v.y = 137.142853f;
        func_0c043014(a, &v);
    }
    if (a->b14b)
        func_0c0346da(a, 22);
}

void func_0c0636be(struct Actor *a)
{
    struct Sub2a4View_0c063510 *s = (struct Sub2a4View_0c063510 *)&a->sub2a4;
    float two;
    B15(s) = 0;
    a->b6++;
    a->b1fc = 0;
    a->b158 = 4;
    a->b1a1 = 23;
    a->f104 = 0.0f;
    a->f96 /= 2.0f;
    a->f108 = -0.401785702f;
    func_0c0346da(a, 22);
    if (a->b1fc == 0)
        a->p3f4 = (void *)dat_0c23fe00;
    else
        a->p3f4 = (void *)dat_0c23fe18;
    a->b1a7 = 2;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 12, a->b158);
    if (a->b1d6 & 0xf0)
        a->b1d6 -= 16;
}

void func_0c063768(struct Actor *a)
{
    struct Sub2a4View_0c063510 *s = (struct Sub2a4View_0c063510 *)&a->sub2a4;
    func_0c02a026(a);
    func_0c042018(a);
    func_0c0421b8(a);
    if (func_0c044e52(a)) {
        func_0c044f1c(a);
        return;
    }
    if (B15(s) < 2 && a->b19e && a->b141) {
        a->b141 = 0;
        B15(s)++;
        a->b1a1 = B15(s) + 23;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
}

void func_0c063836(struct Actor *a)
{
    table_0c2401d8[a->b6](a);
}

void func_0c063848(struct Actor *a)
{
    table_0c2401e0[a->b6](a);
}

void func_0c06385a(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 57;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

void func_0c0638d4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 1);
        func_0c043324(a);
    }
}

void func_0c06397a(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0439c4(a);
        return;
    }
    if (a->b141)
        a->b141 = 0;
}

int func_0c0639a6(struct Actor *a)
{
    int r;
    if (!(a->w1fa & 0xc00) || a->b1f9 == 1 || !a->b1a3)
        return 0;
    if (a->b1fe) {
        if (a->b1f9 == 2)
            return 0;
        if (!(r = func_0c037d54(a)))
            return 0;
        goto s3; s3: a->b1f7 = 3;
    } else if (a->b1f9 == 2) {
        if (!(r = func_0c037d54(a)))
            return 0;
        a->b1f7 = 2;
    } else {
        if (!(r = func_0c037d54(a)))
            return 0;
        a->b1f7 = 0;
    }
    return r;
}

void func_0c063a2c(struct Actor *a)
{
    table_0c2401ec[a->b1f7 & 63](a);
}
