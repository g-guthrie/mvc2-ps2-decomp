#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2419e8[], table_0c241a5c[];
extern char dat_0c2419d8[], dat_0c2419d4[], dat_0c2419dd[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c192ec8(struct Actor *, int);
extern int func_0c02849a(void);
extern int func_0c03916c(struct Actor *);
extern void func_0c13e4ac(struct Actor *, int, float, float);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c0818cc(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c08183c(struct Actor *);
extern void func_0c08191c(struct Actor *);

#define MODE(a) (((struct ActorSub2a4Mode20 *)&(a)->sub2a4)->mode)

void func_0c07e220(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
    if (a->b141) {
        a->b141 = 0;
        func_0c192ec8(a, 1);
    }
}

void func_0c07e298(struct Actor *a);

void func_0c07e25e(struct Actor *a);

void func_0c07e254(struct Actor *a)
{
    if (a->b6 == 0) func_0c07e25e(a);
    else func_0c07e298(a);
}

void func_0c07e25e(struct Actor *a)
{
    int v;

    a->b6++;
    v = dat_0c2419d8[a->b32];
    if (!a->b32) {
        v = dat_0c2419d4[func_0c02849a() & 3];
        MODE(a) = (unsigned char)v;
    }
    func_0c02a0c4(a, 19, v);
}

void func_0c07e298(struct Actor *a)
{
    float x;

    if (a->b32) {
        if (a->b32 == 2)
            goto check;
        goto done;
    }
    if (MODE(a) != 3) {
    if (func_0c03916c(a))
        goto leave;
    goto L6; L6:
    if (!a->b141)
        goto done;
    goto L1; L1:
    a->b141 = 0;
    func_0c13e4ac(a, 1, -34.0f, 95.0f);
    goto done;
    }
jump:
    if (!a->b7) {
        a->b7++;
        x = 5.0f;
        if (a->w130)
            x = -5.0f;
        a->f92 = x;
        a->f104 = 0.0f;
        a->f96 = 23.57143f;
        a->f108 = -1.0044643f;
        goto out;
    }
    if (a->b7 != 1)
        goto check;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c)
        goto done;
    a->b7++;
    a->f56 = a->f41c;
    func_0c02a684(a, 0, a->b2 + 20, 1);
    func_0c02a0c4(a, 19, dat_0c2419dd[func_0c02849a() & 7]);
    func_0c0818cc(a);
    func_0c0344a0(a, 16);
    return;
check:
    goto L2; L2:
    if (func_0c03916c(a)) {
leave:
        func_0c08183c(a);
        return;
    }
done:
    goto L3; L3:
    func_0c02a026(a);
    return;
out:
    ;
}

void func_0c07e408(struct Actor *a)
{
    table_0c2419e8[a->b1e9](a);
}

void func_0c07e41c(struct Actor *a)
{
    func_0c08183c(a);
}

void func_0c07e422(struct Actor *a)
{
    func_0c08183c(a);
}

void func_0c07e428(struct Actor *a)
{
    func_0c08183c(a);
}

void func_0c07e42e(struct Actor *a)
{
    table_0c241a5c[a->b6](a);
    func_0c08191c(a);
}
