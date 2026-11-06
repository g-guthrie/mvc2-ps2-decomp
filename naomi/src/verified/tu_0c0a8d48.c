#include "objects.h"
extern void func_0c042018(struct Actor *);
extern void (*table_0c2444cc[])(struct Actor *, struct ActorSub2a4 *);
extern void (*table_0c2444d4[])(struct Actor *, struct ActorSub2a4 *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, unsigned char, unsigned char);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern struct Actor *func_0c1a1a34(struct Actor *, unsigned char, unsigned char);
extern void func_0c1a286c(struct Actor *, unsigned char, unsigned char);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c0a8d48(struct Actor *a)
{
    if (a->b1f9 == 2) {
        func_0c042018(a);
        if (a->f56 <= a->f41c) a->f56 = a->f41c;
    }
    table_0c2444cc[a->b6](a, &a->sub2a4);
}
void func_0c0a8d88(struct Actor *a, struct ActorSub2a4 *unused)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c048bb0(a, 5);
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    if (a->b1f9 == 2) {
        a->f92 /= 16.0f;
        a->f96 /= 8.0f;
        a->f108 /= 64.0f;
        a->f104 = 0;
        func_0c02a0c4(a, 21, 1);
    } else {
        a->b1f9 = 0;
        a->f56 = a->f41c;
        func_0c0432ca(a);
        func_0c02a0c4(a, 21, 0);
        func_0c02a39a(a, 0);
    }
}
void func_0c0a8e3e(struct Actor *a, struct ActorSub2a4 *unused)
{
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2) func_0c0438de(a);
        else func_0c0437b8(a);
        return;
    }
    if (!a->b141) return;
    a->b141 = 0;
    func_0c1a1a34(a, 12, 7);
    func_0c1a286c(a, 34, 3);
}
void func_0c0a8ed6(struct Actor *a)
{
    if (a->b1f9 == 2) {
        func_0c042018(a);
        if (a->f56 <= a->f41c) a->f56 = a->f41c;
    }
    table_0c2444d4[a->b6](a, &a->sub2a4);
}
void func_0c0a8f16(struct Actor *a, struct ActorSub2a4 *unused)
{
    unsigned char animation;
    a->b6++;
    a->s28 = 24;
    a->s30 = 30;
    func_0c0442fa(a);
    func_0c048bb0(a, 5);
    a->f92 = a->b1d2 ? 0.8333333135f : -0.8333333135f;
    a->f104 = 0;
    if (a->b1f9 == 2) {
        a->f92 /= 16.0f;
        a->f96 /= 8.0f;
        a->f108 /= 64.0f;
        a->f104 = 0;
        a->b1a1 = 51;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        animation = 4;
    } else {
        a->b1f9 = 0;
        func_0c0432ca(a);
        a->b1a1 = 51;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        animation = 2;
    }
    goto L; L:
    func_0c02a0c4(a, 21, animation);
    func_0c02a39a(a, 0);
}

extern int func_0c047bbe(struct Actor *);
void func_0c0a903a(struct Actor *a, struct ActorSub2a4 *unused)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    if (a->b14b) {
        a->b14b = 0;
        a->b1a1 = 51;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
    if (a->s30 > 0) {
        a->s30--;
        if (func_0c047bbe(a)) a->s28 += 2;
    }
    if (--a->s28 < 0) {
        a->b6++;
        a->b158 = 3;
        if (a->b1f9 == 2) a->b158 = 5;
        func_0c02a0c4(a, 21, a->b158);
    }
}
