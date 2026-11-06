#include "objects.h"
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, unsigned char, unsigned char);
extern struct Actor *func_0c1a1a34(struct Actor *, unsigned char, unsigned char);
extern void func_0c0432ca(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c044450(struct Actor *, struct Actor *);
extern void func_0c1a286c(struct Actor *, unsigned char, unsigned char);
extern void func_0c0437b8(struct Actor *);
void func_0c0a98b0(struct Actor *a, struct ActorSub2a4 *unused)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c048bb0(a, 5);
    a->f56 = a->f41c;
    a->b1a1 = 60;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->s28 = 60;
    func_0c02a0c4(a, 15, 4);
    func_0c1a1a34(a, 10, 3);
    func_0c0432ca(a);
}
void func_0c0a991c(struct Actor *a, struct ActorSub2a4 *unused)
{
    func_0c02a026(a);
    if (a->b19e) {
        if (func_0c0447bc(a)) {
            a->b1ea = 1;
            a->b1f7 = 0xc3;
            func_0c044450(a, a->p1b0);
            return;
        }
        a->b6++;
        func_0c02a0c4(a, 21, 17);
        func_0c1a286c(a, 35, 5);
    }
    if (--a->s28 <= 0) {
        a->b6++;
        func_0c02a0c4(a, 21, 17);
        func_0c1a286c(a, 35, 5);
    }
}
void func_0c0a999c(struct Actor *a, struct ActorSub2a4 *unused)
{
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}
