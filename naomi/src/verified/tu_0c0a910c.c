#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void (*table_0c2444e0[])(struct Actor *, struct ActorSub2a4 *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, unsigned char, unsigned char);
extern void func_0c0451f2(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
void func_0c0a910c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->b1a1 = a->b1a3;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2) func_0c0438de(a);
        else func_0c0437b8(a);
        return;
    }
    if (!a->b141) return;
    a->b141 = 0;
}
void func_0c0a9198(struct Actor *a) { table_0c2444e0[a->b6](a, &a->sub2a4); }
void func_0c0a91ae(struct Actor *a, struct ActorSub2a4 *unused)
{
    float velocity;
    a->b6++;
    func_0c0442fa(a);
    func_0c048bb0(a, 5);
    a->s28 = 0;
    a->b1a1 = 54;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    if (a->b1f9 == 2) {
        a->b6++;
        a->b158 = a->b1a3 ? 27 : 11;
        func_0c02a0c4(a, 21, a->b158);
    } else {
        func_0c0451f2(a);
        a->b158 = a->b1a3 ? 26 : 10;
        func_0c02a0c4(a, 21, a->b158);
        func_0c0432ca(a);
    }
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    if (a->b1a3 == 0) {
        a->f96 = 20.3571415f;
        a->f108 = -0.90401781f;
        velocity = -3.3333333f;
        if (a->w130) velocity = 3.3333333f;
    } else {
        a->f96 = 34.2857132f;
        a->f108 = -1.33928561211f;
        velocity = -4.58333302f;
        if (a->w130) velocity = 4.58333302f;
    }
    a->f92 = velocity;
    func_0c02a39a(a, 0);
}
void func_0c0a92ea(struct Actor *a, struct ActorSub2a4 *unused)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->f52 += a->b1d2 ? 86.666664124f : -86.666664124f;
    }
}
