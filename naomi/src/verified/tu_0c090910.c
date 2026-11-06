/* 0x0c090910..0x0c090b30. The second func_0c025900 call reads zero with a folded '& 0' term: retail keeps zero in r13 across the first call (dead-use recipe). */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c19715c(struct Actor *, int, int);
void func_0c090910(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b1f5 = 2;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28)
        return;
    a->b7++;
    a->b1a1 = 56;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c02a0c4(a, 22, 2);
}
void func_0c0909b6(register struct Actor *a, struct Actor *p)
{
    float k, z;
    register void *zero;
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    k = -0.9375f;
    z = 0.0f;
    if (a->b14b) {
        zero = 0;
        if (a->b19e) {
            a->b1a1 = a->b14b;
            a->w1ac = (int)zero;
            a->b19e = (int)zero;
            *(unsigned int *)&a->p1c4 = (int)zero;
            dat_0c2f83f8->arr[a->b2]++;
            a->w1ac |= 16;
            a->b14b = (int)zero;
        } else {
            a->b3f9 = (int)zero;
            a->b3f8 = (int)zero;
            a->b327 = (int)zero;
            a->b328 = (int)zero;
            a->b6++;
            a->b7 = 1;
            p->b3 = (int)zero;
            func_0c025900(a, 0, 13);
            a->f92 = z;
            a->f96 = z;
            a->f104 = z;
            a->f108 = k;
            func_0c02a0c4(a, 22, 6);
        }
    }
    if (a->b141) {
        float d;
        a->b7++;
        func_0c025900(a, (((struct Actor *)zero)->b3 & 0), 13);
        a->f92 = -10.0f;
        a->f104 = z;
        a->f96 = 4.28571415f;
        a->f108 = k;
        if (a->b1d2)
            a->f92 = -a->f92;
        d = 53.3333321f;
        if (a->b1d2)
            d = -53.3333321f;
        a->f52 += d;
        func_0c19715c(a, 0, 0);
    }
}
