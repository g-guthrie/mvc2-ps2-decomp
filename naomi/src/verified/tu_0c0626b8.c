#include "objects.h"

struct Sub2a4View_626 {
    struct Actor *p0;
    char pad4[8];
    char b12, b13, b14, pad15, b16, pad17[5], b22, pad23[5], b28;
};
struct Short4_0c240138 { short s0, s2, s4, s6; };
extern struct Short4_0c240138 table_0c240138[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1ceafe(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c034946(struct Actor *, unsigned char);
extern void func_0c0437b8(struct Actor *);
extern void func_0c18f974(struct Actor *, int);
extern void func_0c04bad8(struct Actor *, struct Actor *);
extern void func_0c04b02a(struct Actor *);
extern void func_0c0445fe(struct Actor *, struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);

void func_0c0626b8(struct Actor *a)
{
    struct Sub2a4View_626 *sub = (struct Sub2a4View_626 *)&a->sub2a4;
    struct LinkedActorVec3 v;
    float sx = 1.66666663f;
    struct Short4_0c240138 *t = table_0c240138;
    float d = 256.0f;
    float sy;
    void *zero;
    v.x = (float)t[sub->b22].s0 * sx / d;
    sy = 2.1428571f;
    v.y = (float)t[sub->b22].s2 * sy / d;
    func_0c1ceafe(a, &v);
    v.x = (float)t[sub->b22].s4 * sx / d;
    v.y = (float)t[sub->b22].s6 * sy / d;
    func_0c1ceafe(a, &v);
    zero = 0;
    if (a->b14b) {
        func_0c034946(a->p1c8, a->b14b - 1);
        a->b14b = (int)zero;
    }
    switch (sub->b22) {
    case 0:
        sub->b22 = 1;
        break;
    case 1:
        goto z;
    case 2:
    case 3:
    case 4:
        sub->b22 = sub->b22 + 1;
        break;
    case 5:
    z:
        sub->b22 = (int)zero;
        break;
    }
}

void func_0c0627b8(struct Actor *a)
{
    char *sub = (char *)&a->sub2a4;
    if (sub[13]) {
        a->b7++;
        func_0c02a0c4(a, 22, 16);
        return;
    }
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c06281c(struct Actor *a)
{
    char *sub = (char *)&a->sub2a4;
    struct Actor *p;
    unsigned char c;
    if (func_0c02a026(a) < 0) {
        sub[14] = 0;
        a->b7++;
        a->f56 = a->f41c;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f96 = 34.2857132f;
        a->f108 = -0.5357143f;
        func_0c02a0c4(a, 22, 13);
        return;
    }
    c = a->b141;
    if (c) {
        a->b141 = 0;
        if (c == 62) {
            func_0c18f974(a, 0);
            p = *(struct Actor **)sub;
            p->p1b4 = a;
            p->b1a1 = c;
            p->w130 = a->w130;
            p->b1f6 = 17;
            p->b1f9 = 2;
            func_0c04bad8(p, a);
        } else {
            p = *(struct Actor **)sub;
            p->p1b4 = a;
            a->b1a1 = c;
            p->b1a1 = c;
            func_0c04b02a(a);
            func_0c04bad8(p, a);
            func_0c04b02a(a);
        }
        func_0c04bad8(p, a);
        func_0c0626b8(a);
    }
}

void func_0c062924(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c + 548.571411133f) {
        a->f56 = a->f41c + 548.571411133f;
        a->b7++;
    }
    func_0c02a026(a);
}

void func_0c062984(struct Actor *a)
{
    char *sub = (char *)&a->sub2a4;
    struct Actor *p = *(struct Actor **)sub;
    if (a->f56 > p->f56) {
        a->b7++;
        sub[14] = -1;
        p->f56 = a->f56;
        func_0c02a0c4(a, 22, 17);
        a->b1f7 = 0xc5;
        func_0c0445fe(a, p);
        return;
    }
    func_0c02a026(a);
}

void func_0c0629d6(struct Actor *a)
{
    char *sub = (char *)&a->sub2a4;
    struct Actor *p;
    p = *(struct Actor **)sub;
    p->f56 = a->f56;
    func_0c02a026(a);
    if (a->b141) {
        if (a->b141 == 63) {
            a->b7++;
            func_0c18f974(a, 2);
            p = a->p1c8;
            p->p1b4 = a;
            p->b1a1 = 63;
            p->w130 = a->w130;
            p->b1f6 = 1;
            p->b1f9 = 2;
            func_0c04bad8(p, a);
            func_0c04bad8(p, a);
            func_0c0626b8(a);
            func_0c02a0c4(a, 22, 18);
        } else {
            p = *(struct Actor **)sub;
            p->p1b4 = a;
            a->b1a1 = a->b141;
            p->b1a1 = a->b141;
            func_0c04b02a(a);
            func_0c04bad8(p, a);
            func_0c04b02a(a);
            func_0c04bad8(p, a);
            a->b141 = 0;
        }
        func_0c0626b8(a);
    }
}

void func_0c062abe(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c025900(a, 0, 0);
        a->b7++;
a->b328 = a->b327 = a->b3f8 = (a->b3f9 = 0) != 0;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f92 = 3.3333333f;
        a->f96 = -4.28571415f;
        a->f108 = -1.07142854f;
        if (a->w130)
            a->f92 = -a->f92;
        func_0c02a0c4(a, 22, 19);
    }
}

void func_0c062b38(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b7++;
        func_0c043324(a);
        func_0c02a0c4(a, 22, 20);
    }
}

void func_0c062bd4(struct Actor *a)
{
    char *sub = (char *)&a->sub2a4;
    goto animate;
animate:
    if (func_0c02a026(a) < 0) {
        sub[12] = 0;
        func_0c0437b8(a);
    }
}

extern void (*table_0c240168[])(struct Actor *);
void func_0c062c08(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    table_0c240168[a->b7](a);
}

#pragma inline(vx_626)
static float vx_626(float v) { return v; }
void func_0c062c36(struct Actor *a)
{
    char *sub = (char *)&a->sub2a4;
    float vx;
    vx = vx_626(a->f92);
    a->f52 += vx;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if ((a->f92 < 0.0f && vx > 0.0f) || (a->f92 > 0.0f && vx < 0.0f)) {
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
    if (func_0c02a026(a) < 0) {
        sub[12] = 0;
        func_0c0437b8(a);
    }
}

extern void (*table_0c240188[])(struct Actor *);
void func_0c062cc2(struct Actor *a) { table_0c240188[a->b6](a); }

struct ActorSubByte28_626 { unsigned char pad[28], b28; };
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
void func_0c062cd4(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    struct LinkedActorVec3 position;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    if (func_0c02a026(a) < 0) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6++;
        a->b7 = 0;
        a->s28 = 30;
        a->f92 = 13.33333302f;
        a->f104 = -0.1041666642f;
        if (!a->w130) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        a->b1f9 = 2;
        func_0c02a0c4(a, 22, 7);
        ((struct ActorSubByte28_626 *)sub)->b28 = 1;
        position.x = -26.666666031f;
        position.y = 137.142853f;
        func_0c0429a4(a, &position, 1);
    }
}

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
void func_0c062da8(struct Actor *a)
{
    int zero;
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b7++;
    func_0c0442fa(a);
    a->b1a1 = 59;
    zero = 0;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, 14);
    func_0c062cd4(a);
}

extern void (*table_0c240198[])(struct Actor *);
void func_0c062e08(struct Actor *a) { table_0c240198[a->b7](a); }

extern void func_0c0344a0(struct Actor *, int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c134db0(struct Actor *, int);
extern void func_0c044548(struct Actor *, struct Actor *);
void func_0c062e50(struct Actor *a)
{
    struct Sub2a4View_626 *sub = (struct Sub2a4View_626 *)&a->sub2a4;
    struct Actor *p;
    register float zero_f, fall;
    func_0c02a026(a);
    zero_f = 0.0f;
    a->f52 += a->f92;
    a->f92 += a->f104;
    fall = -0.80357140303f;
    if (a->b19e < 0) {
        sub->b28 = 0;
        func_0c0344a0(a, 43);
        if (!(a->b19e & 0x7f)) {
            p = a->p1b0;
            if (func_0c0447bc(a)) {
                p->f56 = a->f56;
                a->b6++;
                a->b7 = 0;
                func_0c025900(a, 5, 5);
                sub->p0 = a->p1b0;
                sub->b13 = 0;
                sub->b22 = 0;
                func_0c134db0(a, 1);
                func_0c02a0c4(a, 22, 21);
                a->b1f7 = 0xc5;
                func_0c044548(a, a->p1b0);
                return;
            }
        }
        a->b7 = 1;
        a->f92 = 3.3333333f;
        a->f104 = zero_f;
        a->f96 = 17.142857f;
        a->f108 = fall;
        if (a->w130) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        func_0c02a0c4(a, 22, 11);
    } else if (--a->s28 == 0) {
        a->b7++;
        sub->b28 = 0;
        func_0c0344a0(a, 43);
        a->f92 = a->f92 / 2.0f;
        a->f104 = zero_f;
        a->f96 = -2.1428571f;
        a->f108 = fall;
        func_0c02a0c4(a, 1, 9);
    }
}

void func_0c062fe4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6 = 3;
        a->b7 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c043324(a);
        func_0c02a0c4(a, 22, 12);
    }
}

extern void (*table_0c2401a0[])(struct Actor *);
void func_0c063066(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    table_0c2401a0[a->b7](a);
}

void func_0c063086(struct Actor *a)
{
    struct Sub2a4View_626 *sub = (struct Sub2a4View_626 *)&a->sub2a4;
    func_0c02a026(a);
    if (sub->b13) {
        a->b7++;
        sub->b16 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f96 = 0.5357143f;
        func_0c02a0c4(a, 22, 22);
    }
}

void func_0c063100(struct Actor *a)
{
    struct Sub2a4View_626 *sub = (struct Sub2a4View_626 *)&a->sub2a4;
    struct Actor *p;
    unsigned char c;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c02a0c4(a, 22, 23);
        return;
    }
    c = a->b141;
    a->b141 = 0;
    if (c) {
        if (c == 66) {
            p = sub->p0;
            p->p1b4 = a;
            p->w130 = a->w130;
            p->b1f6 = 17;
            p->b1f9 = 2;
            p->b1a1 = c;
            sub->b16 = -1;
            func_0c025900(a, 12, 12);
            func_0c18f974(a, 0);
            func_0c04bad8(p, a);
            func_0c04bad8(p, a);
            func_0c0626b8(a);
            return;
        }
        p = sub->p0;
        p->p1b4 = a;
        a->b1a1 = c;
        p->b1a1 = c;
        func_0c04b02a(a);
        func_0c04bad8(p, a);
        func_0c04b02a(a);
        func_0c04bad8(p, a);
        func_0c0626b8(a);
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!sub->b16) {
        p = sub->p0;
        p->f56 = a->f56;
    }
}

void func_0c063238(register struct Actor *a)
{
    struct Sub2a4View_626 *sub = (struct Sub2a4View_626 *)&a->sub2a4;
    struct Actor *p;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c025900(a, 0, 0);
        a->w130 = a->w130 ^ 1;
        func_0c02a0c4(a, 22, 24);
        return;
    }
    if (((unsigned char *)&a->w150)[1]) {
        ((unsigned char *)&a->w150)[1] = 0;
        a->b1f7 = 0xc5;
        func_0c0445fe(a, sub->p0);
        p = sub->p0;
        func_0c04bad8(p, a);
        func_0c04bad8(p, a);
        sub->b22 = 2;
    }
    if (a->b141) {
        p = sub->p0;
        p->p1b4 = a;
        p->b1a1 = a->b141;
        a->b1a1 = a->b141;
        a->b141 = 0;
        func_0c04b02a(a);
        func_0c04bad8(p, a);
        func_0c04b02a(a);
        func_0c04bad8(p, a);
        func_0c0626b8(a);
    }
}

void func_0c06330e(register struct Actor *a)
{
    struct Sub2a4View_626 *sub = (struct Sub2a4View_626 *)&a->sub2a4;
    struct Actor *p;
    register void *zero = 0;
    goto animate;
animate:
    if (func_0c02a026(a) < 0) {
        a->b3f9 = (int)zero;
        a->b3f8 = (int)zero;
        a->b327 = (int)zero;
        a->b328 = (int)zero;
        a->b7++;
        a->f92 = 3.3333333f;
        a->f104 = 0.0f;
        a->f96 = -4.28571415f;
        a->f108 = -1.07142854f;
        if (a->w130)
            a->f92 = -a->f92;
        func_0c02a0c4(a, 22, 19);
        return;
    }
    if (a->b141) {
        a->b141 = (int)zero;
        func_0c18f974(a, 2);
        p = sub->p0;
        p->p1b4 = a;
        p->w130 = a->w130;
        p->b1f6 = 1;
        p->b1f9 = 2;
        p->b1a1 = 68;
        func_0c04bad8(p, a);
        func_0c04bad8(p, a);
        func_0c0626b8(a);
    }
}

void func_0c063410(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b7++;
        func_0c043324(a);
        func_0c02a0c4(a, 22, 20);
    }
}

void func_0c06347e(struct Actor *a)
{
    char *sub = (char *)&a->sub2a4;
    goto animate;
animate:
    if (func_0c02a026(a) < 0) {
        sub[12] = 0;
        func_0c0437b8(a);
    }
}

extern void (*table_0c2401a8[])(struct Actor *);
void func_0c0634b2(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    table_0c2401a8[a->b7](a);
}
