/* Candidate: whole unit 0x0c14a9d0..0x0c14b8d8 (func_0c14adac/ae90/b33a
 * reach func_0c14aabc and func_0c14b4f2 reaches func_0c14ab1c by bsr/bra, so
 * the earlier four-function registration was a fragment). 3834 of 3848 bytes
 * equal. func_0c14b1e8 is now exact with plain 1.0f/2.0f literals. Remaining:
 * - func_0c14adac/ae90: retail pushes r13 before loading the dat_0c24ff8c/ffac
 *   table pointer into r4; ours loads it first (two words swapped each).
 * - at 0x0c14b2f4 and 0x0c14b306 two byte tests use r1/r3 where retail
 *   uses r2 (scratch rotation). */
#include "objects.h"
#define A(a) ((struct Actor *)(a))

extern struct LinkedActor *func_0c0374da(int a, int b, int c);
extern void (*table_0c24ffe8[])(struct LinkedActor *);
extern void (*table_0c24fff8[])(struct LinkedActor *);
void func_0c14ab84(struct LinkedActor *a);
void func_0c14b174(struct LinkedActor *a);
extern void func_0c02a0c4(struct LinkedActor *, int, unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c24ff88;
extern float dat_0c24ff8c[], dat_0c24ffac[];
extern float dat_0c24ffcc[];
extern void (*table_0c250024[])(struct LinkedActor *);
void func_0c14b8c4(struct LinkedActor *a);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c1c1678(struct LinkedActor *, short *, int);
extern void (*table_0c250050[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c250058[])(struct LinkedActor *);
extern void (*table_0c25005c[])(struct LinkedActor *);
extern void (*table_0c250060[])(struct LinkedActor *);
extern void (*table_0c250074[])(struct LinkedActor *);
extern void func_0c0346da(struct LinkedActor *, int);
extern void func_0c037688(struct LinkedActor *);

struct LinkedActor *func_0c14a9d0(struct LinkedActor *p, unsigned char b)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c14ab84;
        q->p24 = p;
        q->b32 = b;
    }
    return q;
}

struct LinkedActor *func_0c14a9fe(struct LinkedActor *p, unsigned char b, unsigned char c, unsigned char d)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c14ab84;
        q->p24 = p;
        q->b32 = b;
        q->b33 = d;
        q->b35 = c;
    }
    return q;
}

struct LinkedActor *func_0c14aa48(struct LinkedActor *p, unsigned char b)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c14ab84;
        q->p24 = p;
        q->b32 = b;
        q->b35 = q->p24->b35;
        q->sdc.w130 = q->p24->sdc.w130;
        q->f52 = q->p24->f52;
        q->f56 = q->p24->f56;
        q->f60 = q->p24->f60;
        q->f52 += q->sdc.w130 ? 176 : -176;
    }
    return q;
}

struct LinkedActor *func_0c14aabc(struct LinkedActor *p, unsigned char b, unsigned char c)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c14ab84;
        q->p24 = p->p24;
        q->p20 = p;
        q->b32 = b;
        q->b35 = c;
        q->sdc.w130 = q->p20->sdc.w130;
    }
    return q;
}

struct LinkedActor *func_0c14ab1c(struct LinkedActor *p, unsigned char b, unsigned char c)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c14ab84;
        q->p24 = p->p24;
        q->p20 = p;
        q->b32 = b;
        q->b35 = c;
        q->sdc.w130 = q->p20->sdc.w130;
        q->f52 = q->p20->f52;
        q->f56 = q->p20->f56;
        q->f60 = q->p20->f60;
    }
    return q;
}

void func_0c14ab84(struct LinkedActor *a)
{
    table_0c24ffe8[a->b4](a);
}

void func_0c14ab96(struct LinkedActor *a)
{
    a->b4++;
    a->sdc = a->p24->sdc;
    A(a)->b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    table_0c24fff8[a->b32](a);
    func_0c14b174(a);
}

void func_0c14ac3c(struct LinkedActor *a)
{
    int one = 1;
    int v = 66;
    short *t;

    A(a)->b12c = one;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    A(a)->b19c = v;
    A(a)->b19d = v;
    A(a)->b1a1 = 54;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    t = &dat_0c24ff88;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->s28 = *t;
    a->s30 = one;
    a->f56 += 180.0f;
    A(a)->f264 = 0.300000012f;
    a->f104 = 0.04f;
    a->f108 = 0.2800000012f;
    A(a)->f80 = 1.0f;
    A(a)->f84 = 1.0f;
    A(a)->f80 = A(a)->f80 / 100.0f;
    A(a)->f84 = A(a)->f84 / 100.0f;
    func_0c02a0c4(a, 23, 0);
}

void func_0c14acec(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->b36 = 0;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f56 += 120.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->f264 = 1.0f;
    func_0c02a0c4(a, 23, 1);
}

void func_0c14ad36(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->b36 = 7;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    a->f56 += 120.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->f264 = 1.0f;
    func_0c02a0c4(a, 23, 2);
}

void func_0c14adac(struct LinkedActor *a)
{
    float *t = dat_0c24ff8c;
    int zero = 0;
    unsigned char i;

    A(a)->b12c = 1;
    a->b36 = zero;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    t += (unsigned char)a->b33 * 2;
    a->f52 += a->p24->sdc.w130 ? t[0] : -t[0];
    a->f56 += t[1];
    for (i = zero; i < 8; i++)
        func_0c14aabc(a, 4, i);
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 3);
}

void func_0c14ae42(struct LinkedActor *a)
{
    float *t = dat_0c24ffcc;

    A(a)->b12c = 1;
    a->b36 = 0;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->f52 += t[a->b35];
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 4);
}

void func_0c14ae90(struct LinkedActor *a)
{
    float *t = dat_0c24ffac;
    int zero = 0;
    unsigned char i;

    A(a)->b12c = 1;
    a->b36 = zero;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    t += (unsigned char)a->b33 * 2;
    a->f52 += a->p24->sdc.w130 ? t[0] : -t[0];
    a->f56 += t[1];
    for (i = zero; i < 8; i++)
        func_0c14aabc(a, 6, i);
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 5);
}

void func_0c14af3c(struct LinkedActor *a)
{
    float *t = dat_0c24ffcc;

    A(a)->b12c = 1;
    a->b36 = 0;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->f56 += t[a->b35];
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 6);
}

void func_0c14af8a(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->b36 = 0;
    a->f52 += a->sdc.w130 ? 63.3333321f : -63.3333321f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    A(a)->f84 = 0.01f;
    a->f96 = 0.38f;
    a->f108 = -0.02f;
    A(a)->f264 = 1.0f;
    a->s28 = 5;
    a->f92 = a->sdc.w130 ? 1.66666663f : -1.66666663f;
    a->f104 = a->sdc.w130 ? -0.02604166605f : 0.02604166605f;
    func_0c14ab1c(a, 8, a->b35);
    a->b35++;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    A(a)->b1a1 = 62;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 23, 7);
}

void func_0c14b09a(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->b36 = 0;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = 0.18000001f;
    a->f104 = -0.03f;
    a->s28 = 6;
    func_0c02a0c4(a, 23, 8);
}

void func_0c14b0cc(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->b36 = 0;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->f52 += a->b35 * 80;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 10);
}

void func_0c14b120(struct LinkedActor *a)
{
    A(a)->b12c = 1;
    a->b36 = 0;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    a->f60 = a->p20->f60;
    a->f52 -= a->b35 * 80;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 10);
}

void func_0c14b174(struct LinkedActor *a)
{
    if (a->b1 != a->p24->b1) {
        func_0c14b8c4(a);
        return;
    }
    table_0c250024[a->b32](a);
}

void func_0c14b1b8(struct LinkedActor *a)
{
    table_0c250050[(unsigned char)a->b5](a, a->p24);
    if (A(a->p24)->b19f) {
        a->b4++;
        A(a)->b12c = 0;
    }
}


void func_0c14b1e8(struct LinkedActor *a, struct LinkedActor *owner)
{
    short *timer = (short *)&A(owner)->sub2a4;
    struct Actor *p;

    func_0c02a026(a);
    a->s30 = 1;
    A(a)->i72 = A(a)->i72 + 0x4000;
    if (A(a)->i72 == 0xf000)
        A(a)->i72 = 0;
    A(a)->f80 /= 1.66666663f;
    A(a)->f84 /= 2.1428571f;
    a->f108 += a->f104;
    A(a)->f80 += a->f108;
    A(a)->f84 += a->f108;
    A(a)->f264 += a->f104;
    if (A(a)->f80 > 1.4400001f) {
        A(a)->f80 = 1.4400001f;
        A(a)->f84 = 1.120000124f;
    }
    if (A(a)->f264 > 1.0f)
        A(a)->f264 = 1.0f;
    if (a->s28-- == 0) {
        a->b5++;
        a->s28 = 35;
        A(a)->i72 = 0;
        a->f108 = 2.0f;
        a->f104 = 0.01f;
        return;
    }
    if (A(a)->b19e & 1)
        return;
    if (A(a)->b19e) {
        p = A(a)->p1b0;
        if (!p->b3 && !p->b411 && p->w420) {
            *timer = 600;
            func_0c1c1678(owner, timer, 6);
        }
    }
    func_0c037d0c(a);
}

void func_0c14b33a(struct LinkedActor *a)
{
    func_0c02a026(a);
    A(a)->f80 /= 1.66666663f;
    A(a)->f84 /= 2.1428571f;
    A(a)->f80 += a->f108;
    A(a)->f84 -= a->f104;
    if (!(A(a)->f84 > 0.0046666665003f)) {
        A(a)->f84 = 0.0046666665003f;
        if (a->s28 % 5 == 0) {
            func_0c14aabc(a, 9, a->b35);
            func_0c14aabc(a, 10, a->b35);
            a->b35++;
        }
    }
    if (a->s28-- == 0) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c14b3d4(struct LinkedActor *a)
{
    table_0c250058[(unsigned char)a->b5](a);
    if (A(a)->b19e) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c14b430(struct LinkedActor *a)
{
    func_0c02a026(a);
    A(a)->f264 -= 0.04f;
    if (A(a)->b143 < 0) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c14b462(struct LinkedActor *a)
{
    table_0c25005c[(unsigned char)a->b5](a);
    if (A(a)->b19e) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c14b490(struct LinkedActor *a)
{
    func_0c02a026(a);
    if (A(a)->b143 < 0) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c14b4b4(struct LinkedActor *a)
{
    table_0c250060[(unsigned char)a->b5](a);
}

void func_0c14b4c6(struct LinkedActor *a)
{
    if (A(a)->b141 == 1) {
        a->b5++;
        A(a)->b141 = 0;
        func_0c0346da(a, 76);
    }
    func_0c02a026(a);
}

void func_0c14b4f2(struct LinkedActor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    A(a)->f84 += a->f96;
    a->f96 += a->f108;
    if (a->s28-- < 0) {
        a->b5++;
        if ((unsigned char)a->b35 < 5)
            func_0c14ab1c(a, 7, a->b35);
        return;
    }
    func_0c037d0c(a);
}

void func_0c14b594(struct LinkedActor *a)
{
    func_0c02a026(a);
    A(a)->f80 -= 0.06f + a->s28 * 0.02f;
    if (0.01f > A(a)->f80) {
        a->b5++;
        a->s28 = 8;
        A(a)->f80 = 0.04f;
        a->f108 = -0.1000000015f;
    }
    a->s28++;
    a->f52 += a->f92;
    a->f92 += a->f104;
    A(a)->f84 += a->f96;
    a->f96 += a->f108;
    if (0.01f > A(a)->f84)
        A(a)->f84 = 0.01f;
}

void func_0c14b62e(struct LinkedActor *a)
{
    A(a)->f264 -= 0.06f;
    if (0.1000000015f > A(a)->f264)
        A(a)->f264 = 0.1000000015f;
    a->f52 += a->f92;
    a->f92 += a->f104;
    A(a)->f84 += a->f96;
    a->f96 += a->f108;
    if (0.01f > A(a)->f84)
        A(a)->f84 = 0.01f;
    if (a->s28-- < 0) {
        a->b5++;
        a->f96 /= 100.0f;
        a->f108 /= 100.0f;
    }
}

void func_0c14b6e0(struct LinkedActor *a)
{
    A(a)->f264 -= 0.08f;
    if (0.1000000015f > A(a)->f264)
        A(a)->f264 = 0.1000000015f;
    a->f52 += a->f92;
    a->f92 += a->f104;
    A(a)->f84 += a->f96;
    a->f96 += a->f108;
    if (0.01f > A(a)->f84) {
        a->b4++;
        A(a)->b12c = 0;
        A(a)->f84 = 0.01f;
    }
}

void func_0c14b754(struct LinkedActor *a)
{
    table_0c250074[(unsigned char)a->b5](a);
}

void func_0c14b766(struct LinkedActor *a)
{
    func_0c02a026(a);
    A(a)->f80 += a->f92;
    a->f92 += a->f104;
    if (a->s28 <= 2) {
        A(a)->f264 -= 0.200000003f;
        if (0.1000000015f > A(a)->f264)
            A(a)->f264 = 0.1000000015f;
    }
    if (a->s28-- < 0) {
        a->b5++;
        a->s28 = 6;
        A(a)->f264 = 1.0f;
        A(a)->f80 = 1.0f;
        A(a)->f84 = 1.0f;
        a->f92 = 0.01f;
        a->f104 = -0.00030000001425f;
        a->f96 = 0.02f;
        a->f108 = -0.00030000001425f;
        func_0c02a0c4(a, 23, 9);
    }
}

void func_0c14b830(struct LinkedActor *a)
{
    func_0c02a026(a);
    A(a)->f80 += a->f92;
    a->f92 += a->f104;
    A(a)->f84 += a->f96;
    a->f96 += a->f108;
    if (a->s28-- == 0) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c14b892(struct LinkedActor *a)
{
    func_0c02a026(a);
    if (A(a)->b143 < 0) {
        a->b4++;
        A(a)->b12c = 0;
    }
}

void func_0c14b8b6(struct LinkedActor *a)
{
    a->b4++;
    A(a)->b12c = 0;
}

void func_0c14b8c4(struct LinkedActor *a)
{
    func_0c037688(a);
}
