/* Candidate 0x0c070b60..0x0c070e94: func_0c070b60, func_0c070ba8, func_0c070e4e and all pools but
 * one word match. func_0c070c1e differs in register allocation only: retail keeps the
 * zero in r12 and the linked actor in r11 (swapped here), the 4/14 constants in r7/r6
 * and w34a in r5; the b1d2 toggle spelling is the closest found (792/820 bytes). */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c03489c(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c13a394(struct Actor *, int, int, int);
extern void func_0c06f29c(struct Actor *, struct ActorSub2a4 *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern void (*table_0c240ee4[])(struct Actor *);

void func_0c070b60(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 == 2) {
        struct Actor *p;
        a->b141 = 0;
        p = a->p1c8;
        p->p1b4 = a;
        p->b1f6 = 1;
        p->b1d2 = a->b1d2;
        p->b1a1 = 33;
    }
}

void func_0c070ba8(struct Actor *a)
{
    int zero;
    if (a->b141 < 0) {
        a->b141 = zero = 0;
        if (a->b34 & 2) {
            a->b1d2 ^= 1;
            a->w130 = a->b1d2;
        }
    }
    if (a->b141 == 1) {
        struct Actor *p;
        a->b141 = zero;
        p = a->p1c8;
        p->p1b4 = a;
        p->b1d2 = a->b1d2;
        p->b1a1 = 34;
        p->b1f6 = 11;
        func_0c03489c(p);
    }
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}

void func_0c070c1e(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    int zero = 0;
    float fzero = 0.0f;
    int one = 1;
    struct Actor *p;
    float dx, dy;
    if (a->b6) goto hold;
    if (func_0c02a026(a) >= 0) {
        if (a->b141 == 2) {
            unsigned short w;
            a->b141 = one;
            w = a->w34a;
            if (a->b525) goto none;
            {
                short four = 4; char fourteen = 14;
                if (w & 0x800) { sub->b0 = fourteen; a->b34 = 28; a->s28 = four; }
                else if (!(w & 0x400)) { none: sub->b0 = zero; a->b34 = zero; a->s28 = 5; }
                else { sub->b0 = fourteen; a->b34 = 28; a->s28 = four; { unsigned char *d = &a->b1d2; unsigned char t = a->b1d2 ^ 1; *d = t; a->w130 = t; } }
            }
        }
    } else {
        a->b6++;
        func_0c02a0c4(a, 15, a->s28);
        sub->b1 = 64;
        *(short *)&sub->b2 = 13;
        *(unsigned char *)&sub->w4 = 255;
        a->s28 = 30;
        a->s30 = one;
        func_0c13a394(a, 1, 2, 0);
        {
        struct Actor *q;
        q = a->p1c8;
        *(struct LinkedActorVec3 *)&q->f52 = *(struct LinkedActorVec3 *)&a->f52;
        dx = fzero;
        if (a->b34) {
            dx = -160.0f;
            if (a->b1d2) dx = 160.0f;
        }
        q->f52 += dx;
        q->f56 += 205.71428f;
        }
    }
    return;
hold:
    *(unsigned char *)&sub->w4 = 255;
    p = a->p1c8;
    if (p->b1fd) *(short *)&sub->b2 = zero;
    if (--a->s28 >= 0) {
        func_0c06f29c(a, sub);
        func_0c02a026(a);
        if (!*(short *)&sub->b2) return;
        if (--a->s30) return;
        a->s30 = one;
        dx = fzero;
        dy = 19.2857132f;
        if (a->b34) {
            dx = -10.0f;
            dy = 12.85714245f;
            if (a->b1d2) dx = 10.0f;
        }
        p->f52 += dx;
        p->f56 += dy;
        return;
    }
    *(short *)&sub->b2 = zero;
    *(unsigned char *)&sub->w4 = zero;
    p->p1b4 = a;
    p->b1f6 = one;
    p->b1a1 = 163;
    if (a->b1d2) a->b34 = (32 - a->b34) & 31;
    func_0c02a39a(a, 0);
    func_0c0344a0(a, 43);
    func_0c0437b8(a);
}

void func_0c070e4e(struct Actor *a) { table_0c240ee4[a->b6](a); }
