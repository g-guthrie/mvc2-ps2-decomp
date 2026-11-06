#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c047bbe(struct Actor *);
extern void func_0c13150c(struct Actor *);
extern void func_0c1beeec(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c130260(struct Actor *a);

void func_0c13015c(struct Actor *a)
{
    struct LinkedActorVec3 v;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b140) {
        if ((signed char)a->b140 < 0)
            func_0c02a39a(a, 1);
        else
            func_0c02a684(a, 0, a->s28 + a->b14b, 1);
    }
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        v.x = 0.0f;
        v.y = 34.2857132f;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c1301d2(struct Actor *a)
{
    float f;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        a->s28 = 120;
        f = 10.0f;
        if (!a->w130) f = -10.0f;
        a->f92 = a->f96 = f;
        a->f104 = 0.0f;
        a->f108 = f * 2.0f;
        func_0c02a0c4(a, 22, 15);
        func_0c130260(a);
    }
}

void func_0c130260(struct Actor *a)
{
    void *zero;
    float s;
    a->b328 = 5;
    func_0c02a026(a);
    s = a->f96;
    if (func_0c047bbe(a)) {
        s = a->f108;
        func_0c02a026(a);
    }
    a->f92 = s;
    a->f52 += a->f92;
    a->f92 += a->f104;
    zero = 0;
    if (a->b14b) {
        a->b14b = (int)zero;
        a->b1a1 = 124;
        a->w1ac = (int)zero;
        a->b19e = (int)zero;
        a->p1c4 = (int)zero;
        dat_0c2f83f8->arr[a->b2]++;
    }
    if (!--a->s28) {
        a->b6++;
        func_0c02a0c4(a, 22, 10);
        a->b1a1 = 109;
        a->w1ac = (int)zero;
        a->b19e = (int)zero;
        a->p1c4 = (int)zero;
        dat_0c2f83f8->arr[a->b2]++;
    }
}

void func_0c130328(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        func_0c02a0c4(a, 22, 11);
    }
}

void func_0c13035c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c13150c(a);
    else if (a->b141) {
        a->b141 = 0;
        func_0c1beeec(a);
    }
}
