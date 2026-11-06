/* Actor state routines; reviewed span 0x0c0fe650..0x0c0fe8f0. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1b4f20(struct Actor *);
extern void func_0c1b5070(struct Actor *, int, int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c043352(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;

void func_0c0fe650(register struct Actor *a)
{
    register float vx;
    int zero, one, anim;
    struct Actor *o;
    float d;
    char m;
    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    zero = 0;
    if (a->b141) {
        a->b141 = zero;
        a->f92 = -63.3333321f;
        a->f104 = 0.0f;
        if (a->b1d2)
            a->f92 = -a->f92;
        a->b1a1 = a->s30 + 53;
        a->w1ac = zero;
        a->b19e = zero;
        *(unsigned int *)&a->p1c4 = zero;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c1b4f20(a);
        one = 1;
        func_0c1b5070(a, (a->s30 & one) ^ one, 0);
        func_0c1b5070(a, (a->s30 & one) ^ one, one);
    }
    if (--a->s28 != 0)
        return;
    vx = -6.66666651f;
    m = a->b19e;
    if (m && !(m & 1)) if (func_0c0447bc(a)) goto yes;
    if (0) { yes:
        o = a->p1b0;
        d = 26.666666031f;
        if (a->b1d2)
            d = -26.666666031f;
        o->f52 += d;
        o->f56 = a->f41c;
        o->b1f9 = zero;
        a->b7++;
        a->f92 = vx;
        a->f104 = 1.66666663f;
        if (a->b1d2) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        anim = 5;
    } else {
        a->b3f9 = zero;
        a->b3f8 = zero;
        a->b327 = zero;
        a->b328 = zero;
        a->b6++;
        a->b7 = zero;
        a->f92 = vx;
        a->f104 = 0.41666666f;
        if (a->b1d2) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
        anim = 8;
    }
    func_0c02a0c4(a, 22, anim);
}
void func_0c0fe824(struct Actor *a)
{
    int anim;
    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    if ((a->f92 += a->f104) > 0.0f)
        func_0c043352(a);
    if (func_0c02a026(a) < 0) {
        a->s28 = 20;
        if (++a->s30 == 3) {
            a->b7++;
            anim = 6;
        } else {
            a->b7--;
            anim = (a->s30 & 1) * 2 + 1;
        }
        func_0c0442fa(a);
        func_0c02a0c4(a, 22, anim);
    } else if (a->b141 & 1) {
        a->b141 = 0;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
}
