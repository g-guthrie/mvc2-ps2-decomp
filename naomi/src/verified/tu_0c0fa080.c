/* Actor routines; reviewed span 0x0c0fa080..0x0c0fa2f4. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c025762(void);
extern void func_0c03489c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c04b02a(struct Actor *);
extern void func_0c034946(struct Actor *, int);
extern void func_0c1ce916(struct LinkedActorVec3 *, int, int, int);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern const float dat_0c24a858[];

void func_0c0fa080(struct Actor *a)
{
    struct LinkedActorVec3 v;
    struct Actor *o = a->p1c8;
    a->b1ea = 1;
    if (!a->b6) {
        v.x = dat_0c24a858[a->b1f7 * 2];
        v.y = (dat_0c24a858 + a->b1f7 * 2)[1];
        func_0c1d4610(a, &v);
        func_0c048ce6(a);
        a->b1a0 = 10;
        *((unsigned char *)a + 0x2a9) = 0; /* byte 5 of the +0x2a4 record */
        a->b6++;
    }
    switch (a->b1f7) {
    case 0:
        if (func_0c02a026(a) < 0) {
            func_0c0437b8(a);
            break;
        }
        if (!a->b141)
            break;
        a->b141 = 0;
        o->p1b4 = a;
        o->b1f6 = 2;
        o->b1f9 = 2;
        func_0c025762();
        o->b1a1 = 32;
        o->b1d2 = a->b1d2 ^ 1;
        func_0c03489c(a->p1c8);
        break;
    case 1:
        if (func_0c02a026(a) < 0) {
            func_0c0437b8(a);
            break;
        }
        if (!a->b141)
            break;
        else if (a->b141 > 0) {
            o->p1b4 = a;
            o->b1a1 = 33;
            func_0c04b02a(a);
        } else {
            o->p1b4 = a;
            o->b1f6 = 1;
            o->b1f9 = 2;
            func_0c025762();
            o->b1a1 = 34;
            o->b1d2 = a->b1d2 ^ 1;
        }
        func_0c034946(o, 2);
        a->b141 = 0;
        v.x = -171.66666f;
        if (a->w130)
            v.x = -v.x;
        v.x += a->f52;
        v.y = a->f56 + 182.142853f;
        func_0c1ce916(&v, a->b1d2, 2, 0);
        a->b141 = 0;
        break;
    case 2:
        if (func_0c02a026(a) < 0) {
            func_0c0438de(a);
            break;
        }
        if (!a->b141)
            break;
        o->p1b4 = a;
        o->b1f6 = 1;
        o->b1f9 = 2;
        func_0c025762();
        o->b1a1 = 35;
        o->b1d2 = a->b1d2 ^ 1;
        break;
    }
}
void func_0c0fa272(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}
void func_0c0fa280(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 1; break;
    case 2: a->b1e9 = 1; break;
    }
    func_0c045248(a, 29);
}
void func_0c0fa2a4(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 1; break;
    case 2: a->b1e9 = 1; break;
    }
    func_0c045248(a, 29);
}
