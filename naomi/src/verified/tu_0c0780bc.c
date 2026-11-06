#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24149c[], table_0c2414b0[];
extern char dat_0c22f1c0[][2];
extern float dat_0c22f1c8[][4];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0451f2(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c07827c(struct Actor *a);

void func_0c0780bc(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    table_0c24149c[a->b6](a);
}

void func_0c078108(struct Actor *a)
{
    struct ActorSub2a4Stage *s;

    s = (struct ActorSub2a4Stage *)&a->sub2a4;
    a->b6++;
    a->w352 = 0;
    if (a->b1f9 != 2) {
        func_0c0442fa(a);
        func_0c0432ca(a);
    }
    if (a->b255 == 3) a->b1a1 = 86; else { goto L9; L9: a->b1a1 = dat_0c22f1c0[(unsigned char)a->b1a3][0]; }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    goto L1; L1:
    func_0c048bb0(a, 5);
    s->b12 = 0;
    s->b11 = 10;
    a->b158 = a->b1a3 + 11;
    func_0c02a0c4(a, 21, a->b158);
    s->b9 = a->b141;
    func_0c0451f2(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    if (a->b1d2) {
        a->f92 = dat_0c22f1c8[(unsigned char)a->b1a3][0];
        a->f104 = dat_0c22f1c8[(unsigned char)a->b1a3][1];
    } else {
        a->f92 = -dat_0c22f1c8[(unsigned char)a->b1a3][0];
        a->f104 = -dat_0c22f1c8[(unsigned char)a->b1a3][1];
    }
    a->f96 = dat_0c22f1c8[(unsigned char)a->b1a3][2];
    a->f108 = dat_0c22f1c8[(unsigned char)a->b1a3][3];
    func_0c07827c(a);
}

void func_0c07827c(struct Actor *a)
{
    struct ActorSub2a4Stage *s = (struct ActorSub2a4Stage *)&a->sub2a4;

    a->b6++;
    if (s->w34 == 1)
        func_0c0344a0(a, 21);
    func_0c0344a0(a, 33);
}

void func_0c0782aa(struct Actor *a)
{
    a->b1a1 = dat_0c22f1c0[1][0];
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, 13);
    if (a->b1d2) {
        a->f92 = dat_0c22f1c8[1][0];
        a->f104 = dat_0c22f1c8[1][1];
    } else {
        a->f92 = -dat_0c22f1c8[1][0];
        a->f104 = -dat_0c22f1c8[1][1];
    }
    a->f96 = dat_0c22f1c8[1][2];
    a->f108 = dat_0c22f1c8[1][3];
}

void func_0c078358(struct Actor *a)
{
    a->b1a1 = dat_0c22f1c0[2][0];
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, 12);
    if (a->b1d2) {
        a->f92 = dat_0c22f1c8[2][0];
        a->f104 = dat_0c22f1c8[2][1];
    } else {
        a->f92 = -dat_0c22f1c8[2][0];
        a->f104 = -dat_0c22f1c8[2][1];
    }
    a->f96 = dat_0c22f1c8[2][2];
    a->f108 = dat_0c22f1c8[2][3];
}

void func_0c0783e4(struct Actor *a)
{
    a->b1a1 = dat_0c22f1c0[0][0];
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, 11);
    if (a->b1d2) {
        a->f92 = dat_0c22f1c8[0][0];
        a->f104 = dat_0c22f1c8[0][1];
    } else {
        a->f92 = -dat_0c22f1c8[0][0];
        a->f104 = -dat_0c22f1c8[0][1];
    }
    a->f96 = dat_0c22f1c8[0][2];
    a->f108 = dat_0c22f1c8[0][3];
}

void func_0c078488(struct Actor *a)
{
    struct ActorSub2a4Stage *s;
    void *zero = 0;

    s = (struct ActorSub2a4Stage *)&a->sub2a4;
    s->b9 = a->b141;
    func_0c02a026(a);
    if (s->b11) {
        if (s->b9 != a->b141) {
            if (a->b255 == 3) a->b1a1 = 87; else { goto L7; L7: a->b1a1 = (&dat_0c22f1c0[0][0])[(unsigned char)a->b1a3 * 2 + a->b141]; }
            a->w1ac = (int)zero;
            a->b19e = (int)zero;
            a->p1c4 = (int)zero;
            dat_0c2f83f8->arr[a->b2]++;
        }
        if ((a->b19e & 0x81) == 0x80)
            s->b11--;
        if (s->b12 < 2) {
            goto L2; L2:
            if (!a->b1a3) {
                switch (s->b12) {
                case 0:
                    if ((a->w34e | a->w352) & 0x40)
                        goto stage1;
                    break;
                case 1:
                    if ((a->w34e | a->w352) & 0x20) {
                        a->w352 = (int)zero;
                        s->b12++;
                        func_0c0782aa(a);
                    }
                    break;
                }
            } else {
                switch (s->b12) {
                case 0:
                    if ((a->w34e | a->w352) & 0x40) {
                stage1:
                        a->w352 = (int)zero;
                        s->b12++;
                        func_0c078358(a);
                    }
                    break;
                case 1:
                    if ((a->w34e | a->w352) & 0x40) {
                        a->w352 = (int)zero;
                        s->b12++;
                        func_0c0783e4(a);
                    }
                    break;
                }
            }
        }
    }
    if (a->f96 < 0.0f) {
        a->b6++;
        a->f108 = -0.80357140303f;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        func_0c02a0c4(a, 1, 9);
    }
}

void func_0c078622(struct Actor *a)
{
    func_0c02a026(a);
    if (a->f41c > a->f56) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1fc = 0;
        func_0c0346da(a, 52);
        a->b1f9 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 21, 14);
        func_0c043324(a);
    }
}

void func_0c078686(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0786a8(struct Actor *a)
{
    table_0c2414b0[a->b6](a);
}
