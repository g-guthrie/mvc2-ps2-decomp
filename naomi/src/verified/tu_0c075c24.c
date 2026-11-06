#include "objects.h"
extern void func_0c03edcc(struct Actor*,struct Actor*);
extern void func_0c03f004(struct Actor*,struct Actor*);
extern char func_0c02a026(struct Actor *);
extern int func_0c0427f2(struct Actor *);
extern int func_0c042780(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c044f1c(struct Actor *);
extern void (*const dat_0c241284[])(struct Actor *, struct Actor *);
void func_0c075c24(struct Actor *a);
void func_0c075cd8(struct Actor *a, struct Actor *o);
void func_0c075cde(struct Actor *a, struct Actor *o);

void func_0c075c24(struct Actor *a)
{
    struct ActorSubControlBytes *s = (struct ActorSubControlBytes *)&a->sub2a4;
    struct Actor *o = a->p1c8;
    if ((a->b141 != 8 || a->b142 == 1) && s->b13) {
        a->b141 = 8;
        a->b142 = 4;
    }
    s->b13 = 0;
    if (func_0c02a026(a) < 0 && s->b12 < 0) {
        a->b19d = -128;
        a->b1ed = 0;
        func_0c044f1c(a);
        return;
    }
    if (s->b12 > 0) {
        if (func_0c0427f2(a)) a->b142 = 1;
        o->s25c--;
        if (func_0c042780(o)) {
            s->b12 = -1;
            func_0c02a0c4(a, 15, 3);
        }
    }
    dat_0c241284[a->b141 >> 1](a, o);
}

void func_0c075cd8(struct Actor *a, struct Actor *o){func_0c03edcc(a, o);}

void func_0c075cde(struct Actor *a, struct Actor *o)
{
    o->s28 ^= 1;
    func_0c03f004(a, o);
}
