/* Throw handlers 0x0c128ab8..0x0c129208: attacker a, held victim v. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, char);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c1ce916(struct LinkedActorVec3 *, int, int, int);
extern void func_0c034946(struct Actor *, int);
extern void func_0c1856a4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c1d330c(struct Actor *, struct LinkedActorVec3 *, int, int);
extern void func_0c1bfa20(struct Actor *);
extern int func_0c0427f2(struct Actor *);
extern int func_0c042780(struct Actor *);
extern void func_0c04af58(struct Actor *, int);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern unsigned int func_0c02849a(void);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24daac[])(struct Actor *, struct Actor *);
extern void (*table_0c24dab8[])(struct Actor *, struct Actor *);
extern char dat_0c24dac4[][4];
extern char dat_0c24dad0[][4];
extern char dat_0c24dad8[][4];
void func_0c12902a(struct Actor *a);
void func_0c128c44(struct Actor *a, struct Actor *v);

void func_0c128ab8(struct Actor *a, struct Actor *v)
{
    struct LinkedActorVec3 p;
    func_0c02a026(a);
    if (a->b14b) {
        a->b14b = 0;
        a->b6++;
        v->p1b4 = a;
        v->b1a1 = 32;
        v->b1f6 = 18;
        p.x = 90.0f; if (a->w130) p.x = p.x;
        p.x += a->f52;
        p.y = a->f56 + 285.0f;
        func_0c1ce916(&p, a->b1d2, 2, 0);
        func_0c034946(a->p1c8, 0);
    }
}

void func_0c128b32(struct Actor *a, struct Actor *v)
{
    if (v->b5 == 2 && v->p1b4->b1 == 56 && v->b1f6 == 18) {
        if (v->f56 > 342.85712f) {
            a->b6++;
            v->p1b4 = a;
            v->b1a1 = 70;
            v->b1f6 = 19;
            v->b1f7 = 3;
            v->b6 = v->b7 = 0;
            v->b1a0 = 10;
            func_0c1856a4(a, 18, 0);
        }
        return;
    }
    func_0c12902a(a);
}

void func_0c128b94(struct Actor *a)
{
    if (func_0c02a026(a) < 0) func_0c12902a(a);
}

void func_0c128bb4(struct Actor *a, struct Actor *v)
{
    if (func_0c02a026(a) < 0) {
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
        return;
    }
    goto L; L:
    if (a->b14b) {
        a->b14b = 0;
        v->p1b4 = a;
        v->b1a1 = 32;
        v->b1f6 = 1;
        func_0c128c44(a, v);
    }
}

void func_0c128c44(struct Actor *a, struct Actor *v)
{
    struct LinkedActorVec3 p;
    float x = -90.0f;
    if (a->w130) x = 90.0f;
    p.x = x + v->f52;
    p.y = v->f56 + 285.0f;
    func_0c1ce916(&p, a->b1d2, 2, 0);
    func_0c034946(a->p1c8, 0);
}

void func_0c128c94(struct Actor *a, struct Actor *v)
{
    table_0c24daac[a->b6](a, v);
}

void func_0c128ca6(struct Actor *a, struct Actor *v)
{
    func_0c02a026(a);
    if (a->b14b) {
        a->b14b = 0;
        a->b6++;
        v->p1b4 = a;
        v->b1a1 = 32;
        v->b1f6 = 18;
        func_0c128c44(a, v);
    }
}

void func_0c128d10(struct Actor *a, struct Actor *v)
{
    struct LinkedActorVec3 p;
    if (v->b5 == 2 && v->p1b4->b1 == 56 && v->b1f6 == 18 && v->f56 > 411.42856f) {
        a->b6++;
        v->p1b4 = a;
        v->b1a1 = 69;
        v->b1f6 = 9;
        v->b1f7 = 3;
        v->b6 = v->b7 = 0;
        v->b1a0 = 10;
        func_0c0346da(a, 73);
        p.x = v->f52;
        p.y = v->f56 + 34.2857132f;
        func_0c1d330c(v, &p, 1, 0xf9);
    }
}

void func_0c128d98(struct Actor *a)
{
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}

void func_0c128dba(struct Actor *a, struct Actor *v)
{
    if (a->b6 == 0) {
        goto L; L: func_0c02a026(a);

        if (a->b14b) {
            a->b14b = 0;
            a->b6++;
            v->p1b4 = a;
            v->b1a1 = 33;
            v->b1f6 = 1;
            v->w130 ^= 1;
        }
        return;
    }
    if (func_0c02a026(a) < 0) {
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c12902a(a);
    }
}

void func_0c128e2e(struct Actor *a, struct Actor *v)
{
    table_0c24dab8[a->b6](a, v);
}

void func_0c128e68(struct Actor *a, struct Actor *v)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        a->b6++;
        v->b22a = 3; v->pad220[8] = 3;
        func_0c1bfa20(v);
    }
}

void func_0c128ea6(struct Actor *a)
{
    char t;
    if (func_0c0427f2(a)) a->s28 = a->s28 + 1;
    if (func_0c042780(a->p1c8)) a->s28 = 0;
    func_0c02a026(a);
    if (a->b14b) {
        a->b14b = 0;
        func_0c04af58(a->p1c8, -1);
        if (--a->s28 <= 0) {
            a->b6++;
            func_0c025900(a, 0, 0);
            a->b1a1 = 35;
            a->b19e = a->w1ac = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            func_0c02a0c4(a, 15, 4);
            goto reset;
        }
    }
    t = a->b141;
    if (t) {
        a->b141 = 0;
        if ((char)(t - 4) == 0) {
        reset:
            func_0c02a39a(a, 0);
            return;
        } else
            func_0c02a684(a, 0, 4, 1);
    }
}

void func_0c128f74(struct Actor *a, struct Actor *v)
{
    struct LinkedActorVec3 p;
    if (func_0c02a026(a) < 0) {
        func_0c12902a(a);
        return;
    }
    goto L; L:
    if (a->b140) {
        a->b140 = 0;
        v->p1b4 = a;
        v->b1a1 = 35;
        v->b1f6 = 10;
    }
    if (a->b141) {
        float x;
        a->b141 = 0;
        x = -85.0f;
        if (a->w130) x = 85.0f;
        p.x = x + a->f52;
        p.y = a->f56 + 240.0f;
        func_0c1ce916(&p, a->b1d2, 2, 0);
    }
}

void func_0c12902a(struct Actor *a)
{
    if (a->b1f9 == 2) func_0c0438de(a);
    else func_0c0437b8(a);
}

void func_0c129040(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c12904e(struct Actor *a)
{
    int zero = 0;
    a->b6 = a->b7 = a->b5 = zero;
    switch (a->b4c9) {
    case 0: a->b1e9 = zero; break;
    case 1: a->b1e9 = zero; break;
    case 2: a->b1e9 = zero; break;
    }
    func_0c045248(a, 29);
}

void func_0c129074(struct Actor *a)
{
    int zero = 0;
    a->b6 = a->b7 = a->b5 = zero;
    switch (a->b4c9) {
    case 0: a->b1e9 = zero; break;
    case 1: a->b1e9 = zero; break;
    case 2: a->b1e9 = zero; break;
    }
    func_0c045248(a, 29);
}

void func_0c12909a(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 2; break;
    case 2: goto c2; c2: a->b1e9 = 12; break;
    default: goto skip;
    }
    a->b1a3 = 1;
skip:
    goto k; k:
    func_0c045248(a, 21);
}

void func_0c129108(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 2; break;
    case 2: goto c2; c2: a->b1e9 = 12; break;
    default: goto skip;
    }
    a->b1a3 = 1;
skip:
    goto k; k:
    func_0c045248(a, 21);
}

void func_0c129144(struct Actor *a)
{
    if (a->b141) {
        func_0c02a0c4(a, 0, dat_0c24dac4[a->b141 - 1][func_0c02849a() & 3]);
    }
}

void func_0c12917c(struct Actor *a)
{
    char i = a->b1d3;
    if (i < 0) i = 0;
    func_0c02a0c4(a, 0, dat_0c24dad0[i][func_0c02849a() & 3]);
}

void func_0c1291b2(struct Actor *a)
{
    char i = a->b141;
    if (i) i = 1;
    func_0c02a0c4(a, 0, dat_0c24dad8[i][func_0c02849a() & 3]);
}
