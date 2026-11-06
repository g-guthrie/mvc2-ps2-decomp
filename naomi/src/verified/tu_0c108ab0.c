#include "objects.h"

struct ActorFlagsGlobal { unsigned char pad[5]; unsigned char b5, b6; };
typedef void (*ActorHandler)(struct Actor *);
typedef void (*ActorSubHandler)(struct Actor *, struct ActorSub2a4 *);

extern struct ActorFlagsGlobal dat_0c2d9260;
extern ActorSubHandler dat_0c24b6a8[];
extern ActorHandler table_0c24b6b0[];
extern ActorHandler dat_0c24b6bc[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c172474(struct Actor *, int, int);

void func_0c108ab0(struct Actor *a)
{
    struct Actor *child = a->p1c8;

    func_0c02a026(a);
    if (a->b141 == 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        if (a->b1fd || child->b1fd) {
            a->b6 = a->b6 + 1;
            func_0c02a0c4(a, 15, 1);
            a->s28 = 56;
        }
    }
}

void func_0c108b16(struct Actor *a)
{
    struct Actor *child;

    func_0c02a026(a);
    if (--a->s28 == 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c172474(a, 1, 9);
    }
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        child = a->p1c8;
        child->b1f6 = 1;
        child->b1f9 = 2;
        child->b1a1 = 0x20;
        a->b1a1 = 0x20;
        child->b1d2 = a->b1d2;
        child->b1d2 ^= 1;
        dat_0c2d9260.b5 = 3;
        dat_0c2d9260.b6 = 1;
    }
}

void func_0c108ba2(struct Actor *a)
{
    dat_0c24b6a8[a->b6](a, &a->sub2a4);
}

void func_0c108bb8(struct Actor *a)
{
    struct Actor *child;

    if (func_0c02a026(a) < 0) {
        func_0c0438de(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c172474(a, 1, 7);
    }
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        child = a->p1c8;
        child->b1f6 = 1;
        child->b1f9 = 2;
        child->b1a1 = 0x21;
        a->b1a1 = 0x21;
        child->b1d2 = a->b1d2;
        child->b1d2 ^= 1;
    }
}

void func_0c108c54(struct Actor *a)
{
    struct Actor *child;

    func_0c02a026(a);
    if (--a->s28 == 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c172474(a, 1, 9);
    }
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        child = a->p1c8;
        child->b1f6 = 1;
        child->b1f9 = 2;
        child->b1a1 = 0x22;
        a->b1a1 = 0x22;
        child->b1d2 = a->b1d2;
        child->b1d2 ^= 1;
    }
}

void func_0c108cd0(struct Actor *a)
{
    a->b1ea = 1;
    table_0c24b6b0[a->b1f7](a);
}

void func_0c108cec(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c108cfa(struct Actor *a)
{
    dat_0c24b6bc[a->b1f7 & 63](a);
}

void func_0c108d12(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 6; break;
    case 2: a->b1e9 = 6; break;
    }
    func_0c045248(a, 29);
}

void func_0c108d66(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 6; break;
    case 2: a->b1e9 = 6; break;
    }
    func_0c045248(a, 29);
}

void func_0c108d96(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 2;
        break;
    case 1:
        a->b1e9 = 0;
        break;
    case 2:
        a->b1e9 = 3;
        break;
    }
    a->b1a3 = 0;
    func_0c045248(a, 21);
}

void func_0c108dd4(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 2;
        break;
    case 1:
        a->b1e9 = 0;
        break;
    case 2:
        a->b1e9 = 3;
        break;
    }
    a->b1a3 = 0;
    func_0c045248(a, 21);
}
