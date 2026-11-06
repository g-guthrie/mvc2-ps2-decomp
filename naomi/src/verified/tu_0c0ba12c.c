#include "objects.h"

extern signed char func_0c02a026(struct Actor *a);
extern void func_0c02a0c4(struct Actor *a, int, int);
extern void func_0c15a68c(struct Actor *a, int, int);
extern void func_0c042ed6(struct Actor *a, struct ActorVec3_ba140 *v);
extern unsigned int func_0c02849a(void);
extern int func_0c028642(struct Actor *a);
extern void func_0c0442fa(struct Actor *a);
extern void func_0c0bbb16(struct Actor *a);
extern void func_0c1a94b0(struct Actor *a, int);
extern void (*dat_0c245508[])(struct Actor *a);
extern void (*dat_0c245538[])(struct Actor *a);
extern struct Tbl_ub3_01 *dat_0c2f83f8;

struct ActorVec3_ba140 { float x, y, z; };

void func_0c0ba12c(struct Actor *a)
{
    dat_0c245508[a->b1e9](a);
}

void func_0c0ba140(struct Actor *a)
{
    struct ActorVec3_ba140 v;
    int zero;
    int n;
    zero = 0;
    switch (a->b6) {
    case 0:
        a->b1f9 = zero;
        a->b6++;
        func_0c02a0c4(a, 21, 0);
        func_0c15a68c(a, 0, 0);
        a->s28 = 10;
        a->s30 = zero;
        a->b34 = zero;
        break;
    case 1:
        func_0c02a026(a);
        if (a->b141) {
            a->b6++;
            a->b141 = zero;
            v.x = -(a->f80 * 101.666664124f);
            v.y = a->f84 * 165.0f;
            v.z = a->f60;
            func_0c042ed6(a, &v);
        }
        break;
    case 2:
        a->b328 = 5;
        if (--a->s30 <= 0) {
            a->s30 = func_0c02849a() & 7;
            if (a->b34 = (a->b34 + 1) & 1) {
                a->s30 += 8;
                a->s28--;
                n = a->s28;
            } else {
                n = func_0c02849a() % 3 + 0x80;
            }
            func_0c15a68c(a, 6, n);
            if (a->s28 <= 0)
                a->b6++;
        }
    case 3:
        if (func_0c02a026(a) < 0) {
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            func_0c0bbb16(a);
        }
        break;
    }
}

void func_0c0ba29c(struct Actor *a)
{
    dat_0c245538[a->b6](a);
}

void func_0c0ba2ae(struct Actor *a)
{
    unsigned int zero;
    zero = 0;
    a->b1f9 = zero;
    a->b6++;
    func_0c02a0c4(a, 21, 1);
    a->s28 = zero;
    a->s30 = 3;
    a->b7 = zero;
    if (!func_0c028642(a))
        func_0c0442fa(a);
    a->b1a1 = 50;
    a->w1ac = zero;
    a->b19e = zero;
    a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
}

void func_0c0ba318(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141)
        return;
    a->b6++;
    func_0c1a94b0(a, 0);
    a->f92 = -26.666666031f;
    a->f104 = 0.0f;
    a->f96 = 25.714285f;
    a->f108 = -1.60714281f;
    if (a->b1d2)
        a->f92 = -a->f92;
    a->b32 = 0;
    a->b1f9 = 2;
}
