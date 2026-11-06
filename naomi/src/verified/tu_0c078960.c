#include "objects.h"

/* Throw/knockdown landing view of the actor +0x2a4 record. */
struct ActorSub2a4Hit {
    unsigned char pad0[8]; unsigned char b8; unsigned char pad9[4]; unsigned char b13;
    unsigned char pad14; unsigned char b15; unsigned char pad16[12]; unsigned short w28;
    unsigned char pad30[6]; unsigned short w36; short s38; unsigned char pad40[2]; unsigned short w42;
};

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2414c0[], table_0c2414d8[];
extern unsigned char dat_0c22f1f8[], dat_0c22f248[], dat_0c22f258[], dat_0c22f2b8[];
extern int dat_0c22f208[], dat_0c22f278[];
extern char dat_0c22f268[][3];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a18c(struct Actor *, int, int, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0451f2(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c04392e(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c07a616(struct Actor *, int, float *, float *);
extern int func_0c1ec190(void);
extern void func_0c191f0c(struct Actor *, int);
extern struct Actor *func_0c191d00(struct Actor *, int);

void func_0c078b00(struct Actor *a);
void func_0c078ddc(struct Actor *a);
void func_0c078e80(struct Actor *a);
void func_0c078f1c(struct Actor *a);
void func_0c079382(struct Actor *a);
void func_0c079426(struct Actor *a);

void func_0c078960(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    a->s28--;
    if (a->s28 < 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->pad1d7[1] = 0;
        a->b1fc = 0;
        a->b1d4++;
        a->pad7f2++;
        a->pad1d7[2] = 127;
        func_0c0438de(a);
    }
}

void func_0c0789c4(struct Actor *a)
{
    a->b1f5 = 1;
    table_0c2414c0[a->b6](a);
}

void func_0c0789de(struct Actor *a)
{
    struct ActorSub2a4Hit *s;

    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c0442fa(a);
    func_0c0344a0(a, 34);
    s = (struct ActorSub2a4Hit *)&a->sub2a4;
    s->b15 = 0;
    s->b8 = 2;
    s->s38 = 15;
    s->w28 = 8;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 54;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0451f2(a);
    if (a->f56 > a->f41c) {
        func_0c02a0c4(a, 21, 31);
    } else {
        func_0c02a0c4(a, 21, 32);
        func_0c0432ca(a);
    }
    func_0c078b00(a);
}

int func_0c078ad4(struct Actor *a, unsigned short m)
{
    int hi;
    m &= 0x3c00;
    hi = m & 0x3000;
    hi /= 4096;
    hi |= (m & 0xc00) / 256;
    return hi;
}

void func_0c078b00(register struct Actor *a)
{
    void *zero;
    register struct ActorSub2a4Hit *s;
    struct LinkedActorVec3 v;
    unsigned short m;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    zero = 0;
    if (func_0c02a026(a) >= 0) {
        if (a->b141) {
            a->b141 = (int)zero;
            a->b3f0 = (int)zero;
            a->b3f1 = (int)zero;
            if (a->f56 > a->f41c) {
                v.x = -3.3333333f;
                v.y = 227.142853f;
            } else {
                v.x = -46.666664124f;
                v.y = 225.0f;
            }
            v.z = 0.0f;
            func_0c0429a4(a, &v, 1);
        }
    } else {
        goto L1; L1:
        func_0c0344a0(a, 22);
        func_0c0344a0(a, 34);
        s = (struct ActorSub2a4Hit *)&a->sub2a4;
        s->w36 = s->s38 + 30;
        s->s38 = (int)zero;
        if (a->b525)
            m = s->w42;
        else
            m = a->w34a;
        m &= 0x3c00;
        if (m) {
            s->w28 = func_0c078ad4(a, m);
            s->w28 &= 15;
        }
        a->b6++;
        a->b7 = (int)zero;
        func_0c078ddc(a);
    }
}

void func_0c078c22(struct Actor *a)
{
    struct ActorSub2a4Hit *s;
    float lim;

    a->b3f8 = 2;
    a->b328 = 5;
    lim = a->f41c + 896.0f;
    if (a->f56 > lim)
        a->f56 = lim;
    if (a->b19e & 1) {
        s = (struct ActorSub2a4Hit *)&a->sub2a4;
        s->b15++;
        if (s->b8 != 2) {
            func_0c078e80(a);
            return;
        }
    }
    func_0c078f1c(a);
}

void func_0c078c64(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (a->b1f9 == 2) {
        a->f96 = -0.80357140303f;
        a->b1d3 = -1;
        func_0c04392e(a);
        func_0c043324(a);
    } else {
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}

void func_0c078ce0(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f96 < 0.0f) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->f92 = 0.0f;
        if (func_0c044e52(a)) {
            func_0c0346da(a, 52);
            a->b6++;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            func_0c02a0c4(a, 21, 14);
            func_0c043324(a);
        }
    }
}

void func_0c078d98(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c078ddc(struct Actor *a)
{
    struct ActorSub2a4Hit *s;
    float x, y;
    unsigned char c;

    s = (struct ActorSub2a4Hit *)&a->sub2a4;
    a->b1a1 = dat_0c22f1f8[s->w28];
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, dat_0c22f208[s->w28]);
    a->b34 = dat_0c22f248[s->w28];
    c = a->b34;
    a->b34 = dat_0c22f258[s->w28];
    func_0c07a616(a, 1000, &x, &y);
    a->b34 = c;
    if (a->b1d2)
        x = -x;
    a->f92 = x;
    a->f96 = y;
}

void func_0c078e80(struct Actor *a)
{
    a->b6 += 2;
    func_0c0442fa(a);
    if (a->b1d2) {
        a->f92 = -2.5f;
        a->f104 = 0.02604166605f;
    } else {
        a->f92 = 2.5f;
        a->f104 = -0.02604166605f;
    }
    a->f96 = 17.142857f;
    a->f108 = -0.80357140303f;
    func_0c02a18c(a, 1, 2, 1);
}

void func_0c078f1c(struct Actor *a)
{
    struct ActorSub2a4Hit *s;
    void *zero;
    int r;
    unsigned short w;

    s = (struct ActorSub2a4Hit *)&a->sub2a4;
    s->w36--;
    zero = 0;
    if (s->w36 > 0) {
        if (s->w36 < 10 && (a->w34a & 0x360))
            a->b7 = 1;
        r = func_0c1ec190();
        r &= 3;
        if (!r)
            func_0c191f0c(a, 255);
        func_0c02a026(a);
        if (a->b141) {
            a->b141 = (int)zero;
            a->b1a1 = dat_0c22f1f8[s->w28];
            a->w1ac = (int)zero;
            a->b19e = (int)zero;
            a->p1c4 = (int)zero;
            dat_0c2f83f8->arr[a->b2]++;
        }
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (a->f41c < a->f56)
            return;
        a->f56 = a->f41c;
        a->b1f9 = (int)zero;
        switch (s->w28) {
        case 9:
        case 1:
            s->w28 = func_0c078ad4(a, 0x800);
            break;
        case 5:
            goto store; store: s->w28 = func_0c078ad4(a, 1024);
            break;
        default:
            return;
        }
        func_0c078ddc(a);
        return;
    }
    if (!a->b7 || (s->b8--, !s->b8)) {
        goto vanish; vanish:
        func_0c078e80(a);
        return;
    }
    func_0c02a0c4(a, 21, 33);
    a->b1a1 = dat_0c22f1f8[s->w28];
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    a->p1c4 = (int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->b6--;
    func_0c078b00(a);
}

void func_0c0790c2(struct Actor *a)
{
    table_0c2414d8[a->b6](a);
}

void func_0c0790d4(struct Actor *a)
{
    struct ActorSub2a4Hit *s;

    s = (struct ActorSub2a4Hit *)&a->sub2a4;
    a->b6++;
    func_0c0442fa(a);
    if (a->b1f9 != 2)
        func_0c0432ca(a);
    func_0c0344a0(a, 30);
    s->b13 = 0;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->f52;
    a->f96 = a->f56;
    if (a->p20c->w130)
        a->f104 += a->p20c->f52 + -160.0f;
    else
        a->f104 += a->p20c->f52 + 160.0f;
    a->f108 = a->p20c->f56;
    func_0c02a0c4(a, 21, 43);
}

void func_0c0791b4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->b1f5 = 3;
        a->b1eb = 3;
        a->b1ed = 3;
        a->s28 = 1;
        a->b12c = 0;
        func_0c048bb0(a, 5);
    }
}

void func_0c0791f4(struct Actor *a)
{
    struct Actor *c;
    char *p;

    a->b1f5 = 2;
    a->b1eb = 2;
    a->b1ed = 2;
    a->s28--;
    if (a->s28 <= 0) {
        a->b6++;
        if ((c = func_0c191d00(a, 1)) != 0) {
            c->b1a3 = a->b1a3;
            p = dat_0c22f268[(unsigned char)a->b1a3];
            if ((c = func_0c191d00(a, 0)) != 0)
                c->b1a3 = *p++;
            if ((c = func_0c191d00(a, 0)) != 0)
                c->b1a3 = *p++;
            if ((c = func_0c191d00(a, 0)) != 0)
                c->b1a3 = *p;
        }
    }
}

void func_0c079280(struct Actor *a)
{
    struct ActorSub2a4Hit *s = (struct ActorSub2a4Hit *)&a->sub2a4;

    if (s->b13) {
        a->b6++;
        a->b7 = 0;
        a->b12c = 1;
        func_0c02a0c4(a, 21, 44);
        func_0c0344a0(a, 35);
    } else {
        a->b1f5 = 2;
        a->b1eb = 2;
        a->b1ed = 2;
    }
}

void func_0c0792ca(struct Actor *a)
{
    struct ActorSub2a4Hit *s;
    unsigned short m;

    if (func_0c02a026(a) >= 0) {
        if (a->w34e & 0x360)
            a->b7 = 1;
        return;
    }
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    s = (struct ActorSub2a4Hit *)&a->sub2a4;
    if (!a->b525) {
        if (!a->b7)
            goto skip;
        m = a->w34a;
    } else {
        m = s->w42;
    }
    m &= 0x3c00;
    if (m) {
        a->b6++;
        s->w36 = 16;
        s->w28 = func_0c078ad4(a, m);
        func_0c079382(a);
        func_0c0344a0(a, 34);
        return;
    }
skip:
    func_0c079426(a);
}

void func_0c079382(struct Actor *a)
{
    struct ActorSub2a4Hit *s;
    float x, y;
    unsigned char c;

    s = (struct ActorSub2a4Hit *)&a->sub2a4;
    a->b1a1 = dat_0c22f2b8[s->w28];
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, dat_0c22f278[s->w28]);
    a->b34 = dat_0c22f248[s->w28];
    c = a->b34;
    a->b34 = dat_0c22f258[s->w28];
    func_0c07a616(a, 1000, &x, &y);
    a->b34 = c;
    if (a->b1d2)
        x = -x;
    a->f92 = x;
    a->f96 = y;
}

void func_0c079426(struct Actor *a)
{
    a->pad1d7[1] = 0;
    a->b1fc = 0;
    a->b1d4++;
    a->pad7f2 = 0;
    a->pad1d7[2] = 0;
    func_0c0438de(a);
}
