#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
typedef void (*ActorSubHandler)(struct Actor *, struct ActorSub2a4 *);

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern int func_0c02849a(void);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern char dat_0c24a18c[];
extern char dat_0c24a184[];
extern ActorHandler dat_0c24a194[];
extern ActorSubHandler table_0c24a1d8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;

void func_0c0f203c(struct Actor *a)
{
    a->b6++;
    a->b12c = 1;
    func_0c02a0c4(a, 18, 0);
}

void func_0c0f2050(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}

void func_0c0f207a(struct Actor *a);
void func_0c0f20c6(struct Actor *a);

void func_0c0f2070(struct Actor *a)
{
    if (a->b6 == 0)
        func_0c0f207a(a);
    else
        func_0c0f20c6(a);
}

void func_0c0f207a(struct Actor *a)
{
    int c;
    unsigned char b;

    a->b6 = a->b6 + 1;
    b = a->b32;
    c = dat_0c24a18c[b];
    if (b == 0) {
        c = dat_0c24a184[func_0c02849a() & 7];
        func_0c0344a0(a, (func_0c02849a() & 1) + 15);
    }
    func_0c02a0c4(a, 19, c);
}

void func_0c0f20c6(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c0437b8(a);
        return;
    }
    func_0c02a026(a);
}

void func_0c0f20e8(struct Actor *a)
{
    dat_0c24a194[a->b1e9](a);
}

void func_0c0f20fc(struct Actor *a)
{
    table_0c24a1d8[a->b6](a, &a->sub2a4);
}

void func_0c0f2112(struct Actor *a)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c048bb0(a, 5);
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->b1a1 = a->b1a3 + 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3);
}
