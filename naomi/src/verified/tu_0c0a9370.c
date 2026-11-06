#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2444ec[])(struct Actor *, struct ActorSub2a4 *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, unsigned char, unsigned char);
extern int func_0c043a10(struct Actor *);
void func_0c0a9370(struct Actor *a, struct ActorSub2a4 *unused)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->s28 != (unsigned char)a->b1a3 + 1 && a->b19e) {
        a->s28++;
        if (a->s28 < (unsigned char)a->b1a3 + 2) {
            a->b1a1 = 55;
            a->w1ac = 0;
            a->b19e = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
        }
    }
    if (a->f56 <= a->f41c) {
        a->f56 = a->f41c;
        a->b1f9 = 0;
        func_0c043324(a);
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c0437b8(a);
    }
}
void func_0c0a9448(struct Actor *a) { table_0c2444ec[a->b6](a, &a->sub2a4); }
void func_0c0a945e(struct Actor *a, struct ActorSub2a4 *unused)
{
    a->b6++;
    a->s28 = a->b1a3 ? 40 : 30;
    func_0c0442fa(a);
    func_0c048bb0(a, 5);
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->b1a1 = a->b1a3;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c02a0c4(a, 21, 12);
    a->f92 = a->w130 ? 7.08333302f : -7.08333302f;
    a->b1f2 = 10;
    a->b1f3 = 10;
}
void func_0c0a9520(struct Actor *a, struct ActorSub2a4 *unused)
{
    if ((a->w34a & 0x360) == 0 || !func_0c043a10(a)) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        func_0c02a026(a);
        a->b1f5 = 2;
        if (--a->s28 <= 0) {
            a->b6++;
            a->f92 = 0;
            a->f96 = 0;
            a->f104 = 0;
            a->f108 = 0;
            func_0c02a0c4(a, 21, 13);
        }
    }
}
void func_0c0a959c(struct Actor *a, struct ActorSub2a4 *unused)
{
    a->b1f5 = 2;
    if (func_0c02a026(a) < 0) {
        a->f56 = a->f41c;
        func_0c043324(a);
        func_0c0437b8(a);
    }
}
